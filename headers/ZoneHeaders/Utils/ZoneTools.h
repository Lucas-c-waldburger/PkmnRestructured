#ifndef PKMNRESTRUCTURED_ZONETOOLS_H
#define PKMNRESTRUCTURED_ZONETOOLS_H
#include "../../CardHeaders/Card.h"
#include "../../CardHeaders/Utils/CardComp.h"
#include "../Zone.h"
#include "../../Types/Utils/StringConvert.h"
#include "../../ExceptionHeaders/UnacceptedCType.h"
#include "../../ExceptionHeaders/OverCLimit.h"
#include "../../ExceptionHeaders/CNotFound.h"
#include <vector>
#include <numeric>
#include <unordered_set>

class ZoneTools
{
public:
    static bool validateMove(Zone& origin, Zone& destination, std::initializer_list<ProxyGroup> requestedCards);
    static void moveRequestedCards(Zone& origin, Zone& destination, std::initializer_list<ProxyGroup> requestedCards);
    static void eraseMovedCards(Zone& zone);

    template <class T>
    static int getCount(Zone& zone, T compVal);
    template <class T, class U>
    static int getCount(Zone& zone, T compVal1, U compVal2);
    static int getCount(Zone& zone, const ProxyGroup& proxyGroup);


private:
    struct Validate
    {
        static bool allCardsPresent(Zone& origin, std::initializer_list<ProxyGroup> requestedCards);
        static bool validCType(Zone& destination, std::initializer_list<ProxyGroup> requestedCards);
        static bool validCLimit(Zone& destination, std::initializer_list<ProxyGroup> requestedCards);
    };
};

static inline constexpr int NO_CARD_LIMIT = std::numeric_limits<int>::max();

template<class T>
inline int ZoneTools::getCount(Zone& zone, T compVal)
{
    return std::count_if(zone.cards.begin(), zone.cards.end(), CompSingleType<T>(compVal));
}

template<class T, class U>
inline int ZoneTools::getCount(Zone& zone, T compVal1, U compVal2)
{
    return std::count_if(zone.cards.begin(), zone.cards.end(), CompDoubleType<T, U>(compVal1, compVal2));
}







#endif //PKMNRESTRUCTURED_ZONETOOLS_H
