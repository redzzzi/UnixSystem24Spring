void multstore(long x, long y, long *dest) {
  lont t = mult2(x, y);
  *dest = t;
}

void mult2(long a, long b) {
  long s = a * b;
  return s;
}
