#ifndef SNAKEGAMEPLAY
#define SNAKEGAMEPLAY

#include "gamemechanics.h"

namespace gameplay {

void loadWorld(gameT& game, std::ifstream& input);

void pause();

void printWorld(gameT& game);

void displayResult(gameT& game);

}

#endif