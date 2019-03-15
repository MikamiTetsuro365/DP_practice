#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

ll N;
ll M;
vector<vector<ll> > G;
vector<ll > dp;

ll dfs(ll n){

    if(dp[n] > 0){
        return dp[n];
    }

    ll mx = 0;
    //cout << n << " " ;
    for(ll i = 0; i < G[n].size(); i++){
        mx = max(mx, dfs(G[n][i]) + 1);
        //cout << n << "," << i << endl;
        //if(G[n][i] == 1){
        //    mx = max(mx, dfs(i) + 1);
        //}      
    }
    //cout << endl;
    dp[n] = mx;
    return dp[n];
}

int main(){

    cin >> N;
    cin >> M;

    G = vector<vector<ll> >(N);
    dp = vector<ll > (N , 0);

    ll x = 0, y = 0;
    for(ll i = 0; i < M; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        //G[x - 1][y - 1] = 1;
    }

    //確認
    /*
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    */

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        //cout << "ウェイ" <<  "," << i << endl;
        if(dp[i] == 0){
            ans = max(ans, dfs(i));
        }
    }

    cout << ans << endl;

}