#ifndef RESERVED
#define RESERVED

#include <fstream>
#include <string>
#include <map>
#include <set>


/**
 * @brief  Prompts the user for a filename and sets filestream to read from
 * that file
 * @note   
 * @param  fileStream: filestream
 * @retval None
 */
void openUserFile(std::ifstream& fileStream);


/**
 * @brief  Returns a string containing the contents of a file passed as a
 * parameter
 * @note   
 * @param  file: Input stream
 * @retval 
 */
std::string getFileContents(std::ifstream& file);


/**
 * @brief  Returns a map from keywords to the frequency at which those keywords
 * appear in the input text string. Keywords not contained in the text will not
 * appear in the map
 * @note   
 * @param  contents: Contents of the file
 * @retval 
 */
std::map<std::string, size_t> generateKeywordReport(std::string contents);


/**
 * @brief  Function loads the set of reserved keywords in C++
 * @note   
 * @retval 
 */
std::set<std::string> loadReservedKeywords();


/**
 * @brief  Function replaces all punctuation to spaces in the text
 * @note   
 * @param  text: Text from which punctuations need to be removed
 * @retval None
 */
void preprocessString(std::string& text);

#endif