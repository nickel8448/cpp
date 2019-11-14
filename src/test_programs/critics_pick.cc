/**
 * critics_pick.cc
 * Purpose: Problem 10 from Chapter 7. Write a function to sort a map
 *  
 * @author Rahul W
 * @version 0.1 11/13/19
 */


#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <utility>
#include <iterator>
#include <iostream>

using moviePair = std::pair<std::string, double>;

std::set<std::string> CriticsPick(const std::map<std::string, double>& movieList) {
  typedef std::function<bool(moviePair, moviePair)> Comparator;
  Comparator cmpFunction = [](moviePair firstMovie, moviePair secondMovie) {
    return firstMovie.second < secondMovie.second;
  };
  std::set<std::string, Comparator> sortedMovie(movieList.begin(),
      movieList.end(), cmpFunction);
  std::set<std::string> toReturn(sortedMovie.begin(), sortedMovie.end());
  return toReturn;
}


int main() {
  std::map<std::string, double> movies;
  movies.insert({"aa", 4.0});
  /* movies.insert(std::make_pair("aaa", 4.0)); */
  /* movies.insert(std::make_pair("ddd", 6.0)); */
  /* movies.insert(std::make_pair("ccc", 10.0)); */
  /* for (int i = 0; i < 20; ++i) { */
  /*   char ch = i + 97; */
  /*   std::string movieName = "random"; */
  /*   movies.insert(std::make_pair(movieName.append(&ch), i*23)); */
  /* } */
  std::set<std::string> topMovies = CriticsPick(movies);
  /* std::copy(topMovies.begin(), topMovies.end(), */
  /*     std::ostream_iterator<std::string>(std::cout, "\n")); */
}

