#pragma once
#include "Slot.h"
#include <string>

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG


class Chance : public Slot
{
private:



public:
	// Constructor
	Chance();
	//	Destructor 
	~Chance();
	//Copy Constructor
	Chance(const Chance& CC);



};

