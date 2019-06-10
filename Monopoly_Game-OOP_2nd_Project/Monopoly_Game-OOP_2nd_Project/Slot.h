#pragma once
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG


class Slot
{
private:


protected:



public:
	// Constructor
	Slot();
	//	Destructor 
	~Slot();
	//Copy Constructor
	Slot(const Slot&);



};
