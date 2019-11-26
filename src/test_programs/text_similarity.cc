#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>

using std::string;
using std::vector;

// Function outline

// Function opens the file and returns the contents of the file as string
string OpenFile(string fileName);

// CountOccurance counts the occurance of word in the text
int CountOccurance(const string& text, const string& feature);

// Creates a Feature vector of the text
vector<int> CreateFeatureVector(const string& text);

// Calculates the Similarity
double CalculateSimilarity(const string& text1, const string& text);

double mag(const vector<int>& v);


const vector<string> FEATURE_VEC{"a", "about", "above", "after", "again", "against", "all", "am", "an", "and",
                                 "any", "are", "aren't", "as", "at", "be", "because", "been", "before", "being",
                                 "below", "between", "both", "but", "by", "can't", "cannot", "could", "couldn't",
                                 "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during",
                                 "each", "few", "for", "from", "further", "had", "hadn't", "has", "hasn't", "have",
                                 "haven't", "having", "he", "he'd", "he'll", "he's", "her","here", "here's", "hers",
                                 "herself", "him", "himself", "his", "how", "how's", "i", "i'd", "i'll", "i'm",
                                 "i've", "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself", "let's",
                                 "me", "more", "most", "mustn't", "my", "myself", "no", "nor", "not", "of", "off",
                                 "on", "once", "only", "or", "other", "ought", "our", "ours", "ourselves", "out",
                                 "over", "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should",
                                 "shouldn't", "so", "some", "such", "than", "that", "that's", "the", "their",
                                 "theirs", "them", "themselves", "then", "there", "there's", "these", "they",
                                 "they'd", "they'll", "they're", "they've", "this", "those", "through", "to", "too",
                                 "under", "until", "up", "very", "was", "wasn't", "we", "we'd", "we'll", "we're",
                                 "we've", "were", "weren't", "what", "what's", "when", "when's", "where", "where's",
                                 "which", "while", "who", "who's", "whom", "why", "why's", "with", "won't", "would",
                                 "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
                                 "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+",
                                 ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_",
                                 "`", "{", "|", "}", "~"};
                                 
// Creating outline of the program

// Function opens the file and returns the contents of the file as string
string OpenFile(string fileName) {
  string result = "";
  std::ifstream fileStream(fileName);
  string line = "";
  while(getline(fileStream, line)) {
    std::transform(line.begin(), line.end(), line.begin(), tolower);
    result += line + " ";
  }
  return result;
}

int CountOccurance(const string& text, const string& feature) {
  string wordToFind = " " + feature + " ";
  int count = 0;

  auto curr = text.begin();
  auto end = text.end();
  while (curr != end) {
    auto found = std::search(curr, end, wordToFind.begin(), wordToFind.end());
    if (found == end) break;
    ++count;
    // increment the iterator to go forward
    curr = found + 1;
  }
  return count;
}

vector<int> CreateFeatureVector(const string& text) {
  vector<int> result;
  for (const auto& feature : FEATURE_VEC) {
    result.push_back(CountOccurance(text, feature));
  }
  return result;
}

int CalculateDotProduct(const vector<int>& text1Vector,
                        const vector<int>& text2Vector) {
  return std::inner_product(text1Vector.begin(), text1Vector.end(),
                            text2Vector.begin(), 0);
}

// Function calculates the similarity amongst two texts
double CalculateSimilarity(const string& text1,const string& text2) {
  vector<int> text1Vector = CreateFeatureVector(text1);
  vector<int> text2Vector = CreateFeatureVector(text2);

  int dotProduct = CalculateDotProduct(text1Vector, text2Vector);

  return dotProduct / (mag(text1Vector) * mag(text2Vector));
}


double mag(const vector<int>& v) {
  return std::sqrt(CalculateDotProduct(v, v));
}


int main() {
  // open all the files
  string hamilton = OpenFile("res/hamilton.txt");
  string madison = OpenFile("res/madison.txt");
  string unknown = OpenFile("res/unknown.txt");

  double hamilton_unknwon = CalculateSimilarity(hamilton, unknown);
  double madison_unknwon = CalculateSimilarity(madison, unknown);


  std::cout << "Similarity in hamilton and madison: " << hamilton_unknwon << std::endl;
  std::cout << "Similarity in hamilton and madison: " << madison_unknwon << std::endl;
}