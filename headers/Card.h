#ifndef PKMNRESTRUCTURED_CARD_H
#define PKMNRESTRUCTURED_CARD_H

#include "ProxyGroup.h"


class NullCard;
class Card
{
public:
    Card(const CardData& data);
    ~Card();

    bool operator==(const Card& rhs);
    bool operator==(const ProxyGroup&& proxyGrp);

    const std::unique_ptr<CardData>& getCData();

    static NullCard NULL_CARD;

private:
    std::unique_ptr<CardData> cData;
};


class NullCard
{
public:
    NullCard();
    NullCard(const NullCard& rhs) = delete;
    NullCard& operator=(const NullCard& rhs) = delete;
    std::unique_ptr<Card>& operator()() const;
private:
    mutable std::unique_ptr<Card> nullCard;
};









#endif //PKMNRESTRUCTURED_CARD_H
