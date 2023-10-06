#include "../../headers/ExceptionHeaders/ExceptionLogger.h"

ExceptionLogger& ExceptionLogger::get()
{
    static ExceptionLogger logger;
    return logger;
}

void ExceptionLogger::log(const char* message)
{
    messages.emplace_back(message);
}

void ExceptionLogger::printLog()
{
    std::cout << "<<<<< " << messages.size() <<
    " EXCEPTIONS CAUGHT >>>>>\n-------------------------------\n";
    for (auto& msg : messages)
        std::cout << msg <<
        "-------------------------------\n";
}
