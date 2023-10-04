#ifndef PKMNRESTRUCTURED_ZONE_H
#define PKMNRESTRUCTURED_ZONE_H
#include <vector>
#include <unordered_map>
#include "../CardHeaders/Card.h"

class Zone
{
public:
    friend class ZoneTools;

    Zone(ZoneName zNm, int cLimit);
    virtual ~Zone() = default;

    virtual bool moveTo(Zone& destination, std::initializer_list<ProxyGroup> requestedCards);

    virtual int getCardLimit() const;
    ZoneName getName() const;

    void testAdd(CardID id, CardType ct, EnergyType et);

protected:
    std::vector<std::unique_ptr<Card>> cards;

    const ZoneName name;
    const int cardLimit;
    std::unordered_map<CardType, int> acceptedCTypes;

};

















#endif //PKMNRESTRUCTURED_ZONE_H
