/**
 * reserved.cc
 * Purpose: To test what kind of values are returned when a set is used with an
 * iterator
 *  
 * @author Rahul W
 * @version 0.1 11/05/19
 */

#include <iostream>
#include <cctype>
#include <sstream>
#include <cstring>

#include "reserved.h"
#include "src/cs106l/streams/filestream.h"


void openUserFile(std::ifstream& fileStream) {
  fileStream = OpenFile();
}


std::string getFileContents(std::ifstream& file) {
  /* string which will hold the file contents */
  std::string result;
  /* Keep reading a line of the file until no data remains */
  std::string line;
  while(getline(file, line)) {
    result += line + "\n";  // Add the newline character; getline removes it
  }
  return result;
}


std::set<std::string> loadReservedKeywords() {
  std::ifstream input("src/cs106l/reserved_keywords/keywords.txt");
  std::set<std::string> result;

  if (!input.is_open()) {
    std::cout << "File could not be opened: ";
    std::cout << strerror(errno) << "\nPlease try again.\n";
    std::cout << std::endl;
  }

  std::string keyword;
  while (input >> keyword)
    result.insert(keyword);

  return result;
}


void preprocessString(std::string& text) {
  for (size_t k = 0; k < text.size(); k++) {
    if (ispunct(text.at(k)) && text.at(k) != '_')
      text[k] = ' ';
  }
}


std::map<std::string, size_t> generateKeywordReport(std::string contents) {
  /* Load the set of reserved keywords from disk */
  std::set<std::string> keywords = loadReservedKeywords();

  /* Preprocess the string to allow for easier parsing */
  preprocessString(contents);

  /* Populate a stringstream with the file contents */
  std::stringstream tokenizer;
  tokenizer << contents;

  /* Loop over the words in the file, building up the report */
  std::map<std::string, size_t> result;

  std::string word;
  while(tokenizer >> word) {
    if(keywords.count(word)) {
      ++result[word];
    }
  }
  return result;
}


int main() {
  /* Prompt the user for a valid file and open it as a stream */
  std::ifstream input;
  openUserFile(input);

  /* Generate the report based on the contents of the file */
  std::map<std::string, size_t> report = generateKeywordReport(
    getFileContents(input));
  
  /* Print a summary */
  for (std::map<std::string, size_t>::iterator itr = report.begin();
    itr != report.end(); itr++) {
    std::cout << "Keyword: " << itr->first << " occured " << itr->second 
              << " time." << std::endl;
  }
}