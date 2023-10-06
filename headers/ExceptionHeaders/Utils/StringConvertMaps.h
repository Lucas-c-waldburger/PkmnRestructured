#ifndef PKMNRESTRUCTURED_STRINGCONVERTMAPS_H
#define PKMNRESTRUCTURED_STRINGCONVERTMAPS_H

#include "../../Types.h"
#include <unordered_map>

namespace StringConvertMaps
{

    static inline const std::unordered_map<CardType, std::string> fromCType =
            {
                    { CardType::NULL_CARD, "NULL_CARD" },
                    { CardType::ANY,       "ANY" },
                    { CardType::ENERGY,    "ENERGY" },
                    { CardType::PKMN,      "PKMN" },
                    { CardType::TRAINER,   "TRAINER" }
            };

    static inline const std::unordered_map<EnergyType, std::string> fromEType =
            {
                    { EnergyType::NULL_ENERGY, "NULL_ENERGY" },
                    { EnergyType::ANY,         "ANY" },
                    { EnergyType::WATER,       "WATER" },
                    { EnergyType::FIRE,        "FIRE" },
                    { EnergyType::GRASS,       "GRASS" },
                    { EnergyType::ELECTRIC,    "ELECTRIC" },
                    { EnergyType::PSYCHIC,     "PSYCHIC" },
                    { EnergyType::FIGHTING,    "FIGHTING" },
                    { EnergyType::COLORLESS,   "COLORLESS" }
            };

    static inline const std::unordered_map<ZoneName, std::string> fromZoneName =
            {
                    { ZoneName::BASE,         "BASE" },
                    { ZoneName::ATTACHED,     "ATTACHED" },
                    { ZoneName::ACTIVE_ZONE,  "ACTIVE_ZONE" },
                    { ZoneName::DECK,         "DECK" },
                    { ZoneName::BENCH,        "BENCH" },
                    { ZoneName::HAND,         "HAND" },
                    { ZoneName::DISCARD_PILE, "DISCARD_PILE" },
                    { ZoneName::PRIZES,       "PRIZES" },
                    { ZoneName::NULL_ZONE,    "NULL_ZONE" }
            };

}













#endif //PKMNRESTRUCTURED_STRINGCONVERTMAPS_H
