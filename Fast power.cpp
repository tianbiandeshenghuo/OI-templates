#define int long long
int power(int a, int b, int p){//求 a^b % p
  int cnt = 1;
  for (; b; b >>= 1, (a *= a) %= P){
    if (b & 1){
      (cnt *= a) %= p;
    }
  }
  return cnt;
}
