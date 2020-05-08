#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back
	vector < vector <float> > newGrid;	
	int i, j;		

	static float GLOBAL_BLURRING = 0.12;

	static float CENTER = 1.0 - GLOBAL_BLURRING;
	static float CORNER = GLOBAL_BLURRING / 12.0;
	static float ADJACENT = GLOBAL_BLURRING / 6.0;


	static vector< vector<float> > GLOBAL_WINDOW = {
        {CORNER, ADJACENT, CORNER},
        {ADJACENT, CENTER, ADJACENT},
        {CORNER, ADJACENT, CORNER}
    };

	static vector <int> DX = {-1, 0, 1};
	static vector <int> DY = {-1, 0, 1};

	int dx;
	int dy;
	int ii;
	int jj;
	int new_i;
	int new_j;
	float multiplier;
	float newVal;
    float val;

	// OPTIMIZATION: Use your improved zeros function  
  	newGrid = zeros(grid.size(), grid[0].size());

	for (i=0; i< grid.size(); i++ ) {
		for (j=0; j<grid[0].size(); j++ ) {
			val = grid[i][j];
			newVal = val;
			for (ii=0; ii<3; ii++) {
				dy = DY[ii];
				for (jj=0; jj<3; jj++) {
					dx = DX[jj];
					new_i = (i + dy + grid.size()) % grid.size();
					new_j = (j + dx + grid[0].size()) % grid[0].size();					
					newGrid[new_i][new_j] += newVal * GLOBAL_WINDOW[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
