#pragma once

#include "Chance.h"
using namespace std;

Chance::Chance(int size, string order, int amount): Slot(size)
{
	m_name = "Chance!";
	m_order = order;
	m_amount = amount;
}

Chance::~Chance()
{
}

//Chance::Chance(const Chance& CC)
//{
//	
//}

string Chance::get_name() const
{
	return m_name;
}



bool Chance::play(Player* p)
{
	m_amount > 0 ? cout << "You Won the LOTTORY": cout << "You Have to pay the IRS ";
	cout << m_amount << "$ !";

	p->set_balance(m_amount);

	if (p->get_balance() < 0)
		return false;

	return true;
}