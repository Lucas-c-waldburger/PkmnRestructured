#ifndef PKMNRESTRUCTURED_CARDCOMP_H
#define PKMNRESTRUCTURED_CARDCOMP_H

#include "../Card.h"

// ----------------- Single-Type Comp ----------------- //

template <class T>
struct CompSingleType
{
    inline CompSingleType(T compVal) : compValue(compVal) {};
    T compValue;
    bool operator()(const std::unique_ptr<Card>& c) const;
};

template<>
inline bool CompSingleType<CardType>::operator()(const std::unique_ptr<Card>& c) const
{
    if (c == nullptr)
        return false;
    return compValue == c->getCData()->cType;
}

template<>
inline bool CompSingleType<EnergyType>::operator()(const std::unique_ptr<Card>& c) const
{
    if (c == nullptr)
        return false;
    return compValue == c->getCData()->eType;
}


// ----------------- Two-Type Comp ----------------- //

template <class T, class U>
struct CompDoubleType
{
    inline CompDoubleType(T compVal1, U compVal2) : compValue1(compVal1), compValue2(compVal2) {};
    T compValue1;
    U compValue2;
    bool operator()(const std::unique_ptr<Card>& c) const;
};

template<>
inline bool CompDoubleType<CardType, EnergyType>::operator()(const std::unique_ptr<Card> &c) const
{
    if (c == nullptr)
        return false;
    return compValue1 == c->getCData()->cType && compValue2 == c->getCData()->eType;
}

template<>
inline bool CompDoubleType<EnergyType, CardType>::operator()(const std::unique_ptr<Card> &c) const
{
    if (c == nullptr)
        return false;
    return compValue1 == c->getCData()->eType && compValue2 == c->getCData()->cType;
}


// ----------------- ProxyComp ----------------- //

struct ProxyComp
{
    inline ProxyComp(const ProxyGroup& proxyGroup) : proxyGroupData(proxyGroup.cData) {}
    CardData proxyGroupData;
    bool operator()(const std::unique_ptr<Card>& c) const;
};

inline bool ProxyComp::operator()(const std::unique_ptr<Card> &c) const
{
    if (c == nullptr)
        return false;
    return *(c->getCData()) == proxyGroupData;
}







#endif //PKMNRESTRUCTURED_CARDCOMP_H
