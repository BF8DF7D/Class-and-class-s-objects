#include <iostream>
#include <array>

class Time {
private: int hour,
	minutes;

public: void SetFormat();
public: bool SetBool();
public: void PrintInfo();

public: std::array<int, 2> GetInfo();
	   
public: Time() {};
public: ~Time() {};
};

bool BoolFormatInputTime(Time*);
void SetTimeData(Time*);
void PrintTimeInfo(Time);