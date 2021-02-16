// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main() {
  string W, T;
  int sum = 0, j;
  cin >> W;
  while (getline(cin, T)) {
    if (T == "END_OF_TEXT") {
      break;
    }
    
    if (T.size() >= W.size()) { // 行の文字数 > 単語の文字数で実行
      for (int i = 0; i < T.size() - W.size() + 1; i++) {
        if (T.at(i) == W.at(0) || T.at(i) == W.at(0) + ('A' - 'a') || T.at(i) == W.at(0) - ('A' - 'a')) {
        // 一致する文字を確認した時
          if (i == 0 || (i >= 1 && T.at(i - 1) ==  ' ')) {
          // 一致する文字が列の先頭である、または単語の頭文字である
            j = 0;
            while (j != W.size()) {
              if (T.at(i + j) != W.at(j) && T.at(i + j) != W.at(j) + ('A' - 'a') && T.at(i + j) != W.at(j) - ('A' - 'a')) {
                // n文字目が一致しなければ不一致としてチェック終了
                break;
              }
              if (j == W.size() - 1) { // 全文字の一致を確認した時
                if (i + j == T.size() - 1 || T.at(i + j + 1) == ' ') {
                  // 一致した最後の文字が文の終了にある、または単語の末尾文字である
                  sum++;
                }
              }
              j++;
            }
          }
        }
      }
    }
  }

  cout << sum << endl;
}
