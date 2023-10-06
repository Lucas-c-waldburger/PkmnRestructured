#include <iostream>
#include "headers/ZoneHeaders/Utils/ZoneTools.h"



int main()
{

    Zone hand(ZoneName::HAND, {CardType::PKMN}, 1);
    Zone deck(ZoneName::DECK, {CardType::ANY}, NO_CARD_LIMIT);
    deck.testAdd(CardID::ANY, CardType::ENERGY, EnergyType::FIRE);
    deck.testAdd(CardID::ANY, CardType::ENERGY, EnergyType::WATER);
//
    deck.moveTo(hand, { {1, CardType::PKMN} });
    deck.moveTo(hand, { {1, CardType::ENERGY} });










    ExceptionLogger::get().printLog();
    return 0;
}
