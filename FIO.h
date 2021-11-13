#include <iostream>

class FIO {
private: std::string Last_Name,
	First_Name,
	Patronymic,
	Full_Name;

public: bool SetBool();
public: void SetFormat();

public: std::string* GetInfo();

public: FIO() {};
public: ~FIO() {};
};
