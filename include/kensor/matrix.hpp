#pragma once

#include <kensor/core.hpp>

#include<stdexcept>
#include <vector>

namespace kensor{

class Matrix{
    public:
        Matrix(index_t rows, index_t cols)
            : rows_(rows),
            cols_(cols),
            data_(static_cast<std::size_t>(rows * cols), 0.0){
                if (rows <= 0 || cols <= 0){
                    throw std::invalid_argument("Matrix dimensions must be positive");
                }
        }

        index_t rows() const { return rows_; }
        index_t cols() const { return cols_; }


        double& operator()(index_t i, index_t j){
            return data_[flat_index(i, j)];
        }


        const double& operator()(index_t i, index_t j) const {
            return data_[flat_index(i, j)];
        }
    
    private: 
        std::size_t flat_index(index_t i, index_t j) const {
            return static_cast<std::size_t>(i * cols_ + j);
        }

        index_t rows_;
        index_t cols_;
        std::vector<double> data_;


}; 


}