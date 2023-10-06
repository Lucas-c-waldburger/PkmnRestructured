#ifndef PKMNRESTRUCTURED_TYPES_H
#define PKMNRESTRUCTURED_TYPES_H

#include <iostream>
#include "../ExceptionHeaders/ExceptionLogger.h"

/* ----------------------- CARD ID ----------------------- */

class CardID
{
public:
    inline CardID(int i) : id(i) {};
    inline operator int& () { return id; };
    inline bool operator==(const CardID& rhs) const
    {
        // std::cout << "OVERLOAD == CARDID CALLED\n";
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

enum class EnergyType { NULL_ENERGY, ANY, WATER, FIRE, GRASS, ELECTRIC, PSYCHIC, FIGHTING, COLORLESS };
inline bool operator==(const EnergyType lhs, const EnergyType rhs)
{
    // std::cout << "OVERLOADED EnergyType OPERATOR== CALLED\n";
    return (static_cast<int>(lhs) == static_cast<int>(EnergyType::ANY) &&
            static_cast<int>(rhs) != static_cast<int>(EnergyType::NULL_ENERGY)) ||

           (static_cast<int>(rhs) == static_cast<int>(EnergyType::ANY) &&
            static_cast<int>(lhs) != static_cast<int>(EnergyType::NULL_ENERGY)) ||

           static_cast<int>(lhs) == static_cast<int>(rhs);
}

enum class CardType { NULL_CARD, ANY, ENERGY, PKMN, TRAINER };
inline bool operator==(const CardType lhs, const CardType rhs)
{
    // std::cout << "OVERLOADED CardType OPERATOR== CALLED\n";
    return (static_cast<int>(lhs) == static_cast<int>(CardType::ANY) &&
            static_cast<int>(rhs) != static_cast<int>(CardType::NULL_CARD)) ||

           (static_cast<int>(rhs) == static_cast<int>(CardType::ANY) &&
            static_cast<int>(lhs) != static_cast<int>(CardType::NULL_CARD)) ||

            static_cast<int>(lhs) == static_cast<int>(rhs);
}



/* ----------------------- ZONE NAME ENUM ----------------------- */

enum class ZoneName { NULL_ZONE, BASE, ATTACHED, ACTIVE_ZONE, BENCH, DECK, HAND, DISCARD_PILE, PRIZES };


/* ----------------------- STAGE TYPE ENUM ----------------------- */

enum class Stage { BASIC, EVO_1, EVO_2 };


/* ----------------------- INT CAST / COMP ----------------------- */

template <typename T>
inline constexpr int intCast(T t)
{
    return static_cast<int>(t);
}

// Used for comparisons where we need to identify ...Type::ANY as its' literal integer value and avoid its' overloaded == op
template <typename T>
struct IntCastComp
{
    inline bool operator()(const T& lhs, const T& rhs) const
    {
        return intCast(lhs) == intCast(rhs);
    }
};

#endif //PKMNRESTRUCTURED_TYPES_H
