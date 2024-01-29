//线段树模板(单点修改，区间查询)

const int MAXN = 5e5;
int n, a[MAXN], tr[4 * MAXN];//数组长度 n,存储内容 a[],树存储在 tr[] 中

void js(int id, int l, int r){//建树
  if (l == r){
    tr[id] = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  js(id * 2, l, mid);
  js(id * 2 + 1, mid + 1, r);
  tr[id] = tr[id * 2] + tr[id * 2 + 1];
}
void xg(int id, int l, int r, int p, int q){//修改，a[p] <- a[p] + q
  if (l == r){
    tr[id] += q;
    return ;
  }
  int mid = (l + r) >> 1;
  if (mid < p){
    xg(id * 2 + 1, mid + 1, r, p, q);
  }else {
    xg(id * 2, l, mid, p, q);
  }
  tr[id] = tr[id * 2] + tr[id * 2 + 1];
}
int find(int id, int l, int r, int ql, int qr){//查询区间 [ql, qr] 的和
  if (ql <= l && r <= qr){
    return tr[id];
  }else if (l > qr || r < ql){
    return 0;
  }
  int mid = (l + r) >> 1;
  return find(id * 2, l, mid, ql, qr) + find(id * 2 + 1, mid + 1, r, ql, qr);
}
