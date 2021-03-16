// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C&lang=ja
// 螺旋本を見ながら作成
// ハッシュ計算用の素数・数式は螺旋本をそのまま引用

#include <bits/stdc++.h>
using namespace std;

int M = 1046527; // ハッシュ法で「key % M」に使うので素数でなければならない
vector<string> H(M);

int getChar(char c) {
  if(c == 'A') return 1;
  else if(c == 'C') return 2;
  else if(c == 'G') return 3;
  else if(c == 'T') return 4;
  else return 0;
}

int getKey(string str) {
  double sum = 0, n = str.size(), p = 1;
  for(int i = 0; i < n; i++) {
    sum += p * getChar(str.at(i));
    p *= 5;
  }
  return sum;
}

int h1(int key) {
  return key % M;
}

int h2(int key) {
  return 1 + (key % (M - 1));
}

void insert(string str) {
  double key = getKey(str);
  double h;
  for(int i = 0; ; i++) { // 挿入成功するまで実行するので終了条件なし
    h = (h1(key) + i * h2(key)) % M; // iが増加すれば異なる数値が返る式
    if(H.at(h).size() == 0) { // 空いてる箱ならそこに挿入して終了
      H.at(h) = str;
      break;
    } else if(H.at(h) == str) { //　箱に同じ文字列が入っているのならそのまま終了
      break;
    }
  }
}

bool find(string str) {
  double key = getKey(str);
  double h;
  for(int i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M; // insertで作ったhと同じ数値を確認する
	if(H.at(h) == str) { //　箱に同じ文字列が入っていれば発見
      return true;
    } else if(H.at(h).size() == 0) { //箱が空ならば存在しない
      return false;
    } //異なる文字列であれば次のiに進む
  }
}

int main() {
  int n;
  string com, str, ans;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    cin >> com >> str;
    if(com == "insert") {
      insert(str);
    } else {
      ans = find(str) ? "yes" : "no";
      printf("%s\n", ans.c_str());
    }
  }
}