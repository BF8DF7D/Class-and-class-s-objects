#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>
#include <iomanip>

//Создание структуры "Заболевание"
void Disease::SetDisease() {

	std::cout << " <Ввод информации о заболевании>" << std::endl;
	std::cout << " Наименование: ";
	std::getline(std::cin, this->Name_Disease);
	std::cin.clear();
	
	std::cout << " Симптомы.\n Вводите каждый новый симптом с новой строки.\n Для прекращения операции нажмите Enter" << std::endl;
	
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

//Печать структуры "Заболевание"
void Disease::PrintInfo() {
	std::cout << " Наименование: " << this->GetName() << std::endl;
	std::cout << " Симптомы: " << std::endl;
	
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