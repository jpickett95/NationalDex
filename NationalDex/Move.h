#pragma once

#include <string>

class Move
{
public:
	std::string mName;
	std::string mType;
	std::string mCategory; // physical (based off ATK & DEF) or special (based off SP_ATK & SP_DEF)
	int mPower = 0;
	float mAccuracy = 0; // percentage; between 1.0 - 0.0 
	std::string mNotes; // notes on move
	int mMoveID = 0;
};

