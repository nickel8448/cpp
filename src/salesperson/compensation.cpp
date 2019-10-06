// compensation.cpp: Rahul Wadhwani
//
// Shoes cost around $225
// Straight salary of $600 per week;
// A salary of $7.00 per hour plus a 10% commission on sales;
// No salary, but 20% commissions and $20 for each pair of shoes sold

#include <iostream>
#include "compensation.h"
using namespace std;

// constants which are used in the program
#define kPriceUnit 225		// average price of a pair of shoes
#define kWeeklyWage 600		// currently weekly wage - method 1
#define kHourlySalary 7		// hourly salary - method 2
#define kHoursPerWeek 40	// Numbers of hours worked - method 2
#define kCommission2 0.10	// Commission - method 2
#define kCommission3 0.2	// Commission - method 3
#define kBonusPerUnit 20	// bonus - method 3

// Function to get the weekly sales of units
int getInput() {
	int units;
	std::cout << "Enter the number of units sold per week: ";
	if (!(std::cin >> units)) {
		std::cout << "Numbers only" << std::endl;
		return 0;
	} else {
		return units;
	}
}

double calcMethod1() {
	return kWeeklyWage;
}
double calcMethod2(int sales) {
	double perHour, totalPay, commission;

	perHour = kHourlySalary * kHoursPerWeek;
	commission = (sales * kPriceUnit) * kCommission2;
	totalPay = perHour + commission;
	// std::cout << "Method 2: " << totalPay << std::endl;	
	return totalPay;
}

double calcMethod3(int sales) {
	double totalPay, commission, commission2;

	commission = (sales * kPriceUnit) * kCommission3;
	commission2 = sales * kBonusPerUnit;
	totalPay = commission + commission2;
	// std::cout << "Method 3: " << totalPay << std::endl;
	return totalPay;
}

// int main() {
// 	int weeklySales;

// 	weeklySales = getInput();
// 	if (weeklySales == 0)
// 		return 0;
// 	calcMethod1();
// 	calcMethod2(weeklySales);
// 	calcMethod3(weeklySales);	
//}