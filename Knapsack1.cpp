#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int N = 0;
int W = 0;
int K = 0;


int main(){
    //ナップサック問題　荷物の価値を最大化
    cin >> N;
    cin >> W;

    vector<vector<ll> > T;
    //重量：価値
    T = vector<vector<ll> >(N + 1, vector<ll>(2, 0));
    //初期化
    T[0][0] = 0;
    T[0][1] = 0;

    for(int i = 1; i < N + 1; i++){
        for(int j = 0;  j < 2; j++){
            cin >> T[i][j];
        }
    }
    
    //dp
    vector<vector<ll> > dp;
    dp = vector<vector<ll> >(N + 1, vector<ll>(W + 1, -1));
    dp[0][0] = 0;

    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < W + 1; j++){
            if(dp[i - 1][j] > -1){
                //直下を更新
                if(dp[i][j] <= dp[i - 1][j]){
                    dp[i][j] = dp[i - 1][j];
                } 
                //荷物が入らない
                if(j + T[i][0] > W) break;
                //荷物を足し合わせたところを更新
                if(dp[i][j + T[i][0]] <= dp[i - 1][j] + T[i][1]){
                    dp[i][j + T[i][0]] = dp[i - 1][j] + T[i][1];
                    cout << dp[i - 1][j] << " ";
                } 
            }          
        }
        cout << endl;
    }

    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < W + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}