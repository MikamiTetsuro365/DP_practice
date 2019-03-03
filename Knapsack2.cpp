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

int main(){
    //ナップサック問題　荷物の価値を最大化
    cin >> N;
    cin >> W;

    vector<pair<ll, ll> > T;

    ll value = 0;
    ll weight = 0;
    ll max_value = 0;
    
    //入力
    for(int i = 0; i < N; i++){
        cin >> weight >> value;
        max_value += value;
        T.push_back(make_pair(value, weight));
    }

    //価値が大きい順にソート 
    sort(T.rbegin(), T.rend());
    //余白
    T.insert(T.begin(), make_pair(0, 0));

    //dp　Value　価値を基準に表を作る
    vector<vector<ll> > dp;
    dp = vector<vector<ll> >(N + 1, vector<ll>(max_value + 1, -1));
    dp[0][0] = 0;

    //答え
    ll ans = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= max_value; j++){
            if(dp[i - 1][j] > -1){
                //直下を更新
                if(dp[i][j] <= dp[i - 1][j]){
                    dp[i][j] = dp[i - 1][j];
                }
                //荷物を足し合わせたところを更新
                if(dp[i][j + T[i].first] >= dp[i - 1][j] + T[i].second && dp[i - 1][j] + T[i].second <= W){
                    dp[i][j +T[i].first] = dp[i - 1][j] + T[i].second;
                    //ans確認
                    if(ans < j + T[i].first) ans = j + T[i].first;
                }
            }          
        }

    }

    cout << ans << endl;

    //確認
    
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= max_value; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
}