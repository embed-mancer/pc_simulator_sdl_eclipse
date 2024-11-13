#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>

// Log level definitions
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_DEBUG 4

// Set default log level if not already defined
#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_DEBUG
#endif

// Define log macros for each level, including function name and line number
#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...) \
  printf("[INFO] [%s:%d]: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...)  // Empty definition
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...) \
  printf("[WARNING] [%s:%d]: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_WARN(fmt, ...)  // Empty definition
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(fmt, ...) \
  printf("[ERROR] [%s:%d]: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_ERROR(fmt, ...)  // Empty definition
#endif

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(fmt, ...) \
  printf("[DEBUG] [%s:%d]: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)  // Empty definition
#endif

#endif  // LOG_H_
