// gto219_hw3_q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{
    double itemPrice1, itemPrice2, taxRate, totalBasePrice, discountedItemPrice, discountedPrice, finalPrice;
    double clubDiscountDif, decimalTaxRate, totalTaxRate;
    char clubCard;
    int clubCardInt;
    const double clubDiscount = .10;
    const double decimalTaxConvert = 0.01;
    
    clubDiscountDif = 1 - clubDiscount;

    std::cout << "Enter price of the first item: ";
    std::cin >> itemPrice1;
    std::cout << "Enter price of the second item: ";
    std::cin >> itemPrice2;
    std::cout << "Does customer have a club card? (Y/N): ";
    std::cin >> clubCard;
    std::cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    std::cin >> taxRate;
    
    decimalTaxRate = taxRate * decimalTaxConvert;
    totalTaxRate = 1 + decimalTaxRate;

    if (clubCard == 'Y' || clubCard == 'N'){
        clubCardInt = int(clubCard) + 32; //using ASCII the lowercase of its uppercase equivalent is +32 digits away
        clubCard = char(clubCardInt); //convert the lowercase ASCII back to a char
    }

    
    totalBasePrice = itemPrice1 + itemPrice2;
    if (itemPrice1 < itemPrice2) {
        discountedItemPrice = itemPrice1 / 2;
        discountedPrice = discountedItemPrice + itemPrice2;
    }
    else {
        discountedItemPrice = itemPrice2 / 2;
        discountedPrice = discountedItemPrice + itemPrice1;
    }
    if (clubCard == 'y') {
        discountedPrice *= clubDiscountDif;
    }

    finalPrice = discountedPrice * totalTaxRate;
    std::cout.precision(1);
    std::cout << "Base price: " << std::fixed << totalBasePrice << std::endl;
    std::cout << "Priec after discounts: " << discountedPrice << std::endl;
    std::cout.precision(5);
    std::cout << "Total price: " << std::fixed << finalPrice << std::endl;
    

    
    return 0;
}


