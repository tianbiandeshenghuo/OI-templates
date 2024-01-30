//n 个点，已知边权已提前读入至 dis[][]

for (int q = 1; q <= 3; q++){//不管下面的顺序如何，跑 3 遍一定是正确的。
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        for (int k = 1; k <= n; k++){
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
  }
