#pragma once
using namespace std;

#include "Board.h"
#include "Slot.h"

#include <string>
#include <iostream>


int main()
{

	Board monopoly;	
	string d;
	cout << monopoly;
	Player players[2] = { Player("Neta",monopoly, 350), Player("Yael",monopoly, 350) };
	monopoly.play(players);
	return 0;

}
