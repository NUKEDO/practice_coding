#include <bits/stdc++.h>
using namespace std;

int n, h, w, x, y, sum_time = 0;
string sign = "Go";
vector<string> dir = {"y-", "x+", "y+", "x-"};

void checkXY(vector<vector<char> > &pic) {
    if(x < 0 || x >= w || y < 0 || y >= h || sum_time > 100 ||
       pic.at(y).at(x) == '*' || pic.at(y).at(x) == '#') sign = "Stop";
}

void moveFront(int r, vector<vector<char> > &pic) {
    if(r == 0) return;
    
    if(dir.at(0) == "x+") {
        x++;
    } else if(dir.at(0) == "x-") {
        x--;
    } else if(dir.at(0) == "y+") {
        y++;
    } else if(dir.at(0) == "y-") {
        y--;
    }
    sum_time++;
    
    checkXY(pic);
    
    if(sign != "Go") {
        return;
    } else {
        pic.at(y).at(x) = '*';
        moveFront(r - 1, pic);
    }
}

void turnSnake(char c) {
    string save;
    if(c == 'L') {
        save = dir.at(0);
        dir.at(0) = dir.at(3);
        dir.at(3) = dir.at(2);
        dir.at(2) = dir.at(1);
        dir.at(1) = save;
    } else if(c == 'R') {
        save = dir.at(0);
        dir.at(0) = dir.at(1);
        dir.at(1) = dir.at(2);
        dir.at(2) = dir.at(3);
        dir.at(3) = save;
    }
}

void printPic(vector<vector<char> > pic) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%c", pic.at(i).at(j));
        }
        printf("\n");
    }
}

int main() {
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
    pic.at(y).at(x) = '*';
    for(int i = 0; i < n; i++) {
        scanf("%d %c\n", &time, &c);
        moveFront(time - before_time, pic);
        turnSnake(c);
        if(sign != "Go") break;
        before_time = time;
    }
    
    if(sign == "Go") {
        moveFront(100, pic);
    }
    
    printPic(pic);
}