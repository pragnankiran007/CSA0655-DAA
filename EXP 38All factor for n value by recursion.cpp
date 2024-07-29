#include <stdio.h>
void findFactors(int n, int i) {
    if (i > n / 2) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    findFactors(n, i + 1);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factors of %d are: 1 ", n);
    findFactors(n, 2);
    printf("%d\n", n); 
    return 0;
}
