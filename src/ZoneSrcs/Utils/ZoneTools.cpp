#include "../../../headers/ZoneHeaders/Utils/ZoneTools.h"
#include "../../../headers/ZoneHeaders/Zone.h"


bool ZoneTools::validateMove(Zone& origin, Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    return Validate::allCardsPresent(origin, requestedCards) &&
           Validate::validCLimit(destination, requestedCards) &&
           Validate::validCType(destination, requestedCards);
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
                throw std::runtime_error("Requested card(s) not found in origin zone");

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
            return false;
    }
    return true;
}

bool ZoneTools::Validate::validCLimit(Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    int totalCards = std::accumulate(requestedCards.begin(), requestedCards.end(), 0,
                                     [](int sum, const ProxyGroup& recCs) { return sum + recCs.numCards; });

    return destination.cards.size() + totalCards <= destination.getCardLimit();
}

bool ZoneTools::Validate::validCType(Zone& destination, std::initializer_list<ProxyGroup> requestedCards)
{
    if (destination.acceptedCTypes[CardType::ANY])
        return true;

    // if the card's ctype is not in the accepted map, it will get inserted as a key and the value initialized to 0 (false)
    return std::all_of(requestedCards.begin(), requestedCards.end(),
                       [&destination](const ProxyGroup& reqCs){ return destination.acceptedCTypes[reqCs.cData.cType]; });
}

int ZoneTools::getCount(Zone &zone, const ProxyGroup& proxyGroup)
{
    return std::count_if(zone.cards.begin(), zone.cards.end(), ProxyComp(proxyGroup));
}


