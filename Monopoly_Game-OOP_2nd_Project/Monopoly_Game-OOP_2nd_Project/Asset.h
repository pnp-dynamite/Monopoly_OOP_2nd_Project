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

class Player;
class Asset	: public Slot
{
protected:
	string m_city;
	string m_asset_name;
	int m_rent;
	int m_cost;
	int m_owner;

public:
	// Constructor
	Asset(int size = 0, string city = "", string asset_name= "");
	//	Destructor 
	~Asset();
	//Copy Constructor
	Asset(const Asset& AA);

	string get_name() const;
	string get_city() const;
	string get_asset_name() const;
	int get_owner() const;
	int get_cost() const;
	int get_rent() const;


	bool play(Player* p);
	friend ostream& operator<<(ostream& os, const Asset& P);

};

