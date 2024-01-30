int n, m;//n 个点和 m 条边
int fa[];//并查集


struct Node{
  int u, v, w;
  bool operator<(const Node &i)const{
    return w < i.w;
  }
};
vector<Node> a;//存储每条边
vector<Node> tr;//存储最小生成树的所有边

int find(int x){
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}

sort(a.begin(), a.end());

for (auto v : a){//遍历每条边
  if (find(v.u) != find(v.v)){
    fa[v.u] = find(v.v);
    tr.push_back(v);
  }
}
