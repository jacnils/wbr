#pragma once

#include <fstream>
#include <string>

namespace Wad {
    void extract_wad(std::ifstream& in, const std::string& out_dir = "");
}