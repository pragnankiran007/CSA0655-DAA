#include <stdio.h>
#include <stdbool.h>
#define V 5
void printSolution(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); 
}
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]];
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1)) {
                return true;
            }
            path[pos] = -1; 
        }
    }
    return false;
}
bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0; 

    if (!hamCycleUtil(graph, path, 1)) {
        printf("Solution does not exist\n");
        return false;
    }
    printSolution(path);
    return true;
}
int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    hamCycle(graph);
    return 0;
}
