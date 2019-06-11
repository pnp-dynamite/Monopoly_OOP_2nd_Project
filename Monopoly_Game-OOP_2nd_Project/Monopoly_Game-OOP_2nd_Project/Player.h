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
	int m_slot_num;
	Board* m_board;
	Asset *asset_arr;
	int m_asset_arr_size;

public:
	// Constructor
	Player(string name, Board* BB, int balance);
	//	Destructor 
	~Player();
	//Copy Constructor
	Player(const Player& PP);

	int get_counter();
	string get_name();

	friend ostream& operator<<(ostream& os, const Player& P);

	bool pay_rent(int amount);
	bool add_asset(Asset* a);
	void set_balance(int balance);
	bool draw_dice();

	// Asset stack
	void pop();
	void push(Asset& assest);
	int get_asset_arr_size();


};
