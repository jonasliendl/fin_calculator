//
// Created by Jonas Liendl on 24.02.24.
//
#include "Yield.h"
#include <iostream>
#include <cmath>

Yield::Yield(float startValue, float endValue, unsigned int startYear, unsigned int endYear) {
    this->didValuesChange = true;
    this->startYear = startYear;
    this->endYear = endYear;
    this->startValue = startValue;
    this->endValue = endValue;
    this->yieldDataOverall = 0.0;
    this->yieldDataPerAnno = 0.0;
    this->areYearsProvided = true;
}

float Yield::getStartValue() const {
    return this->startValue;
}

float Yield::getEndValue() const {
    return this->endValue;
}

unsigned int Yield::getStartYear() const {
    return this->startYear;
}

unsigned int Yield::getEndYear() const {
    return this->endYear;
}

Yield *Yield::changeStartValue(float val) {
    this->startValue = val;
    this->didValuesChange = true;
    return this;
}

Yield *Yield::changeEndValue(float val) {
    this->endValue = val;
    this->didValuesChange = true;
    return this;
}

Yield *Yield::changeStartYear(unsigned int year) {
    this->startYear = year;
    this->didValuesChange = true;
    return this;
}

Yield *Yield::changeEndYear(unsigned int year) {
    this->endYear = year;
    this->didValuesChange = true;
    return this;
}

Yield *Yield::calculate() {
     if (this->didValuesChange) {
         if (this->endValue == 0.0) {
             this->didValuesChange = false;
             this->yieldDataOverall = -1.0;
             this->yieldDataPerAnno = -1.0;
             return this;
         }

         if (this->startValue == 0.0) {
             this->didValuesChange = false;
             this->yieldDataOverall = NAN;
             this->yieldDataPerAnno = NAN;
             return this;
         }

         double yield = this->calculateYield();
         this->yieldDataPerAnno = Yield::calculateYieldPerAnno(yield, this->startYear, this->endYear);
         this->yieldDataOverall = yield;
         this->didValuesChange = false;
         return this;
     } else {
         return this;
     }
}

Yield::Yield(float startValue, float endValue) {
    this->didValuesChange = true;
    this->areYearsProvided = false;
    this->startValue = startValue;
    this->endValue = endValue;
    unsigned int currentYear = Yield::calculateCurrentYear();
    this->startYear = currentYear;
    this->endYear = currentYear;
    this->yieldDataOverall = 0.0;
    this->yieldDataPerAnno = 0.0;
}

Yield::Yield(float startValue, float endValue, unsigned int startYear) {
    this->didValuesChange = true;
    this->areYearsProvided = true;
    this->startValue = startValue;
    this->endValue = endValue;
    this->startYear = startYear;
    this->endYear = Yield::calculateCurrentYear();
    this->yieldDataOverall = 0.0;
    this->yieldDataPerAnno = 0.0;
}

double Yield::getYieldOverall() const {
    return this->yieldDataOverall;
}

double Yield::getYieldPerAnno() const {
    return this->yieldDataPerAnno;
}

double Yield::calculateYield() const {
    return this->endValue / this->startValue - 1.0;
}

double Yield::calculateYieldPerAnno(double yieldOverall, unsigned int startYear, unsigned int endYear) {
    if (startYear == endYear) {
        return yieldOverall;
    }
    int passedYears = (int) (endYear - startYear);
    double performancePA = pow(1.0 + yieldOverall, 1.0 / passedYears);
    return performancePA - 1.0;
}

unsigned int Yield::calculateCurrentYear() {
    auto now = std::chrono::system_clock::now();
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&timeNow);
    return localTime->tm_year + 1900;
}

Yield::~Yield() = default;
