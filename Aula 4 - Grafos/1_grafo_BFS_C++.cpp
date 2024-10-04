#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Isso evita a necessidade de prefixar nomes de elementos do namespace std com std::.

struct Node {
    //Define um nó básico para representar um vértice no grafo.
    //'data' para armazena o valor do vértice e 'next' aponta para o próximo nó na lista de adjacência
    int data;
    Node* next;
};

class Grafo {
//Representa um grafo.
    // Atributos:
        // numVertices: Armazena o número total de vértices no grafo.
        // vertices: Um vetor de ponteiros para nós, representando a lista de adjacência de cada vértice.
private:
    int numVertices;
    vector<Node*> vertices;
    // Métodos:
        // getNumVertices(): Retorna o número de vértices do grafo.
        // Construtor:
            // Inicializa o atributo numVertices com o valor passado.
            // Cria um vetor de tamanho numVertices para armazenar as listas de adjacência.
            //Inicializa cada posição do vetor com nullptr, indicando uma lista vazia.
public:
    int getNumVertices() {
        return numVertices;
    }

    // Construtor da classe Grafo:
        // Inicializar o número de vértices do grafo.
        // Criar um vetor de listas de adjacência com o tamanho adequado.
        // Inicializar todas as listas de adjacência como vazias.
    Grafo(int numVertices) : numVertices(numVertices) {
        vertices.resize(numVertices);
        for (int i = 0; i < numVertices; i++) {
            vertices[i] = nullptr;
        }
    }

// Função vazia 'conecta' adiciona uma aresta entre dois vértices, v1 e v2
// em um grafo representado pela classe Grafo.

void conecta(int v1, int v2) {
    // Verifica se os índices dos vértices v1 e v2 são válidos. Caso esteja fora
    // do intervalo 0 a numVertices - 1, retorna nada
        if (v1 >= numVertices || v2 >= numVertices || v1 < 0 || v2 < 0) {
            return;
        }
    // Cria um novo nó na lista de adjacência de v1
        Node* newNode = new Node;
        
    // Atualizaça lista de adjacência
        newNode->data = v2;           // Data apontado pelo novo nó recebe vértice v2 (meu dado)
        newNode->next = vertices[v1]; // Nó seguinte apontado pelo novo nó recebe conteúdo de v1 da lista
        vertices[v1] = newNode;       // Conteúdo de v1 da lista recebe valor de novo nó
    
    // Criação e inserção na lista de adjacência de v2
        // Trecho semelhante ao anterior, mas adiciona uma aresta na direção oposta
        // conectando v2 a v1. Importante para grafos não direcionados.
        newNode = new Node;
        newNode->data = v1;
        newNode->next = vertices[v2];
        vertices[v2] = newNode;
}

    void imprime() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (Node* viz = vertices[i]; viz != nullptr; viz = viz->next) {
                cout << viz->data << " ";
            }
            cout << endl;
        }
    }

    void BFS(int s = 0) {
        s %= numVertices;

        vector<int> cor(numVertices, 0); // 0 = branco, 1 = cinza, 2 = preto
        vector<int> pai(numVertices, -1);
        vector<int> dist(numVertices, -1);

        queue<int> fila;
        cor[s] = 1;
        dist[s] = 0;
        fila.push(s);

        while (!fila.empty()) {
            int origem = fila.front();
            fila.pop();

            for (Node* viz = vertices[origem]; viz != nullptr; viz = viz->next) {
                if (cor[viz->data] == 0) {
                    cor[viz->data] = 1;
                    pai[viz->data] = origem;
                    dist[viz->data] = dist[origem] + 1;
                    fila.push(viz->data);
                }
            }
            cor[origem] = 2;
        }

        for (int i = 0; i < numVertices; i++) {
            cout << "Vértice " << i << ": pai = " << pai[i] << ", distância = " << dist[i] << endl;
        }
    }
};

int main() {
    Grafo grafo(7);
    grafo.conecta(0, 1);
    grafo.conecta(0, 2);
    grafo.conecta(1, 2);
    grafo.conecta(1, 4);
    grafo.conecta(1, 6);
    grafo.conecta(2, 4);
    grafo.conecta(2, 6);
    grafo.conecta(3, 5);
    grafo.conecta(3, 6);
    grafo.conecta(4, 5);
    grafo.imprime();
    grafo.BFS();
    return 0;
}