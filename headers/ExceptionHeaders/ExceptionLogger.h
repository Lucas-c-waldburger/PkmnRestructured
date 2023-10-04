#ifndef PKMNRESTRUCTURED_EXCEPTIONLOGGER_H
#define PKMNRESTRUCTURED_EXCEPTIONLOGGER_H


class ExceptionLogger
{
public:
    static ExceptionLogger& get();

    ExceptionLogger(const ExceptionLogger& rhs) = delete;
    ExceptionLogger& operator=(const ExceptionLogger& rhs) = delete;



private:
    ExceptionLogger();
};











#endif //PKMNRESTRUCTURED_EXCEPTIONLOGGER_H
