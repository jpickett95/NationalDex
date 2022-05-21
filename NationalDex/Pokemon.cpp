#include "Pokemon.h"

void Pokemon::Display() {
	std::cout << '\n';
	std::cout << "Name: " << mName << '\n';
	std::cout << "Pokedex #: " << mPokedexNumber << '\n'; // Pokedex #
	std::cout << "Type1: " << mType1 << '\n'; // Main Type
	std::cout << "Type2: " << mType2 << '\n'; // Secondary Type
	std::cout << "Classification: " << mClassification << '\n'; // string text
	if (mHeight == 0)
		std::cout << "Height: unknown" << '\n';
	else
		std::cout << "Height: " << mHeight << '\n'; // in meters
	if (mWeight == 0)
		std::cout << "Weight: unknown" << '\n';
	else
		std::cout << "Weight: " << mWeight << '\n'; // in kilograms
	//std::cout << "Weaknesses: " << mWeaknesses << '\n'; // damage ratios
	//std::cout << "PrevEvolution: " << mPrevEvolution << '\n';
	//std::cout << "NextEvolution: " << mNextEvolution << '\n';
	//std::cout << "Move1: " << mMove1 << '\n';
	//std::cout << "Move2: " << mMove2 << '\n';
	//std::cout << "Move3: " << mMove3 << '\n';
	//std::cout << "Move4: " << mMove4 << '\n';
	//std::cout << "Entry: " << mEntry << '\n'; // Pokedex entry (description of pokemon)
	std::cout << "Ability: " << mAbility << '\n'; // Potential pokemon abilities
	std::cout << "ATK: " << mBaseAttack << '\n';
	std::cout << "DEF: " << mBaseDefense << '\n';
	std::cout << "SPATK: " << mBaseSpecialAttack << '\n';
	std::cout << "SPDEF: " << mBaseSpecialDefense << '\n';
	std::cout << "SPD: " << mBaseSpeed << '\n';
	std::cout << "HP: " << mBaseHealth << '\n';
	if (mMalePercentage == -1) {
		std::cout << "Male%: N/A" << '\n';
		std::cout << "Female%: N/A" << '\n';
	}
	else {
		std::cout << "Male%: " << mMalePercentage << '\n';
		std::cout << "Female%: " << mFemalePercentage << '\n';
	}
	std::cout << "Generation: " << mGeneration << '\n';
	std::cout << "Legendary: " << isLegendary << '\n';
	std::cout << "Caught: " << isCaught << '\n'; // determines whether the pokemon has been caught (future implementation)
	std::cout << "Capture Rate: " << mCaptureRate << '\n';
}