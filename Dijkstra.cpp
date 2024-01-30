#define int long long

int n, m, dis[];//n 个点，m 条边，点 1 到每个点的最短路 dis[]

struct Node{
  int x, v;
  bool operator<(const Node &i)const{
    return v > i.v;
  }
}
struct bNode{
  int v, w;//一条 u -> v 边权为 w 的边
}

vector<bNode> a[]//邻接矩阵存边


for (int i = 2; i <= n; i++){
  dis[i] = 1e18;
}
priority_queue<Node> b;
b.push({1, 0});
while (b.size()){
  auto x = b.top();
  b.pop();
  if (x.v > dis[x.x){
    continue;
  }
  for (auto v : a[x.x]){
    if (dis[x.x] + v.w < dis[v.x]){
      dis[v.x] = dis[x.x] + v.w;
      b.push({v.x, dis[v.x]});
    }
  }
}
