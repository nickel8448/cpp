/*
 * TODO: complete this file comment.
 */
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "SimpleGraph.h"
#include "graph_utils.h"

using namespace std;

void Welcome();

// Main method
int main() {
    Welcome();
    while (true) {
      SimpleGraph graph;
      GraphUtils::ReadFile(graph);
      InitGraphVisualizer(graph);
      DrawGraph(graph); // Drawing the graph initially
      time_t startTime = time(NULL);
      double numSecondsProgramToRun = GraphUtils::GetNumSeconds();
      while (difftime(time(NULL), startTime) < numSecondsProgramToRun) {
        // Do the computation here again and draw the graph in the end 
        GraphUtils::UpdateGraph(graph);
        DrawGraph(graph);
      }
      std::string endOrNot, dummy;
      std::cout << "Press y to draw another graph: ";
      /* getline(cin, dummy); */
      getline(cin, endOrNot);
      if (endOrNot != "y")
        return 0;
    }
    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}


