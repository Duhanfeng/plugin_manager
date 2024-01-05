//
// Created by cxc on 2024/1/4.
//

#pragma once
#include "plugin_export.hpp"
#include <vector>
#include <string>
#include <array>
#include <memory>

class SS_PLUGIN_EXPORT_API Node
{
public:
    Node();
    ~Node();
    std::vector<double>& getVectors();

protected:
    int value_ = 0;
    std::vector<double> vectors_;
    int* data_ = nullptr;
    std::string name_ = "1232";
    std::array<float, 1024> array_;
    std::shared_ptr<int> ptr_;
};
