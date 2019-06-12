//#pragma once
#include <string>
#include <iostream>
#include "Slot.h"
#include "Player.h"




using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG
//class Player;
//class Slot;
class Go : public Slot
{
protected:
	string m_name;
	string m_order;




public:
	// Constructor
	Go(int size, string order);
	//	Destructor 
	~Go();
	//Copy Constructor
	Go(const Go& GG);
	string get_name() const;
	bool play(Player* p);

};

