#pragma once
using namespace std;

#include "Player.h"

#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

class Player;
class Slot
{

protected:
	int m_size;
	
public:
	// Constructor
	Slot(int slot_num);

	//	Destructor 
	virtual ~Slot();
	//Copy Constructor
	Slot(const Slot& SS);
	 
	virtual bool play(Player* p) = 0;
	virtual string get_name() const = 0;


	static int slot_counter;
	int random_number(int low, int high);

};


