cmake_minimum_required(VERSION 2.8.12)

string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
project(${CURRENT_FOLDER})

# if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wshadow -Wformat=2)
# elseif(MSVC)
#   add_compile_options(/W4 /WX /Ox)
# endif()

file(
  GLOB
  ${PROJECT_NAME}_SRC
  "config/*.c"
  "data/*.c"
  "font/*.c"
  "key/*.c"
  "language/*.c"
  "light/*.c"
  "menu/*.c"
  "other/*.c"
  "screens/*.c"
  "third/json/*.c"
  "tool/*.c"
  "view/*.c"
  "*.c")

include_directories(${CMAKE_SOURCE_DIR}/../lvgl-ui)
# add_definitions(-DLVGL_DIR="L:${CMAKE_INSTALL_FULL_DATAROOTDIR}/lvgl_data/")
list(SORT ${PROJECT_NAME}_SRC)
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC})

set(HEADERS)
file(
  GLOB
  HEADERS
  "config/*.h"
  "data/*.h"
  "font/*.h"
  "key/*.h"
  "screens/main_window.h"
  "language/*.h"
  "light/*.h"
  "menu/*.h"
  "other/*.h"
  "screens/*.h"
  "tool/*.h"
  "view/*.h"
  "third/json/*.h"
  "*.h")

foreach(header ${HEADERS})
  file(RELATIVE_PATH rel_path ${CMAKE_SOURCE_DIR} ${header})
  get_filename_component(dir_path ${rel_path} DIRECTORY)
  install(FILES ${header}
          DESTINATION "${CMAKE_INSTALL_PREFIX}/include/${dir_path}")
endforeach()

if(DEFINED CMAKE_INSTALL_FULL_LIBDIR)
  install(
    TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION "${CMAKE_INSTALL_FULL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_FULL_LIBDIR}"
    RUNTIME DESTINATION bin)
endif()
