#include "Board.h"
#include "Slot.h"
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{

	Board monopoly;	
	cout << monopoly;
	Player players[2] = { Player("Neta",monopoly, 350),Player("Yael",monopoly, 350) };
	monopoly.play(players);
	return 0;

}
