#include <bits/stdc++.h>
using namespace std;

int h, w, x, y;
string stop = "Go";
vector<string> dir = {"y-", "x+", "y+", "x-"};

void checkXY(char c, vector<vector<char> > &pic) { // メモリ消費を抑えるために&をつけた
  if(c == 'x') {
    if(x < 0 || x >= w) {
      stop = "Stop";
      return;
    }
  } else if(c == 'y') {
    if(y < 0 || y >= h) {
      stop = "Stop";
      return;
    }
  }
  if(pic.at(y).at(x) == '#') {
    stop = "Stop";
  }
}


void moveDir(int r, vector<vector<char> > &pic) {
  if(r == 0) return;
  
  if(dir.at(0) == "x+") {
    x++;
    checkXY('x', pic);
  } else if(dir.at(0) == "x-") {
    x--;
    checkXY('x', pic);
  } else if(dir.at(0) == "y+") {
    y++;
    checkXY('y', pic);
  } else if(dir.at(0) == "y-") {
    y--;
    checkXY('y', pic);
  }
  
  if(stop == "Go") printf("%d %d\n", y, x);
  else {
    printf("Stop\n");
    return;
  }
  moveDir(r - 1, pic);
}

void turnDir(char c) {
  string save;
  if(c == 'R') {
    save = dir.at(0);
    dir.at(0) = dir.at(1);
    dir.at(1) = dir.at(2);
    dir.at(2) = dir.at(3);
    dir.at(3) = save;
  } else if(c == 'L') {
    save = dir.at(0);
    dir.at(0) = dir.at(3);
    dir.at(3) = dir.at(2);
    dir.at(2) = dir.at(1);
    dir.at(1) = save;
  }
}

int main(void){
  int n;
  scanf("%d %d %d %d %d\n", &h, &w, &y, &x, &n);
  vector<vector<char> > pic(h, vector<char>(w));
  string str;
  for(int i = 0; i < h; i++) {
    cin >> str;
    for(int j = 0; j < w; j++) {
      pic.at(i).at(j) = str.at(j);
    }
  }
  int time, before_time = 0;
  char c;
  for(int i = 0; i < n; i++) {
    scanf("%d %c\n", &time, &c);
    int dist = time - before_time;
    moveDir(dist, pic);
    
    if(stop == "Stop") break;
    
    turnDir(c);
    before_time = time;
  }
}