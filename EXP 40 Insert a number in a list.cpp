#include <stdio.h>
#define MAX_SIZE 100
void insertInSortedList(int list[], int *size, int num) {
    int i, pos;
    for (i = 0; i < *size; i++) {
        if (list[i] > num) {
            break;
        }
    }
    for (int j = *size; j > i; j--) {
        list[j] = list[j - 1];
    }
    list[i] = num;
    (*size)++;
}
void printList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
int main() {
    int list[MAX_SIZE];
    int size = 0; 
    int num;
    printf("Enter the number of elements in the sorted list: ");
    scanf("%d", &size);
    printf("Enter the elements of the sorted list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    insertInSortedList(list, &size, num);
    printf("Updated list: ");
    printList(list, size);
    return 0;
}
