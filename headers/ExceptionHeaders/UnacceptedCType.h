#ifndef PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H
#define PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H

#include "InvalidMove.h"

class Zone;
class UnacceptedCType : public InvalidMove
{
public:
    UnacceptedCType(const std::string& zoneName, const std::string& validCTypesStr, CardType ct);
    virtual ~UnacceptedCType() = default;

private:
    void makeMessage(const std::string& zoneName, const std::string& validCTypesStr, CardType ct);
};





#endif //PKMNRESTRUCTURED_UNACCEPTEDCTYPE_H
