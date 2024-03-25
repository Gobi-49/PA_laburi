#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int val;
    struct list* next;
} List;

// Graph

List* createNode(int v) {
    List* queue = (List*) malloc(sizeof(List));
    queue->next = NULL;
    queue->val = v;
    return queue;
}

List* graph[11];
int visited[11];
int d[11];
int f[11];

void init_graph() {
    int i;
    for (i = 0; i < 11; i++) {
        visited[i] = 0;
        graph[i] = NULL;
    }
}

void add_edge(int i, int j) {
    List* newNode = createNode(j);
    newNode->next = graph[i];
    graph[i] = newNode;
}
int temp;
void DFS(int val) {
    visited[val] = 1;
    temp++;
    d[val] = temp;
    printf("%c ", val+'A');
    
    List* adjList = graph[val];
    while (adjList != NULL) {
        int adjVal = adjList->val;
        if (visited[adjVal] == 0) {
            
            DFS(adjVal);
        }
        adjList = adjList->next;
    }
    temp++;
    f[val] = temp;
}

int main() {
    int noduri;
    char nod;
    FILE *in = fopen("graf2.in", "r");
    fscanf(in, "%d", &noduri);
    int i = -1;
    init_graph();
    while(fscanf(in, "%c", &nod) && i <noduri ) {
        if(nod == '\n'){
            i++;
            continue;
        }
        if(nod ==  32 || nod == '-') {
            continue;
        }
        add_edge(i, nod-'A');
    }

    DFS(0);
    printf("\n");
    for(int i='A'; i<'A' + noduri; i++) {
        printf("%c ", i);
    }
    printf("\n");

    for(int i=0; i<noduri; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    for(int i=0; i<noduri; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
}
