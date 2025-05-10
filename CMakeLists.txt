cmake_minimum_required(VERSION 3.10)
project(lvgl_demo C CXX)

set(CMAKE_C_STANDARD      11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD    17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/RTOS)

#target_compile_options(${PROJECT_NAME} PRIVATE -O3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
  message(FATAL_ERROR "SDL2 not found")
endif()

file(GLOB_RECURSE LVGL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lv_drivers/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/demos/*.c
)

set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mouse_cursor_icon.c
)

add_executable(${PROJECT_NAME}
    ${APP_SOURCES}
    ${LVGL_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/src
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/demos
    ${CMAKE_CURRENT_SOURCE_DIR}/lv_drivers
    ${SDL2_INCLUDE_DIRS}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    LV_CONF_INCLUDE_SIMPLE
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    freertos_shared
    SDL2
)

add_custom_target(run
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)