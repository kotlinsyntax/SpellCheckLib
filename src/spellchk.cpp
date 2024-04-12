#include "spellchk.hpp"
#include "wordlist.hpp"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>


std::string locale = "en";

std::unordered_map<char, std::unordered_set<std::string>> dictionary;

void loadHexDictionary(const unsigned char* hexDump, const size_t size) {
    std::string currentWord;
    for (size_t i = 0; i < size; ++i) {
        if (hexDump[i] == '\n' || hexDump[i] == '\r') {
            if (!currentWord.empty()) {
                char startingChar = currentWord[0];
                dictionary[startingChar].insert(currentWord);
                currentWord.clear();
            }
        } else {
            currentWord += static_cast<char>(hexDump[i]);
        }
    }
    if (!currentWord.empty()) {
        const char startingChar = currentWord[0];
        dictionary[startingChar].insert(currentWord);
    }
}

void loadDefaultDictionary() {
    loadHexDictionary(wordlist_txt, std::size(wordlist_txt));
}

void loadDictionary(const std::string& filepath) {
    if (std::ifstream file(filepath); file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            line = line.substr(0, line.find_first_of("\r\n")); // Trim newline characters
            if (!line.empty()) {
                char startingChar = line[0];
                dictionary[startingChar].insert(line);
            }
        }
        file.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

int wf(const std::string& s1, const std::string& s2) {
    const int len1 = s1.length();
    const int len2 = s2.length();

    int dp[len2 + 1];

    for (int j = 0; j <= len2; ++j) {
        dp[j] = j;
    }

    for (int i = 1; i <= len1; ++i) {
        int diagonal = dp[0];
        dp[0] = i;
        const char s1_char = s1[i - 1];
        for (int j = 1; j <= len2; ++j) {
            const int temp = dp[j];
            dp[j] = std::min(dp[j] + 1, std::min(dp[j - 1] + 1, diagonal + (s1_char != s2[j - 1])));
            diagonal = temp;
        }
    }

    return dp[len2];
}

std::vector<std::string> spell_check(const std::string& word) {
    if (dictionary[word[0]].count(word)) {
        return {word + " (Distance: 0)"};
    }

    std::unordered_map<std::string, int> suggestions;
    for (const auto& correctWord : dictionary[word[0]]) {
        const int distance = wf(word, correctWord);
        suggestions[correctWord] = distance;
    }

    std::vector<std::string> result;

    result.reserve(suggestions.size());
    for (const auto&[fst, snd] : suggestions) {
        result.push_back(fst);
    }

    std::sort(result.begin(), result.end(), [&suggestions](const std::string& a, const std::string& b) {
        return suggestions[a] < suggestions[b];
    });

    return {result.begin(), result.begin() + 10};
}
