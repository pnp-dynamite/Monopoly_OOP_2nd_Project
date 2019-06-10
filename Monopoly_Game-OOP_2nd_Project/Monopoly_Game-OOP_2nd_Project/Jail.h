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


class Jail : public Slot
{
private:
	const string m_order;

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

