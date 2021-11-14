#include <iostream>
#include <array>

class Disease{
private: std::string Name_Disease,
	Disease_Symptoms[50];

public: void SetDisease();
public: void PrintInfo();

public: std::string GetName();
public: std::array<std::string, 50> GetSymptoms();

public: Disease() {};
public: ~Disease() {};
};