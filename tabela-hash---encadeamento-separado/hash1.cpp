#include <iostream>
#include "hash.h"
using namespace std;

int hashFunc(int chave) {
    return chave % TAM;
}

TabelaHash* criarTabela() {
    TabelaHash* th = new TabelaHash;
    th->tabela = new list<Aluno>[TAM];
    return th;
}

void destruirTabela(TabelaHash* th) {
    delete[] th->tabela;
    delete th;
}

void inserir(TabelaHash* th, int matricula, string& nome) {
    int indice = hashFunc(matricula);
    
    for (const auto& aluno : th->tabela[indice]){
        if (aluno.matricula == matricula){
            cout << "Matricula ja cadastrada!" << endl;
            return;
        }
    }
    
    Aluno novoAluno;
    novoAluno.matricula = matricula;
    novoAluno.nome = nome;
    th->tabela[indice].push_back(novoAluno);
    cout << "Aluno inserido na posicao " << indice << endl;
    
}


bool buscar(TabelaHash* th, int matricula, string& nome){
    int indice = hashFunc(matricula);
    
    for (const auto& aluno : th->tabela[indice]){
        if (aluno.matricula == matricula){
            nome = aluno.nome;
            return true;
        }
    }
    
  return false;
}

void remover(TabelaHash* th, int matricula) {
    int indice = hashFunc(matricula);
    
    auto& lista = th->tabela[indice];
    for (auto it = lista.begin(); it != lista.end(); ++it){
        if (it->matricula == matricula){
            lista.erase(it);
            cout << "Aluno removido da posicao" << endl;
            return;
        }
    }
    
    cout << "Aluno nao encontrado para remocao." << endl;
}

void imprimirTabela(TabelaHash* th) {
   for (int i = 0; i < TAM; i++){
       cout << "[" << i << "]: ";
       if (!th->tabela[i].empty()){
           for (const auto& aluno : th->tabela[i]){
               cout << "Matricula: " << aluno.matricula << ", Nome: " << aluno.nome << " | ";
           }
       }    else {
           cout << "Vazio!";
       }
       cout << endl;
   }
}

