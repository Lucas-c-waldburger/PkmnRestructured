cmake_minimum_required(VERSION 3.24)
project(PkmnRestructured)

set(CMAKE_CXX_STANDARD 17)

add_executable(PkmnRestructured main.cpp headers/Types.h headers/CardData.h src/CardData.cpp headers/Card.h src/Card.cpp headers/ProxyGroup.h src/ProxyGroup.cpp)
