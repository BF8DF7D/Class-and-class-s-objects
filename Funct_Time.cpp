#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iomanip>

void Time::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " Время: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <Время введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Time::SetBool() {
	
	enum Limit_Value {
		Quantity_input_value = 2,
		Minimum_value_for_all = 0,
		Maximum_hour = 23,
		Maximum_minutes = 59,
		Clean_input_stream = '\n'
	};
	
	bool False_Input_Value = scanf("%d.%d", &this->hour, &this->minutes) != Quantity_input_value
		|| (this->hour < Minimum_value_for_all || this->hour > Maximum_hour)
		|| (this->minutes < Minimum_value_for_all || this->minutes > Maximum_minutes)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

std::array<int, 2> Time::GetInfo() {
	std::array<int, 2> time = { this->hour, this->minutes };
	return time;
}

void Time::PrintInfo() {
	std::array<int, 2> time = this->GetInfo();
	enum Value_number_in_info_array {
		hour = 0,
		minutes
	};

	std::cout << std::setfill('0') << std::setw(2) << time[hour] << ".";
	std::cout << std::setfill('0') << std::setw(2) << time[minutes];
	std::cout.fill(' ');
}