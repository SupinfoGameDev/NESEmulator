#include "RomReader.h"
#include <exception>

RomReader::RomReader(const std::string & filename)
{
    reader_ = std::ifstream(filename, std::ios::in | std::ios::binary);
    if (!reader_)
    {
        std::string message { "Cannot open " + filename };
        throw std::exception(message.c_str());
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
    }
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}
