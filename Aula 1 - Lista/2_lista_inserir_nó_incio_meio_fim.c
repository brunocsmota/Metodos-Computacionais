/******************************************************************************

   Lista Simplesmente Encadeada:
        Inserindo nós na lista (início, fim e meio)
   
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// Procedimento para inserir no início

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

// Procedimento para inserir no fim

void inserir_no_fim(No **lista, int num){

    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo -> valor = num;
        novo -> proximo = NULL;
        
        // é o primeiro?
        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
                aux->proximo = novo;
                
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Procedimento para inserir no meio

void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));
    
    // Verifcação se a memória foi alocada corretamente
    if(novo){
        novo -> valor = num;
        
        // é o primeiro?
        if(*lista == NULL){
            novo -> proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d", no->valor);
        no = no -> proximo;
    }
    printf("\n\n");
}


int main() {
    
    int opcao, valor, ref;
    No *lista = NULL;
    do{
        printf("\n\t 0-Sair \n\t 1-Inserir no início\n\t 2-Inserir no meio \n\t 3-Inserir no meio \n\t 4-Imprimir");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_no_inicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_no_fim(&lista, valor);
                break;
            case 3:
                printf("Digite um valor e o valor de referência: ");
                scanf("%d %d", &valor, &ref);
                inserir_no_meio(&lista, valor, ref);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao != 0)
                    printf("Opção invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}