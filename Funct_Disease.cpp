#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>
#include <iomanip>

//�������� ��������� "�����������"
void Disease::SetDisease() {

	std::cout << " <���� ���������� � �����������>" << std::endl;
	std::cout << " ������������: ";
	std::getline(std::cin, this->Name_Disease);
	std::cin.clear();
	
	std::cout << " ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� Enter" << std::endl;
	
	for (std::string& symptom : this->Disease_Symptoms) {
		std::cout << " : ";
		std::getline(std::cin, symptom);
		std::cin.clear();
		if (symptom.empty())
			break;
	}
}

std::string Disease::GetName() {
	return this->Name_Disease;
}

std::array<std::string, 50> Disease::GetSymptoms() {
	std::array<std::string, 50> Disease_Symptoms;
	int Symptom_number = 0;
	for (std::string symptom : this->Disease_Symptoms) {
		Disease_Symptoms[Symptom_number++] = symptom;
		if (symptom.empty()) {
			break;
		}	
	}
	return Disease_Symptoms;
}

//������ ��������� "�����������"
void Disease::PrintInfo() {
	std::cout << " ������������: " << this->GetName() << std::endl;
	std::cout << " ��������: " << std::endl;
	
	int Input_value_number = 0;
	std::string Empty_value_of_symptom = "";
	std::array<std::string, 50> Disease_Symptoms = this->GetSymptoms();
	for (std::string symptom : Disease_Symptoms) {
		if (symptom == Empty_value_of_symptom)
			break;
		std::cout << " [" << std::setfill('0') << std::setw(2) << ++Input_value_number << "] ";
		std::cout << symptom << std::endl;
	}
	std::cout.fill(' ');
}