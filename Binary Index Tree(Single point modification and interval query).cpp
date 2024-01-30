int n, a[], tr[];//数组 a[] 为存储元素，长度为 n,tr[] 为树状数组

#define lb(x) x & -x //lowbit(x)


void add(int x, int p){//a[x] <- a[x] + p
  for(; x <= n; x += lb(x)){
    tr[x] += p;
  }
}

int find(int x){//查询区间 [1,x] 的和
  int cnt = 0;
  for (; x; x -= lb(x)){
    cnt += tr[x];
  }
  return cnt;
}
for (int i = 1; i <= n; i++){
  cin >> a[i];
  add(i, a[i]);
}
cout << find(r) - find(l - 1);//查询区间 [l,r] 的和
