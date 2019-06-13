#pragma once
#include "Slot.h"

using namespace std;


//-----------------------------------Slot-----------------------------------------//
// Constructor.
Slot::Slot(int slot_num)
{
	m_size = slot_num;
}
// Destructor.
Slot::~Slot()
{
}
//--------------------------------------Go------------------------------------//

// Constructor.
Go::Go(int size, string order) : Slot(size)
{
	m_name = "Go!";
	m_order = "god speed!";
}
// Destructor.
Go::~Go()
{
}

string Go::get_name() const
{
	return m_name;
}

bool Go::play(Player* p)
{
	cout << m_order << endl;
	return true;
}

//--------------------------------------Asset------------------------------------//

// Constructor
Asset::Asset(int size, string city, string asset_name) : Slot(size)
{
	m_city = city;
	m_asset_name = asset_name;
	m_owner = -1;

	m_rent = random_number(min_rent, max_rent);
	m_cost = random_number(min_cost, max_cost);
}
// Destructor.
Asset::~Asset()
{
}
// C.C
Asset::Asset(const Asset& AA) : Slot(AA.m_size)
{
	m_city = AA.m_city;
	m_asset_name = AA.m_asset_name;
	m_rent = AA.m_rent;
	m_cost = AA.m_cost;
	m_owner = AA.m_owner;
}

string Asset::get_name() const
{
	return m_city + ',' + m_asset_name;
}

string Asset::get_city() const
{
	return m_city;
}

string Asset::get_asset_name() const
{
	return m_asset_name;
}

int Asset::get_owner() const
{
	return m_owner;
}

int Asset::get_cost() const
{
	return m_cost;
}

int Asset::get_rent() const
{
	return m_rent;
}

void Asset::set_owner(int player_num)
{
	m_owner = player_num;
}
// Confirm purchase, updating balance and asset list.
bool Asset::play(Player* p)
{
	if (get_owner() == -1)
	{
		cout << "Do you want to buy " << m_asset_name << " in "
			<< m_city << " for " << m_cost << " ? (1) To buy, (any key) Continue without buying." << endl;

		int in;
		cin >> in;
		if (in == 1)
		{
			p->add_asset(this);
		}

		return true;
	}
	else if (get_owner() != p->get_player_num())
	{
		if (!p->pay_rent(m_rent))
			return false;
	}
	else
		cout << get_name() << " is Your asset" << endl;
	return true;
}

//--------------------------------------Chance------------------------------------//

// Constructor.
Chance::Chance(int size, string order, int amount) : Slot(size)
{
	m_name = "Chance!";
	m_order = order;
	m_amount = amount;
}
// Destructor.
Chance::~Chance()
{
}

string Chance::get_name() const
{
	return m_name;
}

// Printing orders of the slot and updating the balance
bool Chance::play(Player* p)
{
	cout << m_order << " " << m_amount;

	p->set_balance(m_amount);

	return true;
}

//--------------------------------------Jail------------------------------------//
// Constructor.
Jail::Jail(int size, string order) : Slot(size)
{
	m_name = "Jail!";
	m_order = "You are in Jail! wait 1 turn";
}
// Destructor.
Jail::~Jail()
{
}

string Jail::get_name() const
{
	return m_name;
}

// printing orders of the slot only and setting flags as requested
bool Jail::play(Player* p)
{
	cout << m_order << endl;
	p->set_in_jail();

	return true;
}