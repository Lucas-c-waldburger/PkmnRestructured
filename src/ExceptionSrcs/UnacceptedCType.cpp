#include "../../headers/ExceptionHeaders/UnacceptedCType.h"

UnacceptedCType::UnacceptedCType(CardType ct) : InvalidMove<CardType>(ct)
{}

const char *UnacceptedCType::what() const throw()
{
    return makeMessage();
}

const char *UnacceptedCType::makeMessage()
{
    const std::string cTypeStr = StringConvertMaps::fromCType[data];

}

