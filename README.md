# Tabela Hash — Encadeamento Separado & Endereçamento Aberto

Implementação do Tipo Abstrato de Dados (TAD) **Tabela Hash** em **C++**, demonstrando e comparando as duas principais estratégias para tratamento de colisões: **Encadeamento Separado** (*Separate Chaining*) e **Endereçamento Aberto** (*Open Addressing* com Sondagem Linear).

## Estrutura dos Arquivos

* **`hash.h`**: Cabeçalho com a interface do TAD (definições de estruturas e protótipos das funções)[cite: 7].
* **`hash1.cpp`**: Implementação utilizando **Encadeamento Separado** (listas encadeadas `std::list`)[cite: 8].
* **`hash.cpp`**: Implementação utilizando **Endereçamento Aberto** (sondagem linear com flags de `ocupado` e `removido`)[cite: 10].
* **`main.cpp`**: Menu interativo em terminal para manipulação e testes da tabela[cite: 9].

## Técnicas de Tratamento de Colisão

### 1. Encadeamento Separado (`hash1.cpp`)
- Cada posição da tabela contém uma lista encadeada dinâmica (`std::list<Aluno>`)[cite: 7, 8].
- Quando ocorre uma colisão, o novo elemento é inserido ao final da lista na posição correspondente[cite: 8].
- **Vantagem:** Não possui limite rígido de capacidade; a tabela não fica "cheia"[cite: 8].

### 2. Endereçamento Aberto com Sondagem Linear (`hash.cpp`)
- Todos os elementos são armazenados diretamente no vetor da tabela[cite: 10].
- Se a posição calculada estiver ocupada, o algoritmo busca sequencialmente o próximo slot livre `(indice + 1) % TAM`[cite: 10].
- Utiliza marcas morfológicas (`ocupado` e `removido`) para garantir que buscas e remoções não interrompam a cadeia de sondagem[cite: 10].

## Operações Suportadas

- **Inserção:** Adiciona um novo aluno (`matricula` e `nome`), prevenindo duplicidade de chaves[cite: 8, 10].
- **Busca:** Localiza o nome correspondente a uma matrícula[cite: 8, 10].
- **Remoção:** Remove o registro mantendo a integridade da estrutura[cite: 8, 10].
- **Exibição:** Imprime o estado atual de todas as posições da tabela[cite: 8, 10].


## 🚀 Como Compilar e Executar

### Para testar o Encadeamento Separado (`hash1.cpp`):
```bash
g++ main.cpp hash1.cpp -o hash_encadeamento
./hash_encadeamento
