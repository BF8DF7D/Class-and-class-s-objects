#include <iostream>
#include <array>

class FIO {
private: std::string Last_Name,
	First_Name,
	Patronymic,
	Full_Name;

public: bool SetBool();
public: void SetFormat();

public: std::array<std::string, 4> GetInfo();

public: FIO() {};
public: ~FIO() {};
};
