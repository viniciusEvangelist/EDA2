#include "grafos.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int v; 
    struct No *prox;
} No;

struct Grafo {
    int n;
    No **lista;
};

Grafo* criarGrafo(int n){
    Grafo *g = malloc(sizeof(Grafo));
    g->n = n;
    g->lista = malloc(n * sizeof(No*));
    for(int i = 0; i < n; i++){
        g->lista[i] = NULL;
    }
    return g;
}

void inserirAresta(Grafo *g, int u, int v){
    No *novo = malloc(sizeof(No));
    novo->v = v;
    novo->prox = g->lista[u];
    g->lista[u] = novo;

    No *novo2 = malloc(sizeof(No));
    novo2->v = u;
    novo2->prox = g->lista[v];
    g->lista[v] = novo2;
}

void removerAresta(Grafo *g, int u, int v){
    No *ant = NULL;
    No *p = g->lista[u];

    while (p && p->v != v){
        ant = p;
        p = p->prox;
    }
    if (p){
        if (ant){
            ant->prox = p->prox;
        } else {
            g->lista[u] = p->prox;
        }
        free(p);
    }
}

void imprimirGrafo(Grafo *g){
    for(int i = 0; i < g->n; i++){
        printf("%d: ", i);
        No *p = g->lista[i];
        while(p){
            printf("%d -> ", p->v);
            p = p->prox;
        }
        printf("NULL\n");
    }
}