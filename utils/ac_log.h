#ifndef AC_LOG_H
#define AC_LOG_H

#include "stdio.h"

#define LOG(type, fmt, ...) printf("(%s:%i)["type"]: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define ERRLOG(type, fmt, ...) fprintf(stderr, "(%s:%i)["type"]: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) LOG("INFO", fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) LOG("WARN", fmt, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...) LOG("ERROR", fmt, ##__VA_ARGS__)

#endif