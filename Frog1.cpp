#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
//int moreGcd
int N = 0;
vector<int > h;

int main(){
    
    cin >> N;

    int t = 0;

    for(int i = 0; i < N; i++){
        cin >> t;
        h.push_back(t);
    }
    
    vector<int > cost(N, 0);
    cost[0] = 0;
    cost[1] = abs(h[0] - h[1]);

    for(int i = 2; i  < N; i++){
        cost[i] = min(cost[i-2]+abs(h[i-2]-h[i]), cost[i-1]+abs(h[i]-h[i-1])); 
        cout << cost[i] << endl; 
    }
    
    //search(0, cost);

    cout << cost[N-1] << endl;

}