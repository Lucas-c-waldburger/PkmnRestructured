#include "../../headers/ExceptionHeaders/UnacceptedCType.h"

UnacceptedCType::UnacceptedCType(const std::string& zoneName, const std::string& validCTypesStr, CardType ct) : InvalidMove()
{
    makeMessage(zoneName, validCTypesStr, ct);
}

void UnacceptedCType::makeMessage(const std::string& zoneName, const std::string& validCTypesStr, CardType ct)
{
    whatMsg = "Cannot move CardType::" + StringConvertMaps::fromCType.at(ct) +
              " into ZoneName::" + zoneName +
              ".\nAccepted CTypes are:\n" + validCTypesStr;
}

