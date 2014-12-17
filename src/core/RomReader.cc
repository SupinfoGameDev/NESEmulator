#include "RomReader.h"
#include <exception>

RomReader::RomReader(const std::string & filename)
    : reader_(filename, std::ios::in | std::ios::binary), header_(0)
{
    if (!reader_)
    {
        std::string message { "Cannot open " + filename };
        //throw std::exception(message.c_str());
    }
    read();
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}

RomHeader RomReader::header() const
{
    return RomHeader();
}

void RomReader::read()
{
    int address {};
    while (reader_)
    {
        mapping_.insert(std::pair<int, int>(address, reader_.get()));
        address++;
    }
    for (auto& map : mapping_)
    {
        header_.push_back(map.second);
        if (map.first == 15) break;
    }
    if (!is_header_ok())
    {
        //throw std::exception("Bad ROM header");
    }
}

bool RomReader::is_header_ok() const
{
    bool zero { true };
    for (auto it = header_.begin() + 7; it != header_.end(); it++)
    {
        if (*it != 0)
        {
            zero = false;
            break;
        }
    }
    return (zero && header_[0] == 'N' && header_[1] == 'E' && header_[2] == 'S' && header_[3] == 0x1a);
}

