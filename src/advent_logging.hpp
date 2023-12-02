#pragma once

#include <iostream>

namespace advent
{
    enum class LogLevel
    {
        INFO,
        WARNING,
        ERROR
    };

    class Logger
    {
    public:
        static void log(LogLevel level, const std::string& message)
        {
            switch (level)
            {
            case LogLevel::INFO:
                std::cout << "[INFO] " << message << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "[WARNING] " << message << std::endl;
                break;
            case LogLevel::ERROR:
                std::cout << "[ERROR] " << message << std::endl;
                break;
            default:
                break;
            }
        }
    };

}