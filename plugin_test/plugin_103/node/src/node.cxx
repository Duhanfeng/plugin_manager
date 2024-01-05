//
// Created by cxc on 2024/1/4.
//

#include "node.hpp"

Node::Node()
{
    vectors_.resize(1000 * 1000);
    data_ = new int[10000u * 10000u * 3u];
    ptr_ = std::make_shared<int>(3);
}

Node::~Node()
{
    delete[] data_;
}

std::vector<double>& Node::getVectors()
{
    return vectors_;
}