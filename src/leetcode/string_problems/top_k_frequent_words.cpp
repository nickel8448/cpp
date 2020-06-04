/**
 * @file top_k_frequent_words.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-28
 *
 * @copyright Copyright (c) 2020
 * TODO: This can be re-written using heap
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using std::map;
using std::string;
using std::unordered_map;
using std::vector;

void insert_words_in_maps(unordered_map<string, int> &word_frequency_map,
                          map<int, vector<string>> &frequency_word_map,
                          vector<string> &words) {
  for (size_t i = 0; i < words.size(); ++i) {
    // 1. Put the word in the word map or increase its counter
    // 2. If the frequency is in the map then add the string to it and remove it
    //    from the previous one
    string word = words.at(i);
    if (word_frequency_map.find(word) != word_frequency_map.end()) {
      vector<string> frequency_vector =
          frequency_word_map.at(word_frequency_map.find(word)->second);
      auto pos =
          std::find(frequency_vector.begin(), frequency_vector.end(), word);
      frequency_vector.erase(pos);
      frequency_word_map.at(word_frequency_map.find(word)->second) =
          frequency_vector;
      word_frequency_map[word]++;
    } else {
      word_frequency_map.insert(std::make_pair(word, 1));
    }
    int frequency = word_frequency_map.at(word);
    if (frequency_word_map.find(frequency) != frequency_word_map.end()) {
      // frequency is present in the map
      frequency_word_map.at(frequency).push_back(word);
    } else {
      frequency_word_map.insert(
          std::make_pair(frequency, vector<string>{word}));
    }
  }
}

vector<string> topKFrequent(vector<string> &words, int k) {
  unordered_map<string, int> word_frequency_map;
  map<int, vector<string>> frequency_word_map;
  insert_words_in_maps(word_frequency_map, frequency_word_map, words);
  vector<string> result;
  for (auto itr = frequency_word_map.rbegin(); itr != frequency_word_map.rend();
       itr++) {
    vector<string> current_vec(itr->second.begin(), itr->second.end());
    std::sort(current_vec.begin(), current_vec.end());
    for (int i = 0; i < current_vec.size(); i++) {
      if (k == 0)
        break;
      result.push_back(current_vec.at(i));
      k--;
    }
  }
  return result;
}

int main() {
  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> result = topKFrequent(words, 2);
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result.at(i) << std::endl;
  }
}
