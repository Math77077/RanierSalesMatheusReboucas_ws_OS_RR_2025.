# Identificação de Deadlock usando o Algoritmo do Banqueiro

Este repositório contém os artefatos desenvolvidos para o trabalho de Sistemas Operacionais (SO), cujo objetivo foi implementar um software capaz de **identificar e evitar deadlocks** utilizando o **Algoritmo do Banqueiro**, além de representar e analisar sua lógica com **redes de Petri**.

## 🔍 Tema

> **[TEMA - 5] Identificação de deadlock usando algoritmo do banqueiro**

A proposta consiste em desenvolver um programa que verifica, a cada requisição de recurso, se o sistema permanece em um estado seguro. Se a requisição comprometer a segurança, o atendimento é adiado. A lógica se baseia nas premissas de que:
- Nem todos os processos precisam de todo o seu máximo declarado de recursos.
- O sistema só realiza a alocação caso consiga garantir um estado seguro após a requisição.

## 📂 Estrutura do Repositório

```bash
.
├── docs/                                                         # Documentação do projeto
|   ├── ComportamentoAlgoritmoDoBanqueiro.md                      # Interpretação da análise feita com o TINA do Algoritmo do Banqueiro
│   └── ComportamentoAlgoritmoDoBanqueiroComConcorrencia.md       # Interpretação da análise feita com o TINA do Algoritmo do Banqueiro com Concorrencia
│
├── src/                                     # Código-fonte e modelagem
│   ├── banqueiro.c                          # Implementação do algoritmo do banqueiro em C
│   ├── AlgortimoDoBanqueiro.pn              # Rede de Petri do algoritmo do banqueiro
│   ├── AlgortimoDoBanqueiroConcorrencia.pn  # Rede de Petri com concorrência
|   ├── AlgortimoDoBanqueiro.net             # Rede de Petri em formato analisável pela TINA
|   ├── AlgortimoDoBanqueiroConcorrencia.net # Rede de Petri com Concorrencia em formato analisável pela TINA 
|   ├── analise_tina.txt                     # Resultado da Análise da TINA para Rede de Petri
|   └──analise_tina_concorrencia.txt         # Resultado da Análise da TINA para Rede de Petri com Concorrencia
│   
│
├── img/                                                  # Imagens usadas na documentação ou apresentação
|   ├── rede_de_petri_sem_concorrencia.png             # Visualização da Rede de Petri do Algoritmo do Banqueiro
│   └── rede_de_petri_com_concorrencia.png             # Visualização da Rede de Petri do Algoritmo do Banqueiro com Concorrencia
│
└── README.md                       # Este arquivo
```

## 🎯 Objetivo do Projeto

O objetivo deste projeto é desenvolver uma solução capaz de **identificar e evitar situações de deadlock** em sistemas operacionais utilizando o **Algoritmo do Banqueiro**, proposto por Edsger Dijkstra.

O sistema verifica, a cada requisição de recurso feita por um processo, se é possível atendê-la sem comprometer o estado seguro do sistema. Se a resposta for negativa, a requisição é adiada.

Além disso, o projeto visa **modelar a lógica do algoritmo** utilizando **redes de Petri** (criados no software Snoopy) e realizar uma **análise formal** com a ferramenta **TINA**, validando assim o comportamento do sistema em termos de segurança e concorrência.

---

## 🛠️ Descrição da Solução

A solução foi dividida em duas partes principais:

### 1. Implementação do Algoritmo em C

A implementação simula o gerenciamento de alocação de recursos para múltiplos processos. Ela conta com:

- Matriz de alocação atual de recursos (`allocation`)
- Matriz de necessidade máxima (`max`)
- Vetor de recursos disponíveis (`available`)
- Cálculo da necessidade restante (`need`)
- Funções para:
  - Verificar se o sistema está em estado seguro (`isSafe`)
  - Processar solicitações de recursos (`requestResources`)

> A lógica segue rigorosamente o comportamento descrito pelo algoritmo do banqueiro, impedindo alocações que levem o sistema a estados inseguros.

---

### 2. Modelagem com Redes de Petri

Foram construídas duas redes de Petri no **Snoopy**:
- **Rede do Algoritmo do Banqueiro**: Representa o fluxo básico de requisições e liberações de recursos.
- **Rede com Concorrência**: Simula múltiplos processos interagindo com os mesmos recursos, permitindo a visualização de situações de disputa e contenção.

Ambas as redes foram analisadas com o **TINA**, permitindo verificar propriedades como:
- Ausência de deadlocks
- Possibilidade de execução concorrente
- Alcançabilidade de estados seguros

A interpretação dessas análises está disponível na pasta [`docs/`](./docs).

## 💻 Como Compilar e Executar o Código em C

### Pré-requisitos

- Um compilador C instalado (exemplo: `gcc` disponível no Linux, macOS ou WSL no Windows)
- Terminal ou prompt de comando para executar os comandos

---

### Passo a passo

1. Navegue até a pasta `src` onde está o código:

```bash
cd src
```

2. Compile o código com o comando:
```bash
gcc banqueiro.c -o banqueiro
```

3. Execute o programa:
```bash
./banqueiro
```
## 🛠️ Tecnologias Utilizadas

- **Linguagem C** — para a implementação do algoritmo do banqueiro.
- **Snoopy** — ferramenta para modelagem das redes de Petri.
- **TINA** — ferramenta para análise formal das redes de Petri.
- **GitHub** — para versionamento e hospedagem do repositório.

---

## 📚 Referências

- Coletta, Alex. *Deadlock em Sistemas Operacionais*. Disponível em: [https://alexcoletta.eng.br/artigos/deadlock-em-sistemas-operacionais/](https://alexcoletta.eng.br/artigos/deadlock-em-sistemas-operacionais/)

---

## 👥 Autores

- Ranier Sales Veras  
- Matheus Rebouças de Lima 

---

## 📌 Observações

- A documentação das análises das redes de Petri está disponível na pasta `docs/`.
- Os testes do código em C foram realizados por Ranier, e podem ser incluídos em breve.



