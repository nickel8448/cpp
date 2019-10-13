/**
 * game.cc
 * Purpose: Build a simple snake game
 *  
 * @author Rahul W
 * @version 0.1 10/13/19
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "gameplay.h"
#include "gamemechanics.h"
#include "src/cs106l/streams/filestream.h"


void InitializeGame(gameT& game) {
    std::ifstream file = OpenFile(); 
    gameplay::loadWorld(game, file);
}


void RunSimulation(gameT& game) {
    while (game.numEaten < kMaxFood) {
        gameplay::printWorld(game); // Display the board
        gamemechanics::performAI(game);            // Have the AI choose an action

        if (!gamemechanics::moveSnake(game))       // Move the snake and stop if we crashed
            break;

        gameplay::pause();          // To see what is going on
    }
    gameplay::displayResult(game);
}


int main() {
    gameT game;
    InitializeGame(game);
    RunSimulation(game);
    return 0;
}
