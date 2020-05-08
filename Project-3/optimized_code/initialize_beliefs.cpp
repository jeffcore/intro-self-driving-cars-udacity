#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
  	int i, j;
	float prob_per_cell = 1.0 / ( (float) grid.size() * grid[0].size()) ;

	vector< vector <float> > newGrid;
    newGrid.reserve(grid.size());
	vector<float> newRow;
    newRow.assign(grid[0].size(), prob_per_cell);
  
  	// OPTIMIZATION: Is there a way to get the same results 	// without nested for loops?
  	for (int j = 0; j < grid.size(); j++) {
        newGrid.push_back(newRow);
    }
	return newGrid;
}