int fib(int n)
{
  int i;
  if ((n==0) | (n==1)) return n;
  int a = 0;
  int b = 1;
  int tmp;
  for (i=0; i<n; i++) {
    tmp = b;
    b = a+b;
    a = tmp;
  }
  return a;
}
