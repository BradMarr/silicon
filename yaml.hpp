#pragma once
#include <string>
#include <unordered_map>

class YAML {
public:
    YAML(std::string path);
    ~YAML();
private:
    std::unordered_map<std::string, std::string> data;
}