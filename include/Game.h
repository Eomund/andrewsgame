#include "gameTypes.h"                                                     

class Game{

public:
	Game(gameType* t, string n);
	
	~Game();
private:
	gameType* type;
	string name;
};
