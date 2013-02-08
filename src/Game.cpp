#include "Game.h"
#include <fstream>
using namespace std;

Game::Game(GameType* t, string terrfile, string m){
	type = t;
	loadTerrains(terrfile);
	loadMap(m);
	
}


void Game::loadTerrains(string filename){
	ifstream terrFile;
	terrFile.open(filename);
	if(!terrFile.is_open()){
		cout << "Error: could not find terrain file: " << filename << endl;
		exit(0);
	}else{
		
		
		while(terrFile.good()){
			
			string line;
			getline(terrFile, line);
			
			removeComment(line);
			if(line != ""){
				vector<string> parts;
				split(parts, line, boost::is_any_of(","));
				
				if(parts.size() != 4){
					cout << "Warning: unable to read terrain: " << line << endl;
					continue;
				}else{
					terrs.push_back(Terrain(parts));
				}
			}
			
		}
		
		if(terrs.size() == 0){
			cout << "Error: no terrains found" << endl;
			exit(0);
		}
		
	}

}

void Game::loadMap(string mapFilename){	
	ifstream mapFile;
	mapFile.open(mapFilename);
	if(!mapFile.is_open()){
		cout << "Error: could not find map file: " << mapFilename << endl;
		exit(0);
	}else{
		
		int lineCount = 0;
		int numItems;

		
		while(mapFile.good()){
			
			string line;
			getline(mapFile, line);
			
			removeComment(line);
			if(line != ""){
				if(lineCount == 0){
					numItems = atoi(line.c_str());
					
				}else if(lineCount < numItems + 1){
					Unit::createUnits(line);
					
				}else if(lineCount == numItems + 1){
					width = atoi(line.c_str());
				}else if(lineCount == numItems + 2){
					height = atoi(line.c_str());
				}else{
					vector<int> row;
					for(int i = 0; i < line.size(); i++){
						bool found = false;
						for(int j = 0; j < terrs.size(); j++){
							if(line[i] == terrs[j].mark){
								row.push_back(j);
								found = true;
								break;
							}
						}
						
						if(!found){
							cout << "Warning: terrain not found for symbol: " << line[i] << endl;
							row.push_back(0);
						}
					}
					map.push_back(row);	
						
				}
					
				
				lineCount++;
			}
			
		}
		
		
	}
}

Game::~Game(){
	
};
