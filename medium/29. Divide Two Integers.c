int divide(int dividend, int divisor){
    if(dividend == 0)
        return 0;
    
    if(dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    
    int nag = dividend < 0 ^ divisor < 0;
    
    long long m = fabs((long long)dividend);
    long long n = fabs((long long)divisor);
    long long ret = 0;
    
    while (m >= n) {
        long long t = n, p = 1;
        while (m > (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        ret += p;
        m -= t;
    }
    
    return nag == 1 ? -ret : ret;
}
