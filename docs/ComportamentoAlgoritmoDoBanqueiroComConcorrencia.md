# 🧠 Análise do Algoritmo do Banqueiro com Concorrência via TINA

Este documento apresenta a análise feita com a ferramenta **TINA (TIme petri Net Analyzer)** sobre a rede de Petri modelada para representar o comportamento do **algoritmo do banqueiro com concorrência**.

## 🔧 Configuração

- **Ferramenta utilizada:** TINA 3.8.5 (LAAS/CNRS)
- **Modo de análise:** `-W` (análise completa de acessibilidade)
- **Rede analisada:** `AlgoritmoDoBanqueiroConcorrencia`
- **Elementos do modelo:**
  - **Places:** 16
  - **Transitions:** 6
  - **Arcs:** 54

---

## 📌 Estrutura da Rede

A rede representa o comportamento de um processo concorrente (`P1`) solicitando e utilizando recursos de forma controlada e segura, conforme o algoritmo do banqueiro. Abaixo estão os principais componentes:

### 📍 Lugares (Places)

- **Recursos disponíveis:** `Available_R0`, `Available_R1`, `Available_R2`
- **Necessidades do processo:** `Need_P1_R0`, `Need_P1_R1`, `Need_P1_R2`
- **Solicitação de recursos:** `Request_P1_R*`
- **Alocação realizada:** `Allocation_P1_R*`
- **Controle de segurança:** `Safe_State_P1`
- **Sinalizadores de ação:** `Request_P1_Trigger`, `Allocate_P1_Trigger`, `Deny_P1_Trigger`

### 🔁 Transições

- `Request_P1`: Processo faz requisição de recursos
- `Check_Safety_P1_OK`: Verificação bem-sucedida → alocação permitida
- `Check_Safety_P1_Fail`: Verificação falhou → alocação negada
- `Allocate_P1`: Aloca efetivamente os recursos
- `Deny_P1`: Devolve os recursos se a alocação foi negada
- `Finish_P1`: Processo termina e libera recursos

---

## 📊 Análise de Acessibilidade (Reachability)

A rede possui **7 classes de marcações alcançáveis**, mostrando as possíveis evoluções de estados do sistema.

| Classe | Marcação Principal |
|--------|--------------------|
| 0      | Estado inicial: todos os recursos disponíveis, necessidades pendentes |
| 1      | Solicitação de recursos em andamento |
| 2      | Segurança falhou: recursos não alocados |
| 3      | Segurança OK: alocação será realizada |
| 4      | Recursos devolvidos após negação |
| 5      | Recursos alocados com sucesso |
| 6      | Finalização do processo, recursos parcialmente devolvidos |

---

## 🧪 Análise de Vivacidade (Liveness)

- **Resultado:** `not live` (não viva)
- A rede não é tecnicamente viva porque não possui um ciclo infinito de execuções. Ou seja, **ela não reinicia automaticamente após a finalização** (`Finish_P1`).
- **Nota:** Isso **não compromete** a funcionalidade do algoritmo modelado, pois o objetivo era representar **um ciclo completo de solicitação, verificação e alocação/liberação de recursos** — não a repetição infinita.

---

## 🔁 Componentes Fortemente Conectados (SCCs)

A rede possui 7 componentes fortemente conectados (Strongly Connected Components), representando as possibilidades de transição entre diferentes estados do sistema. Isso mostra a estrutura de decisão e alternância entre alocação e negação de recursos.

---

## ✅ Conclusão

Apesar de não ser uma rede viva, o modelo é **corretamente limitado (`bounded`)** e **possivelmente reversível**, o que demonstra com sucesso o **comportamento essencial do algoritmo do banqueiro com concorrência**:

- Um processo faz requisição de recursos;
- Uma verificação de segurança decide se a requisição pode ser atendida;
- Os recursos são alocados ou negados;
- Ao final, os recursos são devolvidos ao sistema.

O modelo atual pode ser estendido para múltiplos processos (P2, P3, ...) ou modificado para permitir ciclos repetitivos com reinício automático, caso desejado para simulações mais extensas.

---

### 📁 Arquivo gerado por TINA

```txt
# net AlgoritmoDoBanqueiroConcorrencia, 16 places, 6 transitions, 54 arcs
# bounded, not live, possibly reversible
# abstraction        count      props      psets       dead       live
#      states            7         16          ?          2          2
# transitions            6          6          ?          0          0
