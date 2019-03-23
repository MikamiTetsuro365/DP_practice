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
ll waru = 1e9+7;

int main() {

	ll N;
	cin >> N;

    vector<double > p(N,0);
    for(ll i = 0; i < N; i++){
        cin >> p[i];
    }

    vector<vector<double > > dp(N+1, vector<double >(N+1, 0));
    dp[0][0] = 1.0;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= i; j++){
            //全てのコインに区別をつけていつ表になった時、それが何枚目の表なのか
            //同じ枚数の表なら同じ列に足していくと結果的にn枚表だった時の確率
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j]   += dp[i][j] * (1.0 - p[i]);
        }
    }

    
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= N; j++){
            cout << fixed;
            cout << setprecision(5) << dp[i][j] << " ";
        }
        cout << endl;
    }

    double ans = 0;

    for(ll j = N/2+1; j <= N; j++){
        ans += dp[N][j];
    }
    
    cout << fixed;
    cout << setprecision(9) << ans << " ";    
}