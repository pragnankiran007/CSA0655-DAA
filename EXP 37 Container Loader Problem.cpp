#include <stdio.h>
#define MAX_CONTAINERS 100
void sortDescending(int weights[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (weights[j] < weights[j+1]) {
                int temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;
            }
        }
    }
}
int containerLoader(int weights[], int n, int capacity) {
    sortDescending(weights, n);
    int totalWeight = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (totalWeight + weights[i] <= capacity) {
            totalWeight += weights[i];
            count++;
        }
    }
    return count;
}
int main() {
    int n, capacity;
    int weights[MAX_CONTAINERS];
    printf("Enter the number of containers: ");
    scanf("%d", &n);
    printf("Enter the weights of the containers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the capacity of the loader: ");
    scanf("%d", &capacity);
    int maxContainers = containerLoader(weights, n, capacity);
    printf("Maximum number of containers that can be loaded: %d\n", maxContainers);
    return 0;
}
