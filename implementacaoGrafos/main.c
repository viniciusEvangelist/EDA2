#include <stdio.h>
#include "grafos.h"

int main(){
    Grafo *g = criarGrafo(5);
    inserirAresta(g, 0, 1);
    inserirAresta(g, 0, 2);
    inserirAresta(g, 1, 2);
    imprimirGrafo(g);
    excluirGrafo(g);
    return 0;
}