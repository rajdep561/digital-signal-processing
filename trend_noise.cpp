#include <vector>
#include <stdexcept>
#include "pybind11/include/pybind11/pybind11.h"
#include "pybind11/include/pybind11/stl.h"

class MovingAverageFilter {
    public:
    MovingAverageFilter(size_t window_size):window_size_(window_size),sum_(0.0){
    
        if (window_size==0){
            throw std::invalid_argument("window size cannot be zero");
        }
    
    }

    std::vector<double> process_vector(const std::vector<double>& data){
        std::vector<double> smoothed_data;
        smoothed_data.reserve(data.size());
        for (double point:data){
            smoothed_data.push_back(process(point));
        }
        return smoothed_data;
    }
    double process(double new_value){
        window_.push_back(new_value);
        sum_+=new_value;
        if (window_.size()>window_size_){
            sum_-=window_.front();
            window_.erase(window_.begin());
        }
        return sum_/window_.size();

    }
    private:
    size_t window_size_;
    std::vector<double> window_;
    double sum_;
};

namespace py=pybind11;

PYBIND11_MODULE(cpp_ma_filter,m){
    m.doc() = "C++ MA";
    py::class_<MovingAverageFilter>(m,"MovingAverageFilter")
    .def(py::init<size_t>())
    .def("process",&MovingAverageFilter::process,"PRocess a single data point")
    .def("process_vector",&MovingAverageFilter::process_vector,"Process a whole list/vector of data points");
}