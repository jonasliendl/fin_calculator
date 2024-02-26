#include <iostream>
#include <string>
#include "./interest/Interest.h"
#include "./commuter_benefit/CommuterBenefit.h"
#include "./yield/Yield.h"
#include "./percent_calculator/PercentageCalculator.h"


int main() {
    Interest interestObj(5000, 0, 10, 4.0, MONTHLY);
    InterestMap interest = interestObj.calculate();
    for (int i = 0; i < interest.size(); i++) {
        InterestItem item = interest.at(i);
        string prefix = "Interest year ";
        prefix.append(to_string(i));
        string depositCap = to_string(item.deposit);
        string recCap = to_string(item.interestReceived);
        string str = prefix;
        str.append(" ");
        str.append(depositCap);
        str.append(" ");
        str.append(recCap);
        std::cout << str << std::endl;
    }
    CommuterBenefit benefit(225, 58);
    double calculatedBenefit = benefit.calculateBenefit();
    std::cout << calculatedBenefit << std::endl;
    Yield yield(10000.0, 20500.0, 2017, 2023);
    yield.calculate();
    std::cout << yield.getYieldOverall() << std::endl;
    std::cout << yield.getYieldPerAnno() << std::endl;
    PercentageCalculator percent;
    percent.changeStartValue(2000.0);
    percent.changeInterestRate(0.23);
    double endValue = 0.0;
    try {
        endValue = percent.calculateEndValue();
    } catch (std::exception& err) {
        std::cout << err.what() << std::endl;
    }
    std::cout << endValue << std::endl;
    return 0;
}
