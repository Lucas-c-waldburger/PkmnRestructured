#ifndef PKMNRESTRUCTURED_STRINGCONVERTMAPS_H
#define PKMNRESTRUCTURED_STRINGCONVERTMAPS_H

#include "../../Types.h"
#include <unordered_map>

namespace StringConvertMaps
{

    static inline const std::unordered_map<CardType, const std::string> fromCType =
            {
                    {CardType::ENERGY,  "Energy Card"},
                    {CardType::PKMN,    "Pokemon Card"},
                    {CardType::TRAINER, "Trainer Card"}
            };

    static inline const std::unordered_map<EnergyType, const std::string> fromEType =
            {
                    {EnergyType::WATER,     "Water"},
                    {EnergyType::FIRE,      "Fire"},
                    {EnergyType::GRASS,     "Grass"},
                    {EnergyType::ELECTRIC,  "Electric"},
                    {EnergyType::PSYCHIC,   "Psychic"},
                    {EnergyType::FIGHTING,  "Fighting"},
                    {EnergyType::COLORLESS, "Colorless"}
            };

}













#endif //PKMNRESTRUCTURED_STRINGCONVERTMAPS_H
