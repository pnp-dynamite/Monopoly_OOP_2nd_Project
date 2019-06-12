#pragma once

#include "Slot.h"

using namespace std;

//int Slot::slot_counter = 1;


Slot::Slot(int slot_num) : m_size(slot_num)
{

}

Slot::~Slot()
{
}

Slot::Slot(const Slot& SS)
{
	m_size = SS.m_size;
}

// Generate random number between the LOW number and the HIGH number (including)
int Slot::random_number(int low, int high)
{
	int num;
	num = rand() % (high - low + 1) + low;
	return num;
}