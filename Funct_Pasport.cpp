#define _CRT_SECURE_NO_WARNINGS
#include "Pasport.h"
#include <iomanip>

void Pasport::SetFormat(){
	bool False_Input_Value;
	do {
		std::cout << " Паспорт: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <Паспортные данные введены некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Pasport::SetBool() {
	enum Limit_Value {
		Quantity_inpyt_value = 2,
		Minimum_value_for_all = 0,
		Maximum_for_series = 9999,
		Maximum_for_number = 999999,
		Clean_input_stream = '\n'
	};
		bool False_Input_Value = scanf("%d_%d", &this->Series, &this->Number) != Quantity_inpyt_value
		|| (this->Series <= Minimum_value_for_all || this->Series > Maximum_for_series)
		|| (this->Number < Minimum_value_for_all || this->Number > Maximum_for_number)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void Pasport::PrintInfo() {
	std::array<int, 2> pasport = this->GetInfo();
	enum Value_number_in_info_array {
		series = 0,
		number,
	};
	std::cout << std::setfill('0') << std::setw(4) << pasport[series];
	std::cout << " ";
	std::cout << std::setfill('0') << std::setw(6) << pasport[number];
}

std::array<int, 2> Pasport::GetInfo() {
	std::array<int, 2> pasport = { this->Series, this->Number };
	return pasport;
}