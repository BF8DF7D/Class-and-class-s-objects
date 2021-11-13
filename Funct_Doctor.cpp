#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

void Doctor::SetFormat() {

	printf(" <���� ���������� � �������>\n");
	this->Fio.SetFormat();

	std::cout << " ���������: ";
	std::getline(std::cin, this->dolgnost);
	
	std::cout << " <���� ��������>" << std::endl;
}

void Doctor::PrintInfo() {
	std::array<std::string, 4> fio = this->GetFIO().GetInfo();
	enum Value_number_in_info_array {
		full_name = 3
	};
	&this->GetDolgnost();
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(45) << fio[full_name];
	std::cout << " | ";
	std::cout << std::setw(20) << this->GetDolgnost() << " |" << std::endl;
}

FIO Doctor::GetFIO() {
	return this->Fio;
}

std::string Doctor::GetDolgnost() {
	return this->dolgnost;
}