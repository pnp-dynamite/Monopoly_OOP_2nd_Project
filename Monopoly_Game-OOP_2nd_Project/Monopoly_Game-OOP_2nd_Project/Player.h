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

class Player
{
private:
	int m_num;
	string m_name;
	string m_balance;
	bool m_in_jail;
	int m_slot_inx;
	Board* m_board;
	int *asset_arr;
	int m_asset_arr_size;

public:
	// Constructor
	Player(string name, Board* BB, int balance);
	//	Destructor 
	~Player();
	//Copy Constructor
	Player(const Player& PP);

	int draw_dice();
	int get_counter();
	string get_name();
	friend ostream& operator<<(ostream& os, const Player& P);

};
