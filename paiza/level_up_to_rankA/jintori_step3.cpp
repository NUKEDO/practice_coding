#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<char> > pic(20, vector<char>(20));

bool checkPoint(int x, int y) {
  if(x < 0 || x >= w || y < 0 || y >= h) return false;
  if(pic.at(y).at(x) != '.') return false;
  return true;
}

void searchUDLR(int x, int y) {
  if(checkPoint(x, y - 1)) {
    pic.at(y - 1).at(x) = '*';
    searchUDLR(x, y - 1);
  }
  if(checkPoint(x - 1, y)) {
    pic.at(y).at(x - 1) = '*';
    searchUDLR(x - 1, y);
  }
  if(checkPoint(x, y + 1)) {
    pic.at(y + 1).at(x) = '*';
    searchUDLR(x, y + 1);
  }
  if(checkPoint(x + 1, y)) {
    pic.at(y).at(x + 1) = '*';
    searchUDLR(x + 1, y);
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
  int x, y;
  for(int i = 0; i < h; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < w; j++) {
      pic.at(i).at(j) = str.at(j);
      if(str.at(j) == '*') {
        x = j;
        y = i;
      }
    }
  }
  
  searchUDLR(x, y);
  printPic(pic);
}