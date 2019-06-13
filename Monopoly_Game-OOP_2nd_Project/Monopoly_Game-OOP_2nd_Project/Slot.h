#pragma once
#include "Player.h"

using namespace std;

// Project Definitions by demand
#define min_rent 5
#define max_rent 50
#define min_cost 50
#define max_cost 150

//-----------------------------------Slot-----------------------------------------//

class Player;
class Slot
{

protected:
	int m_size;

public:
	// Constructor
	Slot(int slot_num);

	//	Destructor 
	virtual ~Slot() = 0;

	virtual bool play(Player* p) = 0;
	static int slot_counter;

	// Virtual Getter
	virtual string get_name() const = 0;
};



//--------------------------------------Go------------------------------------//
class Go : public Slot
{
protected:
	string m_name;
	string m_order;

public:
	// Constructor
	Go(int size, string order);
	//	Destructor 
	~Go();

	// Getters 
	string get_name() const;


	bool play(Player* p);

};


//--------------------------------------Asset------------------------------------//

class Asset : public Slot
{
protected:
	string m_city;
	string m_asset_name;
	int m_rent;
	int m_cost;
	int m_owner;

public:
	// Constructor
	Asset(int size = 0, string city = "", string asset_name = "");
	//	Destructor 
	~Asset();
	//Copy Constructor
	Asset(const Asset& AA);


	// Getters
	string get_name() const;
	string get_city() const;
	string get_asset_name() const;
	int get_owner() const;
	int get_cost() const;
	int get_rent() const;

	// Setters
	void set_owner(int player_num);

	bool play(Player* p);
};

//--------------------------------------Chance------------------------------------//

class Chance : public Slot
{
protected:
	string m_name;
	string m_order;
	int m_amount;

public:
	// Constructor
	Chance(int size, string order, int amount);
	//	Destructor 
	~Chance();

	// Getter
	string get_name() const;


	bool play(Player* p);
};

//--------------------------------------Jail------------------------------------//

class Jail : public Slot
{
protected:
	string m_name;
	string m_order;

public:
	// Constructor
	Jail(int size, string order);
	//	Destructor 
	~Jail();

	// Getter
	string get_name() const;


	bool play(Player* p);

};
