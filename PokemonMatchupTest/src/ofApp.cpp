#include "ofApp.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	state = States::MENU;
	TitleFont.load("Pokemon Solid.ttf", 90);
	PokeFont.load("Pokemon Solid.ttf", 40);//some pokemon names were too long when using the 90 font size
	ButtonFont.load("PixeloidSans.ttf", 20);
	MatchupFont.load("PixeloidSans.ttf", 13);//Two different font sizes were needed so all the type matchup text could fit
	PokeSound.load("general.wav");
	AddSound.load("menu.wav");

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (state == States::MENU) {
		ofBackground(255);
		BtnSearch.set(100, 500, 350, 50);
		BtnTeam.set(550, 500, 350, 50);
		BtnOff.set(50, 50, 100, 50);
		ofSetColor(0, 255, 0);
		ofDrawRectangle(BtnSearch);
		if (size(PokeList) == 0) {
			ofSetColor(170);
		}
		ofDrawRectangle(BtnTeam);
		ofSetColor(0, 255, 255);
		ofDrawRectangle(BtnOff);
		ofSetColor(0);
		TitleFont.drawString("Pokemon", 250, 200);
		TitleFont.drawString("Stat Reviewer", 100, 330);
		ButtonFont.drawString("Search", 230, 530);
		ButtonFont.drawString("Team", 680, 530);
		ButtonFont.drawString("Exit", 60, 90);
	}
	else if (state == States::SEARCH) {
		if (CurrPokemon.type[0] == "grass") {//Checks the primary type of the current pokemon to determine the background colour
			ofBackground(64, 161, 41);//The colours chosen are the colours used for the types in the games
		}
		else if (CurrPokemon.type[0] == "bug") {
			ofBackground(145, 161, 25);
		}
		else if (CurrPokemon.type[0] == "dark") {
			ofBackground(98, 77, 78);
		}
		else if (CurrPokemon.type[0] == "dragon") {
			ofBackground(80,96,225);
		}
		else if (CurrPokemon.type[0] == "electric") {
			ofBackground(250,192,00);
		}
		else if (CurrPokemon.type[0] == "fairy") {
			ofBackground(239, 112, 239);
		}
		else if (CurrPokemon.type[0] == "fighting") {
			ofBackground(255, 128, 00);
		}
		else if (CurrPokemon.type[0] == "fire") {
			ofBackground(230, 40, 41);
		}
		else if (CurrPokemon.type[0] == "flying") {
			ofBackground(129, 185, 239);
		}
		else if (CurrPokemon.type[0] == "ghost") {
			ofBackground(112, 65, 112);
		}
		else if (CurrPokemon.type[0] == "ground") {
			ofBackground(145, 81, 33);
		}
		else if (CurrPokemon.type[0] == "ice") {
			ofBackground(61, 206, 243);
		}
		else if (CurrPokemon.type[0] == "normal") {
			ofBackground(159, 161, 159);
		}
		else if (CurrPokemon.type[0] == "poison") {
			ofBackground(145, 65, 203);
		}
		else if (CurrPokemon.type[0] == "psychic") {
			ofBackground(239, 65, 121);
		}
		else if (CurrPokemon.type[0] == "rock") {
			ofBackground(175, 169, 129);
		}
		else if (CurrPokemon.type[0] == "steel") {
			ofBackground(96, 161, 184);
		}
		else if (CurrPokemon.type[0] == "water") {
			ofBackground(41, 128, 239);
		}
		ofSetColor(0);
		ButtonFont.drawString(search, 350, 520);
		PokeFont.drawString(CurrPokemon.name, 250, 110);
		ButtonFont.drawString(CurrPokemon.type[0], 320, 200);
		ButtonFont.drawString(CurrPokemon.type[1], 470, 200);
		ButtonFont.drawString("HP = " + CurrPokemon.HP, 620, 280);
		ButtonFont.drawString("Atk = " + CurrPokemon.Atk, 620, 320);
		ButtonFont.drawString("Def = " + CurrPokemon.Def, 620, 360);
		ButtonFont.drawString("SpAtk = " + CurrPokemon.SpAtk, 620, 400);
		ButtonFont.drawString("SpDef = " + CurrPokemon.SpDef, 620, 440);
		ButtonFont.drawString("Spd = " + CurrPokemon.Spd, 620, 480);
		ButtonFont.drawString("For forms, enter 'Name-Form'", 300, 650);//Usability testing indicated that users could not work out how to enter pokemon forms, so I included an explanation in the program to improve usability.
		ofSetColor(255);
		PokeImg.draw(300, 200, 300, 300);
		BtnSel.set(300, 550, 300, 50);
		BtnMenu.set(50, 50, 100, 50);
		if (size(PokeList) < 6) {
			ofSetColor(255, 0, 255);
		}
		else {
			ofSetColor(170);
		}
		ofDrawRectangle(BtnSel);
		ofSetColor(0, 255, 255);
		ofDrawRectangle(BtnMenu);
		ofSetColor(0);
		ButtonFont.drawString("Add Pokemon", 355, 580);
		ButtonFont.drawString("Menu", 60, 90);
	}
	else if (state == States::TEAM) {
		if (PokeList[Position].type[0] == "grass") {
			ofBackground(64, 161, 41);
		}
		else if (PokeList[Position].type[0] == "bug") {
			ofBackground(145, 161, 25);
		}
		else if (PokeList[Position].type[0] == "dark") {
			ofBackground(98, 77, 78);
		}
		else if (PokeList[Position].type[0] == "dragon") {
			ofBackground(80, 96, 225);
		}
		else if (PokeList[Position].type[0] == "electric") {
			ofBackground(250, 192, 00);
		}
		else if (PokeList[Position].type[0] == "fairy") {
			ofBackground(239, 112, 239);
		}
		else if (PokeList[Position].type[0] == "fighting") {
			ofBackground(255, 128, 00);
		}
		else if (PokeList[Position].type[0] == "fire") {
			ofBackground(230, 40, 41);
		}
		else if (PokeList[Position].type[0] == "flying") {
			ofBackground(129, 185, 239);
		}
		else if (PokeList[Position].type[0] == "ghost") {
			ofBackground(112, 65, 112);
		}
		else if (PokeList[Position].type[0] == "ground") {
			ofBackground(145, 81, 33);
		}
		else if (PokeList[Position].type[0] == "ice") {
			ofBackground(61, 206, 243);
		}
		else if (PokeList[Position].type[0] == "normal") {
			ofBackground(159, 161, 159);
		}
		else if (PokeList[Position].type[0] == "poison") {
			ofBackground(145, 65, 203);
		}
		else if (PokeList[Position].type[0] == "psychic") {
			ofBackground(239, 65, 121);
		}
		else if (PokeList[Position].type[0] == "rock") {
			ofBackground(175, 169, 129);
		}
		else if (PokeList[Position].type[0] == "steel") {
			ofBackground(96, 161, 184);
		}
		else if (PokeList[Position].type[0] == "water") {
			ofBackground(41, 128, 239);
		}
		ofSetColor(0);
		PokeFont.drawString(PokeList[Position].name, 250, 110);
		ButtonFont.drawString(PokeList[Position].type[0], 320, 200);
		ButtonFont.drawString(PokeList[Position].type[1], 470, 200);
		ButtonFont.drawString("HP = " + PokeList[Position].HP, 650, 280);
		ButtonFont.drawString("Atk = " + PokeList[Position].Atk, 650, 320);
		ButtonFont.drawString("Def = " + PokeList[Position].Def, 650, 360);
		ButtonFont.drawString("SpAtk = " + PokeList[Position].SpAtk, 650, 400);
		ButtonFont.drawString("SpDef = " + PokeList[Position].SpDef, 650, 440);
		ButtonFont.drawString("Spd = " + PokeList[Position].Spd, 650, 480);
		ofSetColor(255);
		PokeImg.load(PokeList[Position].PokeimgURL);
		PokeImg.draw(300, 200, 300, 300);
		BtnSel.set(300, 550, 300, 50);
		BtnMenu.set(50, 50, 100, 50);
		BtnBack.set(100, 600, 200, 50);
		BtnFor.set(600, 600, 200, 50);
		BtnStats.set(300, 650, 300, 50);
		ofSetColor(255, 0, 255);
		ofDrawRectangle(BtnSel);
		ofSetColor(0, 255, 255);
		ofDrawRectangle(BtnMenu);
		if (Position == 0) {
			ofSetColor(170);
		}
		ofDrawRectangle(BtnBack);
		if (Position == size(PokeList)-1) {
			ofSetColor(170);
		}
		else {
			ofSetColor(0, 255, 255);
		}
		ofDrawRectangle(BtnFor);
		ofSetColor(0, 255, 255);
		ofDrawRectangle(BtnStats);
		ofSetColor(0);
		ButtonFont.drawString("Menu", 60, 90);
		ButtonFont.drawString("Remove Pokemon", 330, 590);
		ButtonFont.drawString("Back", 130, 640);
		ButtonFont.drawString("Forward", 620, 640);
		ButtonFont.drawString("View Stats", 350, 690);
	}
	else if (state == States::STATS) {
		BtnMenu.set(50, 50, 100, 50);
		BtnTeam.set(300, 600, 300, 50);
		ofSetColor(0, 255, 255);
		ofDrawRectangle(BtnMenu);
		ofDrawRectangle(BtnTeam);
		ofSetColor(0);
		ButtonFont.drawString("Menu", 60, 90);
		ButtonFont.drawString("Return to Pokemon", 310, 640);
		ButtonFont.drawString("Average team HP = " + ofToString(AvgHP), 650, 280);
		ButtonFont.drawString("Average team Atk = " + ofToString(AvgAtk), 650, 320);
		ButtonFont.drawString("Average team Def = " + ofToString(AvgDef), 650, 360);
		ButtonFont.drawString("Average team SpAtk = " + ofToString(AvgSpAtk), 650, 400);
		ButtonFont.drawString("Average team SpDef = " + ofToString(AvgSpDef), 650, 440);
		ButtonFont.drawString("Average team Spd = " + ofToString(AvgSpd), 650, 480);
		Xpos = 50;
		Ypos = 160;
		for (int i = 0; i < 18; i++) {
			if (i % 2 == 0) {//Allows me to set up two columns of text without manually placing every type
				Xpos = 50;
				Ypos += 40;
			}
			else {
				Xpos += 300;
			}
			MatchupFont.drawString(json["results"][i]["name"].asString() + " is " + DefMatchup[i], Xpos, Ypos);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (state == States::SEARCH) {
		if (isalpha(key)||isdigit(key)||key==' '||key=='-') {//Allows numbers, letters, hyphens and spaces to be entered, enabling all pokemon names
			ofUTF8Append(search, key);
			PokeSound.play();
		}
		else if (key==OF_KEY_RETURN) {
			getData(ofToLower(search));//all the data in the api is lowercase so this ensures that the user input is interpreted correctly
			lastSearch = search;
			search = "";
			AddSound.play();
		}
		else if (key == OF_KEY_BACKSPACE) {
			search = "";
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (state == States::MENU) {
		if (BtnSearch.inside(x, y)) {
			PokeSound.play();
			state = States::SEARCH;
			getData("bulbasaur");//I chose to make the program automatically load in bulbasaur so that it ouldn't need an extra state for before a pokemon has been searched
		}
		else if (BtnTeam.inside(x, y) && size(PokeList)>0) {
			Position = 0;
			state = States::TEAM;
			PokeSound.play();
		}
		else if (BtnOff.inside(x, y)) {
			//cout << "i" << endl;
			abort();//While abort is a messy way to end the program, I was unable to make exit work so I had to use it
			//cout << "i" << endl;
		}//When running into errors during testing, I would add cout functions to test what the error was. Whie I removed a few of them immediately after the test was done, I've commented out any that I didn't remove to act as evidence of testing.
	}
	if (state == States::SEARCH|| state == States::TEAM||state==States::STATS){
		if (BtnMenu.inside(x, y)) {
			state = States::MENU;
			PokeSound.play();
		}
	}
	if (state == States::TEAM) {
		if (BtnStats.inside(x, y)) {
			PokeSound.play();
			AvgHP = 0;//If the averages aren't set to 0 beforehand, reloading the stats page will cause the averages to become higher than intended
			AvgAtk = 0;
			AvgDef = 0;
			AvgSpAtk = 0;
			AvgSpDef = 0;
			AvgSpd = 0;
			for (int i = 0; i < size(PokeList); i++) {
				AvgHP += ofToInt(PokeList[i].HP);
				cout << AvgHP << endl;
				AvgAtk += ofToInt(PokeList[i].Atk);
				AvgDef += ofToInt(PokeList[i].Def);
				AvgSpAtk += ofToInt(PokeList[i].SpAtk);
				AvgSpDef += ofToInt(PokeList[i].SpDef);
				AvgSpd += ofToInt(PokeList[i].Spd);
			}
			//cout << size(PokeList) << endl;
			AvgHP = AvgHP / size(PokeList);
			//cout << AvgHP << endl;
			AvgAtk = AvgAtk / size(PokeList);
			AvgDef = AvgDef / size(PokeList);
			AvgSpAtk = AvgSpAtk / size(PokeList);
			AvgSpDef = AvgSpDef / size(PokeList);
			AvgSpd = AvgSpd / size(PokeList);
			typeWeakness(PokeList);
			state = States::STATS;
		}
		else if (BtnBack.inside(x, y) && Position > 0) {
			Position -= 1;
			PokeSound.play();
		}
		else if (BtnFor.inside(x, y) && Position < size(PokeList)-1) {
			Position += 1;
			PokeSound.play();
		}
		else if (BtnSel.inside(x, y)) {
			AddSound.play();
			PokeList.erase(PokeList.begin() + Position);
			if (size(PokeList) == 0) {
				state = States::MENU;
			}
			else if (Position > 0) {
				Position -= 1;
			}
		}
	}
	if (state == States::SEARCH) {
		if (BtnSel.inside(x, y) && size(PokeList)<6) {
			PokeList.push_back(CurrPokemon);
			//cout << PokeList[0].name << endl;
			//cout << CurrPokemon.type[0] << endl;
			AddSound.play();
		}
	}
	if (state == States::STATS) {
		if (BtnTeam.inside(x, y)) {
			Position = 0;
			state = States::TEAM;
			PokeSound.play();
		}
	}
}

//--------------------------------------------------------------
void ofApp::getData(string search) {
	for (int i = 0;i < size(search);i++) {
		if (search[i] == ' ') {
			search.replace(i, 1, "-" );//Since the API replaces spaces with hyphens, I did the same
		}
	}
	json.open("https://pokeapi.co/api/v2/pokemon/" + search);//opens a pokemon in the API based on user input
	//cout << json.getRawString() << endl;
	getPokemon();
}
//--------------------------------------------------------------
void ofApp::getPokemon() {
	name = json["name"].asString();
	PokeImgURL= json["sprites"]["front_default"].asString();
	PokeImg.load(PokeImgURL);
	type[0] = json["types"][0]["type"]["name"].asString();
	//cout << type[0] << endl;
	if (json["types"].isValidIndex(1)) {//I had to check if there were multiple type indexes so I could know if the pokemon was monotype or not
		type[1] = json["types"][1]["type"]["name"].asString();
	}
	else {
		type[1] = "";
	}
	HP = json["stats"][0]["base_stat"].asString();//Trying to store these as integers kept on causing errors so I instead stored them as strings and converted them to integers when needed
	Atk = json["stats"][1]["base_stat"].asString();
	Def = json["stats"][2]["base_stat"].asString();
	SpAtk = json["stats"][3]["base_stat"].asString();
	SpDef = json["stats"][4]["base_stat"].asString();
	Spd = json["stats"][5]["base_stat"].asString();
	CurrPokemon.name = name;
	CurrPokemon.PokeimgURL = PokeImgURL; 
	CurrPokemon.type[0] = type[0];
	CurrPokemon.type[1] = type[1];
	CurrPokemon.HP = HP;
	CurrPokemon.Atk = Atk;
	CurrPokemon.Def = Def;
	CurrPokemon.SpAtk = SpAtk;
	CurrPokemon.SpDef = SpDef;
	CurrPokemon.Spd = Spd;
}
void ofApp::typeWeakness(vector <Pokemon> Monlist) {
	DamageChart = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };//Unlike other placeholder lists, I want to directly increment and decrement the variables so I need to set it equal to 18 0s instead of just clearing the list
	for (int i = 0;i < size(Monlist);i++) {
		DamageStore = 0;
		Weaknesses.clear();
		Resistances.clear();
		json.open("https://pokeapi.co/api/v2/type/" + Monlist[i].type[0]);
		for (int i = 0;i < size(json["damage_relations"]["double_damage_from"]);i++) {
			Weaknesses.push_back(json["damage_relations"]["double_damage_from"][i]["name"].asString());//Writes the contents of the vector in the API into the program so I can work with it
			//cout << Weaknesses[i]<<endl;
		}
		for (int i = 0;i < size(json["damage_relations"]["half_damage_from"]);i++) {
			Resistances.push_back(json["damage_relations"]["half_damage_from"][i]["name"].asString());
			//cout << Resistances[i] << endl;
		}
		for (int i = 0;i < size(json["damage_relations"]["no_damage_from"]);i++) {
			Immunity.push_back(json["damage_relations"]["no_damage_from"][i]["name"].asString());
			//cout << Immunity[i] << endl;
		}
		if (Monlist[i].type[1] != "") {//Prevents this code running for monotyped pokemon
			json.open("https://pokeapi.co/api/v2/type/" + Monlist[i].type[1]);
			for (int i = 0;i < size(json["damage_relations"]["double_damage_from"]);i++) {
				Weaknesses.push_back(json["damage_relations"]["double_damage_from"][i]["name"].asString());
				//cout << Weaknesses[i] << endl;
			}
			for (int i = 0;i < size(json["damage_relations"]["half_damage_from"]);i++) {
				Resistances.push_back(json["damage_relations"]["half_damage_from"][i]["name"].asString());
			}
			for (int i = 0;i < size(json["damage_relations"]["no_damage_from"]);i++) {
				Immunity.push_back(json["damage_relations"]["no_damage_from"][i]["name"].asString());
			}
		}
		json.open("https://pokeapi.co/api/v2/type");
		//cout << "i" << endl;
		for (int i = 0; i < 18; i++) {
			DamageStore = 0;//Testing indicated that this value needed to be reset due to the value accumulating over time, causing the recorded types to become inaccurate
			cnt = count(Weaknesses.begin(), Weaknesses.end(), json["results"][i]["name"].asString());
			/*cout << cnt << endl;*/
			DamageStore -= cnt;
			/*cout << cnt << endl;*/
			cnt = count(Resistances.begin(), Resistances.end(), json["results"][i]["name"].asString());
			DamageStore += cnt;
			cnt = count(Immunity.begin(), Immunity.end(), json["results"][i]["name"].asString());
			DamageStore += (5 * cnt);//Ensures that if either type is immune to a damage type it will always be recorded as winning regardless of the other type
			//cout << DamageStore << endl;
			if (DamageStore > 0) {
				DamageChart[i]++;
			}
			else if (DamageStore < 0) {
				DamageChart[i]--;
			}
		}
	}
	DefMatchup = {};
	for (int i = 0; i < 18; i++) {
		//cout << DamageChart[i] << endl;
		if (DamageChart[i] > 0) {
			DefMatchup.push_back("a winning matchup");//During the testing, I found that if I tried setting DefMatchup[i] equal to the strings, it caused errors, causing me to push the content instead.
		}
		else if (DamageChart[i] == 0) {
			//cout << DamageChart[i] << endl;
			DefMatchup.push_back("a neutral matchup");
		}
		else if (DamageChart[i] < 0) {
			DefMatchup.push_back("a losing matchup");
		}
	}
}
