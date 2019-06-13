#pragma once
using namespace std;

#include "Board.h"
#include "Slot.h"
#include <string>
#include <iostream>


void runner()
{
	Board monopoly, monopoly1;
	cout << monopoly;
	Player players[2] = { Player("Neta",monopoly, 350), Player("Yael",monopoly, 350) };
	monopoly.play(players);
	return;
}

int main()
{
	runner();
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}