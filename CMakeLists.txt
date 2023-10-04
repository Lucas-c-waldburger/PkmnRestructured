cmake_minimum_required(VERSION 3.24)
project(PkmnRestructured)

set(CMAKE_CXX_STANDARD 17)

add_executable(PkmnRestructured main.cpp headers/Types.h headers/CardHeaders/Utils/CardData.h src/CardSrcs/Utils/CardData.cpp headers/CardHeaders/Card.h src/CardSrcs/Card.cpp headers/CardHeaders/Utils/ProxyGroup.h src/CardSrcs/Utils/ProxyGroup.cpp headers/ZoneHeaders/Zone.h src/ZoneSrcs/Zone.cpp headers/ZoneHeaders/Utils/ZoneTools.h src/ZoneSrcs/Utils/ZoneTools.cpp headers/CardHeaders/Utils/CardComp.h headers/ExceptionHeaders/InvalidMove.h src/ExceptionSrcs/InvalidMove.cpp headers/ExceptionHeaders/ExceptionLogger.h src/ExceptionSrcs/ExceptionLogger.cpp headers/ExceptionHeaders/Utils/StringConvertMaps.h headers/ExceptionHeaders/UnacceptedCType.h src/ExceptionSrcs/UnacceptedCType.cpp)
