#pragma once

#include "Asset.h"
using namespace std;

Asset::Asset(int size, string city, string asset_name): Slot(size)
{
	m_city = city;
	m_asset_name = asset_name;
	m_owner = 0;

}

Asset::~Asset()
{
}

Asset::Asset(const Asset& AA)
{
}

string Asset::get_name()
{
	return m_name;
}