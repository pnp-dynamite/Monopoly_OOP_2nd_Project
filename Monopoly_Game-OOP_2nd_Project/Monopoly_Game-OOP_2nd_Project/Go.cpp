#pragma once

#include "Go.h"
using namespace std;

Go::Go(int size, string order) : Slot(size), m_order(order)
{
	m_name = "Go";
}

Go::~Go()
{
}

Go::Go(const Go& GG)
{
}