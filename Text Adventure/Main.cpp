#include "GameWorld.hpp"
#include "Encounter.hpp"
//Player(int maxHP, int maxDEF, int ATK, std::string name, int maxAP)
//Enemy(int maxHP, int maxDEF, int ATK, std::string name, std::string attackText, bio)
int main()
{
	std::cout << "what is your name?: ";
	std::string name;
	getline(std::cin, name);
	std::cout << "what is your room mates name?";
	std::string roomMateName;
	getline(std::cin, roomMateName);
	while(1){
	Player *human = new Player(50, 1, 20, name, 10);
	GameWorld *theGame = new GameWorld(name,roomMateName);
	Room* startingRoom = theGame->MakeGameWorld();
	theGame->PlayTheGame(startingRoom,human);
	/*std::cout << "what is your name?: ";
	std::string name;
	getline(std::cin, name);
	std::cout << std::endl;
	Player *Human = new Player(20,0,5,name,10);
	
	Enemy *Pat = new Enemy(10,1,1,"pat","you feel a light gust" , "some bum");
	Enemy *PatTwo = new Enemy(5,0,0,"smole pat","you feel a smole gust", "hes trying his best");
	Enemy *PatPat = new Enemy(20,2,1,"pat pat","you feel a gust gust", "two pat stapled together, what kind of mad man would do this?");
	std::list<Enemy*> fightOneEnemys;
	fightOneEnemys.push_front(Pat);
	fightOneEnemys.push_front(PatTwo);
	fightOneEnemys.push_front(PatPat);

	Encounter* fightOne = new Encounter(fightOneEnemys, Human);
	bool egg = fightOne->Fight();
	*/

	std::list<std::string> finalCutscene;
	finalCutscene.push_back("the triangle shatters onto dust and spread away in the wind");
	finalCutscene.push_back("...");
	finalCutscene.push_back("you wake upon the roof of burnell");
	finalCutscene.push_back("all of the freinds you have made surround you");
	finalCutscene.push_back("you look down at all mob of people in on the lawn");
	finalCutscene.push_back("they are confused but it seems the curse has broken");
	finalCutscene.push_back("you feel something grabing you and then pulling you away");
	finalCutscene.push_back("its esteves, hes draging you back to your class, he says something to you");
	finalCutscene.push_back("\"just because you saved bridgewater it dosen't mean you can skip your COMP-921 class\"");
	finalCutscene.push_back("...");
	finalCutscene.push_back("CREDITS");
	finalCutscene.push_back("craig-programing");
	finalCutscene.push_back("also craig-story");
	finalCutscene.push_back("wait what art team? - art team");
	finalCutscene.push_back("special thanks- prof E");





		std::string enter;
	while(finalCutscene.size() > 0)
	{
		std::cout << finalCutscene.front() << std::endl;
		getline(std::cin,enter);
		std::cout << std::endl << std::endl;
		finalCutscene.pop_front();
	}



	std::cout << "The End new+ start";
}
}