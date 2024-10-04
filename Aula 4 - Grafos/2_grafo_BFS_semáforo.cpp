#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da fila para BFS
typedef struct Fila {
    const char **itens;
    int frente, tras, capacidade;
} Fila;

// Função para criar a fila
Fila* criaFila(int capacidade) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->itens = (const char**) malloc(capacidade * sizeof(const char*));
    fila->frente = 0;
    fila->tras = -1;
    fila->capacidade = capacidade;
    return fila;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->tras < fila->frente;
}

// Função para inserir na fila
void insereFila(Fila* fila, const char* valor) {
    fila->itens[++fila->tras] = valor;
}

// Função para remover da fila
const char* removeFila(Fila* fila) {
    return fila->itens[fila->frente++];
}

// Estrutura de transição de estados do semáforo
typedef struct {
    const char* estado;
    const char** transicoes;
    int numTransicoes;
} Estado;

// Função para encontrar todas as transições possíveis usando BFS
void BFS(Estado* estados, int numEstados, const char* estadoInicial) {
    Fila* fila = criaFila(10);
    int i, j;
    int visitados[numEstados]; // Vetor para marcar estados visitados
    
    // Inicializando o vetor de visitados com 0
    for (i = 0; i < numEstados; i++) {
        visitados[i] = 0;
    }

    // Inserir o estado inicial na fila
    insereFila(fila, estadoInicial);
    
    printf("Sequências de transição no semáforo (BFS):\n");

    // Processar a fila
    while (!filaVazia(fila)) {
        // Remove o primeiro estado da fila
        const char* estadoAtual = removeFila(fila);
        
        // Encontrar o índice do estado atual na lista de estados
        int indiceAtual = -1;
        for (i = 0; i < numEstados; i++) {
            if (strcmp(estados[i].estado, estadoAtual) == 0) {
                indiceAtual = i;
                break;
            }
        }
        
        if (indiceAtual == -1 || visitados[indiceAtual]) {
            continue;
        }
        
        // Marcar o estado como visitado
        visitados[indiceAtual] = 1;

        // Para cada transição do estado atual
        for (j = 0; j < estados[indiceAtual].numTransicoes; j++) {
            const char* proximoEstado = estados[indiceAtual].transicoes[j];
            printf("%s -> %s\n", estadoAtual, proximoEstado);
            
            // Adicionar o próximo estado na fila
            insereFila(fila, proximoEstado);
        }
    }

    // Liberar memória alocada para a fila
    free(fila->itens);
    free(fila);
}

int main() {
    // Definir os estados do semáforo e suas transições
    const char* transicoesVerde[] = {"Amarelo"};
    const char* transicoesAmarelo[] = {"Vermelho"};
    const char* transicoesVermelho[] = {"Verde", "Vermelho"};
    
    Estado estados[] = {
        {"Verde", transicoesVerde, 1},
        {"Amarelo", transicoesAmarelo, 1},
        {"Vermelho", transicoesVermelho, 2}
    };
    
    // Executar o BFS a partir do estado "Verde"
    BFS(estados, 3, "Verde");

    return 0;
}