#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membandingkan dua integer untuk qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    
    // Membaca jumlah nilai
    scanf("%d", &N);
    
    // Validasi jumlah nilai
    if (N < 1 || N > 10000) {
        fprintf(stderr, "Jumlah nilai tidak valid\n");
        return 1;
    }
    
    int values[N];
    
    // Membaca nilai-nilai
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
        
        // Validasi nilai
        if (values[i] < -10000 || values[i] > 10000) {
            fprintf(stderr, "Nilai di luar batas\n");
            return 1;
        }
    }
    
    // Mengurutkan nilai-nilai
    qsort(values, N, sizeof(int), compare);
    
    // Menampilkan hasil
    for (int i = 0; i < N; i++) {
        printf("%d\n", values[i]);
    }
    
    return 0;
}


