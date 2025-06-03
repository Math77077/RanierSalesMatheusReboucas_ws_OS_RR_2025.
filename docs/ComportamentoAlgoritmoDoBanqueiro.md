# 🔐 Análise de Rede de Petri - Algoritmo do Banqueiro (via TINA)

Este documento apresenta a análise formal da rede de Petri modelando o algoritmo do banqueiro, feita utilizando o [TINA - TIme petri Net Analyzer](https://projects.laas.fr/tina/).

> **Objetivo:** modelar e simular os **quatro comportamentos esperados** do algoritmo do banqueiro:
>
> 1. **Pedido seguro e concedido**
> 2. **Pedido inseguro e negado**
> 3. **Liberação de recurso e novo pedido seguro**
> 4. **Encerramento após alocação total**

---

## 📄 Detalhes da Rede

- **Nome da rede:** `AlgoritmoDoBanqueiro`
- **Ferramentas utilizadas:** Snoopy (modelagem) + TINA (análise)
- **Elementos:**
  - **7 Places**
  - **6 Transitions**
  - **21 Arcs**

---

## 🧪 Resultado da Análise (via `./tina AlgoritmoDoBanqueiro.net`)

### ✅ Propriedades verificadas

| Propriedade              | Resultado         | Descrição                                                                 |
|--------------------------|-------------------|---------------------------------------------------------------------------|
| **Bounded**              | ✅ Sim             | Nenhum lugar pode conter infinitos tokens. Uso de recursos é limitado.   |
| **Possibly Reversible**  | ✅ Sim             | O sistema **pode retornar** a um estado anterior, embora não garantido.  |
| **Dead Transitions**     | ✅ Nenhuma         | Nenhuma transição está completamente inativa em todos os estados.        |

---

### ❌ Propriedades problemáticas

| Propriedade              | Resultado        | Descrição                                                                 |
|--------------------------|------------------|---------------------------------------------------------------------------|
| **Live**                 | ❌ Não viva       | Há transições que não podem mais ocorrer em certos estados (parcialmente mortos). |
| **Dead Classes**         | ❌ 5 classes      | 5 estados da rede são inativos: nenhuma transição está habilitada.       |

---

## 🔍 Interpretação dos Resultados

Apesar de a rede ser **conceitualmente correta**, representando fielmente os quatro comportamentos esperados do algoritmo do banqueiro, ela foi considerada **não viva** por TINA. Isso ocorre porque:

- Alguns dos cenários (por exemplo, o de **negação de pedido por insegurança**, ou o de **encerramento do processo**) **levam a estados finais válidos**, onde nenhuma transição adicional está habilitada.
- Em termos de análise formal, esses estados são considerados **"classes mortas"**, pois o sistema **não continua operando** (não é um ciclo infinito).
- Como o TINA define vivacidade com base na possibilidade de uma transição eventualmente ocorrer novamente em **qualquer estado futuro**, isso **quebra o critério de vivacidade**, mesmo que seja o comportamento esperado em um sistema correto.

---

### 🧩 Classes mortas (estados finais legítimos)

- **Classe 11**: alocação parcial não prossegue
- **Classe 17**: processo travado após pedidos sem liberação
- **Classe 19**: alocação concedida sem finalização
- **Classe 22**: negação final
- **Classe 23**: processo finalizado

Esses estados representam o término correto de certas execuções ou bloqueios controlados, **intencionalmente modelados**.

---

## 🔁 Grafo de Alcançabilidade

- **24 classes de estados**
- **30 transições totais**
- A rede percorre corretamente os caminhos de pedido, verificação de segurança, alocação, negação, liberação e finalização.

---

## 🧠 Conclusão

A modelagem cumpre seu propósito de ilustrar os principais comportamentos do algoritmo do banqueiro, mesmo que, sob análise formal do TINA, a rede seja classificada como "não viva".

> Essa abordagem destaca que **nem toda rede não viva representa um erro**, especialmente quando o modelo busca representar **cenários finitos e terminais** de forma didática e segura.

---

## 📁 Arquivos Relacionados

- `AlgoritmoDoBanqueiro.net` – Arquivo da rede de Petri gerado no Snoopy
- `analise_tina.txt` – Saída completa da análise realizada com TINA

---

