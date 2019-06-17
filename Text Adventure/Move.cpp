#include "Move.hpp"


Move::Move(std::string name, std::string discription, int cost)
{
this->name = name;
this->discription = discription;
this->cost = cost;
}
std::string Move::GetName()
{
	return this->name;
}
int Move::GetCost()
{
	return this->cost;
}

void Move::Use()
{

}