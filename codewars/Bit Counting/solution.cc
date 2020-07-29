unsigned int countBits(unsigned long long n){
    unsigned int cnt = 0;
    while (n > 0) {
        n -= n & -n;
        ++cnt;
    }
    return cnt;
}
