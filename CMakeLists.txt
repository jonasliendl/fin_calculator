cmake_minimum_required(VERSION 3.27)
project(fin_calculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(fin_calculator main.cpp
        types/PayInterval.h
        interest/Interest.h
        interest/InterestItem.h
        interest/InterestMap.h
        interest/Interest.cpp
        commuter_benefit/CommuterBenefit.h
        commuter_benefit/CommuterBenefit.cpp
        commuter_benefit/CommuterBenefit.h
        yield/Yield.h
        yield/Yield.cpp)
