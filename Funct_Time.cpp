#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iomanip>

void Time::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " �����: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <����� ������� �����������>" << std::endl;
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
	
	bool False_Input_Value = scanf("%d.%d", &this->time[hour], &this->time[minutes]) != Quantity_input_value
		|| (this->time[hour] < Minimum_value_for_all || this->time[hour] > Maximum_hour)
		|| (this->time[minutes] < Minimum_value_for_all || this->time[minutes] > Maximum_minutes)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

std::array<int, 2> Time::GetInfo() {
	return this->time;
}

void Time::PrintInfo() {
	std::array<int, 2> time = this->GetInfo();

	std::cout << std::setfill('0') << std::setw(2) << time[hour] << ".";
	std::cout << std::setfill('0') << std::setw(2) << time[minutes];
	std::cout.fill(' ');
}