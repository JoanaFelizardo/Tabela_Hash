#include <iostream>
#include "hash.h"
using namespace std;

int hashFunc(int chave) {
    return chave % TAM;
}

TabelaHash* criarTabela() {
    TabelaHash* th = new TabelaHash;
    for(int i = 0; i < TAM; i++) {
        th->tabela[i] = new Aluno;
        th->tabela[i]->ocupado = false;
        th->tabela[i]->removido = false;
    }
    return th;
}

void destruirTabela(TabelaHash* th) {
    for(int i = 0; i < TAM; i++) {
        if (th->tabela[i] != nullptr) {
            delete th->tabela[i];
        }
    }
    delete th;
}

void inserir(TabelaHash* th, int matricula, string& nome) {
    int indice = hashFunc(matricula);
    int tentativas = 0;
    
    while (tentativas < TAM){
         if (!th->tabela[indice]->ocupado || th->tabela[indice]->removido) {
            th->tabela[indice]->matricula = matricula;
            th->tabela[indice]->nome = nome;
            th->tabela[indice]->ocupado = true;
            th->tabela[indice]->removido = false;
            cout << "Aluno inserido na posicao " << indice << endl;
            return;
        }
        
         if (th->tabela[indice]->matricula == matricula && !th->tabela[indice]->removido) {
            cout << "Matrícula já cadastrada!" << endl;
            return;
        }
        
        // Sondagem linear
        indice = (indice + 1) % TAM;
        tentativas++;
    }
    
    cout << "Tabela cheia! Não foi possível inserir." << endl;
}


bool buscar(TabelaHash* th, int matricula, string& nome){
    int indice = hashFunc(matricula);
    int tentativas = 0;
    
    while (tentativas < TAM) {
        if (th->tabela[indice]->ocupado && !th->tabela[indice]->removido && th->tabela[indice]->matricula == matricula) {
            nome = th->tabela[indice]->nome;
            return true;
        }
        
        // Se encontrar posição nunca ocupada, para a busca
        if (!th->tabela[indice]->ocupado && !th->tabela[indice]->removido) {
            break;
        }
        
        // Sondagem linear
        indice = (indice + 1) % TAM;
        tentativas++;
    }
    
    return false;
}

void remover(TabelaHash* th, int matricula) {
    int indice = hashFunc(matricula);
    int tentativas = 0;
   
    while (tentativas < TAM) {
        if (th->tabela[indice]->ocupado && !th->tabela[indice]->removido && 
            th->tabela[indice]->matricula == matricula) {
            th->tabela[indice]->removido = true;
            th->tabela[indice]->ocupado = false;
            cout << "Aluno removido da posicao " << indice << endl;
            return;
        }
        
        // Se encontrar posição nunca ocupada, para a busca
        if (!th->tabela[indice]->ocupado && !th->tabela[indice]->removido) {
            break;
        }
        
        // Sondagem linear
        indice = (indice + 1) % TAM;
        tentativas++;
    }
    
    cout << "Aluno nao encontrado para remocao." << endl;
}

void imprimirTabela(TabelaHash* th) {
    for(int i = 0; i < TAM; i++) {
        cout << "[" << i << "]: ";
        if (th->tabela[i] != nullptr && th->tabela[i]->ocupado) {
            cout << "Matricula: " << th->tabela[i]->matricula
                 << ", Nome: " << th->tabela[i]->nome;
        } else {
            cout << "Vazio";
        }
        cout << endl;
    }
}

