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
#include <time.h>
#include <chrono>
#include <thread>

float StrToFloat(std::string _str); // convert a string to a boolean
int StrToInt(std::string _str); // convert a string 
bool StrToBool(std::string _str);
Move GenerateMove(Pokemon* _pokemon, std::unordered_map<int,Move> _movesDex);
std::string ToUpper(std::string _str);
void NationalPokedexNameArt();
void PokemonLogoArt();
int DisplayMainMenu();
void PikachuArt();
void BulbasaurArt();
void CharmanderArt();
void SquirtleArt();
void LearnNewMove(Pokemon* _pokemon, std::unordered_map<int, Move> _movesDex);
void BattleWildPokemon(Pokemon* _pokemon, std::unordered_map<int, Pokemon*> _pokedex);
void GenerateHPVisual(int _hp, Pokemon* _pokemon);
int CalculateDamage(Move _move, Pokemon* _pokemon1, Pokemon* _pokemon2);
float WeaknessFactor(Pokemon* _pokemon, Move _move);
bool CatchPokemon(Pokemon* _pokemon);

// Main
int main()
{
#if 1 // Filling Pokedex & Movedex
#pragma region
	// Open file & populate Movedex with Moves
	std::unordered_map<int, Move> MovesDex;
	std::ifstream movesFile("moves.csv");
	std::string currline;
	int moveID = 1;
	while (std::getline(movesFile, currline)) {
		std::istringstream iss(currline);
		std::string lineStream;

		std::vector<std::string> strVector;

		while (std::getline(iss, lineStream, ',')) {
			strVector.push_back(lineStream);
		}

		Move currMove;

		currMove.mName = strVector[0];
		currMove.mType = ToUpper(strVector[1]);
		currMove.mCategory = ToUpper(strVector[2]);
		currMove.mPower = stoi(strVector[3]);
		currMove.mAccuracy = stof(strVector[4]);
		currMove.mNotes = strVector[5];
		currMove.mMoveID = moveID;
		moveID++;

		// Insert Move into Movedex 
		std::pair<int, Move> currPair(currMove.mMoveID, currMove);
		MovesDex.insert(currPair);
	}
	movesFile.close();
#pragma endregion MovesDex

#pragma region
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
		currPokemon->mClassification = ToUpper(strVec[20]);

		// Set Defense
		currPokemon->mBaseDefense = stoi(strVec[21]);

		// Set Height
		currPokemon->mHeight = stof(strVec[22]);

		// Set HP
		currPokemon->mBaseHealth = stoi(strVec[23]);

		// Set Name
		currPokemon->mName = ToUpper(strVec[24]);

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
		currPokemon->mType1 = ToUpper(strVec[30]);

		// Set Type2
		currPokemon->mType2 = ToUpper(strVec[31]);

		// Set Weight
		currPokemon->mWeight = stof(strVec[32]);

		// Set Generation
		currPokemon->mGeneration = stoi(strVec[33]);

		// Set Legendary Status
		currPokemon->isLegendary = StrToBool(strVec[34]);

		// Set Capture Rate
		currPokemon->mCaptureRate = stoi(strVec[35]);

		// Generate Moves
		currPokemon->mMove1 = GenerateMove(currPokemon, MovesDex);
		currPokemon->mMove2 = GenerateMove(currPokemon, MovesDex);
		currPokemon->mMove3 = GenerateMove(currPokemon, MovesDex);
		currPokemon->mMove4 = GenerateMove(currPokemon, MovesDex);

		// Insert Pokemon into Pokedex 
		std::pair<int, Pokemon*> currPair(currPokemon->mPokedexNumber, currPokemon);
		NationalDex.insert(currPair);
		//NationalDex.find(currPokemon->mPokedexNumber)->second->Display();
	}
	pokemonFile.close();
#pragma endregion NationalDex
#endif


#pragma region
	system("Color 06");
	PokemonLogoArt();
	NationalPokedexNameArt();
	std::cout << "\t\t\tIncludes Pokemon from Generations I-VII!\n\n";
	std::cout << "\t\tDeveloper: Jonah Pickett\tVersion: 1.0 - 5/21/2022\n";
	std::cout << "\n\n\t\t\t";
	system("pause"); // Press any key to continue . . .
	system("Color 07");
#pragma endregion Title Screen

#pragma region
	Pokemon* myPokemon = nullptr;
	int starterSelection = -1;

	system("cls");
	std::cout << '\n';
	PikachuArt();
	std::cout << "\n 1.) Bulbasaur - The Seed Pokemon\n";
	std::cout << "\n 2.) Charmander - The Lizard Pokemon\n";
	std::cout << "\n 3.) Squirtle - The Tiny Turtle Pokemon\n";
	while (starterSelection < 1 || starterSelection > 3) {
		std::cout << "\n Please select your starter pokemon: ";
		std::cin >> starterSelection;
	}

	switch (starterSelection) {
	case 1:
		system("cls");
		std::cout << "\n\n\t\tYou Chose Bulbasaur!\n\n";
		BulbasaurArt();
		std::cout << "\n\t";
		myPokemon = NationalDex.find(1)->second;
		system("pause");
		break;
	case 2:
		system("cls");
		std::cout << "\n\n\tYou Chose Charmander!\n\n";
		CharmanderArt();
		std::cout << "\n\t";
		myPokemon = NationalDex.find(4)->second;
		system("pause");
		break;
	case 3: 
		system("cls");
		std::cout << "\n\n\tYou Chose Squirtle!\n\n";
		SquirtleArt();
		std::cout << "\n\t";
		myPokemon = NationalDex.find(7)->second;
		system("pause");
		break;
	}
	myPokemon->isCaught = true;
#pragma endregion Select Your Starter Pokemon

#pragma region
	system("cls");
	int selected = -1;

	while (selected != 0) {
		selected = DisplayMainMenu();
		int pokedexNo = -1; // used in case 1

		switch (selected) {
		case 0:
			system("pause");
			break;
		case 1: // Find Pokemon
			system("cls");
			while (pokedexNo < 1 || pokedexNo > 801) {
				std::cout << "\n\tPlease enter the pokedex number of the Pokemon you seek: ";
				std::cin >> pokedexNo;
			} 
			std::cout << "\n\n";
			NationalDex.find(pokedexNo)->second->Display();
			system("pause");
			break;
		case 2: // Visit Wild Area
			BattleWildPokemon(myPokemon, NationalDex);
			std::cout << "\n\n";
			system("pause");
			break;
		case 3: // Learn New Moves
			system("cls");
			std::cout << "\n\tYour current Pokemon is:\n";
			myPokemon->Display();
			LearnNewMove(myPokemon, MovesDex);
			system("pause");
			break;
		case 4: // Change Selected Pokemon
			system("cls");
			std::cout << "\n\tYour current Pokemon is:\n";
			myPokemon->Display();
			
			while (pokedexNo < 1 || pokedexNo > 801) {
				std::cout << "\n Enter the pokedex number of the pokemon you wish to change to: ";
				std::cin >> pokedexNo;
			}
			myPokemon = NationalDex.find(pokedexNo)->second;
			std::cout << "\n\tYour current Pokemon is now:\n";
			myPokemon->Display();
			system("pause");
			break;
		case 5: // My Pokemon
			system("cls");
			std::cout << "\n\t===== My Pokemon =====\n";
			myPokemon->Display();
			system("pause");
			break;
		}
	}

#pragma endregion Main Menu

	
	return 0;
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
Move GenerateMove(Pokemon* _pokemon, std::unordered_map<int, Move> _movesDex) {
	Move move;
	move = _movesDex.find(rand() % _movesDex.size() + 1)->second;  

	if (move.mMoveID == _pokemon->mMove1.mMoveID || move.mMoveID == _pokemon->mMove2.mMoveID || move.mMoveID == _pokemon->mMove3.mMoveID || move.mMoveID == _pokemon->mMove4.mMoveID)
		move = GenerateMove(_pokemon, _movesDex);

	return move;
}
std::string ToUpper(std::string _str) {
	for (int i = 0; i < _str.size() / (sizeof(char)); ++i)  
		_str.at(i) = std::toupper(_str.at(i));
	return _str;
}
int DisplayMainMenu() {
	std::string menuOptions[6] = { "\t1 - Find Pokemon", "\t2 - Visit the Wild Area", "\t3 - Learn New Moves", "\t4 - Change My Pokemon", "\t5 - My Pokemon", "\t0 - Exit" };
	int selection = -1;

	system("cls");
	NationalPokedexNameArt();
	PikachuArt();
	std::cout << "\n =+=+=+=+=+= Main Menu =+=+=+=+=+=\n\n";
	for (int i = 0; i < 6; ++i)
		std::cout << " " << menuOptions[i] << '\n';

	while (selection > 5 || selection < 0) {
		std::cout << "\n Please make your selection: ";
		std::cin >> selection;
	}

	return selection;
}
void LearnNewMove(Pokemon* _pokemon, std::unordered_map<int, Move> _movesDex) {
	int selection = -1;
	std::cout << " ========== Moves =========\n";
	std::cout << " Move1: " << _pokemon->mMove1.mName << "\n Move2: " << _pokemon->mMove2.mName << "\n Move3: " << _pokemon->mMove3.mName << "\n Move4: " << _pokemon->mMove4.mName << '\n';

	while (selection > 4 || selection < 1) {
		std::cout << " Which Move would you like to change? #";
		std::cin >> selection;
	}

	switch (selection) {
	case 1:
		_pokemon->mMove1 = GenerateMove(_pokemon, _movesDex);
		break;
	case 2:
		_pokemon->mMove2 = GenerateMove(_pokemon, _movesDex);
		break;
	case 3:
		_pokemon->mMove3 = GenerateMove(_pokemon, _movesDex);
		break;
	case 4:
		_pokemon->mMove4 = GenerateMove(_pokemon, _movesDex);
		break;
	}

	system("cls");
	std::cout << "\n\tYour current Pokemon is:\n";
	_pokemon->Display();
}
void BattleWildPokemon(Pokemon* _pokemon, std::unordered_map<int, Pokemon*> _pokedex) {
	system("cls");
	srand(time(NULL));
	int randomPokemon = rand() % 801 + 1;
	Pokemon* wildPokemon = _pokedex.find(randomPokemon)->second;
	std::cout << "\n  __      __.__.__       .___  ___________                                 __               ._." << '\n';
	std::cout << " /  \\    /  \\__|  |    __| _/  \\_   _____/ ____   ____  ____  __ __  _____/  |_  ___________| |" << '\n';
	std::cout << " \\   \\/\\/   /  |  |   / __ |    |    __)_ /    \\_/ ___\\/  _ \\|  |  \\/    \\   __\\/ __ \\_  __ \\ |" << '\n';
	std::cout << "  \\        /|  |  |__/ /_/ |    |        \\   |  \\  \\__(  <_> )  |  /   |  \\  | \\  ___/|  | \\/\\|" << '\n';
	std::cout << "   \\__/\\  / |__|____/\\____ |   /_______  /___|  /\\___  >____/|____/|___|  /__|  \\___  >__|   __" << '\n';
	std::cout << "        \\/                \\/           \\/     \\/     \\/                 \\/          \\/       \\/" << "\n\n";
	if (rand()  % 100 <= wildPokemon->mMalePercentage) {
		std::cout << "\tYou encountered a wild male " << wildPokemon->mName << "!\n";
	}
	else
		std::cout << "\tYou encountered a wild female " << wildPokemon->mName << "!\n";
	
	int healthPts = wildPokemon->mBaseHealth;
	bool skipBattle = false;
	while (healthPts > 0 && skipBattle == false) {
		GenerateHPVisual(healthPts, wildPokemon);
		std::cout << " ========== Moves =========\n";
		std::cout << " Move1: " << _pokemon->mMove1.mName << "\n Move2: " << _pokemon->mMove2.mName << "\n Move3: " << _pokemon->mMove3.mName << "\n Move4: " << _pokemon->mMove4.mName << "\n 0 - Back to Main Menu" << '\n';
		int move = -1;
		while (move < 0 || move > 4) {
			std::cout << " Please select your move: #";
			std::cin >> move;
		}
		switch (move) {
		case 0:
			healthPts = 0;
			skipBattle = true;
			break;
		case 1:
			healthPts -= CalculateDamage(_pokemon->mMove1, _pokemon, wildPokemon);
			break;
		case 2:
			healthPts -= CalculateDamage(_pokemon->mMove2, _pokemon, wildPokemon);
			break;
		case 3:
			healthPts -= CalculateDamage(_pokemon->mMove3, _pokemon, wildPokemon);
			break;
		case 4:
			healthPts -= CalculateDamage(_pokemon->mMove4, _pokemon, wildPokemon);
			break;
		}
	}
	system("Color 07");
	if (skipBattle != true) {
		std::cout << "\n\t" << wildPokemon->mName << " fainted! - You won!\n\tLet's try to catch it!\n";
		while (wildPokemon->isCaught == false) {
			wildPokemon->isCaught = CatchPokemon(wildPokemon);
			std::this_thread::sleep_for(std::chrono::seconds(1)); 
			if (wildPokemon->isCaught == false)
				std::cout << "\n\tThe wild " << wildPokemon->mName << " broke free!Let's try again!\n\t";
			else if (wildPokemon->isCaught == true)
				std::cout << "\n\tThe wild " << wildPokemon->mName << " was caught! Congrats!\n\t";
		}
	}
	
}
void GenerateHPVisual(int _hp, Pokemon* _pokemon) {
	std::cout << "\n\t" << _pokemon->mName << "'s Health Points:\n";
	for (int i = 0; i < _hp; ++i) {
		if (_hp > _pokemon->mBaseHealth * .65)
			system("Color 02");
		else if (_hp > _pokemon->mBaseHealth * .25)
			system("Color 06");
		else if (_hp < _pokemon->mBaseHealth * .25)
			system("Color 04");
		std::cout << " <> ";
		if (i % 15 == 0 && i != 0)
			std::cout << '\n';
	} 
	std::cout << "\n\n";
}
int CalculateDamage(Move _move, Pokemon* _pokemon1, Pokemon* _pokemon2) {
	int damage = 0;
	bool miss = true;
	if (rand() % 100 <= _move.mAccuracy * 100)
		miss = false;
	if (miss == false) {
		if (_move.mCategory == "PHYSICAL")
			damage = (_move.mPower / _pokemon2->mBaseDefense) * _pokemon1->mBaseAttack;
		else if (_move.mCategory == "SPECIAL")
			damage = (_move.mPower / _pokemon2->mBaseSpecialDefense) * _pokemon1->mBaseSpecialAttack;
	}
	damage = (damage * WeaknessFactor(_pokemon2, _move)) / 3;
	if (damage < 1)
		damage = 1;
	std::cout << "\n\tYou did " << damage << " damage!\n";
	return damage;
}
float WeaknessFactor(Pokemon* _pokemon, Move _move) {
	std::string moveType = ToUpper(_move.mType);

	if(moveType == "BUG")
		return _pokemon->mWeakness.against_bug;
	else if (moveType == "DARK")
		return _pokemon->mWeakness.against_dark;
	else if (moveType == "DRAGON")
		return _pokemon->mWeakness.against_dragon;
	else if(moveType == "ELECTRIC")
		return _pokemon->mWeakness.against_electric;
	else if (moveType == "FAIRY")
		return _pokemon->mWeakness.against_fairy;
	else if (moveType == "FIGHT")
		return _pokemon->mWeakness.against_fight;
	else if (moveType == "FIRE")
		return _pokemon->mWeakness.against_fire;
	else if (moveType == "FLYING")
		return _pokemon->mWeakness.against_flying;
	else if (moveType == "GHOST")
		return _pokemon->mWeakness.against_ghost;
	else if (moveType == "GRASS")
		return _pokemon->mWeakness.against_grass;
	else if (moveType == "GROUND")
		return _pokemon->mWeakness.against_ground;
	else if (moveType == "ICE")
		return _pokemon->mWeakness.against_ice;
	else if (moveType == "NORMAL")
		return _pokemon->mWeakness.against_normal;
	else if (moveType == "POISON")
		return _pokemon->mWeakness.against_poison;
	else if (moveType == "PSYCHIC")
		return _pokemon->mWeakness.against_psychic;
	else if (moveType == "ROCK")
		return _pokemon->mWeakness.against_rock;
	else if (moveType == "STEEL")
		return _pokemon->mWeakness.against_steel;
	else if (moveType == "WATER")
		return _pokemon->mWeakness.against_water;
}
bool CatchPokemon(Pokemon* _pokemon) {
	srand(time(NULL));
	int n = rand() % 150;
	if (n > _pokemon->mCaptureRate)
		return false;
	else {
		return true;
	}
}


// Art
void NationalPokedexNameArt() {
	std::cout << "\n     _   _       _   _                   _     ____       _            _           " << '\n';
	std::cout << "    | \\ | | __ _| |_(_) ___  _ __   __ _| |   |  _ \\ ___ | | _____  __| | _____  __" << '\n';
	std::cout << "    |  \\| |/ _` | __| |/ _ \\| '_ \\ / _` | |   | |_) / _ \\| |/ / _ \\/ _` |/ _ \\ \\/ /" << '\n';
	std::cout << "    | |\\  | (_| | |_| | (_) | | | | (_| | |   |  __/ (_) |   <  __/ (_| |  __/>  < " << '\n';
	std::cout << "    |_| \\_|\\__,_|\\__|_|\\___/|_| |_|\\__,_|_|   |_|   \\___/|_|\\_\\___|\\__,_|\\___/_/\\_\\" << '\n';
	std::cout << "                                                                                   " << '\n';
}
void PokemonLogoArt() {
	std::cout << "\n\t                                   ,'\\" << '\n';
	std::cout << "\t     _.----.        ____         ,'  _\\   ___    ___     ____" << '\n';
	std::cout << "\t _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << '\n';
	std::cout << "\t \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << '\n';
	std::cout << "\t  \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << '\n';
	std::cout << "\t    \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << '\n';
	std::cout << "\t     \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << '\n';
	std::cout << "\t      \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << '\n';
	std::cout << "\t       \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << '\n';
	std::cout << "\t        \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << '\n';
	std::cout << "\t         \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << '\n';
	std::cout << "\t                                 `'                            '-._|" << '\n';
}
void PikachuArt() {
	std::cout << "\n         \\:.             .:/ " << '\n';
	std::cout << "          \\``._________.''/  " << '\n';
	std::cout << "           \\             / " << '\n';
	std::cout << "   .--.--, / .':.   .':. \\ " << '\n';
	std::cout << "  /__:  /  | '::' . '::' | " << '\n';
	std::cout << "     / /   |`.   ._.   .'| " << '\n';
	std::cout << "    / /    |.'         '.| " << '\n';
	std::cout << "   /___-_-,|.\\  \\   /  /.| " << '\n';
	std::cout << "        // |''\\.;   ;,/ '| " << '\n';
	std::cout << "        `==|:=         =:| " << '\n';
	std::cout << "           `.          .' " << '\n';
	std::cout << "             :-._____.-: " << '\n';
	std::cout << "            `''       `'' " << '\n';
}
void BulbasaurArt() {
	std::cout << "\n                                            /" << '\n';
	std::cout << "                         _,.------....___,.' ',.-." << '\n';
	std::cout << "                      ,-'          _,.--\"        |" << '\n';
	std::cout << "                    ,'         _.-'              ." << '\n';
	std::cout << "                   /   ,     ,'                   `" << '\n';
	std::cout << "                  .   /     /                     ``." << '\n';
	std::cout << "                  |  |     .                       \\.\\" << '\n';
	std::cout << "        ____      |___._.  |       __               \\ `." << '\n';
	std::cout << "      .'    `---\"\"       ``\"-.--\"'`  \\               .  " << '\n';
	std::cout << "     .  ,            __               `              |   ." << '\n';
	std::cout << "     `,'         ,-\"'  .               \\             |    L" << '\n';
	std::cout << "    ,'          '    _.'                -._          /    |" << '\n';
	std::cout << "   ,`-.    ,\".   `--'                      >.      ,'     |" << '\n';
	std::cout << "  . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'" << '\n';
	std::cout << "  ||:, .           ,'  ;  /  / \\ `        `.    .      .'/" << '\n';
	std::cout << "  ||:   \\          `--'  ' ,'_  . .         `.__, \\   , /" << '\n';
	std::cout << " / L:_  |                 .  \"' :_;                `.'.'" << '\n';
	std::cout << " .    \"\"'                  \"\"\"\"\"'                    V" << '\n';
	std::cout << "  `.                                 .    `.   _,..  `" << '\n';
	std::cout << "    `,_   .    .                _,-'/    .. `,'   __  `" << '\n';
	std::cout << "     ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  ." << '\n';
	std::cout << "    /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |" << '\n';
	std::cout << "   .   _  `\"\"'--.._____..--\"   ,             '         |" << '\n';
	std::cout << "   | .\" `. `-.                /-.           /          ," << '\n';
	std::cout << "   | `._.'    `,_            ;  /         ,'          ." << '\n';
	std::cout << "  .'          /| `-.        . ,'         ,           ," << '\n';
	std::cout << "  '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'" << '\n';
	std::cout << "  `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--' " << '\n';
}
void CharmanderArt() {
	std::cout << "\n               _.--\"\"`-.." << '\n';
	std::cout << "             ,'          `." << '\n';
	std::cout << "           ,'          __  `." << '\n';
	std::cout << "          /|          \" __   \\" << '\n';
	std::cout << "         , |           / |.   ." << '\n';
	std::cout << "         |,'          !_.'|   |" << '\n';
	std::cout << "       ,'             '   |   |" << '\n';
	std::cout << "      /              |`--'|   |" << '\n';
	std::cout << "     |                `---'   |" << '\n';
	std::cout << "      .   ,                   |                       ,\"." << '\n';
	std::cout << "       ._     '           _'  |                    , ' \\ `" << '\n';
	std::cout << "   `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|" << '\n';
	std::cout << "   |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\" << '\n';
	std::cout << " -:..     `. `-..--_.,.<       `\"      / `.        `-/ |   ." << '\n';
	std::cout << "   `,         \"\"\"\"'     `.              ,'         |   |  ',," << '\n';
	std::cout << "     `.      '            '            /          '    |'. |/" << '\n';
	std::cout << "       `.   |              \       _,-'           |       ''" << '\n';
	std::cout << "         `._'               \   '\"\\                .      |" << '\n';
	std::cout << "            |                '     \\                `._  ,'" << '\n';
	std::cout << "            |                 '     \\                 .'|" << '\n';
	std::cout << "            |                 .      \\                | |" << '\n';
	std::cout << "            |                 |       L              ,' |" << '\n';
	std::cout << "            `                 |       |             /   '" << '\n';
	std::cout << "             \\                |       |           ,'   /" << '\n';
	std::cout << "           ,' \\               |  _.._ ,-..___,..-'    ,'" << '\n';
	std::cout << "          /     .             .      `!             ,j'" << '\n';
	std::cout << "         /       `.          /        .           .'/" << '\n';
	std::cout << "        .          `.       /         |        _.'.'" << '\n';
	std::cout << "         `.          7`'---'          |------\"'_.'" << '\n';
	std::cout << "        _,.`,_     _'                ,''-----\"'" << '\n';
	std::cout << "    _,-_    '       `.     .'      ,\\" << '\n';
	std::cout << "    -\" /`.         _,'     | _  _  _.|" << '\n';
	std::cout << "     \"\"--'---\"\"\"\"\"'        `' '! |! /" << '\n';
	std::cout << "                             `\" \" -' " << '\n';
}
void SquirtleArt() {
	std::cout << "\n                _,........__ " << '\n';
	std::cout << "             ,-'            \"`-." << '\n';
	std::cout << "           ,'                   `-." << '\n';
	std::cout << "         ,'                        \\" << '\n';
	std::cout << "       ,'                           ." << '\n';
	std::cout << "       .'\\               ,\"\".       `" << '\n';
	std::cout << "      ._.'|             / |  `       \\" << '\n';
	std::cout << "      |   |            `-.'  ||       `." << '\n';
	std::cout << "      |   |            '-._,'||       | \\" << '\n';
	std::cout << "      .`.,'             `..,'.'       , |`-." << '\n';
	std::cout << "      l                       .'`.  _/  |   `." << '\n';
	std::cout << "      `-.._'-   ,          _ _'   -\" \\  .     `" << '\n';
	std::cout << " `.\"\"\"\"\"'-.`-...,---------','         `. `....__." << '\n';
	std::cout << " .'        `\"-..___      __,'\\          \\  \\     \\" << '\n';
	std::cout << " \\_ .          |   `\"\"\"\"'    `.           . \\     \\ " << '\n';
	std::cout << "   `.          |              `.          |  .     L" << '\n';
	std::cout << "     `.        |`--...________.'.        j   |     |" << '\n';
	std::cout << "       `._    .'      |          `.     .|   ,     |" << '\n';
	std::cout << "          `--,\\       .            `7\"\"' |  ,      |" << '\n';
	std::cout << "             ` `      `            /     |  |      |    _,-'\"\"\"`-." << '\n';
	std::cout << "              \\ `.     .          /      |  '      |  ,'          `." << '\n';
	std::cout << "               \\  v.__  .        '       .   \\    /| /              \\" << '\n';
	std::cout << "                \\/    `\"\"\\\"\"\"\"\"\"\"`.       \\   \\  /.''                |" << '\n';
	std::cout << "                 `        .        `._ ___,j.  `/ .-       ,---.     |" << '\n';
	std::cout << "                 ,`-.      \\         .\"     `.  |/        j     `    |" << '\n';
	std::cout << "                /    `.     \\       /         \\ /         |     /    j" << '\n';
	std::cout << "               |       `-.   7-.._ .          |\"          '         /" << '\n';
	std::cout << "               |          `./_    `|          |            .     _,'" << '\n';
	std::cout << "               `.           / `----|          |-............`---'" << '\n';
	std::cout << "                 \\          \\      |          |" << '\n';
	std::cout << "                ,'           )     `.         |" << '\n';
	std::cout << "                 7____,,..--'      /          |" << '\n';
	std::cout << "                                   `---.__,--.'" << '\n';
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
