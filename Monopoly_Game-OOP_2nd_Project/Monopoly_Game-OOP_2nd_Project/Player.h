#pragma once
#include "Slot.h"
#include <string>

using namespace std;
#define GoMoney 350

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

class Player
{
protected:
	static int player_counter;
	int m_player_num;
	string m_name;
	int m_balance;
	bool m_in_jail;
	int m_slot_num; //index on board
	Board* m_board;
	Asset* asset_arr;
	int m_asset_arr_size;

public:
	// Constructor
	Player(const string name, Board BB, int balance);
	//	Destructor 
	~Player();
	//Copy Constructor
	Player(const Player& PP);



	friend ostream& operator<<(ostream& os, const Player& P);

	bool pay_rent(int amount);
	bool add_asset(Asset* a);


	// Asset stack
	void pop(); // + advance + set balance
	void push(Asset* asset);

	int get_asset_arr_size()const;
	int get_player_num()const;
	int get_balance()const;
	int get_counter()const;
	string get_name()const;

	void set_in_jail();
	void set_balance(int balance);

	int Player::random_number(int low, int high);
	bool draw_dice();


};
