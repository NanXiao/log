#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

/* The base conditon to stop */
void log(std::ostream& out, std::stringstream& ss);

template <typename First, typename... Rest>
void log(std::ostream& out, std::stringstream& ss, First&& first, Rest&&... rest)
{
    ss << std::forward<First>(first);
    log(out, ss, std::forward<Rest>(rest)...);
    return;
}

template <typename First, typename... Rest>
void log(std::ostream& out, First&& first, Rest&&... rest)
{
    std::stringstream ss;
    /* Output timestamp */
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto ptm = std::localtime(&now);
    ss << "[" << std::put_time(ptm, "%x %X") << ", " ;
    /* Output thread ID */
    ss << "0x"<<std::hex << std::this_thread::get_id() << "] "<<std::dec;
    ss << std::forward<First>(first);
    log(out, ss, std::forward<Rest>(rest)...);
    return;
}
