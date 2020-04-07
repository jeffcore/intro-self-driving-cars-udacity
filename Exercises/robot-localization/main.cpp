#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

vector<float> sense(vector<float> p, string Z, vector<string> world, float pHit, float pMiss) ;
vector<float> move(vector<float> p, int U);

int main() {
    vector<float> p (5, 0.2);
    vector<string> world (5);
    world[0] = "green";
    world[1] = "red";
    world[2] = "red";
    world[3] = "green";
    world[4] = "green";
    
    vector<string> measurements (2);
    measurements[0] = "red";
    measurements[1] = "green";   
    vector<int> motions (2, 1);
    float pHit = 0.6;
    float pMiss = 0.2;

    for (int i = 0; i < measurements.size(); i++) {
        p = sense(p, measurements[i], world, pHit, pMiss);
        p = move(p, motions[i]);
    }

    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;        
    }
    
	return 0;
}

vector<float> sense(vector<float> p, string Z, vector<string> world, float pHit, float pMiss) {
    vector<float> q (5);
    int hit;
    float sum;

    for (int i = 0; i < p.size(); i++) {        
        if (Z == world[i]) {
            hit = 1;
        }  else {
            hit = 0;
        }      
        q[i] = (p[i] * (hit * pHit + (1-hit) * pMiss));              
    }
    sum = accumulate(q.begin(), q.end(), 0.0); 
    
    for (int i = 0; i < q.size(); i++) {       
        q[i] = q[i] / sum;        
    }

    return q;
}

vector<float> move(vector<float> p, int U) {
    vector<float> q (5);
    float s;
    float pExact = 0.8;
    float pOvershoot = 0.1;
    float pUndershoot = 0.1;

     for (int i = 0; i < p.size(); i++) {
        s = pExact * p[(p.size() + (i-U % p.size())) % p.size()];
        s = s + pOvershoot * p[(p.size() + (i-U-1 % p.size())) % p.size()];
        s = s + pUndershoot * p[(p.size() + (i-U+1 % p.size())) % p.size()];
        q[i] = s;        
     }

    return q;
}