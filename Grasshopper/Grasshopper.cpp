// Grasshopper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector> 

class Leaf
{
public:
	Leaf(int,bool);
	~Leaf();
	int getnumber();
	void setstate(bool);
	bool getstate();

private:
	bool _eaten;
	int _number;
};

Leaf::Leaf(int number, bool state)
{
	_number = number;
	_eaten = state;
}

Leaf::~Leaf()
{
}

int Leaf::getnumber()
{
	return _number;
}

void Leaf::setstate(bool newstate)
{
	_eaten = newstate;
}

bool Leaf::getstate()
{
	return _eaten;
}

/////////////////////////
class Grasshopper
{
public:
	Grasshopper(int,int);
	~Grasshopper();
	void JumpLeft();
	void JumpRight();
	int GetPos();

private:
	std::vector<Leaf> _leaves;
	int currentpos;
};

Grasshopper::Grasshopper(int number_of_leaves, int startposition)
{
	bool state = false;
	currentpos = startposition - 1;
	for (int i = 0; i < number_of_leaves; i++)
	{
		Leaf newleaf(i+1, state);
		_leaves.push_back(newleaf);
	}
}

Grasshopper::~Grasshopper()
{

}

void Grasshopper::JumpLeft()
{
	int i = 0;
	_leaves[currentpos].setstate(true);
	do
	{
		i++;
	} while (_leaves[currentpos-i].getstate());
	do
	{
		i++;
	} while (_leaves[currentpos - i].getstate());
	currentpos = currentpos - i;
}
void Grasshopper::JumpRight()
{
	int i = 0;
	_leaves[currentpos].setstate(true);
	do
	{
		i++;
	} while (_leaves[currentpos + i].getstate());
	do
	{
		i++;
	} while (_leaves[currentpos + i].getstate());
	currentpos = currentpos + i;
}
int Grasshopper::GetPos()
{
	return _leaves[currentpos].getnumber();
}

int main()
{
	Grasshopper grasshopper(5, 2);
	grasshopper.JumpRight();
	std::cout << grasshopper.GetPos() << std::endl;
	grasshopper.JumpLeft();
	std::cout << grasshopper.GetPos() << std::endl;
    return 0;
}

