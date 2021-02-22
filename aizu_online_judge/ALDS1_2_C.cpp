// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_C&lang=ja

#include <bits/stdc++.h>
using namespace std;

struct Card{
  int value;
  char suite;
};

vector<Card> bubbleSort(vector<Card> card, int N) {
  Card save_card;
  int flag = 1;
  if ( N != 1) {
    while(flag == 1){
      flag = 0;
      for (int j = N - 1; j > 0; j--) {
        if( card.at(j).value < card.at(j - 1).value ) {
          save_card = card.at(j);
          card.at(j) = card.at(j - 1);
          card.at(j - 1) = save_card;
          flag = 1;
        }
      }
    }
  }
  
  return card;
} 

vector<Card> selectionSort(vector<Card> card, int N) {
  int min_j;
  Card save_card;
  
  for( int i = 0; i < N - 1; i++ ) {
    min_j = i;
    for (int j = i + 1; j < N; j++ ) {
      if( card.at(j).value < card.at(min_j).value ) {
        min_j = j;
      }
    }
    if( min_j != i){
      save_card = card.at(i);
      card.at(i) = card.at(min_j);
      card.at(min_j) = save_card;
    }
  }
  
  return card;
}

void print_card(vector<Card> card, int N) {
  for(int i = 0; i < N; i++) {
    cout << card.at(i).suite << card.at(i).value;
    if( i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

void stable_judge(vector<Card> origin, vector<Card> new_card) {
  vector<int> num(9, 0);
  int x, y, z, w;
  string str_ori = "", str_new = "";
  
  for (int i = 0; i < origin.size(); i++) {
    for (int j = 0; j < 9; j++) {
      if(origin.at(i).value == j + 1) {
        num.at(j) += 1;
        break;
      }
    }
  }
    
  z = 0; // break用
  for (int i = 0; i < 9; i++) {
    x = num.at(i);
    
    if(x != 0) {
      w = 0;
      while( x != 0 ) {
        if(origin.at(w).value == i + 1) {
          str_ori.push_back( origin.at(w).suite );
          x--;
        }
        w++;
      }
      
      x = num.at(i);
      w = 0;
      while( x != 0 ) {
        if(new_card.at(w).value == i + 1) {
          str_new.push_back( new_card.at(w).suite );
          x--;
        }
        w++;
      }
           
      if(str_ori != str_new) {
        cout << "Not stable" << endl;
        z = 1;
      }
      
    }
    if(z == 1) {
      break; //for i
    }
  }
  
  if( z == 0) {
    cout << "Stable" << endl;
  }
}
  
int main() {
  int N;
  cin >> N;
  string str;
  vector<Card> card(N);
  for (int i = 0; i < N; i++) {
    cin >> str;
    card.at(i).suite = str.at(0);
    card.at(i).value = str.at(1) - '0';
  }

  vector<Card> bubble_sort_card = bubbleSort(card, N);
  print_card(bubble_sort_card, N);
  stable_judge(card, bubble_sort_card);
  
  vector<Card> selection_sort_card = selectionSort(card, N);
  print_card(selection_sort_card, N);
  stable_judge(card, selection_sort_card);
}