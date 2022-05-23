#include "Pokemon.h"

void Pokemon::Display() {
	std::cout << '\n';
	std::cout << " Pokedex #: " << mPokedexNumber << '\t'; // Pokedex #
	std::cout << " Name: " << mName << '\t';
	std::cout << " Generation: " << mGeneration << '\n';
	std::cout << " Classification: " << mClassification << '\n'; // string text
	std::cout << " Type1: " << mType1 << '\t'; // Main Type
	std::cout << " Type2: " << mType2 << '\n'; // Secondary Type	
	if (mHeight == 0)
		std::cout << " Height: unknown" << '\t';
	else
		std::cout << " Height: " << mHeight << "m\t"; // in meters
	if (mWeight == 0)
		std::cout << " Weight: unknown" << '\n';
	else
		std::cout << " Weight: " << mWeight << "kg\n"; // in kilograms
	//std::cout << "Weaknesses: " << mWeaknesses << '\n'; // damage ratios
	//std::cout << "PrevEvolution: " << mPrevEvolution << '\n';
	//std::cout << "NextEvolution: " << mNextEvolution << '\n';
	std::cout << " Move1: " << mMove1.mName << '\n';
	std::cout << " Move2: " << mMove2.mName << '\n';
	std::cout << " Move3: " << mMove3.mName << '\n';
	std::cout << " Move4: " << mMove4.mName << '\n';
	//std::cout << "Entry: " << mEntry << '\n'; // Pokedex entry (description of pokemon)
	std::cout << " Ability: " << mAbility << '\n'; // Potential pokemon abilities
	std::cout << " ATK: " << mBaseAttack << '\t';
	std::cout << " DEF: " << mBaseDefense << '\n';
	std::cout << " SPATK: " << mBaseSpecialAttack << '\t';
	std::cout << " SPDEF: " << mBaseSpecialDefense << '\n';
	std::cout << " SPD: " << mBaseSpeed << '\t';
	std::cout << " HP: " << mBaseHealth << '\n';
	if (mMalePercentage == -1) {
		std::cout << " Male%: N/A" << '\t';
		std::cout << " Female%: N/A" << '\n';
	}
	else {
		std::cout << " Male%: " << mMalePercentage << '\t';
		std::cout << " Female%: " << mFemalePercentage << '\n';
	}
	if(isLegendary == true)
		std::cout << " Legendary: Yes" << '\n';
	else if(isLegendary == false)
		std::cout << " Legendary: No" << '\n';
	if(isCaught == true)
		std::cout << " Caught: Yes" << '\n'; // determines whether the pokemon has been caught (future implementation)
	else if(isCaught == false)
		std::cout << " Caught: No" << '\n';
	std::cout << " Capture Rate: " << mCaptureRate << '\n';
	std::cout << '\n';
}