/******************************************************************************

   Lista Simplesmente Encadeada:
        Inserindo no início da lista
   
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_no_inicio(No **lista, int num){

    No *novo = malloc(sizeof(No));
    
    // Verifcação se a memória foi alocada corretamente
    if(novo){
        // valor do nó inicial é o número recebido como parâmetro
        novo -> valor = num;
        // o próximo nó (segundo) recebe o conteúdo do primeiro nó anterior
        novo -> proximo = *lista;
        // início da lista passa a ser o novo nó
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void imprimir_lista(No *lista) {
    No *aux = lista;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

int main() {
    No *lista = NULL; // Inicializa a lista como vazia

    // Insere alguns valores na lista
    inserir_no_inicio(&lista, 30);
    inserir_no_inicio(&lista, 20);
    inserir_no_inicio(&lista, 10);

    printf("Lista inicial:\n");
    imprimir_lista(lista);

    // Insere um novo valor no início da lista
    int novoValor = 5;
    inserir_no_inicio(&lista, novoValor);

    printf("Lista após inserir %d no início:\n", novoValor);
    imprimir_lista(lista);

    return 0;
}