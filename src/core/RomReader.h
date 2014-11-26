#ifndef NESEMU_ROMREADER
#define NESEMU_ROMREADER

#include <fstream>
#include <map>
#include <string>
#include <vector>

struct RomHeader
{
    int PrgRomPagesCount;
    int ChrRomPagesCount;
};

class RomReader
{
public:
    RomReader(const std::string& filename);
    std::map<int, int> map() const;
    RomHeader header() const;
private:
    void read();
    bool is_header_ok() const;
    std::map<int, int> mapping_;
    std::ifstream reader_;
    std::vector<int> header_;
};

#endif
