#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "Slot.h"

using namespace std;
class Slot;
class Player;

class Board {
public:
	enum action { END_GAME, PLAY, PRINT_BOARD };

private:
	int m_size;
	Slot **m_arr;
	string m_board_image[6][5];
	int m_slot_width;	
	void increase_board();
	void init_board_image();
	void print_help();	
	Board::action get_command() const;

public:
	
	Board();	
	int size() const;
	Slot* operator[](int idx) const;
	void play(Player* players);
	void add_asset_slot(const string& city, const string& propertyName);
	void add_go_slot(const string& text);
	void add_jail_slot(const string& text);
	void add_chance_slot(const string& text, float amount);
	friend ostream& operator<<(ostream& os, const Board& b);
};



#endif
