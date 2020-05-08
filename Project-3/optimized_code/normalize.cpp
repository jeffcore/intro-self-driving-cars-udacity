#include "headers/normalize.h"
using namespace std;

// OPTIMIZATION: Pass variable by reference
vector< vector<float> > normalize(vector< vector <float> > &grid) {

  	// OPTIMIZATION: Avoid declaring and defining 				// intermediate variables that are not needed.
	float total = 0.0;
	int i;
	int j;
	vector<float> row;
	vector<float> newRow;
	
	for (i = 0; i < grid.size(); i++)
	{		
		for (j=0; j < grid[i].size(); j++)
		{			
			total += grid[i][j];
		}
	}

	vector< vector<float> > newGrid;

	for (i = 0; i < grid.size(); i++) {				
		for (j=0; j< grid[i].size(); j++) {			
			grid[i][j] = grid[i][j] / total;
		}
	}

	return grid;
}
