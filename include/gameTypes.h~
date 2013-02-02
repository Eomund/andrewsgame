#include <vector>
#include <iostream>
using namespace std;

struct gameType{
	string name;
	int (* win)();
	gameType(string n, int (* w)()){
		name = n;
		win = w;
	}
};



extern vector<gameType> gameTypes;

void setupTypes();
