#pragma once
#include <string>

void logInit();
void logWrite(const char* fmt, ...);
void logClose();

#define LOG(fmt, ...) logWrite(fmt, ##__VA_ARGS__)
