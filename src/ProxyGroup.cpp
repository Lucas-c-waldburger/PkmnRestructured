#include "../headers/ProxyGroup.h"


ProxyGroup::ProxyGroup(int nCards, CardType ct) : numCards(nCards), cData(CardID::ANY, ct, EnergyType::ANY)
{}

ProxyGroup::ProxyGroup(int nCards, CardType ct, EnergyType et) : numCards(nCards), cData(CardID::ANY, ct, et)
{}

ProxyGroup::ProxyGroup(int nCards, CardID id) : numCards(nCards), cData(id, CardType::ANY, EnergyType::ANY)
{}

ProxyGroup::ProxyGroup(int nCards) : numCards(nCards), cData(CardID::ANY, CardType::ANY, EnergyType::ANY)
{}


