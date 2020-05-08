#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector< vector <float> > move(int dy, int dx, 
	vector < vector <float> > &beliefs) 
{
	float belief;
	vector < vector <float> > newGrid = zeros(beliefs.size(), beliefs[0].size());
  
	// OPTIMIZATION: Eliminate any variables that aren't needed
	
	int i, j, new_i, new_j;
	
  	for (i=0; i<beliefs.size(); i++) {
		for (j=0; j<beliefs[i].size(); j++) {
			new_i = (i + dy + beliefs.size()) % beliefs.size();
			new_j = (j + dx + beliefs[0].size())  % beliefs[0].size();
			newGrid[new_i][new_j] = beliefs[i][j];
		}
	}
	return beliefs;
}
