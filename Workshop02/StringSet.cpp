/************************************************************************
*                           Workshop 02
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-01-27
* Authentication Declaration:
* I have done all the coding by myself and only copied the code that my
* professor provided to complete my workshops and assignments.
************************************************************************/
#include "StringSet.h"

using namespace std;

namespace seneca 
{
    void StringSet::set() 
    {
        strings = nullptr;
        numStrings = 0;
    }

    size_t StringSet::size() const 
    {
        return numStrings;
    }

    std::string StringSet::operator[](size_t index) const 
    {
        std::string str = "";
        if (index < numStrings) {
            str = strings[index];
        }
        return str;
    }

    StringSet::StringSet() : strings(nullptr), numStrings(0) {}

    StringSet::StringSet(const StringSet& S) : StringSet() 
    { 
        *this = S; 
    }

    StringSet::StringSet(const char* filename) : StringSet() 
    {
        if (strings != nullptr) {
            return;
        }

        std::string content;
        size_t count = 0;
        std::ifstream file(filename);
        if (file.is_open()) {
            while (std::getline(file, content, ' ')) {
                count++;
            }
            file.clear();
            file.seekg(0);
            strings = new std::string[count];

            while (std::getline(file, content, ' ')) {
                strings[numStrings] = content;
                numStrings++;
            }
            file.close();
        }
    }


    StringSet::StringSet(StringSet&& SS) : StringSet() 
    {
        *this = std::move(SS);
    }

    StringSet& StringSet::operator=(StringSet&& SS) 
    {
        if (this != &SS) {
            StringSet::~StringSet();
            numStrings = SS.numStrings;
            strings = std::move(SS.strings);
            SS.set();
        }
        return *this;
    }

    StringSet& StringSet::operator=(const StringSet& S) 
    {
        if (this != &S) {
            numStrings = S.numStrings;
            StringSet::~StringSet();
            strings = new std::string[numStrings];
            for (size_t i = 0; i < numStrings; i++) {
                strings[i] = S.strings[i];
            }
        }
        return *this;
    }

    StringSet::~StringSet() 
    {
        if (strings) {
            delete[] strings;
            strings = nullptr;
        }
    }
}