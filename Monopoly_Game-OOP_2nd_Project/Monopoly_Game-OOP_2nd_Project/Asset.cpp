#pragma once

#include "Asset.h"

using namespace std;

Asset::Asset(int size, string city, string asset_name): Slot(size)
{
	m_city = city;
	m_asset_name = asset_name;
	m_owner = -1;

	m_rent = random_number(5, 50);
	m_cost = random_number(50, 150);

}

Asset::~Asset()
{
}

Asset::Asset(const Asset& AA): Slot(AA.m_size)
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


bool Asset::play(Player* p)
{
	if (get_owner() == -1)
	{
		cout << "Do you want to buy " << m_asset_name << " in "
			<< m_city << "for " << m_cost << " ?";

		// action 1
		int in;
		cin >> in;
		if(in == 1)
			p->add_asset(this);

		return true;
	}
	else if (get_owner() != p->get_player_num())
	{
		if (!p->pay_rent(m_rent))
			return false;
	}
	return true;
}