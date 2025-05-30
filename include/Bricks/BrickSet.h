#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>

class BrickSet {
    std::vector<std::string> layout;

    public:
    explicit BrickSet(const std::vector<std::string> &layout);
    ~BrickSet() = default;

    auto Draw() const -> void;
};

#endif //LEVEL_H
