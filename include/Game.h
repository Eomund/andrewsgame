#include "helper.h"        
#include "Unit.h"


struct Square{
	int terr;
	int unit;

};
	
class Game{

public:
	Game(GameType*, string, string);
	
	~Game();
private:
	GameType* type;
	vector< vector<int> > map;
	vector<Unit> units;
	int width;
	int height;
	vector<Terrain> terrs;
	void loadTerrains(string);
	void loadMap(string);
	
};
