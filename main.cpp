#include <iostream>
#include "headers/Card.h"

std::unique_ptr<Card>& retCard(bool b, std::unique_ptr<Card>& c)
{
    return (b) ? c : Card::NULL_CARD();
}

int main()
{
    auto card1 = std::make_unique<Card>(CardData({ CardID::ANY, CardType::ANY, EnergyType::FIRE }));

//    auto& cardNull = Card::NULL_CARD();

    //Card card2({ CardID::ANY, CardType::ANY, EnergyType::NULL_ENERGY });

    std::cout << std::boolalpha << (*card1 == ProxyGroup(2, CardType::NULL_CARD, EnergyType::FIRE));

    return 0;
}
