#pragma once

#include "Chance.h"
using namespace std;

Chance::Chance(int size, string order, int amount): Slot(size), m_order(order)
{
	m_name = "Chance";
}

Chance::~Chance()
{
}

Chance::Chance(const Chance& CC)
{
	
}