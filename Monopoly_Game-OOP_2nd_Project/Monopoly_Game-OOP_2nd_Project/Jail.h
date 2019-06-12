#pragma once
using namespace std;

#include "Slot.h"
//#include "Player.h"


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

#define GoMoney 350

class Jail : public Slot
{
protected:
	string m_name;
	string m_order;

public:
	// Constructor
	Jail(int size, string order);
	//	Destructor 
	~Jail();
	//Copy Constructor
	Jail(const Jail& JJ);
	string get_name() const;
	bool play(Player* p);



};

