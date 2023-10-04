#ifndef PKMNRESTRUCTURED_CARDDATA_H
#define PKMNRESTRUCTURED_CARDDATA_H

#include "../../Types.h"

struct PkmnData;
struct EnergyData;
struct TrainerData;

struct CardData
{
    CardData(CardID id, CardType ct, EnergyType et);
    virtual ~CardData();
    virtual bool operator==(const CardData& rhs);

    CardID cId;
    CardType cType;
    EnergyType eType;

    virtual const PkmnData *getPkmnData() const;
    virtual EnergyData *getEnergyData();
    virtual TrainerData *getTrainerData();

    //virtual void print() const;
};

struct PkmnData : public CardData
{
    using AttackNames = std::pair<std::string, std::string>;

    PkmnData(CardID id, EnergyType et, Stage st, int bHp, EnergyType weak, EnergyType res, AttackNames  atNm);
    virtual ~PkmnData();

    Stage stage;
    int baseHp;
    EnergyType weakness;
    EnergyType resistance;
    AttackNames attackNames; // use names as keys for attackFuncMap

    const PkmnData* getPkmnData() const override;
    //void print() const override;

};

struct EnergyData : public CardData
{
    EnergyData(CardID id, EnergyType et, int val);
    virtual ~EnergyData();

    int value;

    EnergyData* getEnergyData() override;
    //void print() const override;

};

struct TrainerData : public CardData
{
    TrainerData(CardID id, const std::string& effNm);
    virtual ~TrainerData();

    std::string effectName;

    TrainerData* getTrainerData() override;
    //void print() const override;

};













#endif //PKMNRESTRUCTURED_CARDDATA_H
