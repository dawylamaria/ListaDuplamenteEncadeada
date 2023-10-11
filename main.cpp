#include <iostream>

struct No {
    int data;
    No* anterior;
    No* next;
};

void inserir(No *&head, int valor) {
    No* novoNo = new No;
    novoNo -> data = valor;
    novoNo -> anterior = NULL;
    novoNo -> next = NULL;

    if (head == NULL) {
        head = novoNo;
        return;
        
    } else {
        No* aux = head;
        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = novoNo;
        novoNo->anterior = aux;
    }
}
 
using namespace std;
void removerNaPosicao(No *&head, int posicao) {
    if (head == NULL) {
        cout << "A lista está vazia!" << endl;
        return;
    }

    if (posicao == 0) {
        No* temp = head;
        head = head->next;

        if (head != NULL) {
            head->anterior = NULL;
        }

        delete temp;
        return;
    }

    No* atual = head;
    int contador = 0;

    while (atual != NULL && contador < posicao) {
        atual = atual->next;
        contador++;
    }

    if (atual == NULL) {
        cout << "Posição inválida!" << endl;
        return;
    }

    if (atual->anterior != NULL) {
        atual -> anterior -> next = atual -> next;
    } else {
        head = atual->next;
    }

    if (atual -> next != NULL) {
        atual -> next -> anterior = atual -> anterior;
    }

    delete atual;
}

using namespace std;
void imprimirLista(No *&head) {
    No* atual = head;
    while (atual != NULL) {
        cout << atual->data << " ";
        atual = atual->next;
    }
    cout << endl;
}



int tamanho(No *&head) {
    int contador = 0;
    No* aux = head;
    while (aux != NULL) {
        contador++;
        aux = aux->next;
    }
    return contador;
}
using namespace std;
int main(int argc, char** argv) {
    No* head = NULL;

    inserir(head, 1);
    inserir(head, 2);
    inserir(head, 3);
    inserir(head, 4);
    inserir(head, 5);

    cout << "O tamanho da lista: " << tamanho(head) << endl;
	cout << endl;
    
    cout << "Lista original: " << endl;
    
	imprimirLista(head);
	cout << endl;

    removerNaPosicao(head, 1);

    cout << "Tamanho da lista apos a remocao: " << tamanho(head) << endl;

    cout << "Lista apos a remocao:";

    imprimirLista(head);




    No* atual = head;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->next;
        delete temp;
    }

    return 0;
}

