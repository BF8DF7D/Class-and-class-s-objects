#include <iostream>
#include <array>

class Date {
private: int day,
	mounth,
	year;

public: bool SetBool();
public: void SetFormat();
public: void PrintInfo();

public: std::array<int, 3> GetInfo();

public: Date() {};
public: ~Date() {};
};