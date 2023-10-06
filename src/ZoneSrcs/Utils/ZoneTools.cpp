#include "../../../headers/ZoneHeaders/Utils/ZoneTools.h"
#include "../../../headers/ZoneHeaders/Zone.h"


bool ZoneTools::validateMove(Zone& origin, Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    bool moveValid = false;
    try
    {
        moveValid = Validate::allCardsPresent(origin, requestedCards) &&
                    Validate::validCLimit(destination, requestedCards) &&
                    Validate::validCType(destination, requestedCards);
    }
    catch (InvalidMove& invMove)
    {
        ExceptionLogger::get().log(invMove.what());
    }

    return moveValid;
}

void ZoneTools::moveRequestedCards(Zone& origin, Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    for (auto& reqCs : requestedCards)
    {
        int numCards = reqCs.numCards;
        while (numCards > 0)
        {
            auto foundCard = std::find_if(origin.cards.begin(), origin.cards.end(), ProxyComp(reqCs));

            if (foundCard == origin.cards.end())
                throw CNotFound(StringConvertMaps::fromZoneName.at(origin.getName()), reqCs.cData);

            destination.cards.push_back(std::move(*foundCard));

            --numCards;
        }
    }
}

void ZoneTools::eraseMovedCards(Zone& zone)
{
    zone.cards.erase(std::remove(zone.cards.begin(), zone.cards.end(), nullptr), zone.cards.end());
}


/* Validate */
bool ZoneTools::Validate::allCardsPresent(Zone& origin, std::initializer_list<ProxyGroup> requestedCards)
{
    for (auto& reqCs : requestedCards)
    {
        if (ZoneTools::getCount(origin, reqCs) < reqCs.numCards)
            throw CNotFound(StringConvertMaps::fromZoneName.at(origin.getName()), reqCs.cData);
    }
    return true;
}

bool ZoneTools::Validate::validCLimit(Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    int totalCards = std::accumulate(requestedCards.begin(), requestedCards.end(), 0,
                                     [](int sum, const ProxyGroup& recCs) { return sum + recCs.numCards; });

    bool withinLimits = destination.cards.size() + totalCards <= destination.getCardLimit();

    if (!withinLimits)
        throw OverCLimit(StringConvertMaps::fromZoneName.at(destination.getName()),
                         totalCards, destination.cards.size(), destination.getCardLimit());

    return withinLimits;
}

bool ZoneTools::Validate::validCType(Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    for (auto& reqCs : requestedCards)
    {
        if (!destination.acceptedCTypes(reqCs.cData.cType))
            throw UnacceptedCType(StringConvertMaps::fromZoneName.at(destination.getName()),
                                  destination.acceptedCTypes.getAsList(), reqCs.cData.cType);
    }
    return true;
}

int ZoneTools::getCount(Zone &zone, const ProxyGroup& proxyGroup)
{
    return std::count_if(zone.cards.begin(), zone.cards.end(), ProxyComp(proxyGroup));
}


