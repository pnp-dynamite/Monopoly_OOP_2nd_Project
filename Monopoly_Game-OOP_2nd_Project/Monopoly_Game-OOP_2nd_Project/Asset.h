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
	string m_city;
	string m_asset_name;
	int m_rent;
	int m_cost;
	int m_owner;

public:
	// Constructor
	Asset(int size, string city, string asset_name);
	//	Destructor 
	~Asset();
	//Copy Constructor
	Asset(const Asset& AA);

	string get_name();
	string get_city();
	string get_asset_name();
	int get_owner();

	bool play(Player* p);

};

