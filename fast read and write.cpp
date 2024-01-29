int read(){
  int x = 0;
  bool f = 1;
  char c = getchar();
  while(c < '0' || c > '9'){
    if(c == '-') {
      f = 0;
    }
    c=getchar();
  }
  while(c >= '0' && c <= '9'){
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return f ? x : -x;
}
void print(int x){
  if(x < 0) {
    putchar('-');
    x = -x;
  }
  if(x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}
