#include "Bricks/BrickLoader.h"

#include <fstream>

#include "Utils/Constants.h"

auto BrickLoader::SetPatternToLoad(const std::string &pattern) -> std::string {
    return game::ROOT + "assets/grids_layout/" + pattern + ".txt";
}

auto BrickLoader::LoadFromFile(const std::string &filename) -> std::vector<std::string> {
    std::ifstream file{filename};
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + filename);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}
