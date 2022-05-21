#pragma once

#include <string>

class Move
{
	std::string mName;
	std::string mType;
	std::string mCategory; // physical (based off ATK & DEF) or special (based off SP_ATK & SP_DEF)
	int mPower;
	int mAccuracy; // percentage; between 1.0 - 0.0
	std::string mNotes; // notes on move
};

