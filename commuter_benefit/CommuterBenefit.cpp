//
// Created by Jonas Liendl on 23.02.24.
//
#include "CommuterBenefit.h"

CommuterBenefit::CommuterBenefit(unsigned int workingDays, unsigned int commuteInKm) {
    this->workingDays = workingDays;
    this->commuteInKm = commuteInKm;
    didValuesChange = true;
    benefitValue = 0.0;
}

unsigned int CommuterBenefit::getWorkingDays() const {
    return workingDays;
}

unsigned int CommuterBenefit::getCommuteInKM() const {
    return commuteInKm;
}

void CommuterBenefit::changeWorkingDays(unsigned int days) {
    workingDays = days;
    didValuesChange = true;
}

void CommuterBenefit::changeCommuteInKM(unsigned int km) {
    commuteInKm = km;
    didValuesChange = true;
}

double CommuterBenefit::calculateBenefit() {
    if (didValuesChange) {
        if (commuteInKm >= 21) {
            double benefitForFirstTwenty = workingDays * 20.0 * COMMUTER_BENEFIT_BASIC;
            double benefitFromTwentyFirst = workingDays * (commuteInKm - 20) * COMMUTER_BENEFIT_ADVANCED;

            didValuesChange = false;
            benefitValue = benefitFromTwentyFirst + benefitForFirstTwenty;

            return benefitValue;
        } else {
            double benefit = workingDays * commuteInKm * COMMUTER_BENEFIT_BASIC;

            didValuesChange = false;
            benefitValue = benefit;

            return benefit;
        }
    } else {
        return benefitValue;
    }
}

CommuterBenefit::~CommuterBenefit() = default;

