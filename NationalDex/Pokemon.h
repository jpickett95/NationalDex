#pragma once

#include <iostream>
#include <string>
#include "Weakness.h"
#include "Move.h"

class Pokemon
{
public:
	std::string mName; // Pokemon Name
	int mPokedexNumber = 0; // Pokedex #
	std::string mType1; // Main Type
	std::string mType2; // Secondary Type
	std::string mClassification; // string text
	float mHeight = 0; // in meters
	float mWeight = 0; // in kilograms
	Weakness mWeakness; // damage ratios
	//Pokemon* mPrevEvolution;
	//Pokemon* mNextEvolution;
	Move mMove1;
	Move mMove2;
	Move mMove3;
	Move mMove4;
	std::string mEntry; // Pokedex entry (description of pokemon)
	std::string mAbility; // Potential pokemon abilities
	int mBaseAttack = 0;
	int mBaseDefense = 0;
	int mBaseSpecialAttack = 0;
	int mBaseSpecialDefense = 0;
	int mBaseSpeed = 0;
	int mBaseHealth = 0;
	float mMalePercentage = 0;
	float mFemalePercentage = 0;
	int mGeneration = 0;
	bool isLegendary = 0;
	bool isCaught = false; // determines whether the pokemon has been caught (future implementation)
	int mCaptureRate = 0;

	void Display();




};

