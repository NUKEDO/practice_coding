#include <bits/stdc++.h>
using namespace std;

int h, w, x, y;
vector<string> pic(20);

void changePic(int a, int b, string xy) {
  for(int i = a; i <= b; i++) { //a ~ b (a ~ b-1 ではない)
    if(xy == "x") pic.at(y).at(i) = '*';
    else if(xy == "y") pic.at(i).at(x) = '*';
  }
}

void search(string str) {
  int x2 = x,  y2 = y;
  if(str == "y-") {
    y2--;
    while(y2 >= 0 && pic.at(y2).at(x2) == '.') y2--;
    if(y2 != -1 && pic.at(y2).at(x2) != '#') changePic(y2 + 1, y - 1, "y");
  } else if(str == "y+") {
    y2++;
    while(y2 < h && pic.at(y2).at(x2) == '.') y2++;
    if(y2 != h && pic.at(y2).at(x2) != '#') changePic(y + 1, y2 - 1, "y");
  } else if(str == "x-") {
    x2--;
    while(x2 >= 0 && pic.at(y2).at(x2) == '.') x2--;
    if(x2 != -1 && pic.at(y2).at(x2) != '#') changePic(x2 + 1, x - 1, "x");
  } else if(str == "x+") {
    x2++;
    while(x2 < w && pic.at(y2).at(x2) == '.') x2++;
    if(x2 != w && pic.at(y2).at(x2) != '#') changePic(x + 1, x2 - 1, "x");
  }
}

void reversiUDLR() {
  search("y-");
  search("y+");
  search("x-");
  search("x+");
}

void changeSlant(int x, int y, int r, string dir) {
  for(int i = 0; i < r; i++) {
    if(dir == "RD") pic.at(y + i).at(x + i) = '*';
    else if(dir == "RU") pic.at(y - i).at(x + i) = '*';
  }
}

void searchSlant(string str) {
  int x2 = x, y2 = y, sum = 0;
  if(str == "x-y-") {
    x2--;
    y2--;
    while(x2 >= 0 && y2 >= 0 && pic.at(y2).at(x2) == '.') {
      sum++;
      x2--;
      y2--;
    }
    if(x2 != -1 && y2 != -1 && pic.at(y2).at(x2) != '#') changeSlant(x2 + 1, y2 + 1, sum, "RD"); //RD:右下  
  } else if(str == "x-y+") {
    x2--;
    y2++;
    while(x2 >= 0 && y2 < h && pic.at(y2).at(x2) == '.') {
      sum++;
      x2--;
      y2++;
    }
    if(x2 != -1 && y2 != h && pic.at(y2).at(x2) != '#') changeSlant(x2 + 1, y2 - 1, sum, "RU");
  } else if(str == "x+y-") {
    x2++;
    y2--;
    while(x2 < w && y2 >= 0 && pic.at(y2).at(x2) == '.') {
      sum++;
      x2++;
      y2--;
    }
    if(x2 != w && y2 != -1 && pic.at(y2).at(x2) != '#') changeSlant(x + 1, y - 1, sum, "RU");
  } else if(str == "x+y+") {
    x2++;
    y2++;
    while(x2 < w && y2 < h && pic.at(y2).at(x2) == '.') {
      sum++;
      x2++;
      y2++;
    }
    if(x2 != w && y2 != h && pic.at(y2).at(x2) != '#') changeSlant(x + 1, y + 1, sum, "RD");
  }
}

void reversiSlant() {
  searchSlant("x-y-");
  searchSlant("x-y+");
  searchSlant("x+y-");
  searchSlant("x+y+");
}

void printPic(vector<string> v) {
  for(int i = 0; i < h; i++) {
    cout << v.at(i) << endl;
  }
}

int main() {
  int n;
  scanf("%d %d %d\n", &h, &w, &n);
  string str;
  for(int i = 0; i < h; i++) {
    cin >> str;
    pic.at(i) = str;
  }
  
  for(int i = 0; i < n; i++) {
    scanf("%d %d\n", &y, &x);
    pic.at(y).at(x) = '*';
    reversiUDLR();
    reversiSlant();
  }
  printPic(pic);
}