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
//1から６までの整数が等確率にでるサイコロ
//このサイコロをN回振った時にでる目の和がK以上になる確率を求める

int main() {

	ll N, K;
	cin >> N >> K;
    ll diceNumMax = 6;
    double p[6] = {1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0,1.0/6.0};

    vector<vector<double > > dp(N+1, vector<double >(N * diceNumMax, 0));
    //初期化
    dp[0][0] = 1.0;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= K; j++){
            //求められないところは求めない
            if(dp[i][j] == 0.0) continue;
            for(ll d = 1; d <= diceNumMax; d++){
                //K以上が出たらもう更新しない
                if(j + d < K){
                    dp[i+1][j+d] += dp[i][j] * p[d-1];
                }
            }
        }
    }

    
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= K; j++){
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
    cout << K << "以上がでる確率:" << setprecision(9) << 1 - ans << endl;

}