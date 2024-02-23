//
// Created by Jonas Liendl on 18.02.24.
//

#ifndef FIN_CALCULATOR_INTEREST_H
#define FIN_CALCULATOR_INTEREST_H

#include "../types/PayInterval.h"
#include "InterestItem.h"
#include "InterestMap.h"

class Interest {
public:
    Interest(unsigned int startCapital, unsigned int monthlySavings, unsigned int years, float interestRate, PayInterval payInterval);
    ~Interest();
    [[nodiscard]] unsigned int getStartCapital() const;
    [[nodiscard]] unsigned int getMonthlySaving() const;
    [[nodiscard]] unsigned int getYears() const;
    [[nodiscard]] float getInterestRate() const;
    [[nodiscard]] PayInterval getPayInterval();
    Interest* changeStartCapital(unsigned int capital);
    Interest* changeMonthlySaving(unsigned int saving);
    Interest* changeYears(unsigned int savingYears);
    Interest* changeInterestRate(float rate);
    Interest* changePayInterval(PayInterval interval);
    InterestMap calculate();
private:
    unsigned int startCapital;
    unsigned int monthlySaving;
    unsigned int years;
    float interestRate;
    PayInterval payInterval;
    bool didValuesChange;
    InterestMap data;
    InterestItem calculateForOneYear(InterestItem previousItem);
    [[nodiscard]] unsigned int calculateOneUnit(unsigned int currentCapital) const;
};

#endif //FIN_CALCULATOR_INTEREST_H
