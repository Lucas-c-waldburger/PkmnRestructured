#ifndef PKMNRESTRUCTURED_INVALIDMOVE_H
#define PKMNRESTRUCTURED_INVALIDMOVE_H
#include "Utils/StringConvertMaps.h"
#include <exception>

template <class T>
class InvalidMove : public std::exception
{
public:
    InvalidMove(T d);
    virtual ~InvalidMove() = 0;
    virtual const char* what() const throw() = 0;

protected:
    const T data;
    virtual const char* makeMessage() = 0;
};

template<class T>
InvalidMove<T>::InvalidMove(T d) : data(d)
{}


#endif //PKMNRESTRUCTURED_INVALIDMOVE_H
