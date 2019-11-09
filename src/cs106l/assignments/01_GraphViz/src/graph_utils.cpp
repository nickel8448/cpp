#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>

#include "graph_utils.h"
#include "SimpleGraph.h"


void GraphUtils::ReadFile(SimpleGraph& graph) {
  while (true) {
    std::cout << "Please enter the file name: ";
    std::string fileName;
    getline(std::cin, fileName);
    std::ifstream input;
    input.open(fileName);
    if(input.is_open()) {
      size_t numNodes;
      Edge edge;
      Node node;
      input >> numNodes;
      for (int i = 0; i < numNodes; ++i) {
        node.x = std::cos((2*kPi*i)/numNodes);
        node.y = std::sin((2*kPi*i)/numNodes);
        graph.nodes.push_back(node);
      }
      while (input >> edge.start && input >> edge.end) {
        graph.edges.push_back(edge);
      }
      input.close();
      break;
    } else {
      // TODO: Have a better error
      std::cout << "Could not open the file. Please try again " << std::endl;
    }
  }
}

double GraphUtils::GetNumSeconds() {
  std::cout << "Number of seconds program should run: ";
  std::string stringNumSeconds;
  getline(std::cin, stringNumSeconds);
  return atof(stringNumSeconds.c_str());
}

void GraphUtils::UpdateGraph(SimpleGraph& graph) {
  std::vector<double> incrementalX(graph.nodes.size());
  std::vector<double> incrementalY(graph.nodes.size());

  GraphUtils::GraphUpdateUtils::UpdateNodes(graph, incrementalX, incrementalY);
  GraphUtils::GraphUpdateUtils::UpdateEdges(graph, incrementalX, incrementalY);

  // Updating the values
  for (size_t i = 0; i < graph.nodes.size(); i++) {
    graph.nodes.at(i).x += incrementalX.at(i);
    graph.nodes.at(i).y += incrementalY.at(i);
  }
}

void GraphUtils::GraphUpdateUtils::UpdateNodes(SimpleGraph& graph,
    std::vector<double>& incrementalX, std::vector<double>& incrementalY) {
  for (size_t i = 0; i < graph.nodes.size(); i++) {
    for(size_t j = i + 1; j < graph.nodes.size(); j++) {
      // Getting all the variable
      double x0 = graph.nodes.at(i).x;
      double x1 = graph.nodes.at(j).x;
      double y0 = graph.nodes.at(i).y;
      double y1 = graph.nodes.at(j).y;

      // Creating F Repel
      double fRepel = kRepel / 
        std::sqrt(std::pow((y1 - y0), 2) + std::pow((x1 - x0), 2));

      // Variables for updating the graph
      double theata = atan2(y1 - y0, x1 - x0);
      double fRepelCos = fRepel * std::cos(theata);
      double fRepelSin = fRepel * std::sin(theata);

      // Registering x0 and y0
      incrementalX[i] -= fRepelCos;
      incrementalY[i] -= fRepelSin;

      // Registering x1 and y1
      incrementalX[j] += fRepelCos;
      incrementalY[j] += fRepelSin;
    }
  }
}

void GraphUtils::GraphUpdateUtils::UpdateEdges(SimpleGraph &graph,
    std::vector<double>& incrementalX, std::vector<double>& incrementalY) {
  for (size_t i = 0; i < graph.edges.size(); i++) {
    Edge tempEdge = graph.edges.at(i);
    size_t startEdge = tempEdge.start;
    size_t endEdge = tempEdge.end;

    Node firstNode = graph.nodes.at(startEdge);
    Node secondNode = graph.nodes.at(endEdge);

    // Getting all the variable
    double x0 = firstNode.x;
    double x1 = secondNode.x;
    double y0 = firstNode.y;
    double y1 = secondNode.y;

    // Creating F Attract
    double fAttract = kAttract *
      (std::pow((y1 - y0), 2) + std::pow((x1 - x0), 2));

    // Variables for updating the graph
    double theata = atan2(y1 - y0, x1 - x0);
    double fAttractCos = fAttract * std::cos(theata);
    double fAttractSin = fAttract * std::sin(theata);

    // Registering x0 and y0
    incrementalX[startEdge] += fAttractCos;
    incrementalY[startEdge] += fAttractSin;

    // Registering x1 and y1
    incrementalX[endEdge] -= fAttractCos;
    incrementalY[endEdge] -= fAttractSin;
  }
}
