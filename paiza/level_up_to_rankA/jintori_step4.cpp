#include <bits/stdc++.h>
using namespace std;

struct Point{
  int x, y, t;
};

int h, w;
vector<vector<char> > pic(20, vector<char>(20));
queue<Point> q;

void intoQue(int x, int y, int t) {
  Point p;
  p.x = x;
  p.y = y;
  p.t = t;
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
  
  int x = p.x, y = p.y, t = p.t;
  if(checkPoint(x, y - 1)) {
    pic.at(y - 1).at(x) = t + 1 + '0';
    intoQue(x, y - 1, t + 1);
  }
  if(checkPoint(x - 1, y)) {
    pic.at(y).at(x - 1) = t + 1 + '0';
    intoQue(x - 1, y, t + 1);
  }
  if(checkPoint(x, y + 1)) {
    pic.at(y + 1).at(x) = t + 1 + '0';
    intoQue(x, y + 1, t + 1);
  }
  if(checkPoint(x + 1, y)) {
    pic.at(y).at(x + 1) = t + 1 + '0';
    intoQue(x + 1, y, t + 1);
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
  int t = 0;
  for(int i = 0; i < h; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < w; j++) {
      pic.at(i).at(j) = str.at(j);
      if(str.at(j) == '*') {
        intoQue(j, i, t);
        pic.at(i).at(j) = t + '0';
      }
    }
  }
  
  while(q.size() > 0) {
    searchUDLR();
  }
  printPic(pic);
}