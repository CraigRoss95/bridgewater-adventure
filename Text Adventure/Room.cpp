
#include "Room.hpp"

Room::Room(std::list<Enemy*> EnemysInRoom, std::string title, std::string description, bool clears, std::list<Item*> itemsInRoom, std::list <NPC*> NPCsInRoom)
{
	this->itemsInRoom = itemsInRoom;
	this->clear = clear;
	this->EnemysInRoom = EnemysInRoom;
	this->title = title;
	this->description = description;
	this->NPCsInRoom = NPCsInRoom;
}
void Room::MakeCutScene(std::list<std::string> scene)
{
	this->hasCutscene = true;
	this->cutscene = scene;
}
void Room::ShowCutScene()
{
	std::cout <<"\n\n\n";
	std::string enter;
	while (this->cutscene.size() > 0)
	{
		std::cout << cutscene.front() << std::endl;
		this->cutscene.pop_front();
		if (this->cutscene.size() > 0)
		{
			std::cout << "(press Enter to continue...)\n";
			getline(std::cin, enter);
		}
		std::cout << std::endl;
	}
}

void Room::ClearRoom()
{
	clear = true;
}
void Room::MakeCheckpoint()
{
	this->isCheckpoint = true;
}
bool Room::GetIsCheckpoint()
{
	return this->isCheckpoint;
}

bool Room::IsClear()
{
	return clear;
}
std::string Room::GetTitle()
{
	return title;
}
std::string Room::GetDescription()
{
	return description;
}

Room* Room::GetNorthRoom()
{
	return northRoom;
}

Room* Room::GetEastRoom()
{
	return eastRoom;
}

Room* Room::GetSouthRoom()
{
	return southRoom;
}

Room* Room::GetWestRoom()
{
	return westRoom;
}

void Room::SetNorthRoom(Room* room)
{
	northRoom = room;
}

void Room::SetEastRoom(Room* room)
{
	eastRoom = room;
}

void Room::SetSouthRoom(Room*room)
{
	southRoom = room;
}

void Room::SetWestRoom(Room* room)
{
	westRoom = room;
}
std::list<Enemy*> Room::GetEnemys()
{
	return this->EnemysInRoom;
}
std::list<NPC*> Room::GetNPCS()
{
	return this->NPCsInRoom;
}
std::list<Item*> Room::GetItems()
{
	return this->itemsInRoom;
}
bool Room::GetLooted()
{
	return this->looted;
}
void Room::SetLooted(bool looted)
{
	this->looted = looted;
}
void Room::PrintNPCs()
{
	std::list<NPC*> NPCListCopy = NPCsInRoom;
	while (NPCListCopy.size() > 0)
	{
		std::cout << "[" << NPCListCopy.front()->GetName() << "]  ";
		NPCListCopy.pop_front();
	}
	std::cout << std::endl;
}

void Room::MakeFinalRoom()
{
	this->finalRoom = true;
}
bool Room::GetFinalRoom()
{
	return this->finalRoom;
}
