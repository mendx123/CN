#include <stdio.h>

int main() {
    int a[10][10], n;
    int i, j, root;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter connection of %d --> %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter root node (1 to %d): ", n);
    scanf("%d", &root);
    printf("\nAdjacent nodes of root node %d:\n", root);
    for (i = 1; i <= n; i++) {
        if (a[root][i] == 1 || a[i][root] == 1) {
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}