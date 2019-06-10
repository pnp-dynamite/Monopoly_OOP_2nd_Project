#pragma once
using namespace std;

#include <string>
#include "Player.h"
#include "Jail.h"
#include "Go.h"
#include "Chance.h"
#include "Asset.h"
#include "Player.h"
#include "Board.h"

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
	int m_size;
	string m_name;

	// Constructor
	Slot(int slot_num, string& name);

	//	Destructor 
	~Slot();	
	//Copy Constructor
	Slot(const Slot& SS);

	virtual bool play(Player* p) = 0;
	virtual string get_name() const = 0;

public:
	static int slot_counter;
	string get_name();
	int random_number(int low, int high);

};


