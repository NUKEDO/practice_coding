#include <bits/stdc++.h>
using namespace std;

int h, w, x, y;
vector<string> pic(20);

void changePic(int a, int b, char xy) {
  for(int i = a; i <= b; i++) { //a ~ b (a ~ b-1 ではない)
    if(xy == 'x') pic.at(y).at(i) = '*';
    else pic.at(i).at(x) = '*';
  }
}

void search(string str) {
  int x2 = x,  y2 = y;
  if(str == "y-") {
    y2--;
    while(y2 >= 0 && pic.at(y2).at(x2) == '.') {
      y2--;
    }
    if(y2 != -1) changePic(y2 + 1, y - 1, 'y');
  } else if(str == "y+") {
    y2++;
    while(y2 < h && pic.at(y2).at(x2) == '.') {
      y2++;
    }
    if(y2 != h) changePic(y + 1, y2 - 1, 'y');
  } else if(str == "x-") {
    x2--;
    while(x2 >= 0 && pic.at(y2).at(x2) == '.') {
      x2--;
    }
    if(x2 != -1) changePic(x2 + 1, x - 1, 'x');
  } else if(str == "x+") {
    x2++;
    while(x2 < w && pic.at(y2).at(x2) == '.') {
      x2++;
    }
    if(x2 != w) changePic(x + 1, x2 - 1, 'x');
  }
}

void reversiUDLR() {
  search("y-");
  search("y+");
  search("x-");
  search("x+");
}

void printPic(vector<string> v) {
  for(int i = 0; i < h; i++) {
    cout << v.at(i) << endl;
  }
}

int main() {
  scanf("%d %d %d %d\n", &h, &w, &y, &x);
  string str;
  for(int i = 0; i < h; i++) {
    cin >> str;
    pic.at(i) = str;
  }

  pic.at(y).at(x) = '*';
  reversiUDLR();
  printPic(pic);
}