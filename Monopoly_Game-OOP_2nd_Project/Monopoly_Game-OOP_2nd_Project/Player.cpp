#pragma once

#include "Player.h"
#include "Board.h"
#include "Slot.h"
#include "Asset.h"

#define GoMoney 350

using namespace std;

//int Player::player_counter = 1;
//class Board;

Player::Player(const string name, Board* BB, int balance) : m_player_num(player_counter++)
{
	m_name = name;
	m_board = BB; // μαγεχ φιξεγ
	m_balance = balance;
	m_in_jail = false;
	m_slot_num = 1;
	asset_arr = nullptr;
	m_asset_arr_size = 0;
}

Player::~Player()
{
	if (m_asset_arr_size != 0)
		delete[] asset_arr;
}

Player::Player(const Player& PP)
{
}



int Player::get_player_num()const
{
	return m_player_num;
}

int Player::get_counter()
{
	return player_counter;
}

string Player::get_name()const
{
	return m_name;
}

int Player::get_asset_arr_size() const
{
	return m_asset_arr_size;
}
int Player::get_balance()const
{
	return m_balance;
}

void Player::set_in_jail()
{
	m_in_jail = true;
}
void Player::set_balance(int balance)
{
	m_balance += balance;
}


bool Player::pay_rent(int amount)
{
	while (amount > m_balance)
	{
		if (m_asset_arr_size == 0)
			return false;
		else
			pop();
	}

	set_balance(amount);
	return true;
}

bool Player::add_asset(Asset* a)
{
	if (a->get_cost() > m_balance)
		return false;
	else
	{
		push(a);
		return true;
	}
}

void Player::pop() 
{
	m_balance += asset_arr[0].get_cost();
	Asset *temp = new Asset[m_asset_arr_size - 1];
	for (int i = 0; i < m_asset_arr_size-1; i++)
		temp[i] = asset_arr[i + 1];
	
	delete[] asset_arr;
	asset_arr = temp;
	m_asset_arr_size -= 1;
}

void Player::push(Asset* asset)
{
	m_balance -= asset->get_cost();
	Asset *temp = new Asset[m_asset_arr_size + 1];
	for (int i = 0; i < m_asset_arr_size; i++)
		temp[i] = asset_arr[i];
	
	temp[m_asset_arr_size] = *asset;

	delete[] asset_arr;
	asset_arr = temp;
	m_asset_arr_size += 1;
}


bool Player::draw_dice()
{
	if (m_in_jail)
	{
		cout << "You are in Jail!" << endl;
		m_in_jail = false;
		return true;
	}
	int dice = random_number(1, 6);

	m_slot_num = ((m_slot_num + dice) % 18) - 1;
	if ((m_slot_num + dice) / 18)
	{
		cout << "Bon Voyage" << endl;
		set_balance(GoMoney);
	}
	
	return m_board->get_slot(m_slot_num)->play(this);
}


// Generate random number between the LOW number and the HIGH number (including)
int Player::random_number(int low, int high)
{
	int num;
	num = rand() % (high - low + 1) + low;
	return num;
}