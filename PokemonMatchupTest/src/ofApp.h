#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <string>
#include <vector>

class Pokemon {
public:
	string name, type[2], PokeimgURL, HP, Atk, Def, SpAtk, SpDef, Spd;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void getData(string search);
		void getPokemon();
		void typeWeakness(vector <Pokemon> Mon);

		ofRectangle BtnBack, BtnFor, BtnSel, BtnMenu, BtnSearch, BtnTeam, BtnStats, BtnOff;
		vector<Pokemon> PokeList;
		vector<string> Resistances;
		vector<string> Weaknesses;
		vector<string> Immunity;
		int DamageStore;
		vector<int> DamageChart;
		vector<string>DefMatchup;
		int cnt;
		Pokemon CurrPokemon;
		enum class States{MENU, SEARCH, TEAM, STATS};
		States state;
		ofxJSONElement json;
		string search;
		string lastSearch;
		int Position;
		int Xpos;
		int Ypos;
		ofSoundPlayer PokeSound;
		ofSoundPlayer AddSound;
		ofTrueTypeFont TitleFont;
		ofTrueTypeFont PokeFont;
		ofTrueTypeFont ButtonFont;
		ofTrueTypeFont MatchupFont;

		//Variables to make pokemon object
		string name, type[2], HP, Atk, Def, SpAtk, SpDef, Spd;
		string PokeImgURL;
		ofImage PokeImg;
		int AvgHP, AvgAtk, AvgDef, AvgSpAtk, AvgSpDef, AvgSpd;
		
};
