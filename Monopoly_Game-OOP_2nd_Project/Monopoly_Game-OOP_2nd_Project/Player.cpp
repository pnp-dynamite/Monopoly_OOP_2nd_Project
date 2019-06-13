#pragma once

#include "Player.h"
#include "Board.h"
#include "Slot.h"


using namespace std;

// Static players counter init.
int Player::player_counter = 0;

// Constructor 
Player::Player(string name, Board& BB, int balance) : m_player_num(++player_counter), m_name(name)
{
	m_board = &BB;
	m_balance = balance;
	m_in_jail = false;
	m_slot_num = 0;
	asset_arr = nullptr;
	m_asset_arr_size = 0;
}
// Destructor 
Player::~Player()
{
	delete[] asset_arr;
}

// Printing the status of the player (balance and assent list) at the end od his turn.
void Player::player_printer() const
{
	cout << endl << m_name << " Balance: " << m_balance << endl << " Assets: ";
	if (!m_asset_arr_size)
		cout << " none";
	else
	{
		for (int i = 0; i < m_asset_arr_size; i++)
		{
			cout << asset_arr[i].get_city() << " , " << asset_arr[i].get_asset_name() << " | ";
		}
	}
	cout << endl;
}


ostream& operator<<(ostream& os, const Player& P)
{
	P.player_printer();
	return os;
}

int Player::get_player_num() const
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

// Updating the Jail flag of the specific player.
void Player::set_in_jail()
{
	m_in_jail = true;
}

// Adding the amount to the player's balance.
void Player::set_balance(int balance)
{
	m_balance += balance;
}

// When steping on another's player Asset, reducing the specific rent from balance of the player.
bool Player::pay_rent(int amount)
{
	cout << "This is a private Asset! You have to pay: " << amount << " $" << endl;
	while (amount > m_balance)
	{
		cout << "You don't have enough money! " << endl;
		if (m_asset_arr_size == 0)
		{
			cout << "You dont have any assets, GAME OVER!" << endl;
			return false;
		}
		else
		{
			cout << asset_arr[0].get_name() << " has been sold for " << asset_arr[0].get_cost() << " $" << endl;
			pop();
		}
	}
	set_balance(-amount);
	return true;
}

// Adding an Asset to the players Asset's stack
bool Player::add_asset(Asset* a)
{
	if (a->get_cost() > m_balance)
	{
		cout << "Not enought money!" << endl;
		return false;
	}
	else
	{
		a->set_owner(m_player_num);
		push(a);
		cout << "Purchase confirmed!" << endl;
		return true;
	}
}

// Poping the first Asset that purchased as requested.
void Player::pop()
{
	m_balance += asset_arr[0].get_cost();
	asset_arr[0].set_owner(-1);
	Asset *temp = new Asset[m_asset_arr_size - 1];

	for (int i = 0; i < m_asset_arr_size - 1; i++)
		temp[i] = asset_arr[i + 1];

	delete[] asset_arr;
	asset_arr = temp;
	m_asset_arr_size--;
}


// Adding an Assent to the players assets stack.
void Player::push(Asset* asset)
{
	m_balance -= asset->get_cost();
	Asset *temp = new Asset[m_asset_arr_size + 1];
	for (int i = 0; i < m_asset_arr_size; i++)
		temp[i] = asset_arr[i];

	temp[m_asset_arr_size] = *asset;

	delete[] asset_arr;
	asset_arr = temp;
	m_asset_arr_size++;
}

// Checking if the player in jail (if yes updating the correct status for next turn), 
//if not throwing a dice and moving to the slot, and playing by the specific polymorphistic slot.
bool Player::draw_dice()
{
	if (m_in_jail)
	{
		cout << "You are in Jail!" << endl;
		m_in_jail = false;
		return true;
	}
	int dice = random_number(1, 6);
	cout << "You move " << dice << " steps " << endl;
	(m_slot_num + dice) >= 18 ? cout << "Bon Voyage" << endl, set_balance(GoMoney) : false;
	m_slot_num = ((m_slot_num + dice) % 18);
	return m_board->get_slot(m_slot_num)->play(this);
}


// Generate random number between the LOW number and the HIGH number (including)
int random_number(int low, int high)
{
	int num;
	num = rand() % (high - low + 1) + low;
	return num;
}