#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101];
    
    // Membaca input string A dan B
    scanf("%100s", A);
    scanf("%100s", B);
    
    // Mendapatkan panjang kedua string
    int lenA = strlen(A);
    int lenB = strlen(B);
    
    // Memeriksa panjang string
    if (lenA != lenB) {
        printf("BERBEDA\n");
    } else {
        // Memeriksa apakah string identik
        if (strcmp(A, B) == 0) {
            printf("IDENTIK\n");
        } else {
            printf("MIRIP\n");
        }
    }
    
    return 0;
}
