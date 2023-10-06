#ifndef PKMNRESTRUCTURED_INVALIDMOVE_H
#define PKMNRESTRUCTURED_INVALIDMOVE_H
#include "../CardHeaders/Utils/CardData.h"
#include <exception>


class InvalidMove : public std::exception
{
public:
    InvalidMove() = default;
    virtual ~InvalidMove() = default;
    inline virtual const char* what() const throw() { return whatMsg.c_str(); };

protected:
    std::string whatMsg;
};



#endif //PKMNRESTRUCTURED_INVALIDMOVE_H
