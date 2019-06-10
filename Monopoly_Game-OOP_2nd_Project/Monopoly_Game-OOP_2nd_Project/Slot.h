#pragma once
using namespace std;

#include <string>
#include "Player.h"

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG


class Slot
{
private:


protected:

	// Constructor
	Slot();
	//	Destructor 
	~Slot();	
	//Copy Constructor
	Slot(const Slot& SS);

	virtual bool play(Player* p) = 0;
	virtual string get_name() const = 0;

public:
	string get_name();

};


