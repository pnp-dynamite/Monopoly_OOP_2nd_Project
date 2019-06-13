#pragma once
using namespace std;

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

// Project Definitions by demand
#define GoMoney 350

class Slot;
class Board;
class Asset;
class Player

{
protected:
	int m_player_num;
	string m_name;
	int m_balance;
	bool m_in_jail;
	int m_slot_num; // The index of the slot on board							
	Asset* asset_arr;
	int m_asset_arr_size;
	Board* m_board;


public:
	static int player_counter;

	// Constructor
	Player(string name, Board& BB, int balance);

	//	Destructor 
	~Player();

	bool pay_rent(int amount);
	bool add_asset(Asset* a);
	bool draw_dice();

	// Asset stack
	void pop();
	void push(Asset* asset);

	// Getters
	int get_asset_arr_size()const;
	int get_player_num()const;
	int get_balance()const;
	static int Player::get_counter();
	string get_name()const;


	// Setters
	void set_in_jail();
	void set_balance(int balance);

	void player_printer() const;
	friend ostream& operator<<(ostream& os, const Player& P);
};

int random_number(int low, int high);
