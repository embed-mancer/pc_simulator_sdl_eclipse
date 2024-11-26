cmake_minimum_required(VERSION 2.8.12)

string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} ) 
project(${CURRENT_FOLDER})

# add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Werror ) 
# add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Werror)
# 设置编译器标志
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # 强警告和优化选项
    add_compile_options(
        -Wall            # 开启所有常见的警告
        -Wextra          # 开启额外的警告
        -Wpedantic       # 启用符合 ISO C/C++ 标准的警告
        -Werror          # 将所有警告视为错误
        -Wshadow         # 警告变量覆盖
        -Wformat=2       # 强化 printf 格式检查
        # -Wfloat-equal    # 警告浮点数比较
        # -Wcast-align     # 警告指针类型强制转换对齐问题
        # -Wpointer-arith  # 警告对无类型指针的算术操作
        # -Wmissing-declarations # 警告缺少声明的函数
        # -Wredundant-decls     # 警告重复的声明
        # -Wconversion     # 警告隐式类型转换可能存在数据丢失
        # -Wsign-conversion # 警告不同符号整数之间的转换
        # -O3              # 使用最高级别的优化
    )
elseif(MSVC)
    # Windows 平台使用 MSVC 编译器时的设置
    add_compile_options(
        /W4              # 最高警告级别
        /WX              # 将警告视为错误
        /Ox              # 使用最高级别的优化
    )
endif()



file(GLOB ${PROJECT_NAME}_SRC
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
  "*.c"
)

list (SORT ${PROJECT_NAME}_SRC)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} )


install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib  # 动态库安装路径
  ARCHIVE DESTINATION lib  # 静态库安装路径
  RUNTIME DESTINATION bin  # 可执行文件安装路径
  PUBLIC_HEADER DESTINATION include  # 头文件安装路径
)