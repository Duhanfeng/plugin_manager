//
// Created by cxc on 2024/1/4.
//

#include "node.hpp"

NodeUI::NodeUI(Node* node)
{
    vectors_.resize(1000 * 1000);
    data_ = new int[10000u * 10000u * 3u];
    ptr_ = std::make_shared<int>(3);
    node_ = node;
    if (node_ != nullptr)
    {
        auto& vec = node_->getVectors();
        vec.insert(vec.end(), 1000 * 1000, 50);
    }
}

NodeUI::~NodeUI()
{
    delete[] data_;
}

std::vector<double>& NodeUI::getVectors()
{
    return vectors_;
}