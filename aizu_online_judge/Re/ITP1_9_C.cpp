#include <bits/stdc++.h>
using namespace std;
#define Taro 1
#define Hanako 2
#define EVEN 3

int main() {
  int n;
  string word_t, word_h;
  scanf("%d", &n);
  int p_t = 0, p_h = 0;
  for(int i = 0; i < n; i++) {
    cin >> word_t >> word_h;
    
    int min_str = min(word_t.size(), word_h.size());
    int winner = EVEN;
    for(int i = 0; i < min_str; i++) {
      if(word_t.at(i) > word_h.at(i)) winner = Taro;
      else if(word_t.at(i) < word_h.at(i)) winner = Hanako;
      if (winner != EVEN) break; 
    }
    
    if(winner == EVEN) {
      if(word_t.size() > word_h.size()) winner = Taro;
      else if(word_t.size() < word_h.size()) winner = Hanako;
    }
    
    if(winner == Taro) p_t += 3;
    else if(winner == Hanako) p_h += 3;
    else {
      p_t += 1;
      p_h += 1;
    }
  }

  printf("%d %d\n", p_t, p_h);
}