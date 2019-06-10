#pragma once

#include "Slot.h"
using namespace std;

//int Slot::slot_counter = 1;


Slot::Slot(int slot_num, string& name) : m_size(slot_num)
{
	m_name = name;
}

Slot::~Slot()
{
}

Slot::Slot(const Slot& SS)
{
}

string Slot::get_name()
{

}

// Generate random number between the LOW number and the HIGH number (including)
int Slot::random_number(int low, int high)
{
	int num;
	num = rand() % (high - low + 1) + low;
	return num;
}