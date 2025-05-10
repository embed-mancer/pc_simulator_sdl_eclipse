cmake_minimum_required(VERSION 3.10)
project(lvgl_demo C CXX)

# —— 语言标准 —— 
set(CMAKE_C_STANDARD      11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD    17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# —— 编译优化 —— 
# 如果想做调试用 -g
#target_compile_options(${PROJECT_NAME} PRIVATE -O3)

# —— 输出目录 —— 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

# —— 查找 SDL2 —— 
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
  message(FATAL_ERROR "SDL2 not found")
endif()

# —— 源文件列表 —— 
file(GLOB_RECURSE LVGL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lv_drivers/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/demos/*.c
)
# 主程序
set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mouse_cursor_icon.c
)

# —— 添加可执行目标 —— 
add_executable(${PROJECT_NAME}
    ${APP_SOURCES}
    ${LVGL_SOURCES}
)

# —— 包含目录 —— 
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}               # 自己的头
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl          # lvgl 根头
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/src      # internal headers
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/demos    # 示例头
    ${CMAKE_CURRENT_SOURCE_DIR}/lv_drivers    # 驱动头
    ${SDL2_INCLUDE_DIRS}                      # SDL2
)

# —— 宏定义 —— 
target_compile_definitions(${PROJECT_NAME} PRIVATE
    LV_CONF_INCLUDE_SIMPLE
)

# —— 链接库 —— 
target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2
)

# —— “run” 伪目标 —— 
add_custom_target(run
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

