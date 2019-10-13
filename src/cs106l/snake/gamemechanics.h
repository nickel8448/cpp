#ifndef SNAKEMECHANICS
#define SNAKEMECHANICS

#include <string>
#include <vector>
#include <deque>

/* Number of food pellets that must be eaten to win */
const int kMaxFood = 20;

/* Constants for the different tile types */
const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile = '$';
const char kSnakeTile = '*';

const double kWaitTime = 0.1;
const std::string kClearCommand = "clear";
const double kTurnRate = 0.2; // 20% chance to turn each step

/* A struct encoding a point in a two-dimensional grid */
struct pointT {
    int row, col;
};


/* A struct containing relevant game information. */
struct gameT {
    std::vector<std::string> world;  // The playing field
    int numRows, numCols;            // The size of the playing field
    
    std::deque<pointT> snake;        // The snake body
    int dx, dy;                      // The snake direction

    int numEaten;                    // How much food we've eaten
};


namespace gamemechanics {

/**
 * Creates a new point
 * @param  row row
 * @param  col column
 * @return     New point
 */
pointT makePoint(int row, int col);


/**
 * Returns the coordinate of where the next head would be
 * @param  game current game
 * @return      Returns the next head coordinate
 */
pointT getNextHeadPosition(gameT& game, int dx, int dy);


/**
 * Checks if the coordinate is in world
 * @param  nextHead next position of the snake
 * @param  game     current game
 * @return          Returns if the next coordinate is the in the game world
 */
bool inWorld(pointT& pt, gameT& game);


/**
 * Checks if the snake has crashed
 * @param  nextHead coordinate of the next move
 * @param  game     current game
 * @return          Returns if the snake has crashed
 */
bool crashed(pointT& nextHead, gameT& game);

/**
 * Returns the random chance of snake taking a turn
 * @param  probability probability of taking a turn
 * @return             Returns if it takes a turn
 */
bool randomChance(double probability);


/**
 * Performs basic AI functions on the snake
 * @param game current game
 */
void performAI(gameT& game);


/**
 * Moves the snake one step forward on its path
 * @param  game current game
 * @return      if snake crashes it returns false
 */
bool moveSnake(gameT& game);


/**
 * Places new food on the game board
 * @param game current game
 */
void placeFood(gameT& game);

}

#endif