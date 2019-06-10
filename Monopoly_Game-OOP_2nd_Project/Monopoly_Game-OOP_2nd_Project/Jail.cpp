#pragma once

#include "Jail.h"
using namespace std;

Jail::Jail(int size, string order) : Slot(size), m_order(order)
{
	m_name = "Jail";
}

Jail::~Jail()
{
}

Jail::Jail(const Jail& JJ)
{
}

string Jail::get_name()
{

	return m_name;
}