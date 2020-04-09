#include "matrix.h"
#include <vector>

Matrix::Matrix() {
    std::vector <std:: vector <float> > initial_grid (10, std::vector <float>(5, 0.5));
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();
}

Matrix::Matrix(std::vector< std::vector<float> > initial_grid) {
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();
}

// set functions
void Matrix::setGrid(std::vector< std::vector<float> > initial_grid){
    grid = initial_grid;
    rows = initial_grid.size();
    cols = initial_grid[0].size();

}

// get functions
std::vector< std::vector<float> > Matrix::getGrid(){
    return grid;
}
std::vector<float>::size_type Matrix::getRows(){
    return rows;    
}
std::vector<float>::size_type Matrix::getCols(){
    return cols;
}

// functions
Matrix Matrix::matrix_addition (Matrix other_matrix) {
    if ((rows != other_matrix.getRows()) || (cols != other_matrix.getCols())) {
        throw std::invalid_argument( "matrices are not the same size" );
    }
    std::vector< std::vector<float> > matrix3 (grid.size(), std::vector<float>(grid[0].size(), 0));
    Matrix matrix_sum = Matrix(matrix3);
    
    for (int row = 0; row < grid.size(); row++) {
        for (int column = 0; column < grid[0].size(); column++) {
            matrix_sum.grid[row][column] = grid[row][column] + other_matrix.grid[row][column];
        }
    }
    
    return matrix_sum;
}

Matrix Matrix::matrix_transpose() {
    std::vector< std::vector<float> > new_grid;
    std::vector<float> row;

    for (int i = 0; i < cols; i++) {
        row.clear();

        for (int j = 0; j < rows; j++) {
            row.push_back(grid[j][i]); 
        }
        new_grid.push_back(row);
    }

    return Matrix(new_grid);
}

void Matrix::matrix_print() {
     for (int row = 0; row < grid.size(); row++) {
        for (int column = 0; column < grid[0].size(); column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

