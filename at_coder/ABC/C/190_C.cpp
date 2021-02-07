#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K; // 皿N枚, 条件M, 人数K
  cin >> N >> M;
  vector<vector<int>> terms(M, vector<int> (2));
  for (int i = 0; i < M; i++) {
    cin >> terms.at(i).at(0) >> terms.at(i).at(1);
  }
  
  cin >> K;
  vector<vector<int>> choice(K, vector<int> (2));
  for (int i = 0; i < K; i++) {
    cin >> choice.at(i).at(0) >> choice.at(i).at(1);
  }
  
  vector<int> balls(N, 0);
  for (int tmp = 0; tmp < (1 << K); tmp++) {
    bitset<K> s(tmp);
    
  }
}
