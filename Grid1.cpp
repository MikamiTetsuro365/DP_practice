#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
ll waru = 1e9+7;

int main() {

	ll H, W;
	cin >> H >> W;
	vector<vector<ll > > K(H + 2, vector<ll >(W + 2, 0));

    string t;
	for(ll i = 1; i <= H; i++){
        cin >> t;
        for(ll j = 1; j <= W; j++){
            if(t.substr(j-1,1) == "."){
                K[i][j] = 1;
            }
        }
	}
    
    vector<vector<ll > > dp(H + 2, vector<ll >(W + 2, 0));
    dp[1][1] = 1;
	for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            if(i == 1 && j == 1) continue;
            if(K[i][j] != 1) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            //途中で越えることもあるかもなので一応剰余とる
            dp[i][j] %= waru;
        }
	}
    
    /*
	for(ll i = 1; i <= H; i++){
        for(ll j = 1; j <= W; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
	}
    */
    

    ll ans = dp[H][W] % waru;

    cout << ans  << endl;
      
}
