#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using std::string;
using std::unordered_set;


// Invariants:
// Valid Wikipedia link:
// 1. The link is of the form "/wiki/PAGENAME"
// 2. The PAGENAME doesn't contain any of the disallowed characters (# or :).
//
// Use algos like std::search and std::find that operate on iterators
// Possible solution contains the following algorithms:
// std::search
// std::find
// std:all_of

// Possible decomposition
// 1. Tokentize the entire file - done
// 2. Check if any word contains /wiki/PAGENAME pattern - done
// 3. Check if it contains any illegal chars - done
// 4. If doesn't contain any illegal chars, strip it using transform and regex

// Function declarations

// Function takes the html of a page in the form of a string as a parameter
// and returns an unordered_set<string> containing all the valid Wikipedia
// links in the page_html string
unordered_set<string> findWikiLinks(const string& page_html);

// getAllWikiLinksFromPage gets the links in string without any cleaning
unordered_set<string> getAllWikiLinksFromPage(const string& page_html);

// Reads a file and returns the contents of the file as string
string ReadFile(const string& fileName);

void CleanWikiLinks(unordered_set<string>& result);

// Function declarations end

int main() {
	
    /* TODO: Write code here! */

    /* Note if your file reading isn't working, please go to the
     * projects tab on the panel on the left, and in the run section,
     * uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */
  string fileContents = ReadFile("simple-invalid.txt");
  unordered_set<string> result = findWikiLinks(fileContents);
  std::copy(result.begin(), result.end(),
            std::ostream_iterator<string>(std::cout, "\n"));
}

string ReadFile(const string& fileName) {
  std::ifstream file;
  try {
    file.open(fileName);
  } catch (std::exception &ex) {
    std::cout << "Ouch! That hurts, because: "
              << ex.what() << "!\n";
  }
  string result = "";
  string line = "";
  while(getline(file, line)) {
    result += line + " ";
  }
  return result;
}

unordered_set<string> findWikiLinks(const string& page_html) {
  // find next link
  unordered_set<string> result = getAllWikiLinksFromPage(page_html);

  return result;
}



bool IsLinkWithInvalidCharacter(const string& text) {
  auto checkInvalidChar = [](char c)->bool {
    if (c == '#' || c == ':') return true;
    return false;
  };
  return std::any_of(text.begin(), text.end(), checkInvalidChar);
}

unordered_set<string> getAllWikiLinksFromPage(const string& page_html) {
    unordered_set<string> result;
    auto curr = page_html.begin();
    auto end = page_html.end();
    string toFind = "href=\"/wiki/";
    while (curr < end) {
      // find the first occurance of "/wiki/"
      auto found = std::search(curr, end, toFind.begin(), toFind.end());
      if (found == end) break;
      string hrefLink = "";
      while (*found != '\"') {
        hrefLink += *found;
        ++found;
      }
      if (hrefLink != "" && !IsLinkWithInvalidCharacter(hrefLink))
        result.insert(hrefLink.substr(12));
      curr = found + 1;  // updating the curr iterator to search for the next
    }
    return result;
}
