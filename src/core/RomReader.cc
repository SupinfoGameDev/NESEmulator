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
    char buffer[100];
    while (reader_.read(buffer, 1))
    {
        mapping_.insert(std::pair<int, int>(address++, reader_.get()));
        if (address == 0x0800) break;
    }
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}
