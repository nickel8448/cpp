#ifndef GRAPH_UTILS
#define GRAPH_UTILS

#include <vector>

#include "SimpleGraph.h"

const double kRepel = 0.001;
const double kAttract = 0.0001;

namespace GraphUtils {

// Asks the user for a file name and reads the file to pupulate data into a
// graph struct
void ReadFile(SimpleGraph& graph);

// Prompts the user to get the amount of time the program should run for
double GetNumSeconds(); 

// Function updates the graph with new values
void UpdateGraph(SimpleGraph& graph);

namespace GraphUpdateUtils {
  // Updates the nodes in the graph by calucating the repuslsive force
  void UpdateNodes(SimpleGraph& graph, std::vector<double>& incrementalX,
      std::vector<double>& incrementalY);

  // Updates the edges in the graph by calucating the repuslsive force
  void UpdateEdges(SimpleGraph& graph, std::vector<double>& incrementalX,
      std::vector<double>& incrementalY);
}

}

#endif
