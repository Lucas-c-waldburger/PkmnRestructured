#ifndef PKMNRESTRUCTURED_TYPES_H
#define PKMNRESTRUCTURED_TYPES_H

#include <iostream>

/* ----------------------- CARD ID ----------------------- */

class CardID
{
public:
    inline CardID(int i) : id(i) {};
    inline operator int& () { return id; };
    inline bool operator==(const CardID& rhs) const
    {
        std::cout << "OVERLOAD == CARDID CALLED\n";
        int any = 0, null_id = -1;

        return (this->id == any && rhs.id != null_id) ||  // CardID::ANY matches with any cId EXCEPT CardID::NULL_ID
               (rhs.id == any && this->id != null_id) ||
               this->id == rhs.id;
    }

    static const CardID NULL_ID;
    static const CardID ANY;

private:
    int id;
};

inline const CardID CardID::NULL_ID = -1;
inline const CardID CardID::ANY = 0;


/* ----------------------- CDATA TYPE ENUMS ----------------------- */

enum class EnergyType { WATER, FIRE, GRASS, ELECTRIC, PSYCHIC, FIGHTING, COLORLESS, ANY, NULL_ENERGY };
inline bool operator==(const EnergyType lhs, const EnergyType rhs)
{
    std::cout << "OVERLOADED EnergyType OPERATOR== CALLED\n";
    return (static_cast<int>(lhs) == static_cast<int>(EnergyType::ANY) &&
            static_cast<int>(rhs) != static_cast<int>(EnergyType::NULL_ENERGY)) ||

           (static_cast<int>(rhs) == static_cast<int>(EnergyType::ANY) &&
            static_cast<int>(lhs) != static_cast<int>(EnergyType::NULL_ENERGY)) ||

           static_cast<int>(lhs) == static_cast<int>(rhs);
}

enum class CardType { ENERGY, PKMN, TRAINER, ANY, NULL_CARD };
inline bool operator==(const CardType lhs, const CardType rhs)
{
    std::cout << "OVERLOADED CardType OPERATOR== CALLED\n";
    return (static_cast<int>(lhs) == static_cast<int>(CardType::ANY) &&
            static_cast<int>(rhs) != static_cast<int>(CardType::NULL_CARD)) ||

           (static_cast<int>(rhs) == static_cast<int>(CardType::ANY) &&
            static_cast<int>(lhs) != static_cast<int>(CardType::NULL_CARD)) ||

            static_cast<int>(lhs) == static_cast<int>(rhs);
}


/* ----------------------- ZONE NAME ENUM ----------------------- */

enum class ZoneName { BASE, ATTACHED, ACTIVE_ZONE, BENCH, DECK, HAND, DISCARD_PILE, PRIZES, NULL_ZONE };


/* ----------------------- STAGE TYPE ENUM ----------------------- */

enum class Stage { BASIC, EVO_1, EVO_2 };










#endif //PKMNRESTRUCTURED_TYPES_H
