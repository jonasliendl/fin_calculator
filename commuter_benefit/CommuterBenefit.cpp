//
// Created by Jonas Liendl on 23.02.24.
//
#include "CommuterBenefit.h"

CommuterBenefit::CommuterBenefit(unsigned int workingDays, unsigned int commuteInKm) {
    this->workingDays = workingDays;
    this->commuteInKm = commuteInKm;
    this->didValuesChange = true;
    this->benefitValue = 0.0;
}

unsigned int CommuterBenefit::getWorkingDays() const {
    return this->workingDays;
}

unsigned int CommuterBenefit::getCommuteInKM() const {
    return this->commuteInKm;
}

CommuterBenefit *CommuterBenefit::changeWorkingDays(unsigned int days) {
    this->workingDays = days;
    this->didValuesChange = true;
    return this;
}

CommuterBenefit *CommuterBenefit::changeCommuteInKM(unsigned int km) {
    this->commuteInKm = km;
    this->didValuesChange = true;
    return this;
}

float CommuterBenefit::calculateBenefit() {
    if (this->didValuesChange) {
        if (this->commuteInKm >= 21) {
            float benefitForFirstTwenty = (float)this->workingDays * (float)20.0 + (float)this->commuterBenefitPerKM;
            float benefitFromTwentyFirst = (float)this->workingDays * (float)(this->commuteInKm - 20) * this->commuterBenefitAdvanced;
            this->didValuesChange = false;
            return benefitForFirstTwenty + benefitFromTwentyFirst;
        } else {
            float benefit = (float)this->workingDays * (float)this->commuteInKm * this->commuterBenefitPerKM;
            this->didValuesChange = false;
            return benefit;
        }
    } else {
        return this->benefitValue;
    }
}

CommuterBenefit::~CommuterBenefit() = default;

