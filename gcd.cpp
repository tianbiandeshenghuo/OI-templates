int gcd(int a, int b){//求 a,b 的最大公约数
  if (!a || !b){// 特判 a 或 b 为 0 的情况
    return max(a, b);
  }
  while (a ^= b ^= a ^= b %= a);//辗转相除
  return b;
}
