#pragma once
#include "Slot.h"

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG


class Asset	: public Slot
{
private:





public:
	// Constructor
	Asset();
	//	Destructor 
	~Asset();
	//Copy Constructor
	Asset(const Asset& AA);



};

