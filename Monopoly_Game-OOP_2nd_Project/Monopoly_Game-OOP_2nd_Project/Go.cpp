#pragma once

#include "Go.h"


using namespace std;

Go::Go(int size, string order) : Slot(size)
{
	m_name = "Go!";
	m_order = "godspeed!";
}

Go::~Go()
{
}

Go::Go(const Go& GG): Slot(GG.m_size)
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