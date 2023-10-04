#ifndef PKMNRESTRUCTURED_PROXYGROUP_H
#define PKMNRESTRUCTURED_PROXYGROUP_H

#include "CardData.h"

struct ProxyGroup
{
    ProxyGroup(int nCards, CardType ct);
    ProxyGroup(int nCards, CardType ct, EnergyType et);
    ProxyGroup(int nCards, CardID id);
    ProxyGroup(int nCards);

    int numCards;
    CardData cData;
};



#endif //PKMNRESTRUCTURED_PROXYGROUP_H
