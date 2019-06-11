//#pragma once

#include "Jail.h"


using namespace std;

Jail::Jail(int size, string order) : Slot(size)
{
	m_name = "Jail!";
	m_order = "You are in Jail! wait 1 turn";
}

Jail::~Jail()
{
}

Jail::Jail(const Jail& JJ) : Slot(JJ.m_size)
{
}

string Jail::get_name() const
{
	return m_name;
}

bool Jail::play(Player* p)
{
	cout << m_order << endl;
	p->set_in_jail();

	return true;
}