#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > vector_dot_product (vector< vector<int> > v1, vector< vector<int> > v2);

int main() {
    vector< vector<int> > v1 (4, vector<int>(3,4));
    vector< vector<int> > v2 (3, vector<int>(3,2));    
    vector< vector<int> > v_results;
    try {
    	v_results = vector_dot_product(v1, v2);
	}catch( const char* msg ) {
   		cout << msg << endl;
	}
    for (int row = 0; row < v_results.size(); row++) {
        for (int column = 0; column < v_results[0].size(); column++) {
            cout << v_results[row][column] << " ";
        }
        cout << endl;
    }
	
	return 0;
}

vector< vector<int> > vector_dot_product (vector< vector<int> > v1, vector< vector<int> > v2) {
    float total = 0;
	
	if (v1[0].size() != v2.size()) {
		throw "vector 1 column count does not match vector row count";
	}
	
	vector< vector<int> > v_results  (v1.size(), vector<int>(v1[0].size(),0));
    
    for (int row = 0; row < v1.size(); row++) {		        
		for (int column = 0; column < v2[0].size(); column++) {
			total = 0;
			for (int column_inner = 0; column_inner < v2.size(); column_inner++) {
				total += (v1[row][column_inner] * v2[column][column_inner]);
			}
			v_results[row][column] = total;			
        }		
		
    }
    
    return v_results;
}


