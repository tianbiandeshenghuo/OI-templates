int fa[];
int find(int x){
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
