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


class Go : public Slot
{
private:





public:
	// Constructor
	Go();
	//	Destructor 
	~Go();
	//Copy Constructor
	Go(const Go& GG);



};

