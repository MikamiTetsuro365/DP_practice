#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
//int moreGcd
int N = 0;
int K = 0;
vector<int > h;

//何がだめなのか全くわからん

int main(){
    
    cin >> N;
    cin >> K;

    int t = 0;

     h.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> t;
        h.push_back(t);
    }
    
    vector<int > cost(N + 1, 1145141919);

    //cout << cost.size() << endl;

    //初期化的な
    cost[0] = 0;
    cost[1] = 0;

    for(int i = 1; i <= N; i++){
        //cout << h[i] << endl;
        for(int j = 1; j <= K; j++){
            if(i - j >= 1){
                //cout << abs(h[i]-h[i-j]) << endl;
                
                cost[i] = min(cost[i], cost[i-j] + abs(h[i]-h[i-j]));
                //cout << cost[i] << " " ;

            }
        }
        
        //cout << "::" << cost[i] << endl;

    }

    cout << cost[N] << endl;

}