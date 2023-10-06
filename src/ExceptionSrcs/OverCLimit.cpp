#include "../../headers/ExceptionHeaders/OverCLimit.h"

OverCLimit::OverCLimit(const std::string& zoneName, int cMove, int cCurrent, int cLimit) : InvalidMove()
{
    makeMessage(zoneName, cMove, cCurrent, cLimit);
}


void OverCLimit::makeMessage(const std::string& zoneName, int cMove, int cCurrent, int cLimit)
{
    whatMsg = "Cannot move " + std::to_string(cMove) +  " Card(s) into ZoneName::" + zoneName +
              ".\nCurrent " + zoneName + " contents: " + std::to_string(cCurrent) + " / " + std::to_string(cLimit) + '\n';

}