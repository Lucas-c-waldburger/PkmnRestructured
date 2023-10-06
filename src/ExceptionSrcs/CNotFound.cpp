#include "../../headers/ExceptionHeaders/CNotFound.h"

CNotFound::CNotFound(const std::string& zoneName, const CardData& cd)
{
    makeMessage(zoneName, cd);
}

void CNotFound::makeMessage(const std::string& zoneName, const CardData& cd)
{
    whatMsg = "Requested card not found in ZoneName::" + zoneName + ":\n" + cd.getAsStr() + '\n';
}