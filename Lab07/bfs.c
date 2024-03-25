#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int val;
    struct list* next;
} List;

List* createQueue(int start) {
    List* queue = (List*) malloc(sizeof(List));
    queue->next = NULL;
    queue->val = start;
    return queue;
}

int isEmpty(List* q) {
    return q == NULL;
}

void enqueue(List** q, int value) {
    List* node = (List*) malloc(sizeof(List));
    node->val = value;
    if(*q == NULL) {
        *q = node;
        return;
    }
    List* aux = *q;
    while (!isEmpty(aux->next))
    {
        aux = aux->next;
    }
    aux->next = node;
}

int dequeue(List** q) {
    int item;
    if (isEmpty(*q)) {
        printf("lista goala");
        return -1;
    }
    else {
        item = (*q)->val;
        (*q) = (*q)->next;
    }
    return item;
}

// Graph

List* createNode(int v) {
    List* queue = (List*) malloc(sizeof(List));
    queue->next = NULL;
    queue->val = v;
    return queue;
}

List* graph[11];
int visited[11];
int distance[11];

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

void bfs(int start_node) {
    List* q = createQueue(start_node);
    visited[start_node] = 1;

    while (!isEmpty(q)) {
        int current_node = dequeue(&q);
        printf("%c %d\n", current_node+'A', distance[current_node]);

        List* temp = graph[current_node];
        while (temp != NULL) {
            int adj_node = temp->val;
            if (!visited[adj_node]) {
                distance[adj_node] = distance[current_node] + 1;
                visited[adj_node] = 1;
                enqueue(&q, adj_node);
            }
            temp = temp->next;
        }
    }
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

    bfs(0);
    printf("\ndistante\n");
    for(int i=0; i<noduri; i++) {
        printf("%d ", distance[i]);
    }
    printf("\n");
    for(int i='A'; i<'A' + noduri; i++) {
        printf("%c ", i);
    }
    printf("\n");

    return 0;
}
