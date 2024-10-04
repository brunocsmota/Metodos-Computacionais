/******************************************************************************

     Inserir e remover na fila encadeada (alocação de memória dinâmica)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo -> valor = num;
        novo -> proximo = NULL;
        if(*fila == NULL){
            *fila = novo;
        }else{
            aux = *fila;
            while(aux->proximo)
                aux = aux->proximo;
                aux->proximo = novo;
        }
    }else
        printf("\nErro ao alocar memoria.");
}

No* remover_da_fila(No **fila){
    No *remover = NULL;
    
    if(*fila){
        remover = *fila;
        *fila = remover -> proximo;
    }else{
        printf("\tFila vazia\n");
    }
    
    return remover;
}

// Procedimento para imprimir

void imprimir (No *fila){
    printf("\t-------- FILA --------\n");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t-------- FIM DA FILA --------\n\n");
}

int main()
{

    No *fila = NULL; // Inicializa o ponteiro da fila como vazio

    // Insere alguns valores na fila
    inserir_na_fila(&fila, 30);
    inserir_na_fila(&fila, 20);
    inserir_na_fila(&fila, 10);

    printf("Fila inicial:\n");
    imprimir(fila);

    // Insere um novo valor daa fila (sempre no final)
    int novoValor = 5;
    inserir_na_fila(&fila, novoValor);

    printf("Fila após inserir %d no início:\n", novoValor);
    imprimir(fila);
    
    // Remove um valor da fila (sempre no começo)
    remover_da_fila(&fila);
    printf("Fila após remover o primeiro elemento:\n");
    imprimir(fila);

    return 0;
}