int power(int x, unsigned p) {
    if (p == 0) return 1;
    else if (p == 1) return x;
    else return x * power(x, --p);
}