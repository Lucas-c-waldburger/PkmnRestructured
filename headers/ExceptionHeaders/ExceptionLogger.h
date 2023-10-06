#ifndef PKMNRESTRUCTURED_EXCEPTIONLOGGER_H
#define PKMNRESTRUCTURED_EXCEPTIONLOGGER_H
#include <vector>
#include <iostream>

class ExceptionLogger
{
public:
    static ExceptionLogger& get();

    ExceptionLogger(const ExceptionLogger& rhs) = delete;
    ExceptionLogger& operator=(const ExceptionLogger& rhs) = delete;

    void log(const char* message);
    void printLog();

private:
    ExceptionLogger() = default;
    std::vector<std::string> messages;
};











#endif //PKMNRESTRUCTURED_EXCEPTIONLOGGER_H
