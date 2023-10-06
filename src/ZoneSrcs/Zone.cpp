#include "../../headers/ZoneHeaders/Zone.h"
#include "../../headers/ZoneHeaders/Utils/ZoneTools.h"


Zone::Zone(ZoneName zNm, std::initializer_list<CardType> acceptedCTs, int cLimit) :
name(zNm), cardLimit(cLimit), acceptedCTypes(acceptedCTs)
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

Zone::AcceptedCTypes::AcceptedCTypes(std::initializer_list<CardType> cts) : mSet(cts)
{
    //for (auto& s : mSet ) { std::cout << StringConvertMaps::fromCType.at(s) << " "; }
    if (mSet.count(CardType::NULL_CARD))
        throw std::invalid_argument("Cannot permit a zone to accept NULL_CARD type");
    if (mSet.count(CardType::ANY))
        mSet = { CardType::PKMN, CardType::ENERGY, CardType::TRAINER };
    for (auto& s : mSet ) { std::cout << StringConvertMaps::fromCType.at(s) << " "; }
    std:: cout << "\n\n";
}

bool Zone::AcceptedCTypes::operator()(CardType ct)
{
    return (intCast(ct) == intCast(CardType::ANY)) || mSet.count(ct);
}

std::string Zone::AcceptedCTypes::getAsList()
{
    std::string validCTypeStr;
    for (auto& ct : mSet)
        validCTypeStr += StringConvertMaps::fromCType.at(ct) + '\n';

    return validCTypeStr;
}





