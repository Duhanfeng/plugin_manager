﻿#pragma once

#include <iostream>
#include <ctime>
#include <chrono>

class Timer
{
public:
    Timer() :
        beg_(clock_::now())
    {
    }

    void reset()
    {
        beg_ = clock_::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_>(clock_::now() - beg_).count();
    }

    void out(const std::string& message = "")
    {
        double t = elapsed();
        std::cout << message << "\n    elapsed time:" << t * 1000 << "ms\n"
                  << std::endl;
        reset();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;

    typedef std::chrono::duration<double, std::ratio<1>> second_;

    std::chrono::time_point<clock_> beg_;
};
