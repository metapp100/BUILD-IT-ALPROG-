#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Fungsi untuk melakukan pengujian Miller-Rabin
bool millerRabinTest(unsigned long long n, unsigned int d) {
    // Pilih bilangan acak a antara 2 dan n-2
    unsigned long long a = 2 + rand() % (n - 4);
    unsigned long long x = pow(a, d);
    x = x % n;

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

// Fungsi untuk menentukan apakah n adalah bilangan prima
bool isPrime(unsigned long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    unsigned long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Uji Miller-Rabin dengan 5 basis
    for (int i = 0; i < 5; i++) {
        if (!millerRabinTest(n, d))
            return false;
    }
    return true;
}

int main() {
    unsigned long long N;
    
    // Membaca input
    scanf("%llu", &N);
    
    // Memeriksa apakah N adalah bilangan prima
    if (isPrime(N)) {
        printf("PRIMA\n");
    } else {
        printf("BUKAN\n");
    }
    
    return 0;
}
