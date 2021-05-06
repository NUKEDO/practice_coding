#include <bits/stdc++.h>
using namespace std;

int isPrime(int num) { //num >= 2 の条件
  if(num != 2 && num % 2 == 0) return 0; //2以外の偶数は素数ではない
  int n = sqrt(num); //小数点以下切り捨て
  for(int i = 3; i <= n; i += 2) { //3~nまでの奇数で割れるかを試す, 偶数は5行目で判定済みなので飛ばす 
    if(num % i == 0) return 0; //約数発見
  }
  return 1; //numは素数
}

int main() {
  int n, num;
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    if(isPrime(num)) sum++;
  }
  printf("%d\n", sum);
}