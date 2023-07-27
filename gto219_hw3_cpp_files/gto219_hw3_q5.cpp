// gto219_hw3_q5.cpp

#include <iostream>

int main()
{
    double userWeightLbs, userHeightInch;
    double userWeightKgs, userHeightMeter, BMI;
    const double LbsToKgs = 0.453592;
    const double InchToMeter = 0.0254;
    const double UnderWeight = 18.5;
    const double Normal = 25;
    const double OverWeight = 30;
    

    std::cout << "Please enter weight (in pounds): ";
    std::cin >> userWeightLbs;
    std::cout << "Please enter height (in inches): ";
    std::cin >> userHeightInch;
    
    userWeightKgs = userWeightLbs * LbsToKgs;
    userHeightMeter = userHeightInch * InchToMeter;

    BMI = userWeightKgs / (userHeightMeter * userHeightMeter);
    std::cout << BMI << std::endl;
    if (BMI < UnderWeight) {
        std::cout << "The weight status is: Underweight";
    }
    else if (BMI >= UnderWeight && BMI < Normal) {
        std::cout << "The weight status is: Normal";
    }
    else if (BMI >= Normal && BMI < OverWeight) {
        std::cout << "The weight status is: Overweight";
    }
    else {
        std::cout << "The weight status is: Obese";
    }

    return 0;
}
