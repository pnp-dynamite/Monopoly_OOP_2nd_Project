#pragma once

#include "Asset.h"
using namespace std;

Asset::Asset(int size, string city, string asset_name): Slot(size, city+','+asset_name)
{
	m_city = city;
	m_asset_name = asset_name;
	m_owner = 0;

	m_rent = random_number(5, 50);
	m_cost = random_number(50, 150);

}

Asset::~Asset()
{
}

Asset::Asset(const Asset& AA): Slot(AA.m_size, AA.m_name)
{
	 m_city = AA.m_city;
	 m_asset_name = AA.m_asset_name;
	 m_rent = AA.m_rent;
	 m_cost = AA.m_cost;
	 m_owner = AA.m_owner;
}

string Asset::get_name()
{
	return m_name;
}
string Asset::get_city()
{
	return m_city;
}
string Asset::get_asset_name()
{
	return m_asset_name;
}

int Asset::get_owner()
{
	return m_owner;
}

bool Asset::play(Player* p)
{
	if (get_owner() == p.) 


}