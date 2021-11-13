#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iomanip>

void Date::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " Дата: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <Дата введена некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Date::SetBool(){
	enum Limit_Value {
		Quantity_input_value = 3,
		Minimum_for_days_and_months = 0,
		Minimum_value_for_years = 999,
		Maximum_day = 31,
		Maximum_mounth = 12,
		Maximum_years = 9999,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%d.%d.%d", &this->day, &this->mounth, &this->year) != Quantity_input_value
		|| (this->day <= Minimum_for_days_and_months || this->day > Maximum_day)
		|| (this->mounth <= Minimum_for_days_and_months || this->mounth > Maximum_mounth)
		|| (this->year <= Minimum_value_for_years || this->year > Maximum_years)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void Date::PrintInfo() {
	int* date_array = this->GetInfo();
	enum Value_number_of_info_array {
		day = 0,
		mounth,
		year
	};

	std::cout << std::setfill('0') << std::setw(2) << date_array[day] << ".";
	std::cout << std::setfill('0') << std::setw(2) << date_array[mounth] << ".";
	std::cout << std::setw(4) << date_array[year];
	std::cout.fill(' ');
}

int* Date::GetInfo() {
	int date_array[] = { this->day, this->mounth, this->year };
	return date_array;
}