#ifndef PKMNRESTRUCTURED_ZONE_H
#define PKMNRESTRUCTURED_ZONE_H
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../CardHeaders/Card.h"

class Zone
{
public:
    friend class ZoneTools;

    Zone(ZoneName zNm, std::initializer_list<CardType> acceptedCTs, int cLimit);
    virtual ~Zone() = default;

    virtual int getCardLimit() const;
    ZoneName getName() const;

    virtual bool moveTo(Zone& destination, std::initializer_list<ProxyGroup> requestedCards);
    void testAdd(CardID id, CardType ct, EnergyType et);

protected:
    std::vector<std::unique_ptr<Card>> cards;

    const ZoneName name;
    const int cardLimit;

    class AcceptedCTypes
    {
    public:
        AcceptedCTypes(std::initializer_list<CardType> cts);
        bool operator()(CardType ct);
        std::string getAsList();
    private:
        std::unordered_set<CardType, std::hash<CardType>, IntCastComp<CardType>> mSet;
        //std::unordered_set<CardType> mSet;
    } acceptedCTypes;
};

















#endif //PKMNRESTRUCTURED_ZONE_H
