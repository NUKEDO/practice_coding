#include <bits/stdc++.h>
using namespace std;

int n;

struct Card {
  char suite;
  int num;
};

void CardBubbleSort(vector<Card> &A) {
  for(int i = 0; i < n; i++) { 
    for(int j = n - 1; j >= i + 1; j--) {
      if(A.at(j).num < A.at(j - 1).num) {
        swap(A.at(j), A.at(j - 1));
      }
    }
  }
}

void CardSelectionSort(vector<Card> &A) {
  for(int i = 0; i < n - 1; i++) {
    int min_A = INT_MAX, min_j;
    for(int j = i; j < n; j++) {
      if(min_A > A.at(j).num) {
        min_A = A.at(j).num;
        min_j = j;
      }
    }
    if(i != min_j) {
      swap(A.at(i), A.at(min_j));
    }
  }
}

void printCard(vector<Card> A) {
  for(int i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%c%d", A.at(i).suite, A.at(i).num);
  }
  printf("\n");
}

int sameCheck(vector<Card> A, vector<Card> B) {
  for(int i = 0; i < n; i++) {
    if(A.at(i).suite != B.at(i).suite) return 0;
  }
  return 1;
}

int main() {
  scanf("%d\n", &n);
  vector<Card> A(n), B(n);
  for(int i = 0; i < n; i++) {
    scanf("%c%d ", &A.at(i).suite, &A.at(i).num);
    B.at(i).suite = A.at(i).suite;
    B.at(i).num = A.at(i).num;
  }
  
  CardBubbleSort(A); //必ず安定的なソート
  CardSelectionSort(B);
  
  printCard(A);
  printf("Stable\n");
  printCard(B);
  if(sameCheck(A, B)) printf("Stable\n");
  else printf("Not stable\n");
}