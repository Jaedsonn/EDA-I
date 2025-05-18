#ifndef listas_s
#define listas_s
#define MAX 100

struct lista_sequencial
{
    int n;
    int lista[MAX];
    lista_sequencial() : n(-1) {};
    lista_sequencial(int a) : n(a) {};
    int busca(int valor);
    int busca_ordenada(int valor);
    void excluir(int valor);
    void incluir(int valor);
    void inclusao_ordenada(int valor);
};

#endif
