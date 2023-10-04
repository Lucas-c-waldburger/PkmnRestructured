#ifndef PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H
#define PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H

#include "InvalidMove.h"


class UnacceptedCType : public InvalidMove<CardType>
{
public:
    UnacceptedCType(CardType ct);

    const char* what() const throw() override;

private:
    const char* makeMessage() override;
};




#endif //PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H
