#ifndef PKMNRESTRUCTURED_STRINGCONVERT_H
#define PKMNRESTRUCTURED_STRINGCONVERT_H
#include "StringConvertMaps.h"

static inline std::string asString(CardType ct)
{
    return StringConvertMaps::fromCType.at(ct);
}

static inline std::string asString(EnergyType et)
{
    return StringConvertMaps::fromEType.at(et);
};

static inline std::string asString(ZoneName zNm)
{
    return StringConvertMaps::fromZoneName.at(zNm);
};

static inline std::string asString(CardID cId)
{
    if (intCast(cId) == intCast(CardID::NULL_ID))
        return "NULL_ID";

    if (intCast(cId) == intCast(CardID::ANY))
        return "ANY";

    return std::to_string(cId);
};


#endif //PKMNRESTRUCTURED_STRINGCONVERT_H
