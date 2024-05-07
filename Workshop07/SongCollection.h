/************************************************************************
*                              Workshop 07
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-03-16
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace seneca
{
    struct Song
    {
        std::string m_artist{};
        std::string m_title{};
        std::string m_album{};
        double m_price{ 0.0f };
        size_t m_year{ 0u };
        size_t m_length{ 0u };
    };

    class SongCollection
    {
        std::vector<Song> songs;

        void trim(std::string& str) const;
    public:
        SongCollection(const char* filename);
        void display(std::ostream& out) const;
        void sort(const std::string& str);
        void cleanAlbum();
        bool inCollection(const std::string& name) const;
        std::list<Song> getSongsForArtist(const std::string& name) const;
    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif // !SENECA_SONGCOLLECTION_H
