#include "logger.hpp"

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <mutex>
#include <sys/stat.h>

#ifdef __SWITCH__
#include <switch.h>
#endif

namespace {
FILE* s_logFile = nullptr;
std::mutex s_logMutex;
auto s_start = std::chrono::steady_clock::now();
}  // namespace

void logInit() {
    std::lock_guard<std::mutex> lk(s_logMutex);
#ifdef __SWITCH__
    mkdir("sdmc:/config", 0777);
    mkdir("sdmc:/config/NXtify", 0777);
    const char* logPath = "sdmc:/config/NXtify/app.log";
    const char* prevPath = "sdmc:/config/NXtify/app.log.previous";
#else
    const char* logPath = "app.log";
    const char* prevPath = "app.log.previous";
#endif
    std::remove(prevPath);
    std::rename(logPath, prevPath);
    s_logFile = std::fopen(logPath, "w");
    s_start = std::chrono::steady_clock::now();
    if (s_logFile) {
        std::fprintf(s_logFile, "=== NXtify UI Log Started ===\n");
        std::fflush(s_logFile);
    }
}

void logWrite(const char* fmt, ...) {
    std::lock_guard<std::mutex> lk(s_logMutex);
    const auto now = std::chrono::steady_clock::now();
    const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - s_start).count();

    char buf[2048];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    if (s_logFile) {
        std::fprintf(s_logFile, "[%08lld ms] %s\n", static_cast<long long>(ms), buf);
        std::fflush(s_logFile);
    }
    std::printf("[%08lld ms] %s\n", static_cast<long long>(ms), buf);
}

void logClose() {
    std::lock_guard<std::mutex> lk(s_logMutex);
    if (s_logFile) {
        std::fprintf(s_logFile, "=== NXtify UI Log Closed ===\n");
        std::fflush(s_logFile);
        std::fclose(s_logFile);
        s_logFile = nullptr;
    }
}
