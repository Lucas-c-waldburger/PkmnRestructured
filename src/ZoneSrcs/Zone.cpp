#include "../../headers/ZoneHeaders/Zone.h"
#include "../../headers/ZoneHeaders/Utils/ZoneTools.h"


Zone::Zone(ZoneName zNm, int cLimit) : name(zNm), cardLimit(cLimit)
{}

bool Zone::moveTo(Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    if (!(ZoneTools::validateMove(*this, destination, requestedCards)))
        return false;

    ZoneTools::moveRequestedCards(*this, destination, requestedCards);
    ZoneTools::eraseMovedCards(*this);

    return true;
}












int Zone::getCardLimit() const
{
    return cardLimit;
}

ZoneName Zone::getName() const
{
    return name;
}

void Zone::testAdd(CardID id, CardType ct, EnergyType et)
{
    cards.emplace_back(std::make_unique<Card>(CardData{id, ct, et}));
}






