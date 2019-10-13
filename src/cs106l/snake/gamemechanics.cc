/**
 * gameMechanics.cc
 * Purpose: Functions for game mechanics of the snake game
 *  
 * @author Rahul W
 * @version 0.1 10/13/19
 */

#include <ctime>
#include <cstdlib>
	
#include "gamemechanics.h"

pointT gamemechanics::makePoint(int row, int col) {
    pointT result;
    result.row = row;
    result.col = col;
    return result;
}


pointT gamemechanics::getNextHeadPosition(gameT& game, int dx, int dy) {
	// current position
	pointT result = game.snake.front();

	// Increment the head position
	result.row += dy;
	result.col += dx;
	return result;
}


bool gamemechanics::inWorld(pointT& pt, gameT& game) {
	return pt.col >= 0 &&
		   pt.row >= 0 &&
		   pt.col < game.numCols &&
		   pt.row < game.numRows;
}


bool gamemechanics::crashed(pointT& nextHead, gameT& game) {
	return !inWorld(nextHead, game) ||
		game.world[nextHead.row][nextHead.col] == kSnakeTile ||
		game.world[nextHead.row][nextHead.col] == kWallTile;	
}


bool gamemechanics::randomChance(double probability) {
	return (rand() / (RAND_MAX + 1.0)) < probability;
}


void gamemechanics::performAI(gameT& game) {
	// Seed the randomizer. The static_cast converts the result of time(NULL)
	// from time_t to the unsigned int required by srand. This line is
	// idiomatic C++
	// TODO: Try removing this and see the results
    srand(static_cast<unsigned int>(time(NULL)));

	// Figure out where we will be after we move this turn
	pointT nextHead = gamemechanics::getNextHeadPosition(game, game.dx, game.dy);	

	// if it hits the a wall or we randomly decide to turn the snake
	if(gamemechanics::crashed(nextHead, game) ||
		gamemechanics::randomChance(kTurnRate)) {
		int leftDx = -game.dy;
		int leftDy = game.dx;

		int rightDx = game.dy;
		int rightDy = -game.dx;

		pointT leftPoint = gamemechanics::getNextHeadPosition(game, leftDx, leftDy);
		pointT rightPoint = gamemechanics::getNextHeadPosition(game, rightDx, rightDy);

		bool canLeft = !gamemechanics::crashed(leftPoint, game);
		bool canRight = !gamemechanics::crashed(rightPoint, game);

		bool willTurnLeft = false;
		if(!canLeft && !canRight)
			return; // If we can't turn, don't turn
		else if(canLeft && !canRight)
			willTurnLeft = true; // if we must turn left, do so
		else if(!canLeft && canRight)
			willTurnLeft = false; // turn right
		else
			willTurnLeft = gamemechanics::randomChance(0.5); // pick randomly

		game.dx = willTurnLeft? leftDx : rightDx;
		game.dy = willTurnLeft? leftDy : rightDy;
	}
}

bool gamemechanics::moveSnake(gameT& game) {
	pointT nextHead = gamemechanics::getNextHeadPosition(game, game.dx, game.dy);
	if (gamemechanics::crashed(nextHead, game))
		return false;

	bool isFood = (game.world[nextHead.row][nextHead.col] == kFoodTile);

	game.world[nextHead.row][nextHead.col] = kSnakeTile;
	game.snake.push_front(nextHead);

	// move the snake's tail
	if(!isFood) {
		game.world[game.snake.back().row][game.snake.back().col] = kEmptyTile;
		game.snake.pop_back();
	} else {
		++game.numEaten;
		gamemechanics::placeFood(game);
	}
	return true;
}

void gamemechanics::placeFood(gameT& game) {
	while(true) {
		int row = rand() % game.numRows;
		int col = rand() % game.numCols;

		// if the specified position is empty, place the food there
		if(game.world[row][col] == kEmptyTile) {
			game.world[row][col] = kFoodTile;
			return;
		}
	}
}