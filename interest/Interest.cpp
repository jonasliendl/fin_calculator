//
// Created by Jonas Liendl on 18.02.24.
//
#include "Interest.h"
#include <iostream>

Interest::Interest(unsigned int startCapital, unsigned int monthlySaving, unsigned int years, float interestRate, PayInterval payInterval) {
    this->startCapital = startCapital;
    this->monthlySaving = monthlySaving;
    this->years = years;
    this->interestRate = interestRate;
    this->payInterval = payInterval;

    this->didValuesChange = true;
}

unsigned int Interest::getStartCapital() const {
    return this->startCapital;
}

unsigned int Interest::getMonthlySaving() const {
    return this->monthlySaving;
}

unsigned int Interest::getYears() const {
    return this->years;
}

float Interest::getInterestRate() const {
    return this->interestRate;
}

PayInterval Interest::getPayInterval() {
    return this->payInterval;
}

Interest* Interest::changeStartCapital(unsigned int capital) {
    this->startCapital = capital;
    this->didValuesChange = true;
    return this;
}

Interest *Interest::changeMonthlySaving(unsigned int saving) {
    this->monthlySaving = saving;
    this->didValuesChange = true;
    return this;
}

Interest *Interest::changeYears(unsigned int savingYears) {
    this->years = savingYears;
    this->didValuesChange = true;
    return this;
}

Interest *Interest::changeInterestRate(float rate) {
    this->interestRate = rate;
    this->didValuesChange = true;
    return this;
}

Interest *Interest::changePayInterval(PayInterval interval) {
    this->payInterval = interval;
    this->didValuesChange = true;
    return this;
}

InterestMap Interest::calculate() {
    if (this->didValuesChange) {
        InterestMap interestMap{};

        for (int i = 0; i < this->years; i++) {
            InterestItem previousItem{};
            if (i == 0) {
                previousItem = {this->startCapital, 0};
            } else {
                previousItem = interestMap[i - 1];
            }
            InterestItem item = this->calculateForOneYear(previousItem);
            interestMap[i] = item;
        }

        return interestMap;
    } else {
        return this->data;
    }
}

InterestItem Interest::calculateForOneYear(InterestItem previousItem) {
    int ITERATIONS = 1;

    unsigned int savingPerMonth = this->monthlySaving;

    switch(this->payInterval) {
        case MONTHLY:
            ITERATIONS = 12;
            break;
        case QUARTERLY:
            ITERATIONS = 4;
            savingPerMonth = this->monthlySaving / 6;
            break;
        case YEARLY:
            ITERATIONS = 1;
            savingPerMonth = this->monthlySaving / 12;
            break;
    }

    unsigned int currentCapital = previousItem.deposit + previousItem.interestReceived;
    for (int i = 0; i < ITERATIONS; i++) {
        currentCapital = this->calculateOneUnit(currentCapital + savingPerMonth);
    }
    const unsigned int gainedCapital = currentCapital - previousItem.deposit - (this->monthlySaving * 12);
    const unsigned int depositCapital = previousItem.deposit + (12* this->monthlySaving);
    return {depositCapital, gainedCapital};
}

unsigned int Interest::calculateOneUnit(unsigned int currentCapital) const {
    float calculatedVal = ((float)currentCapital * (this->interestRate/100)) / 12;
    unsigned int rndVal = (unsigned int)roundf(calculatedVal);
    unsigned int finalCapital = rndVal + currentCapital;
    return finalCapital;
}

Interest::~Interest() = default;
