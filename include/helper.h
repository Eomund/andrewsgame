#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;
using namespace std;

struct GameType{
	string name;
	int (* win)();
	GameType(string n, int (* w)()){
		name = n;
		win = w;
	}
};

struct Terrain{
	string name;
	char mark;
	bool blocksLOS;
	bool blocksMovement;

	Terrain(vector<string> input){
		for(vector<string>::iterator it = input.begin(); it != input.end(); it++){
			trim(*it);
		}
		name = input[0];
		mark = input[1][0];
		to_upper(input[2]);
		if(input[2] == "TRUE"){
			blocksLOS = true;
		}
		
		if(input[3] == "TRUE"){
			blocksMovement= true;
		}
	}
};

extern vector<GameType> gameTypes;


void loadGameTypes();

void removeComment(string &);
