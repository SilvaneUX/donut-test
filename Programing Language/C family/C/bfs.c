#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Function to add element to queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void bfs(int adj[MAX][MAX], int n, int start) {
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int n, i, j, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}
