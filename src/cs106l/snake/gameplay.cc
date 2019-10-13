/**
 * gamePlay.cc
 * Purpose: Functions for gameplay of the game
 *  
 * @author Rahul W
 * @version 0.1 10/13/19
 */

#include <fstream>
#include <iostream>

#include "gameplay.h"

void gameplay::loadWorld(gameT& game, std::ifstream& input) {
    input >> game.numRows >> game.numCols;
    game.world.resize(game.numRows);

    // Reading the velocity of the snake
    input >> game.dx >> game.dy;

    // The first call to getline after using the stream extraction operator
    // will return the empty string because the new line character
    // delimiting the data is still waiting to be read. Hence the dummy
    // variable
    std::string dummy;
    getline(input, dummy);

    for (int row = 0; row < game.numRows; ++row) {
        getline(input, game.world[row]);

        // Finding the snake head and adding it to the deque
        int col = game.world[row].find(kSnakeTile);
        if (col != std::string::npos)
            game.snake.push_back(gamemechanics::makePoint(row, col));
    }

    game.numEaten = 0;
}


void gameplay::pause() {
    clock_t startTime = clock(); // clock_t is the type which holds clock ticks
    
    /* This loop does nothing except loop and check how much time is left
     * Note that we have to typecast startTime from clock to clock_t to double
     * so that the division is correct. The static_cast<double>(..) syntax
     * is the preferred C++ way of performing a typecast of this sort
     */

    while(static_cast<double>(clock() - startTime)
            / CLOCKS_PER_SEC < kWaitTime);
}


void gameplay::printWorld(gameT& game) {
    system(kClearCommand.c_str());
    for (int row = 0; row < game.numRows; ++row) {
        std::cout << game.world[row] << std::endl;
    }
    std::cout << "Food eaten: " << game.numEaten << std::endl;
}


void gameplay::displayResult(gameT& game) {
    printWorld(game);
    if(game.numEaten == kMaxFood) {
        std::cout << "The snake ate enough food and wins!" << std::endl;
    } else {
        std::cout << "Oh no! The snake crashed." << std::endl;
    }
}