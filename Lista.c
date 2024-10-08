#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct 
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int numeroElemntos;
} LISTA;



void inicializarLista (LISTA l) {
    l.numeroElemntos = 0;
}

int tamanho(LISTA *l) {
    return l->numeroElemntos;
}

void exibirlista (LISTA l) {
    int i; 
    printf("Lista: \" ");
    for (i = 0; i < l.numeroElemntos; i++) {
        printf("%d", l.A[i].chave);
    }
    printf("\"\n");
}

bool inserirElemlista (LISTA *l, REGISTRO reg, int i) {
    int j;
    if ((l->numeroElemntos == MAX) || (i < 0) || (i > l->numeroElemntos)) {
        return false;
    }

    for (j = l->numeroElemntos; j > i; j--) {
        l->A[j] = l->A[j-1];
    }
    l->A[i] = reg;
    l->numeroElemntos++;
    return true;
}

bool excluirElemlista (TIPOCHAVE ch, LISTA *l) {
    int pos, j;
    pos = buscaSequencial(l, ch);

    if (pos == -1) {
        return false;
    }

    for (j = pos; j < l->numeroElemntos - 1; j++) {
        l->A[j] = l->A[j+1];
    }

    l->numeroElemntos--;
    return true;
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch) {
    int i = 0;
    while (i < l->numeroElemntos)
    {
        if (ch == l->A[i].chave) {
            return i;
        }
        else i++;
    }
    return -1;
}

int buscaSentinela(LISTA *l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->numeroElemntos].chave = ch;
    while (l->A[i].chave != ch) i++;
    if (i == l->numeroElemntos) return -1;
    else return i;
}

/*Inserção de Elemento - Ordenada*/

bool inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    if (l->numeroElemntos >= MAX) return false;
    int pos = l->numeroElemntos;
    while (pos > 0 && l->A[pos-1].chave > reg.chave) 
    {
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->numeroElemntos++;
}

/*Busca Binária*/

int buscaBinaria(LISTA *l, TIPOCHAVE ch) {
    int esq, dir, meio;
    esq = 0;
    dir = l->numeroElemntos-1;
    while (esq <= dir)
    {
        meio = ((esq + dir))/2;
        if (l->A[meio].chave == ch) return meio;
        else {
            if (l->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
    }
    return -1;
}
