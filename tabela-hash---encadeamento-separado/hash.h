#include <string>
#include <list>
using namespace std;

const int TAM = 10;

struct Aluno {
    int matricula;
    string nome;
};

struct TabelaHash {
    list<Aluno>* tabela;
};

// Interface da TAD
TabelaHash* criarTabela();
void destruirTabela(TabelaHash* th);
void inserir(TabelaHash* th, int matricula, string& nome);
bool buscar(TabelaHash* th, int matricula, string& nome);
void remover(TabelaHash* th, int matricula);
void imprimirTabela(TabelaHash* th);


