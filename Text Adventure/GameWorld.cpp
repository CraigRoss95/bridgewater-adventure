#include "GameWorld.hpp"
#include "Encounter.hpp"
#include "NPC.hpp"

GameWorld::GameWorld(std::string playerName, std::string roomMateName)
{
	this->playerName = playerName;
	this->roomMateName = roomMateName;
}

Room* GameWorld::MakeGameWorld()
{
	//Room(std::list<Enemy*> EnemysInRoom, std::string title, std::string description, bool clear);
	//LinkRooms(Room* roomOne, Room* roomTwo, std::string direction)
	//NPC(std::string name, std::string talkText, std::string talkTextAgain, std::string bio, bool hasItem, Item* giveItem);
	//StatUp::StatUp(std::string name, std::string description, int value, std::string) : Item(name, description)
	std::list<Item*> noItems;
	std::list<Enemy*> noEnemys;
	std::list<NPC*> noNPCs;


	Move* firewave = new Move("firewave", "hits all enemys", 5);
	Move* heal = new Move("heal", "heals for 10 hp", 5);
	Move* breaks = new Move("break", "deals true damage", 7);
	Move* voodoo = new Move("voodoo", "deals 20 damage, costs hp", 10);


	//your room
	std::list<Item*> roomOneItemList;
	Move *dab = new Move("dab", "makes everyone angry but restores ap", 0);
	Item *dabScroll = new Scroll("dab scroll", "a move scroll that teaches 'dab' ", dab);

	Room *dormRoom = new Room(noEnemys, "your room" , "it,s a mess in here", true, noItems, noNPCs);
	dormRoom->MakeCheckpoint();
	this->currCheckpoint = dormRoom;

	std::list<std::string> sceneOne;
	sceneOne.push_back("welcome to the game");
	sceneOne.push_back("the commands are standard and you can type back to go back in a menu");
	sceneOne.push_back("you can aslo type the first letter of a command, name, or object insted of the full name in most cases");
	sceneOne.push_back("have fun!");
	sceneOne.push_back("...");
	sceneOne.push_back("you wake up in your bed and you notice the power is out");
	sceneOne.push_back("you see " + this->roomMateName + " in the common room and something is off about them");
	sceneOne.push_back("the campus is also especilay quite for Monday morning");
	dormRoom->MakeCutScene(sceneOne);

	//commn0 room 2
	//room 2
	//room 2 enemys
	Enemy *enPat = new Enemy(10, 0, 2, roomMateName, roomMateName + " slaps you lightly" , "what is wrong with them?");
	Enemy *fly = new Enemy(1, 0, 0, "fly", "buz buzz" , "it is trying to fly out the window throught the screen");
	std::list<Enemy*> roomTwoEnemyList;
	roomTwoEnemyList.push_back(enPat);
	roomTwoEnemyList.push_back(fly);
	//room 2 npcs
	Item *burrito = new Food("rice burrito", "a burrito filled with rice, disgusting", 5);
	NPC *npcPat = new NPC(roomMateName, "make sure to always talk to people twice!", "there you go! you get the idea", " its your room mate" + roomMateName, true , burrito);
	std::list<NPC*> roomTwoNPC;
	roomTwoNPC.push_back(npcPat);
	//making room 2
	Room *commonRoom = new Room(roomTwoEnemyList, "the common room" , "where we hang out" , false , noItems, roomTwoNPC);
	//linking room 2
	LinkRooms(dormRoom, commonRoom, "w");

	//dm room
	Item *cokea = new Drink("coke", "better then bepsi", 5);
	Item *cokeb = new Drink("coke", "better then bepsi", 5);
	Item *cokec = new Drink("coke", "better then bepsi", 5);

	Item *sweatShirt = new StatUp("my sweat shirt", "i realy need to wash this thing", 10 , "hp");
	std::list<Item*> roomThreeItems;
	roomThreeItems.push_back(cokea);
	roomThreeItems.push_back(cokeb);
	roomThreeItems.push_back(cokec);

	Room *DMRoom = new Room(noEnemys, "my dorm mates room" , "there are soda cans everywhere" , true , roomThreeItems, noNPCs);
	LinkRooms(commonRoom, DMRoom, "w");
	//hall 0

	Room *hallZero = new Room(noEnemys, "hall" , "the hall leading to the stairs" , true , noItems, noNPCs);
	LinkRooms(commonRoom,hallZero, "n");
	Item *davidsHat = new StatUp("hat", "its a hat david gave you", 10 , "ap");
	//hall1
	NPC *david = new NPC("david", "thanks a buch! here take this!(he hands you his hat)", "i don't know about you but i can only wear one hat", "he is playing a pokemone fan game on his phone", true , davidsHat);
	NPC *ali = new NPC("ali", "what happened? are you ok", "im glad we didn't hurt eachother", "she is waching david play a game", false , burrito);
	
	std::list<NPC*> hallwayNPCS;
	hallwayNPCS.push_back(david);
	hallwayNPCS.push_back(ali);
	Enemy *enemyDavid = new Enemy(1, 0, 0, "hat wearing guy", "hat wearing guy hits you with his laptop" , "How did he get here?");
	Enemy *enemyAli = new Enemy(1, 0, 0, "owo", "owo 0w0s" , "why is this persons name an emoj?");

	std::list<Enemy*> hallwayEnemys;
	hallwayEnemys.push_back(enemyDavid);
	hallwayEnemys.push_back(enemyAli);

	Room *hallOne = new Room(hallwayEnemys, "hall end" , "righ infront of the stairs" , false , noItems, hallwayNPCS);
	LinkRooms(hallZero,hallOne, "e");

	//stairs
	std::list<Enemy*> stairsEnemy;
	std::list<NPC*> stairsNPC;
	std::list<Item*> stairsItems;

	Item *firewaveScroll = new Scroll("firewave scroll", "a move scroll that teaches 'firewave' ", firewave);
	stairsItems.push_back(firewaveScroll);
	Enemy *craigEnemy = new Enemy(1, 1, 1, "stairwell gremlin", "swipes at you", "hes realy sweaty");
	Item *cookie = new Food("cookie burrito", "you dont like oatmeal but you didnt want to be that guy",10);


	NPC *craig = new NPC("craig", "hey how did i get in here? oh well, anyway here have a cookie", "it sucks the powers out. i had to take the stairs!", "hes still slightly sweaty",true, cookie);
	
	stairsEnemy.push_back(craigEnemy);
	stairsNPC.push_back(craig);


	Room *stairs = new Room(stairsEnemy, "stairs" , "leads to the lobby" , false , stairsItems, stairsNPC);
	LinkRooms(hallOne,stairs, "e");

	//loby
	std::list<Enemy*> lobyEnemy;
	std::list<NPC*> lobyNPC;
	Enemy *enemyVotie = new Enemy(20, 0, 0,"dabbing millennial","dabs","as you look at the dabbing millennial they dab faster");
	lobyEnemy.push_back(enemyVotie);
	NPC *votie = new NPC("votie","(votie dabs a majestic majestic, they are holding a rolled up peice of papper)", "(votie dabs)","what am i suppose to do dab back?",true, dabScroll);
	lobyNPC.push_back(votie);

	Room *loby = new Room(lobyEnemy,"loby", "votie sits dabbing behinde the desk dabbing",false,noItems,lobyNPC);
	LinkRooms(stairs,loby,"n");

	//wegand yard
	std::list<Enemy*> wegandYardEnemys;
	std::list<NPC*> wegandYardNPCs;

	Enemy* enemyCj = new Enemy(20,0,0,"angry programer","greif for the computer science department looms over you","he is slamming on his laptop keys");
	wegandYardEnemys.push_back(enemyCj);
	NPC* cj = new NPC("cj", "did you know that wildlife is natraly attracted to save points?", "craig! im in your game and therefore can not see your code but i know it is slopy","(he has unity open: yous see a ball rolling around on a square collecting coins)",false,burrito);
	wegandYardNPCs.push_back(cj);

	Room *wegandYard = new Room(wegandYardEnemys,"wegand yard", "from where you stand you can only see cj, you also see votie dabbing from the window", false, noItems,wegandYardNPCs);
	LinkRooms(loby,wegandYard,"n");

	//ecc
	std::list<Enemy*> eccEnemys;
	std::list<Item*> eccItems;

	Enemy *souperMan = new Enemy(15,0,0,"souper man", "flings soup at you", "he is dripping with soup");
	eccEnemys.push_back(souperMan);

	Item* tray = new StatUp("tray", "i could use this as a shield" , 2, "def");
	Item* soupBurrito = new Food("souper burrito", "soup wrapped in a tortia", 10);

	eccItems.push_back(tray);
	eccItems.push_back(soupBurrito);

	Room *ecc = new Room(eccEnemys,"ecc", "you see what is left of souper man in a puddle on the ground", false, eccItems, noNPCs);
	LinkRooms(wegandYard,ecc,"n");

	Room *crimsonEx = new Room(noEnemys,"outside of crimson","you hear buzzing, lots of bussing! it is comming from the east", true, noItems,noNPCs);
	LinkRooms(wegandYard, crimsonEx, "w");

	std::list<Item*> CrimsonItems;
	Item* cokeZ = new Drink("coke zero", "0 cokes sold on campus", 10);
	Item* chickenBurrito = new Food("fried chicken burrito", "chicken tendersmwrapped in a tortia", 10);

	CrimsonItems.push_back(chickenBurrito);
	CrimsonItems.push_back(cokeZ);

	Room *crimsonInside = new Room(noEnemys,"crimson", "most of the food is gone but most of the people are too so you feel safe here", true,CrimsonItems,noNPCs);
	LinkRooms(crimsonEx,crimsonInside, "n");
	crimsonInside->MakeCheckpoint();

	std::list<Enemy*> beesEnemy;
	std::list<Item*> feildAItems;
	Enemy *beeGolem = new Enemy(100,0,0,"bee golem", "a fist made of bees clobers you", "its a giant person made entirely out of bees");
	Enemy *beea = new Enemy(1, 2, 0, "bee a", "stings you", "a stray bee off of the golem");
	Enemy *beeBee = new Enemy(1, 2, 0, "bee bee", "stings you", "a stray bee off of the golem");
	Enemy *beec = new Enemy(1, 2, 0, "bee c", "stings you", "a stray bee off of the golem");
	Enemy *beed = new Enemy(1, 2, 0, "bee d", "stings you", "a stray bee off of the golem");
	Enemy *beee = new Enemy(1, 2, 0 ,"bee e", "stings you", "a stray bee off of the golem");
	Enemy *beef = new Enemy(1, 2, 0, "bee f", "stings you", "a stray bee off of the golem ,smells like steak");

	beesEnemy.push_back(beea);
	beesEnemy.push_back(beeBee);
	beesEnemy.push_back(beec);
	beesEnemy.push_back(beeGolem);
	beesEnemy.push_back(beed);
	beesEnemy.push_back(beee);
	beesEnemy.push_back(beef);

	Item *honey = new Drink("honey soda", "yup its a cocacola product!" , 10);
	feildAItems.push_back(honey);

	Room *feildA = new Room(beesEnemy, "feild 1", "well thats where all of the buzzing came from", false,feildAItems,noNPCs);
	LinkRooms(crimsonEx,feildA, "w");

	Room *feildB = new Room(noEnemys,"feild 2" , "a quick break before continueing onwards", true ,noItems, noNPCs);
	LinkRooms(feildA,feildB, "w");

	std::list<std::string> sceneTwo;
	sceneTwo.push_back("you continue through the feild and look up at the sky");
	sceneTwo.push_back("dark storm clouds are circleing over boyden");
	sceneTwo.push_back("you also feel as if you should stop by crimson if you havent already");

	feildB->MakeCutScene(sceneTwo);

	std::list<Enemy*> feildCEnemys;
	Enemy *door = new Enemy(100,0,0, "door","dose nothing" , "its just standing there menicingly");
	feildCEnemys.push_back(door);

	Room *feildC = new Room(feildCEnemys, "feild 3", "you probbly could have gone around", false, noItems, noNPCs);
	LinkRooms(feildB,feildC,"w");

	std::list<Enemy*> statueEnemys;
	std::list<NPC*> statueNPCs;

	Enemy *crissEnemy = new Enemy(1,0,0,"late-age postmodern hipster", "jams out","what is wrong with this guys gituar?");
	statueEnemys.push_back(crissEnemy);

	Item *bass = new StatUp("\"bass\"", "it's just a gituar with some of its strings ripped out", 3, "atk");
	Item *metalBurrito = new Food("metal burrito", "given to you by the statue", 20);
	
	NPC *criss = new NPC("criss", "hey wanna give this thing a shot?", "not bad you can hang on to it for a while just give it back when you are done!", "hes wearing a persona teeshirt and flipflops", true, bass);
	NPC *statue = new NPC("metal child", "(the child says nothing and hands you a burrito)", "(the child is smiling)", "he stands compleatly still looking to the west", true, metalBurrito);
	statueNPCs.push_back(criss);
	statueNPCs.push_back(statue);

	Room *statueRoom = new Room(statueEnemys,"statue", "a metal child stands and tends to the garden at his feed",false,noItems,statueNPCs);
	LinkRooms(feildC,statueRoom,"w");

	std::list<Item*> bridgeItems;
	Item *fishBurrito = new Food("fish burrito", "smells aweful",10);
	bridgeItems.push_back(fishBurrito);

	Room *bridge = new Room(noEnemys,"bridge","the bridge that leads to moakly", true,bridgeItems,noNPCs);
	LinkRooms(statueRoom,bridge,"n");

	Item *cokeM = new Drink("coke max", "refreshing!", 20);
	std::list<NPC*> moaklyNPCs;
	NPC *pat = new NPC("pat","please take my coke its all i have left", "oh i thought you were criss and comming to bully me again! fewf!" ,"he is shakeing and on the verge of tears", true , cokeM);

	Room *moakly = new Room(noEnemys,"moakly", "this place is a lot smaller on the inside!", true, noItems,moaklyNPCs);
	LinkRooms(bridge,moakly,"n");

	std::list<Item*> tracksItems;
	Item *breakScroll = new Scroll("break scroll", "a move scroll that teaches 'break' ", breaks);
	Item *flipFlops = new StatUp("flip flops", "these are used for two things 1)flipping 2)footwear", 10 ,"hp");
	tracksItems.push_back(flipFlops);
	tracksItems.push_back(breakScroll);

	Room *tracks = new Room(noEnemys,"under the train tracks", "it is cold and wet down here", true,tracksItems, noNPCs);
	LinkRooms(statueRoom,tracks, "w");

	std::list<std::string> sceneThree;

	sceneThree.push_back("you still see the the smoke bellowing out of the west side of campus");
	sceneThree.push_back("you are allmost sure now that it is comming from boyden");
	sceneThree.push_back("you notice something now that you havent noticed before");
	sceneThree.push_back("the smoke is slowly changing colors");
	tracks->MakeCutScene(sceneThree);


	tracks->MakeCheckpoint();

	std::list<Item*> eastCampusItems;
	std::list<Enemy*> eastCampusEnemys;

	Enemy *squrrel = new Enemy(30,3,3, "squrrel golem","claws at you","a golem made out of twenty something squrrels");
	eastCampusEnemys.push_back(squrrel);

	Item *nut = new Food("nut burrito", "a crunchy treat", 15);
	eastCampusItems.push_back(nut);

	Room *eastCampus = new Room(eastCampusEnemys,"east campus", "half way there", false, eastCampusItems,noNPCs);
	LinkRooms(tracks,eastCampus,"w");

	std::list<Enemy*> churchEnemys;
	std::list<NPC*> churchNPCs;
	std::list<Item*> churchItems;

	Enemy *daddy = new Enemy(10,4,2, "daddy", "smites you" , "i will not call him daddy");
	churchEnemys.push_back(daddy);
	Item *HealScroll = new Scroll("heal scroll", "a move scroll that teaches 'heal' ", heal);	
	NPC *fatherGorg = new NPC("father gorg","hello my child! if you are ever in need of aid use this", "there is no admission fee and no locks in this house of god but i ask that you get going", "still moist with holy water",true, HealScroll);
	churchNPCs.push_back(fatherGorg);

	Item *holyCoke = new Drink("holy coke","like holy water but with more betus", 10);
	churchItems.push_back(holyCoke);

	Room *church = new Room(churchEnemys,"church", "we are now in gorgs house",false, churchItems,churchNPCs);
	LinkRooms(eastCampus,church, "n");

	std::list<Enemy*> DMFEEnemys;
	std::list<NPC*> DMFENPCs;
	std::list<Item*> DMFEItems;

	Enemy *pizzaKnight = new Enemy(10, 0, 0 , "pizza knight", "slices with a pizza box", "card board pizza box armor, there might be a person inside");
	DMFEEnemys.push_back(pizzaKnight);

	Item *pizza = new Food("pizza burrito","a slice of a pizza burrito", 30);

	Item *pizzaCoke = new Drink("pizza flavored coke", "wheres my drink",15);

	DMFEItems.push_back(pizzaCoke);

	NPC *josh = new NPC("josh","hey who are you? can you throw this out for me?", "hey you wanna buy me a pizza","josh is building a fort out of pizza boxes", true, pizza);
	DMFENPCs.push_back(josh);

	Room *dMFE = new Room(DMFEEnemys, "dmf e", "pizza boxes litter the entry way", false, DMFEItems,DMFENPCs);
	LinkRooms(eastCampus,dMFE,"w");

	std::list<Enemy*> dmfOneEnemys;
	std::list<NPC*> dmfOneNPCs;

	Enemy *blackEnemy = new Enemy(1,1,1, "brutalizer black", "attacks with a laser sword","a frizy ponytail is hid behind a leather mask");
	dmfOneEnemys.push_back(blackEnemy);

	Item *laserSword = new StatUp("laser sword", "the letters  M B are written on the bottem", 5, "atk");
	NPC *black = new NPC("p black","hi there, thanks for freeing me! guess i dont need this anymore", "i have no idea why the programer gave us all wrestler names!", "he took off his costume and is wearing the stylish button up that he was wearing under it", true, laserSword );

	Room *dmfOne = new Room(dmfOneEnemys, "dmf 1", "you see proffesor black looking out the window at josh, shakeing his head", false, noItems,dmfOneNPCs);
	LinkRooms(dMFE,dmfOne, "w");

	std::list<Enemy*> dmfTwoEnemys;
	std::list<NPC*> dmfTwoNPCs;		

	Enemy *santoriEnemy = new Enemy(1,1,1,"the bridgewater basher", "bashes you", "this man needs a shirt");
	dmfTwoEnemys.push_back(santoriEnemy);

	NPC *santori = new NPC("prof santori", "did you free me from the curse? thanks, ill write you a good recomendation letter when this is all over","have you seen my pants?", "he is looking around for some more layers to put on", false, burrito);
	dmfTwoNPCs.push_back(santori);

	Room *dmfTwo= new Room(dmfTwoEnemys, "dmf 2", "it looks like someone was trying to make a cage for wrestleing", false, noItems, dmfTwoNPCs);
	LinkRooms(dmfOne,dmfTwo,"w");

	std::list<Enemy*> dmfThreeEnemys;
	std::list<NPC*> dmfThreeNPCs;		

	Item *capybara= new StatUp("framed capy'bara", "hey he has a shield so close enough", 5, "def");

	Enemy *eEnemy = new Enemy(1,1,1, "proffesor pain", "throws a desktop at you", "looks disapointed with me");
	dmfThreeEnemys.push_back(eEnemy);

	NPC *e = new NPC("prof esteves", "oh hey! gotta raid soon take this and get out!", "hang on guys hes still in here!", "you cant tell if he is more dissapointed with you or his team", true, capybara);
	dmfThreeNPCs.push_back(e);

	Room *dmfThree = new Room(dmfThreeEnemys,"dmf 3", "the halls are quiet with the occasinal dissapointed sigh and some clicking", false, noItems, dmfThreeNPCs);
	LinkRooms(dmfTwo,dmfThree,"w");

	std::list<Enemy*> dmfClassEnemys;
	std::list<NPC*> dmfClassNPCs;	
	std::list<Item*>dmfClassItems;

	Item *sweater = new StatUp("small sweater", "too small to wear like a shirt but can be stylishly placed around the hips or around the neck", 20, "ap");
	dmfClassItems.push_back(sweater);

	Enemy *oldManEnemy = new Enemy(1,1,1, "confused old man", "says something you dont understand", "who is this guy?");
	dmfClassEnemys.push_back(oldManEnemy);

	NPC *oldMan = new NPC("confused old man", "(the confused old man screaches something)", "(the confused old man is still making noises)", "how did this guy get here?", false, burrito);
	dmfClassNPCs.push_back(oldMan);

	Room *dmfClass = new Room(dmfClassEnemys, "dmf class", "a computer science classroom", false, dmfClassItems, dmfClassNPCs);
	LinkRooms(dmfThree, dmfClass,"n");

	Room *dmfFront = new Room(noEnemys, "dmf front", "dose anyone acutaly read these?", true, noItems, noNPCs);
	LinkRooms(dmfThree,dmfFront,"s");
	dmfFront->MakeCheckpoint();
	std::list<std::string> sceneFour;
	sceneFour.push_back("from where you are standing you can see the smoke pouring out of boyden");
	sceneFour.push_back("the smoke flows you like a waterfall flowing both up and down");
	sceneFour.push_back("as you walk twords the front doors of dmf you see others walking twords the pillar of smoke");
	sceneFour.push_back("they have the same look in their eyes as the students and proffesors you have seen before");
	sceneFour.push_back("and then you see it");
	sceneFour.push_back("a bear in the road right infront of you");

	dmfFront->MakeCutScene(sceneFour);

	std::list<Enemy*> streetEnemys;	
	std::list<Item*>streetItems;

	Enemy *bear = new Enemy(1,1,1, "bear golem", "slashes at you", "a golem made up of one bear");
	streetEnemys.push_back(bear);

	Item *bearHide = new StatUp("bear hide", "appon closer ispection it is a mascot costume", 30, "hp");
	streetItems.push_back(bearHide);

	Room *street = new Room(streetEnemys,"street", "you are getting close to boyden", false, streetItems, noNPCs);
	LinkRooms(dmfFront,street,"s");


	std::list<Enemy*> rccEnemys;
	Enemy *tankEnemy = new Enemy(1,1,1, "tank", "trys to dps", "be nice to him hes trying his best!");
	Enemy *healerEnemy = new Enemy(1,1,1, "healer", "fails lifesteal", "didn't get the memo about this game not having heal spells for npcs");
	Enemy *dpsEnemy = new Enemy(1,1,1, "dps", "strikes", "the longest queue time");

	rccEnemys.push_back(tankEnemy);
	rccEnemys.push_back(healerEnemy);
	rccEnemys.push_back(dpsEnemy);
	Item *voodooScroll = new Scroll("voodoo scroll", "a move scroll that teaches 'voodoo' ", voodoo);
	NPC *tank = new NPC("t h i c c   d a d d y", "could you leave we wanna finish this game before the world ends", "roll for...", "even if there was class going on he would still be here", false, burrito);
	NPC *healer = new NPC("yewbot69", "whats so funny?", "whats so funny!", "winners don't bot", false, burrito);
	NPC *dps = new NPC("shadow katana 666", "do you think god stays in heaven because he to fears what he has created? just take this and get out of my face!", "deep stuff huh?", "how can he see through his left eye with all that hair?", true, voodooScroll);

	std::list<NPC*> rccNPCs;
	rccNPCs.push_back(tank);
	rccNPCs.push_back(healer);
	rccNPCs.push_back(dps);

	Room *rcc = new Room(rccEnemys, "rcc", "dont these kids have somewhere else to be?", false, noItems, rccNPCs);
	LinkRooms(street,rcc,"s");

	std::list<Enemy*> bearsEnemys;	
	std::list<NPC*>bearsNPCS;

	Enemy *enemyGriff = new Enemy( 1,1,1, "red phantom", "ravioli steps on your toes", "he is taunting you with emotes");
	bearsEnemys.push_back(enemyGriff);

	Item *icecreamBurrito = new Food("ice cream burrito", "made with a soft waffle cone for the shell", 20);
	NPC *griff = new NPC("Griff", "hey good fight man take this", "dule later", "he is clutching a red sphere", true, icecreamBurrito);
	bearsNPCS.push_back(griff);

	Room *bears = new Room(bearsEnemys, "bears den", "fifty thousand students used to dine here and now its a ghost town", false, noItems,bearsNPCS);
	LinkRooms(rcc,bears,"s");

	Room *bearsEx = new Room(noEnemys,"outside bears den", "you see students and the occasinal proffessor climb the hil and hobbel twords boyden", false, noItems,noNPCs);
	LinkRooms(bears,bearsEx, "w");
	std::list<std::string> sceneFive;
	sceneFive.push_back("as you leave bears den you turn a corner to find out where all of those other people were going");
	sceneFive.push_back("they walk in circles around boyden slowly");
	sceneFive.push_back("you also notice light flashes of light comming from the loby of boyden");

	bearsEx->MakeCutScene(sceneFive);


	std::list<Enemy*> hillEnemys;

	Enemy *bill = new Enemy(1,1,1, "bill", "just sits on a hill", "just a bill sitting on a hill");

	hillEnemys.push_back(bill);

	std::list<Item*> hillItems;

	Item *paperBurrito = new Food("paper burrito", "poor bill!", 1);

	hillItems.push_back(paperBurrito);

	Room *hill = new Room(hillEnemys, "hill", "boyden looms in the distance", false, hillItems,noNPCs);
	LinkRooms(bearsEx,hill,"s");

	std::list<Enemy*> burnellYardEnemys;

	Enemy *mob = new Enemy(1,1,1,"the mob", "mobs you", "they loom around boyden");
	burnellYardEnemys.push_back(mob);

	Room *burnellYard = new Room(burnellYardEnemys, "boyden yard", "the sky around her is dark and you feel somehing resenating from boyden", false, noItems,noNPCs);
	LinkRooms(hill,burnellYard,"s");

	std::list<Enemy*> tillyEnemys;
	std::list<Item*> tillyItems;

	Item *eggBurrito = new Food("egg burrito", "a breakfast and a burrito", 30);
	Item *eggSoda = new Drink("egg coke", "why? why did soeone ruin this perfictly good coke with an egg?", 25);
	tillyItems.push_back(eggBurrito);
	tillyItems.push_back(eggSoda);

	Enemy *flya = new Enemy(1,1,1, "ftilly fly a","buzzes", "buzz buzz");
	Enemy *flyb = new Enemy(1,1,1, "ftilly fly b", "buzzes","buzz buzz");
	Enemy *flyc = new Enemy(1,1,1, "ftilly fly c", "buzzes","buzz buzz");
	Enemy *flyd = new Enemy(1,1,1, "ftilly fly d", "buzzes","buzz buzz");
	Enemy *flye = new Enemy(1,1,1, "ftilly fly e", "buzzes","buzz buzz");
	Enemy *flyf = new Enemy(1,1,1, "ftilly fly f", "buzzes","buzz buzz");
	Enemy *flyg = new Enemy(1,1,1, "ftilly fly g", "buzzes","buzz buzz");

	tillyEnemys.push_back(flya);
	tillyEnemys.push_back(flyb);
	tillyEnemys.push_back(flyc);
	tillyEnemys.push_back(flyd);
	tillyEnemys.push_back(flye);
	tillyEnemys.push_back(flyf);
	tillyEnemys.push_back(flyg);

	Room *tilly = new Room(tillyEnemys, "tilly", "dead flys litter the dining hall", false, tillyItems,noNPCs);
	LinkRooms(burnellYard,tilly, "e");

	Room *burnell = new Room(noEnemys,"boyden","almost there", true, noItems,noNPCs);
	LinkRooms(burnellYard,burnell,"s");

	std::list<std::string> sceneSix;

	sceneSix.push_back("well you made it");
	sceneSix.push_back("you see fred clark through his open dormroom door");
	sceneSix.push_back("he is wearing a chrimson robe and holding a book");
	sceneSix.push_back("you now think that you may have the guy you are looking for");

	burnell->MakeCutScene(sceneSix);

	std::list<Enemy*> fredClarksDormEnemys;
	Enemy *fredClarkEnemy = new Enemy(1,1,1,"fred clark?", "was freddy for you","something is off");
	fredClarksDormEnemys.push_back(fredClarkEnemy);

	std::list<NPC*> fredClarksDormNPCs;
	NPC *fredClark = new NPC("fred clark", "hello! how did i get here?", "who was that guy?", "he is still confused from being knocked out", false, burrito);
	fredClarksDormNPCs.push_back(fredClark);

	Room *fredClarksDorm = new Room(fredClarksDormEnemys,"fred clark's dorm", "its an office with a cot on the ground", false, noItems, fredClarksDormNPCs);
	LinkRooms(burnell,fredClarksDorm, "s");

	std::list<std::string> sceneSeven;
		sceneSeven.push_back("as you land the final blow you see a glowing triangl float out of fred clark's chest");
		sceneSeven.push_back("\"i no longer need this puppet to fufill my task\"");
		sceneSeven.push_back("the triangle flys into fred clark's closet phasing through the door");
		sceneSeven.push_back("you open the door to the abyss that is fred clark's closet and the abbys stares back at you");
		sceneSeven.push_back("tred carefuly, you may not be able to leave after entering his room");
		sceneSeven.push_back("if you have something that need doing before the end of the world now would be the time!");

	fredClarksDorm->MakeCutScene(sceneSeven);

	Room *fredsCloset = new Room(noEnemys, "fred's closet", "the final room", false, noItems, noNPCs);
	LinkRooms(fredClarksDorm, fredsCloset, "s");

	fredsCloset->MakeFinalRoom();



	Room* startingRoom = dormRoom;

	return startingRoom;
}

void GameWorld::PlayTheGame(Room* startingRoom, Player* human)
{	SetCurrRoom(startingRoom);


	std::cout << std::endl;
	Move* slam = new Move("slam", "hits an enemy for 10 damage", 5);
	
	Item *garlicBread = new Food("half eaten burrito", "found this one in my pants", 5);
	human->AddItem(garlicBread);
	human->Learn(slam);


	std::string command;
	bool gameOver = false;
	bool gameBeaten = false;
	while (gameBeaten == false)
	{
		while (gameOver == false)
		{
			if(currRoom->GetFinalRoom() == true)
			{
				Encounter *finalFight = new Encounter(currRoom->GetEnemys(), human);
				finalFight->FinalFight(roomMateName);
				gameBeaten = true;
				break;
			}

			if (currRoom->GetEnemys().size() > 0 && currRoom->IsClear() == false)
			{
				Encounter* fightOne = new Encounter(currRoom->GetEnemys(), human);
				gameOver = fightOne->Fight();
				if (human->GetCurrHP() > 0)
				{
					std::cout <<"you made it out";
					currRoom->ClearRoom();
				}
			}
			currRoom->ShowCutScene();
			if (gameOver == false && gameBeaten == false)
			{
				if (currRoom->GetIsCheckpoint() == true)
				{
					this->currCheckpoint = currRoom;
				}
				std::cout << "\nyou are in " << currRoom->GetTitle() << "\nWhat would you like to do?\n";
				std::cout << "[look] [move] [speak] [you] [bag] [take]\n";

				getline(std::cin, command);
				std::cout << std::endl << std::endl;
				if (command == "you" || command == "y" || command == "u" || command == "me" || command == "self" || command == "stats")
				{
					human->ShowStatsFull();
				}
				//MOVEING MOVEING MOVEING MOVEING MOVEING MOVEING MOVEING MOVEING MOVEING
				else if (command == "move" || command == "m" || command == "go")
				{

					LookAround();
					bool waySelected = false;
					while (waySelected == false) {
						std::cout << "\nWhich way?: ";
						getline(std::cin, command);
						if (command == "north" || command == "n")
						{
							if (currRoom->GetNorthRoom() != nullptr)
							{
								currRoom = currRoom->GetNorthRoom();
								waySelected = true;
							}
							else
							{
								std::cout << "there is nothing to the north \n";
							}
						}
						else if (command == "east" || command == "e")
						{
							if (currRoom->GetEastRoom() != nullptr)
							{
								currRoom = currRoom->GetEastRoom();
								waySelected = true;
							}
							else
							{
								std::cout << "there is nothing to the east \n";
							}
						}
						else if (command == "south" || command == "s")
						{
							if (currRoom->GetSouthRoom() != nullptr)
							{
								currRoom = currRoom->GetSouthRoom();
								waySelected = true;
							}
							else
							{
								std::cout << "there is nothing to the south \n";
							}
						}
						else if (command == "west" || command == "w")
						{
							if (currRoom->GetWestRoom() != nullptr)
							{
								currRoom = currRoom->GetWestRoom();
								waySelected = true;
							}
							else
							{
								std::cout << "there is nothing to the west \n";
							}
						}
						else if (command == "back" || command == "b")
						{
							waySelected = true;
						}
						else
						{
							std::cout << "cant go " << command << std::endl;
						}
					}

				}
				//LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING LOOKING
				else if (command == "look" || command == "l")
				{
					std::cout << "[here] " << currRoom->GetTitle() << std::endl;
					LookAroundPlus();
					bool waySelected = false;
					while (waySelected == false)
					{
						std::cout << "at what";
						getline(std::cin, command);
						if (command == "here" || command == "h")
						{
							std::cout << std::endl << currRoom->GetTitle() << ": " << currRoom->GetDescription() << std::endl;
							waySelected = true;
						}

						else if (command == "back" || command == "b")
						{
							waySelected = true;
						}
						else
						{
							bool foundThing = false;
							std::list<NPC*> NPCListCoppy = currRoom->GetNPCS();
							while (NPCListCoppy.size() > 0)
							{
								if (command == NPCListCoppy.front()->GetName() || (command.length() == 1 && NPCListCoppy.front()->GetName().at(0) == command.at(0)))
								{
									NPCListCoppy.front()->PrintBio();

									foundThing = true;
								}
								NPCListCoppy.pop_front();
							}
							std::list<Item*> itemListCopy = currRoom->GetItems();
							while (itemListCopy.size() > 0)
							{
								if (command == itemListCopy.front()->GetName() || (command.length() == 1 && itemListCopy.front()->GetName().at(0) == command.at(0)))
								{
									std::cout << itemListCopy.front()->GetDescription();

									foundThing = true;
								}
								itemListCopy.pop_front();
							}
							if (foundThing == false)
							{
								std::cout  << "error\n\n";
							}
						}
					}
				}
				//BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG BAG
				else if (command == "bag" || command == "b" || command == "item" || command == "inventory")
				{	bool optionPicked = false;
					while (optionPicked == false)
					{
						bool itemPicked = false;
						std::cout << "[look] [use]";
						std::cout << "what yould you like to in your bag?: ";
						getline(std::cin, command);
						if (command == "use" || command == "u")
						{
							while (itemPicked == false) {
								human->PrintInventory();
								std::cout << "what would you like to use?: ";
								getline(std::cin, command);
								if (human->UseItem(command))
								{
									itemPicked = true;
								}
								else if (command == "back" || command == "b")
								{
									itemPicked = true;

								}
								else
								{
									std::cout << "you do not have any " << command << std::endl;
								}
							}
						}
						else if (command == "look" || command == "l")
						{
							while (itemPicked == false) {
								human->PrintInventory();
								std::cout << "what item would you like to look at?: ";
								getline(std::cin, command);
								if (human->LookItem(command) == true)
								{
									itemPicked = true;
									std::cout << std::endl << std::endl;
								}
								else if (command == "back" || command == "b")
								{
									itemPicked = true;
								}
								else
								{
									std::cout << "\nerror could not find \n" << command << std::endl;
								}

							}
						}
						else if (command == "back" || command == "b")
						{
							optionPicked = true;
						}
						else
						{
							std::cout << "\nrepeat command\n";
						}

					}
				}
				//TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK TALK
				else if (command == "speak" || command == "s")
				{
					if (currRoom->GetNPCS().size() > 0)
					{
						currRoom->PrintNPCs();
						bool selection = false;
						while (selection == false)
						{
							std::cout << "speak with who? :";
							getline(std::cin, command);
							if (command == "back" || command == "b")
							{
								selection = true;
							}

							std::list<NPC*> NPCListCoppy = currRoom->GetNPCS();
							bool spoke = false;
							while (NPCListCoppy.size() > 0)
							{
								if (spoke == false && (command == NPCListCoppy.front()->GetName() || (command.length() == 1 && NPCListCoppy.front()->GetName().at(0) == command.at(0))))
								{
									spoke = true;
									NPCListCoppy.front()->TalkTo(human);
									selection = true;
								}
								NPCListCoppy.pop_front();

							}
							if (spoke == false) {

								std::cout << "Could not find that person\n";
							}

						}
					}
					else
					{
						std::cout << "there is no one so you just start talking hopeing someone chimes in";
					}



				}

				else if (command == "take" || command == "t")
				{
					if (currRoom->GetLooted() == false && currRoom->GetItems().size() > 0)
					{
						std::list<Item*> itemListCopy = currRoom->GetItems();
						while (itemListCopy.size() > 0)
						{

							human->AddItem(itemListCopy.front());
							std::cout << "you get " << itemListCopy.front()->GetName() << std::endl;
							itemListCopy.pop_front();
							if (itemListCopy.size() == 1)
							{
								std::cout << "and\n";
							}
						}
						currRoom->SetLooted(true);
					}
					else
					{
						std::cout << "nothing useful in here\n";
					}
				}
				else
				{
					std::cout << "error: invalad command!\n\n";
				}
			}
			
		}
		human->Heal(10000);
		human->SetAP(human->GetMaxAP());
		this->currRoom = this->currCheckpoint;
		gameOver = false;
	}

}

void GameWorld::LookAround()
{

	if (currRoom->GetNorthRoom() != nullptr)
	{
		std::cout << "[north]: " << currRoom->GetNorthRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetEastRoom() != nullptr) {
		std::cout << "[east]: " << currRoom->GetEastRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetSouthRoom() != nullptr)
	{
		std::cout << "[south]: " << currRoom->GetSouthRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetWestRoom() != nullptr)
	{
		std::cout << "[west]: " << currRoom->GetWestRoom()->GetTitle() << std::endl;
	}

}
void GameWorld::LookAroundPlus()
{

	if (currRoom->GetNorthRoom() != nullptr)
	{
		std::cout << "north: " << currRoom->GetNorthRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetEastRoom() != nullptr) {
		std::cout << "east: " << currRoom->GetEastRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetSouthRoom() != nullptr)
	{
		std::cout << "south: " << currRoom->GetSouthRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetWestRoom() != nullptr)
	{
		std::cout << "west: " << currRoom->GetWestRoom()->GetTitle() << std::endl;
	}
	if (currRoom->GetNPCS().size() > 0)
	{
		std::cout << "you also have company:\n";
		std::list<NPC*> NPCListCoppy =  currRoom->GetNPCS();
		while (NPCListCoppy.size() > 0)
		{
			std::cout << "[" << NPCListCoppy.front()->GetName() << "]    ";
			NPCListCoppy.pop_front();
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "you are alone\n";
	}
	if (currRoom->GetItems().size() > 0)
	{
		std::cout << "you see items on the ground\n";

		std::list<Item*> itemListCopy = currRoom->GetItems();
		while (itemListCopy.size() > 0)
		{
			std::cout << "[" << itemListCopy.front()->GetName() << "]    ";
			itemListCopy.pop_front();
		}
		std::cout << std::endl;

	}
	else
	{
		std::cout << "there are no items on the ground\n";
	}

}
void GameWorld::LinkRooms(Room * roomOne, Room * roomTwo, std::string direction)
{
	if (direction == "north" || direction == "n")
	{
		roomOne->SetNorthRoom(roomTwo);
		roomTwo->SetSouthRoom(roomOne);
	}
	else if (direction == "east" || direction == "e")
	{
		roomOne->SetEastRoom(roomTwo);
		roomTwo->SetWestRoom(roomOne);
	}
	else if (direction == "south" || direction == "s")
	{
		roomOne->SetSouthRoom(roomTwo);
		roomTwo->SetNorthRoom(roomOne);
	}
	else if (direction == "west" || direction == "w")
	{
		roomOne->SetWestRoom(roomTwo);
		roomTwo->SetEastRoom(roomOne);
	}
	else
	{
		std::cout << "Error: GameWorld could not find a direction : " << direction << std::endl;
	}
}

Room* GameWorld::GetCurrRoom()
{
	return this->currRoom;
}

void GameWorld::SetCurrRoom(Room * room)
{
	this->currRoom = room;
}