#pragma once
#include <iostream>

class Date {
private: int day,
	mounth,
	year;

public: bool SetBool();
public: void SetFormat();
public: void PrintInfo();

public: int* GetInfo();

public: Date() {};
public: ~Date() {};
};