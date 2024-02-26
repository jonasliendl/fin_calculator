//
// Created by Jonas Liendl on 24.02.24.
//

#ifndef FIN_CALCULATOR_YIELD_H
#define FIN_CALCULATOR_YIELD_H

#include <chrono>

using namespace std;

using namespace std::chrono;

class Yield {
public:
    Yield(float startValue, float endValue, unsigned int startYear, unsigned int endYear);
    Yield(float startValue, float endValue);
    Yield(float startValue, float endValue, unsigned int startYear);
    ~Yield();
    [[nodiscard]] float getStartValue() const;
    [[nodiscard]] float getEndValue() const;
    [[nodiscard]] unsigned int getStartYear() const;
    [[nodiscard]] unsigned int getEndYear() const;
    Yield* changeStartValue(float val);
    Yield* changeEndValue(float val);
    Yield* changeStartYear(unsigned int year);
    Yield* changeEndYear(unsigned int year);
    Yield* calculate();
    [[nodiscard]] double getYieldOverall() const;
    [[nodiscard]] double getYieldPerAnno() const;
private:
    bool didValuesChange;
    float startValue;
    float endValue;
    unsigned int startYear;
    unsigned int endYear;
    double yieldDataOverall;
    double yieldDataPerAnno;
    bool areYearsProvided;
    [[nodiscard]] double calculateYield() const;
    [[nodiscard]] static double calculateYieldPerAnno(double overallYield, unsigned int startYear, unsigned int endYear) ;
    static unsigned int calculateCurrentYear();
};

#endif //FIN_CALCULATOR_YIELD_H
