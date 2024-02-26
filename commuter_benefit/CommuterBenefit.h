//
// Created by Jonas Liendl on 23.02.24.
//

#ifndef FIN_CALCULATOR_COMMUTERBENEFIT_H
#define FIN_CALCULATOR_COMMUTERBENEFIT_H

class CommuterBenefit {
public:
    CommuterBenefit(unsigned int workingDays, unsigned int commuteInKm);
    ~CommuterBenefit();
    [[nodiscard]] unsigned int getWorkingDays() const;
    [[nodiscard]] unsigned int getCommuteInKM() const;
    void changeWorkingDays(unsigned int days);
    void changeCommuteInKM(unsigned int km);
    double calculateBenefit();
private:
    unsigned int workingDays;
    unsigned int commuteInKm;
    const double COMMUTER_BENEFIT_BASIC = 0.3;
    const double COMMUTER_BENEFIT_ADVANCED = 0.38;
    bool didValuesChange;
    double benefitValue;
};

#endif //FIN_CALCULATOR_COMMUTERBENEFIT_H
