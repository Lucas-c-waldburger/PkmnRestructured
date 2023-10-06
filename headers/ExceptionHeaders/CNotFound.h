#ifndef PKMNRESTRUCTURED_CNOTFOUND_H
#define PKMNRESTRUCTURED_CNOTFOUND_H

#include "InvalidMove.h"

class Zone;
class CNotFound : public InvalidMove
{
public:
    CNotFound(const std::string& zoneName, const CardData& cd);
    virtual ~CNotFound() = default;

private:
    void makeMessage(const std::string& zoneName, const CardData& cd);
};



#endif //PKMNRESTRUCTURED_CNOTFOUND_H
