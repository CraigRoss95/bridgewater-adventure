#include "Scroll.hpp"


Scroll::Scroll(std::string name, std::string description, Move* move) : Item(name, description)
{
	this->move = move;
}
void Scroll::UseItem(Player* player)
{
	std::cout << "used " << this->GetName() << std::endl;
	std::cout << "you learned " << this->GetMove()->GetName() << std::endl;
	player->Learn(this->move);
}
Move* Scroll::GetMove()
{
	return move;
}
