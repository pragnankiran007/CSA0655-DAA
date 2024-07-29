#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define N 4
int min(int a, int b) {
    return (a < b) ? a : b;
}
void copyToFinal(int curr_path[], int final_path[]) {
    for (int i = 0; i < N; i++) {
        final_path[i] = curr_path[i];
    }
    final_path[N] = curr_path[0];
}
int firstMin(int cost[N][N], int i) {
    int min = INT_MAX;
    for (int k = 0; k < N; k++) {
        if (cost[i][k] < min && i != k) {
            min = cost[i][k];
        }
    }
    return min;
}
int secondMin(int cost[N][N], int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) {
            continue;
        }
        if (cost[i][j] <= first) {
            second = first;
            first = cost[i][j];
        } else if (cost[i][j] <= second && cost[i][j] != first) {
            second = cost[i][j];
        }
    }
    return second;
}
void TSPRec(int cost[N][N], int curr_bound, int curr_weight, int level, int curr_path[], bool visited[], int final_path[], int *final_res) {
    if (level == N) {
        if (cost[curr_path[level - 1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + cost[curr_path[level - 1]][curr_path[0]];
            if (curr_res < *final_res) {
                copyToFinal(curr_path, final_path);
                *final_res = curr_res;
            }
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (cost[curr_path[level - 1]][i] != 0 && visited[i] == false) {
            int temp = curr_bound;
            curr_weight += cost[curr_path[level - 1]][i];
            if (level == 1) {
                curr_bound -= ((firstMin(cost, curr_path[level - 1]) + firstMin(cost, i)) / 2);
            } else {
                curr_bound -= ((secondMin(cost, curr_path[level - 1]) + firstMin(cost, i)) / 2);
            }
            if (curr_bound + curr_weight < *final_res) {
                curr_path[level] = i;
                visited[i] = true;

                TSPRec(cost, curr_bound, curr_weight, level + 1, curr_path, visited, final_path, final_res);
            }
            curr_weight -= cost[curr_path[level - 1]][i];
            curr_bound = temp;

            for (int j = 0; j < N; j++) {
                visited[j] = false;
            }
            for (int j = 0; j <= level - 1; j++) {
                visited[curr_path[j]] = true;
            }
        }
    }
}
void TSP(int cost[N][N]) {
    int curr_bound = 0;
    int curr_path[N + 1];
    int final_path[N + 1];
    bool visited[N];
    int final_res = INT_MAX;
    for (int i = 0; i < N; i++) {
        curr_bound += (firstMin(cost, i) + secondMin(cost, i));
    }
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    curr_path[0] = 0;
    TSPRec(cost, curr_bound, 0, 1, curr_path, visited, final_path, &final_res);
    printf("Minimum cost : %d\n", final_res);
    printf("Path taken : ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", final_path[i]);
    }
    printf("\n");
}
int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    TSP(cost);
    return 0;
}
