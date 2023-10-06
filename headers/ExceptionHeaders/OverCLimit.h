#ifndef PKMNRESTRUCTURED_OVERCLIMIT_H
#define PKMNRESTRUCTURED_OVERCLIMIT_H

#include "InvalidMove.h"

class Zone;
class OverCLimit : public InvalidMove
{
public:
    OverCLimit(const std::string& zoneName, int cMove, int cCurrent, int cLimit);
    virtual ~OverCLimit() = default;

private:
    void makeMessage(const std::string& zoneName, int cMove, int cCurrent, int cLimit);
};









#endif //PKMNRESTRUCTURED_OVERCLIMIT_H
