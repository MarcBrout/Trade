cmake_minimum_required(VERSION 3.6)
project(trade)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/ICom.hh
        src/ICore.hh
        src/ICurve.hh
        src/Curve.cpp
        src/Curve.hh
        src/Com.cpp
        src/Com.hh
        src/trade.cpp src/trade.cpp)
add_executable(trade ${SOURCE_FILES})