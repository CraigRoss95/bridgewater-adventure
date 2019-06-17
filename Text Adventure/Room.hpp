#ifndef ROOM_HPP
#define ROOM_HPP
#include "Enemy.hpp"
#include "Item.hpp"
#include "NPC.hpp"
#include <list>


class Room 
{
public:
	Room(std::list<Enemy*> EnemysInRoom, std::string title, std::string description, bool clear, std::list<Item*> itemsInRoom, std::list <NPC*> NPCsInRoom);

	std::string GetTitle();
	std::string GetDescription();

	Room* GetNorthRoom();
	Room* GetEastRoom();
	Room* GetSouthRoom();
	Room* GetWestRoom();

	std::list<Enemy*> GetEnemys();
	std::list<NPC*> GetNPCS();

	void SetNorthRoom(Room* room);
	void SetEastRoom(Room*room);
	void SetSouthRoom(Room* room);
	void SetWestRoom(Room*room);

	void ClearRoom();

	bool IsClear();
	std::list<Item*> GetItems();
	bool GetLooted();
	void SetLooted(bool looted);
	void MakeCheckpoint();
	bool GetIsCheckpoint();
	void MakeCutScene(std::list<std::string> scene);
	void ShowCutScene();
    void PrintNPCs();
    void MakeFinalRoom();
    bool GetFinalRoom();
	
private:
	bool finalRoom = false;
	bool hasCutscene = false;
	std::list<std::string> cutscene;
	bool isCheckpoint = false;
	bool looted= false;
	std::list <NPC*> NPCsInRoom;
	std::list<Item*> itemsInRoom;
	bool clear;
	std::string title;
	std::string description;
	std::list<Enemy*> EnemysInRoom;
	Room* northRoom = nullptr;
	Room* eastRoom = nullptr;
	Room* southRoom = nullptr;
	Room* westRoom = nullptr;
};
#endif