/**
 * simple_dfa.cc
 * Purpose: Try out a simple DFA
 *  
 * @author Rahul W
 * @version 0.1 11/06/19
 */

#include <map>
#include <utility>
#include <set>

struct DFA {
  std::map<std::pair<int, char>, int> transitions;
  std::set<int> acceptingStates;
  int startState;
};

bool simulateDFA(DFA& d, std::string input) {
  int currentState = d.startState;
  for (std::string::iterator itr = input.begin(); itr != input.end(); ++itr) {
    currentState = d.transitions[std::make_pair(currentState, *itr)];
  }
  return d.acceptingStates.find(currentState) != d.acceptingStates.end();
}
