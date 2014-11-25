#include "RomReader.h"

RomReader::RomReader(const std::string & filename)
{
    reader_ = std::ifstream(filename, std::ios::in | std::ios::binary);
    read();
}

void RomReader::read()
{
    int address {};
    char buffer[100];
    while (reader_.read(buffer, 1))
    {
        mapping_.insert(std::pair<int, int>(address++, reader_.get()));
    }
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}
