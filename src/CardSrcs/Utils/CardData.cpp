#include <utility>

#include "../../../headers/CardHeaders/Utils/CardData.h"

/* CardData */
CardData::CardData(CardID id, CardType ct, EnergyType et) : cId(id), cType(ct), eType(et)
{}

CardData::~CardData()
{}

bool CardData::operator==(const CardData& rhs)
{
    return this->cId == rhs.cId &&
           this->cType == rhs.cType &&
           this->eType == rhs.eType;
}

const PkmnData* CardData::getPkmnData() const { return nullptr; }
EnergyData* CardData::getEnergyData() { return nullptr; }
TrainerData* CardData::getTrainerData() { return nullptr; }

std::ostream& operator<<(std::ostream& os, CardData& cd)
{
    os << "CardID: " << cd.cId
       << "\nCardType: " << StringConvertMaps::fromCType.at(cd.cType)
       << "\nEnergyType: " << StringConvertMaps::fromEType.at(cd.eType);

    return os;
}

std::string CardData::getAsStr() const
{
    std::string cIdStr = "CardID: " +  std::to_string(intCast(cId)) +
                         "\nCardType: " + StringConvertMaps::fromCType.at(cType) +
                         "\nEnergyType: " + StringConvertMaps::fromEType.at(eType);
    return cIdStr;
}

/* PkmnData */
PkmnData::PkmnData(CardID id, EnergyType et, Stage st, int bHp, EnergyType weak, EnergyType res, AttackNames atNm) :
CardData(id, CardType::PKMN, et), stage(st), baseHp(bHp), weakness(weak), resistance(res), attackNames(std::move(atNm))
{}

PkmnData::~PkmnData()
{}

const PkmnData* PkmnData::getPkmnData() const { return this; }


/* EnergyData */
EnergyData::EnergyData(CardID id, EnergyType et, int val) : CardData(id, CardType::ENERGY, et), value(val)
{}

EnergyData::~EnergyData()
{}

EnergyData* EnergyData::getEnergyData() { return this; }


/* TrainerData */
TrainerData::TrainerData(CardID id, const std::string& effNm) : CardData(id, CardType::TRAINER, EnergyType::ANY)
{}

TrainerData::~TrainerData()
{}

TrainerData* TrainerData::getTrainerData() { return this; }




