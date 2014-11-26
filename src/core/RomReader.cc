#include "RomReader.h"
#include <exception>

RomReader::RomReader(const std::string & filename) : reader_(filename, std::ios::in | std::ios::binary)
{
    if (!reader_)
    {
        std::string message { "Cannot open " + filename };
        throw std::ios_base::failure(message.c_str());
    }
    read();
}

void RomReader::read()
{
    int address {};
    while (reader_)
    {
        mapping_.insert(std::pair<int, int>(address++, reader_.get()));
    }
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}
