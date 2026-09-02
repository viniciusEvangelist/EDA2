typedef struct Grafo Grafo;
Grafo* criarGrafo(int n);
void inserirAresta(Grafo *g, int u, int g);
void removerAresta(Grafo *g, int u, int g);
void imprimirGrafo(Grafo* g);
void excluirGrafo(Grafo* g);
