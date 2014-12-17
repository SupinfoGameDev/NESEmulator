#include "tools.h"

#include <dirent.h>

std::vector<std::string> get_roms()
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> roms;
    if ((dir = opendir ("roms/")) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            std::string rom = ent->d_name;
            if (rom.substr(rom.size() - 4, rom.size()) == ".nes")
            {
                roms.push_back(rom);
            }
        }
        closedir(dir);
        delete ent;
    }
    return roms;
}
