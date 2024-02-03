#ifndef SPELLCHECK_LIBRARY_H
#define SPELLCHECK_LIBRARY_H
#include <string>
#include <vector>

/**
 * \brief Loads a dictionary of words, can be called multiple times or in junction with loadDefaultDictionary
 * \param filepath
 */
void loadDictionary(const std::string& filepath);
void loadDefaultDictionary();

/**
 * \brief Would not recommend calling this...
 * \param hexDump
 * \param size
 */
void loadHexDictionary(const unsigned char* hexDump, size_t size);
std::vector<std::string> spell_check(const std::string& word);

#endif //SPELLCHECK_LIBRARY_H
