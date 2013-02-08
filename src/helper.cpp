#include "helper.h"
#include <fstream>

using namespace std;



void removeComment(string & line){
	int pos = line.find(';');
	if(pos >= 0){
		line = line.substr(0, pos);
	}
	trim(line);
}


void loadGameTypes(){
	
	//Built in types
	gameTypes.push_back(GameType("Elimination", [](){return 0;}	));
	
	//User types
}





