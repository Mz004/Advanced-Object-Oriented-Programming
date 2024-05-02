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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "SpellChecker.h"

using namespace std;

namespace seneca
{
    SpellChecker::SpellChecker(const char* filename)
    {
        std::ifstream file(filename);
        if(!file) {
            throw "Bad file name!";
        }
        for(auto i = 0u; i < MAX_WORDS; i++) {
            file >> m_badWords[i] >> m_goodWords[i];
            m_wordCount[m_badWords[i]] = 0;
        }
    }

    void SpellChecker::operator()(std::string& text)
    {
        for(auto i = 0u; i < MAX_WORDS; i++) {
            replaceWord(text, m_badWords[i], m_goodWords[i]);
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const
    {
        out << "Spellchecker Statistics\n";
        for(auto i = 0u; i < MAX_WORDS; i++) {
            out << std::right << std::setw(15) << m_badWords[i] << ": "
                << m_wordCount.at(m_badWords[i]) << " replacements" << std::endl;
        }
    }

    void SpellChecker::replaceWord(std::string& text, const std::string& badWord,
        const std::string& goodWord)
    {
        size_t pos = 0;
        while((pos = text.find(badWord, pos)) != std::string::npos) {
            text.replace(pos, badWord.length(), goodWord);
            m_wordCount[badWord]++;
            pos += goodWord.length();
        }
    }
}