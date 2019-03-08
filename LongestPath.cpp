#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int N = 0;
int M = 0;

int main(){
    //ナップサック問題　荷物の価値を最大化
    cin >> N;
    cin >> M;

    vector<vector<ll> > G;
    G = vector<vector<ll> >(N + 1, vector<ll>(N + 1, 0));

    int x, y = 0;
    for(int i = 0; i < M; i++){
        cin >> x;
        cin >> y;
        G[x][y] = 1;

    }

    //確認
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }   
    cout << endl; 

    vector<vector<ll> > dp;
    dp = vector<vector<ll> >(N + 1, vector<ll>(N + 1, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(G[i - 1][j] > 0){
                dp[j][i] += G[i][j];
            }else{
                dp[i][j] = dp[i][j];
            }
        }
    }

    //確認
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}