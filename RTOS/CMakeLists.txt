cmake_minimum_required(VERSION 3.15)
project(freertos_shared C)

set(FREERTOS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS" CACHE PATH "Path to FreeRTOS root")
set(FREERTOS_PLUS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Plus" CACHE PATH "Path to FreeRTOS-Plus root")
set(KERNEL_DIR "${FREERTOS_DIR}/Source")

option(TRACE_ON_ENTER   "Enable TRACE_ON_ENTER=1 (else 0)" OFF)
option(COVERAGE_TEST    "Enable projCOVERAGE_TEST=1 (else 0)" OFF)
option(PROFILE          "Enable profiling (-pg -O0)" OFF)
option(SANITIZE_ADDRESS "Enable AddressSanitizer" OFF)
option(SANITIZE_LEAK    "Enable LeakSanitizer" OFF)
option(BLINKY_DEMO      "Build blinky demo (USER_DEMO=0)" OFF)
option(FULL_DEMO        "Build full demo   (USER_DEMO=1)" OFF)

# —— 全局编译选项 —— 
# 和 Makefile 保持一致的 -ggdb3
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ggdb3")

# PROFILE vs 默认优化
if(PROFILE)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg -O0")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg -O0")
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -O3")
endif()

# Address & Leak Sanitizers
if(SANITIZE_ADDRESS)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=alignment")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fsanitize=alignment")
endif()
if(SANITIZE_LEAK)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=leak")
endif()

file(GLOB APP_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)
file(GLOB KERNEL_SRCS
    "${KERNEL_DIR}/*.c"
)

# Memory manager + Posix port
set(MEMMANG_SRCS
  "${KERNEL_DIR}/portable/MemMang/heap_3.c"
)
set(POSIX_SRCS
  "${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c"
  "${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/port.c"
)

set(ALL_SRCS
  ${APP_SRCS}
  ${KERNEL_SRCS}
  ${MEMMANG_SRCS}
  ${POSIX_SRCS}
)

add_library(${PROJECT_NAME} SHARED ${ALL_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
  "${KERNEL_DIR}/include"
  "${KERNEL_DIR}/portable/ThirdParty/GCC/Posix"
  "${KERNEL_DIR}/portable/ThirdParty/GCC/Posix/utils"
  "${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/Include"
)

# BUILD_DIR
target_compile_definitions(${PROJECT_NAME} PUBLIC
  BUILD_DIR=\"${CMAKE_BINARY_DIR}\"
  _WINDOWS_
)
# Trace & Coverage
if(TRACE_ON_ENTER)
  target_compile_definitions(${PROJECT_NAME} PUBLIC TRACE_ON_ENTER=1)
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC TRACE_ON_ENTER=0)
endif()
if(COVERAGE_TEST)
  target_compile_definitions(${PROJECT_NAME} PUBLIC projCOVERAGE_TEST=1)
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC projCOVERAGE_TEST=0)
endif()

# USER_DEMO
if(BLINKY_DEMO)
  target_compile_definitions(${PROJECT_NAME} PUBLIC USER_DEMO=0)
elseif(FULL_DEMO)
  target_compile_definitions(${PROJECT_NAME} PUBLIC USER_DEMO=1)
endif()

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads)
