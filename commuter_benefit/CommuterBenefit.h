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
    CommuterBenefit* changeWorkingDays(unsigned int days);
    CommuterBenefit* changeCommuteInKM(unsigned int km);
    float calculateBenefit();
private:
    unsigned int workingDays;
    unsigned int commuteInKm;
    const float commuterBenefitPerKM = 0.3;
    const float commuterBenefitAdvanced = 0.38;
    bool didValuesChange;
    float benefitValue;
};

#endif //FIN_CALCULATOR_COMMUTERBENEFIT_H
