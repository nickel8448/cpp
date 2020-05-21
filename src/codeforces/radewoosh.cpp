/*
 * =====================================================================================
 *
 *       Filename:  radewoosh.cpp
 *
 *    Description: Solution for problem
 * https://codeforces.com/problemset/problem/658/A
 *
 *        Version:  1.0
 *        Created:  10/05/2020 11:42:02
 *       Revision:  none
 *       Compiler:  c++17
 *
 *         Author:  Rahul Wadhwani
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

int main() {
  int numQuestions, constantTime;
  std::cin >> numQuestions;
  std::cin >> constantTime;
  std::vector<int> points;
  std::vector<int> timeVector;
  for (int i = 0; i < numQuestions; i++) {
    int point;
    std::cin >> point;
    points.push_back(point);
  }
  for (int i = 0; i < numQuestions; i++) {
    int t;
    std::cin >> t;
    timeVector.push_back(t);
  }
  int limakPoints = 0, radewooshPoints = 0;
  int limakCumalativeTime = 0, radewooshCumalativeTime = 0;
  for (int i = 0; i < numQuestions; i++) {
    // limak points
    limakCumalativeTime += timeVector.at(i);
    limakPoints += std::max(0, points.at(i) - (constantTime * limakCumalativeTime));

    // radewoosh points
    radewooshCumalativeTime += timeVector.at(timeVector.size() - i - 1);
    radewooshPoints += std::max(0, points.at(points.size() - i - 1) -
                       (constantTime * radewooshCumalativeTime));
  }
  if (limakPoints == radewooshPoints)
    printf("Tie\n");
  else if (limakPoints > radewooshPoints)
    printf("Limak\n");
  else
    printf("Radewoosh");
  return 0;
}
