#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;
typedef long long ll;
//コイントス　連続

int main() {

	ll N, K;
	cin >> N >> K;
    double p = 1.0 / 2.0;

    vector<vector<double > > dp(N+1, vector<double >(K+1, 0));
    //初期化
    dp[1][1] = 1;

    for(ll i = 1; i < N; i++){
        for(ll j = 1; j <= K; j++){
            //if(dp[i][j] == 0.0) continue;
            if(j+1 < K){
                //連続中
                dp[i+1][j+1] += dp[i][j] * p;
            }         
            //連続が途切れる
            dp[i+1][1] += dp[i][j] * p;
        }
    }

    
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= K; j++){
            cout << fixed;
            cout << setprecision(5) << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    double ans = 0.0;

    for(ll j = 0; j < K; j++){
        ans += dp[N][j];
    }
    
    cout << fixed;
    cout << K << "連続以上がでる確率:" << setprecision(9) << 1 - ans << endl;
    
}