/************************************************************************
*                           Workshop 05
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-02-17
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

namespace seneca {
    class SpellChecker
    {
        const static size_t MAX_WORDS = 6;
        std::string m_badWords[MAX_WORDS];
        std::string m_goodWords[MAX_WORDS];
        std::unordered_map<std::string, int> m_wordCount;
        void replaceWord(std::string& text, const std::string& badWord, const std::string& goodWord);

    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif // !SENECA_SPELLCHECKER_H