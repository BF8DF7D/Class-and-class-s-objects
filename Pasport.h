#include <iostream>
#include <array>

class Pasport {
private: int Series,
	Number;

public: void SetFormat();
public: bool SetBool();
public: void PrintInfo();

public: std::array<int, 2> GetInfo();

public:	Pasport() {};
public:	~Pasport() {};
};