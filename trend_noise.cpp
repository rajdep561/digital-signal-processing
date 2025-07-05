#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <iomanip>

class MovingAverageFilter {
    public:
    MovingAverageFilter(size_t window_size):window_size_(window_size),sum_(0.0){
        if (window_size ==0){
            throw std::invalid_argument("window size cannot be zero");
        })
    }

    double process(double new_value){
        window_push_back(new_value);
        sum_+=new_value;
        if (window_.size()>window_size_){
            sum_ -=window_.front();
            window_.erase(window_.begin());
        }
        return sum_/window_.size();
    }

    private:
    size_t window_size_;
    std::vector<double> window_;
    double sum_;
};

int main(){
    const int signal_length = 100;
    std::vector<double> original_signal;
    original_signal.reserve(signal_length);

    std::randeom_device_rd;
    //filtering_decomposition_tutorial.cpp
}