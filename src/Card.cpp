#include "../headers/Card.h"

Card::Card(const CardData& data) : cData(std::make_unique<CardData>(data))
{}

Card::~Card()
{}

bool Card::operator==(const Card &rhs)
{
    return (*this->cData) == *(rhs.cData);
}

bool Card::operator==(const ProxyGroup&& proxyGrp)
{
    return *(this->cData) == proxyGrp.cData;
}

const std::unique_ptr<CardData> &Card::getCData()
{
    return this->cData;
}


// Used to return invalid card searches
// Must return a non-const reference to work with many search methods.
// To circumvent this, we make one const nullCard instance with a mutable unique_ptr
// and one public operator method that "resets" the unique_ptr before returning the reference to it
NullCard Card::NULL_CARD{};

NullCard::NullCard() : nullCard(std::make_unique<Card>(CardData{CardID::NULL_ID, CardType::NULL_CARD, EnergyType::NULL_ENERGY}))
{}

std::unique_ptr<Card>& NullCard::operator ()() const
{
    nullCard = std::make_unique<Card>(CardData{CardID::NULL_ID, CardType::NULL_CARD, EnergyType::NULL_ENERGY});
    return nullCard;
}
