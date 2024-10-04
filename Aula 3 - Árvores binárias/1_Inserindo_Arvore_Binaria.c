/******************************************************************************

                             Árvore Binária
                                Inserção

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{ // Criando o struct que indica o tipo "no"
    // A estrutura possuirá o conteúdo do nó
    int conteudo;
    // E conterá também dois ponteiros, um da esquerda e outro da direita
    struct no *esquerda, *direita; // Ponteiros do tipo "no"
}No; // apelido para struct no

typedef struct{
    No *raiz;
}ArvB;

// Declarar funções criadas para que o compilador as reconheça
// quando forem declaradas implicidamente uma dentro da outra
void inserirDireita(No *no, int valor); // Declaração da função
void inserirEsquerda(No *no, int valor); // Declaração da função

void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){                 // se nó da esquerda for vazio
        No *novo_no = (No*)malloc(sizeof(No));// Cria um novo nó (ponteiro)
        novo_no->conteudo = valor;            // novo nó aponta para var conteudo, que recebe o valor
        novo_no->esquerda = NULL;             // novo nó agora aponta para esquerda, que recebe nulo
        novo_no->direita = NULL;              // novo nó agora aponta para direita, que recebe nulo
        no->esquerda = novo_no;               // ponteiro que aponta esquerda recebe conteúdo de novo nó
    }else{                                    // se nó da esquerda não for vazio
        if(valor < no->esquerda->conteudo){   // se valor for menor que conteúdo do no esquerdo]
            inserirEsquerda(no->esquerda, valor); // recursividade!
        }else{                              // se valor for maior que conteúdo do nó da esquerda
            inserirDireita(no->esquerda, valor); // insere no nó a direita do nó esquerda
        }
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo_no = (No*)malloc(sizeof(No));// Cria um novo nó (ponteiro)
        novo_no->conteudo = valor;            // novo nó aponta para var conteudo, que recebe o valor
        novo_no->esquerda = NULL;             // novo nó agora aponta para esquerda, que recebe nulo
        novo_no->direita = NULL;              // novo nó agora aponta para direita, que recebe nulo
        no->direita = novo_no;
    }else{
        if(valor > no->direita->conteudo){
            inserirDireita(no->direita, valor);
        }else{
            inserirEsquerda(no->direita, valor);
        }
    }

}

void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){                  // se o ponteiro que aponta raiz for nulo (raiz é nula, vazia)
        No *novo = (No*)malloc(sizeof(No)); // Cria um novo nó (ponteiro)
        novo->conteudo = valor;             // novo nó aponta para var conteudo, que recebe o valor
        novo->esquerda = NULL;              // novo nó agora aponta para esquerda, que recebe nulo
        novo->direita = NULL;               // novo nó agora aponta para direita, que recebe nulo
        arv->raiz = novo;                   // ponteiro que aponta raiz recebe novo nó (endereço deste nó recém criado)
    }else{                                  // se o ponteiro que aponta raiz não for nulo
        if(valor < arv->raiz->conteudo){ // se valor é menor que nó anterior (conteudo)
            inserirEsquerda(arv->raiz, valor); // insere valor na esquerda
        }else{                              // se valor é maior que nó anterior (conteúdo)
            inserirDireita(arv->raiz, valor); // insere valor na direita
        }
    }
}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);    // recursão para imprimir nó da esquerda
        printf("\t %d \t", raiz->conteudo); // imprimindo o conteudo apontado por raiz (1º no)
        imprimir(raiz->direita);     // recursão para imprimir nó da direita
    }
}

int main(){
    int opcao, valor;
    ArvB arvore;
    // arvore é um objeto, logo objeto.atributo (se fosse ponteiro, seria ->)
    // usar ponteiro->variável é o mesmo que (*ponteiro).variável (variável é quem quero acessar pelo ponteiro)
    arvore.raiz = NULL; // Verificar vídeos de lista encadeada para entender diferença de -> e .
    
    do{
        printf("\n0 - sair\n1-inserir\n2-imprimir\n\n");
        scanf("%d", &opcao);               // função scanf sempre registra pelo endereço
        
        switch(opcao){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                inserir(&arvore, valor);
                break;
            case 2:
                printf("\nImpressão da arvore binaria: \n");
                imprimir(arvore.raiz);
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    }while(opcao != 0);
    return 0;
}