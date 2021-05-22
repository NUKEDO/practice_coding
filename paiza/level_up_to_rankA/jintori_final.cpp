#include <bits/stdc++.h>
using namespace std;

struct Point{
  int x, y;
  char c;
};

int h, w, sum_A = 1, sum_B = 1;
vector<vector<char> > pic(1000, vector<char>(1000));
queue<Point> q;

void intoQue(int x, int y, char c) {
  Point p;
  p.x = x;
  p.y = y;
  p.c = c;
  q.push(p);
}

bool checkPoint(int x, int y) {
  if(x < 0 || x >= w || y < 0 || y >= h) return false;
  if(pic.at(y).at(x) != '.') return false;
  return true;
}

void searchUDLR() {
  Point p = q.front();
  q.pop();
  
  int x = p.x, y = p.y;
  char c = p.c;
  if(checkPoint(x, y - 1)) {
    pic.at(y - 1).at(x) = c;
    intoQue(x, y - 1, c);
    if(c == 'A') sum_A++;
    else sum_B++;
  }
  if(checkPoint(x - 1, y)) {
    pic.at(y).at(x - 1) = c;
    intoQue(x - 1, y, c);
    if(c == 'A') sum_A++;
    else sum_B++;
  }
  if(checkPoint(x, y + 1)) {
    pic.at(y + 1).at(x) = c;
    intoQue(x, y + 1, c);
    if(c == 'A') sum_A++;
    else sum_B++;
  }
  if(checkPoint(x + 1, y)) {
    pic.at(y).at(x + 1) = c;
    intoQue(x + 1, y, c);
    if(c == 'A') sum_A++;
    else sum_B++;
  }
}

void printPic(vector<vector<char> > v) {
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      printf("%c", v.at(i).at(j));
    }
    printf("\n");
  }
}

int main() {
  scanf("%d %d\n", &h, &w);
  char first;
  scanf("%c\n", &first);
  Point second;
  for(int i = 0; i < h; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < w; j++) {
      pic.at(i).at(j) = str.at(j);
      if(str.at(j) == 'A' || str.at(j) == 'B') {
        if(str.at(j) == first) {
          intoQue(j, i, str.at(j));
        } else {
          second.x = j;
          second.y = i;
          second.c = str.at(j);
        }
      }
    }
  }
  intoQue(second.x, second.y, second.c);
  
  
  while(q.size() > 0) {
    searchUDLR();
  }
  
  string ans;
  if(sum_A > sum_B) ans = "A";
  else if(sum_A < sum_B) ans = "B";
  else ans = "Draw";
  printf("%d %d\n%s\n", sum_A, sum_B, ans.c_str());
}