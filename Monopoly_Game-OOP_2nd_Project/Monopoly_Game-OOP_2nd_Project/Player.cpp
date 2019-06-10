#pragma once

#include "Player.h"
using namespace std;

Player::Player(string name, Board* BB, int balance)
{
	m_name = name;
	m_board = BB; // μαγεχ φιξεγ
	m_balance = balance;
	m_in_jail = false;
	m_slot_num = 1;


}

Player::~Player()
{
}

Player::Player(const Player& PP)
{
}

int Player::draw_dice()
{
}

int Player::get_counter()
{
}

string Player::get_name()
{
}