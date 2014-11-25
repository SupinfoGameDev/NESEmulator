#ifndef NESEMU_ROMREADER
#define NESEMU_ROMREADER

#include <fstream>
#include <map>
#include <string>

class RomReader
{
public:
    RomReader(const std::string& filename);
    std::map<int, int> map() const;

private:
    void read();
    std::map<int, int> mapping_;
    std::ifstream reader_;
};

#endif
