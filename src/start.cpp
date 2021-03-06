#include "Game.h"
#include <fstream>
using namespace std;


string defaultMap = "maps/default.agm";
int defaultType = 0;
string terrainFile = "terrs";

vector<GameType> gameTypes;



int getGameTypeNumber(string name){
	for(unsigned int i = 0; i < gameTypes.size(); i++){
		if(to_upper_copy(gameTypes[i].name) == to_upper_copy(name)){
			return i;
		}
	}
	cout << "Warning: Game type '" + name + "' not found." << endl; 
	return defaultType;
}


void processConfig(string line){
	//handles a line of the config file
	int pos = line.find('=');
	string name = line.substr(0, pos);
	string rule = line.substr(pos + 1);
	trim(name);
	trim(rule);
	to_upper(name);
	if(name == "MAP"){
		defaultMap = rule;
	}
	
	if(name == "TYPE"){
		defaultType = getGameTypeNumber(rule);
		
	}
	
	if(name == "TERRAINFILE"){
		terrainFile = rule;
	}
	
}

int main(int argc, char* argv[]){
	
	for(int i = 1; i < argc; i++){
		
		if(strcmp(argv[i], "-h") == 0){
			cout << "Usage: andrewsgame [options]" << endl << "-t\tspecify a game type" << endl  << "-m\tspecify a map";
			exit(0);
		}
	}
	loadGameTypes();
	if(gameTypes.size() == 0){
		cout << "Error: no game types loaded" << endl;
		exit(0);
	}
	
	ifstream conf;
	conf.open("config");
	string line;
	
	//Read the config file
	while ( conf.good() )
    {
      getline (conf,line);
      
      //Remove comments
      removeComment(line);
      
      //we don't need to process it if it is just a comment or blank line
      if(line != ""){
      	  processConfig(line);
      }
    }
	conf.close();
	
	//Read command line arguments
	//These will override the config file (if given)
	string map = defaultMap;
	int type = defaultType;
	
	for(int i = 1; i < argc; i++){
		
		if(strcmp(argv[i], "-t") == 0){
			if(i <= argc - 1){
				cout << "Error: no type given" << endl;
				exit(0);
			}else{
				type = getGameTypeNumber(argv[i + 1]);
			}
		}
		
		if(strcmp(argv[i], "-m") == 0){
			if(i <= argc - 1){
				cout << "Error: no map file given" << endl;
				exit(0);
			}else{
				map = argv[i + 1];
			}
		}
		
	}
	
	Game game (&gameTypes[type], terrainFile, map);
}



