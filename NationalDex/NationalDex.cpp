// NationalDex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Move.h"
#include "Pokemon.h"
#include "Weakness.h"
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <vector>

float StrToFloat(std::string _str);
int StrToInt(std::string _str);
bool StrToBool(std::string _str);

int main()
{
	// Open file & populate Pokedex with Pokemon 
	std::unordered_map<int, Pokemon*> NationalDex;
	std::ifstream pokemonFile("pokemon.csv");
	std::string line;
	while (std::getline(pokemonFile, line)) {
		std::istringstream iss(line);
		std::string lineStream;

		std::vector<std::string> strVec;

		while (std::getline(iss, lineStream, ',')) {
			strVec.push_back(lineStream);
		}

		Pokemon* currPokemon = new Pokemon();

		// Set Ability
		currPokemon->mAbility = strVec[0];

		// Set Weaknesses
		currPokemon->mWeakness.against_bug = stof(strVec[1]);
		currPokemon->mWeakness.against_dark = stof(strVec[2]);
		currPokemon->mWeakness.against_dragon = stof(strVec[3]);
		currPokemon->mWeakness.against_electric = stof(strVec[4]);
		currPokemon->mWeakness.against_fairy = stof(strVec[5]);
		currPokemon->mWeakness.against_fight = stof(strVec[6]);
		currPokemon->mWeakness.against_fire = stof(strVec[7]);
		currPokemon->mWeakness.against_flying = stof(strVec[8]);
		currPokemon->mWeakness.against_ghost = stof(strVec[9]);
		currPokemon->mWeakness.against_grass = stof(strVec[10]);
		currPokemon->mWeakness.against_ground = stof(strVec[11]);
		currPokemon->mWeakness.against_ice = stof(strVec[12]);
		currPokemon->mWeakness.against_normal = stof(strVec[13]);
		currPokemon->mWeakness.against_poison = stof(strVec[14]);
		currPokemon->mWeakness.against_psychic = stof(strVec[15]);
		currPokemon->mWeakness.against_rock = stof(strVec[16]);
		currPokemon->mWeakness.against_steel = stof(strVec[17]);
		currPokemon->mWeakness.against_water = stof(strVec[18]);

		// Set Attack
		currPokemon->mBaseAttack = stoi(strVec[19]);

		// Set Classification
		currPokemon->mClassification = strVec[20];

		// Set Defense
		currPokemon->mBaseDefense = stoi(strVec[21]);

		// Set Height
		currPokemon->mHeight = stof(strVec[22]);

		// Set HP
		currPokemon->mBaseHealth = stoi(strVec[23]);

		// Set Name
		currPokemon->mName = strVec[24];

		// Set Gender Percentage
		currPokemon->mMalePercentage = stof(strVec[25]);
		currPokemon->mFemalePercentage = 100 - currPokemon->mMalePercentage;

		// Pokedex #
		currPokemon->mPokedexNumber = stoi(strVec[26]);

		// Set Special ATK
		currPokemon->mBaseSpecialAttack = stoi(strVec[27]);

		// Set Special DEF
		currPokemon->mBaseSpecialDefense = stoi(strVec[28]);

		// Set Speed
		currPokemon->mBaseSpeed = stoi(strVec[29]);

		// Set Type1
		currPokemon->mType1 = strVec[30];

		// Set Type2
		currPokemon->mType2 = strVec[31];

		// Set Weight
		currPokemon->mWeight = stof(strVec[32]);

		// Set Generation
		currPokemon->mGeneration = stoi(strVec[33]);

		// Set Legendary Status
		currPokemon->isLegendary = StrToBool(strVec[34]);

		// Set Capture Rate
		currPokemon->mCaptureRate = stoi(strVec[35]);


		// Insert Pokemon into Pokedex 
		std::pair<int, Pokemon*> currPair(currPokemon->mPokedexNumber, currPokemon);
		NationalDex.insert(currPair);
		NationalDex.find(currPokemon->mPokedexNumber)->second->Display();
	}
	pokemonFile.close();


}

// Methods
float StrToFloat(std::string _str) {
	return stof(_str);
}
int StrToInt(std::string _str) {
	return stoi(_str);
}
bool StrToBool(std::string _str) {
	int number = stoi(_str);
	if (number == 1)
		return true;
	else
		return false;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
