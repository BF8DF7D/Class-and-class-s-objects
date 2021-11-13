#define _CRT_SECURE_NO_WARNINGS
#include "FIO.h"
#include <string>
#include <sstream>
#include <iomanip>

void FIO::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool FIO::SetBool() {
	std::getline(std::cin, this->Full_Name);
	std::cin.clear();
	std::stringstream Name_elements_stream(this->Full_Name);
	std::string *name_elements[] = { &this->Last_Name, &this->First_Name, &this->Patronymic };

	bool False_Input_Value;
	for (std::string* element : name_elements) {
		if (!Name_elements_stream.eof()) {
			Name_elements_stream >> *element;
		}
		else {
			break;
		}
	}
	bool False_Input_Value = this->Patronymic.empty() || Name_elements_stream.eof();

	return False_Input_Value;
}

std::array<std::string, 4> FIO::GetInfo() {
	std::array<std::string, 4> name = { this->Last_Name, this->First_Name, this->Patronymic, this->Full_Name };
	return name;
}