#include <stdio.h>
#define MAX 100
int n, target, subset[MAX], solution[MAX];
void findSubset(int s, int k, int sum) {
    if (sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < k; i++) {
            if (solution[i]) {
                printf("%d ", subset[i]);
            }
        }
        printf("\n");
        return;
    }
    if (s >= n || sum > target) {
        return;
    }
    solution[s] = 1;
    findSubset(s + 1, k + 1, sum + subset[s]);
    solution[s] = 0;
    findSubset(s + 1, k, sum);
}
int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &subset[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    printf("Subsets with the target sum are:\n");
    findSubset(0, 0, 0);
    return 0;
}
