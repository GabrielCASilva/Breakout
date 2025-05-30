#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <string>
#include <vector>

class BrickLoader {
public:
    static auto SetPatternToLoad(const std::string &pattern) -> std::string;
    static auto LoadFromFile(const std::string& filename) -> std::vector<std::string>;
};

#endif //LEVEL_LOADER_H
