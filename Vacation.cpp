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

int main(){
    
    cin >> N;

    vector<vector<int> > T;
    T = vector<vector<int> >(N + 1, vector<int>(3, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 0;  j < 3; j++){
            cin >> T[i][j];
        }
    }

    vector<vector<int> > dp;
    dp = vector<vector<int> >(N + 1, vector<int>(3, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(!(k == j)) dp[i][j] = max(dp[i][j], dp[i - 1][k] + T[i][j]);
            }
        }
    }

    
    for(int i = 0; i <= N; i++){
        for(int j = 0;  j < 3; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[N][2] << endl;

}