# 🧠 Teste de Detecção de Deadlock — Algoritmo do Banqueiro

## 🔧 Dados do Sistema

- **Número de processos:** 5
- **Número de recursos:** 3
- **Recursos disponíveis (Available):** `{3, 3, 2}`

### 📑 Matrizes do Sistema

#### 🗂️ Matriz Max
| Processo | R0 | R1 | R2 |
|----------|----|----|----|
| **P0**   | 7  | 5  | 3  |
| **P1**   | 3  | 2  | 2  |
| **P2**   | 9  | 0  | 2  |
| **P3**   | 2  | 2  | 2  |
| **P4**   | 4  | 3  | 3  |

#### 🗂️ Matriz Allocation
| Processo | R0 | R1 | R2 |
|----------|----|----|----|
| **P0**   | 0  | 1  | 0  |
| **P1**   | 2  | 0  | 0  |
| **P2**   | 3  | 0  | 2  |
| **P3**   | 2  | 1  | 1  |
| **P4**   | 0  | 0  | 2  |

#### 🗂️ Matriz Need = Max - Allocation
| Processo | R0 | R1 | R2 |
|----------|----|----|----|
| **P0**   | 7  | 4  | 3  |
| **P1**   | 1  | 2  | 2  |
| **P2**   | 6  | 0  | 0  |
| **P3**   | 0  | 1  | 1  |
| **P4**   | 4  | 3  | 1  |

---

## 🧪 Teste 1 — Verificar Estado Inicial

### 🔸 Ação:
Executar o algoritmo do banqueiro sem requisições.

### 🔸 Resultado:
O sistema está em estado SEGURO.
Sequência segura: P1 P3 P4 P0 P2

yaml
Copiar
Editar

✅ **Sistema seguro.**

---

## 🧪 Teste 2 — Solicitação do Processo P1

### 🔸 Solicitação:
P1 solicita {1, 0, 2}

markdown
Copiar
Editar

### 🔸 Verificações:
- **Pedido ≤ Need:** ✅
- **Pedido ≤ Available:** ✅

### 🔸 Estado após alocação temporária:
- **Available:** `{2, 3, 0}`
- **Allocation (P1):** `{3, 0, 2}`
- **Need (P1):** `{0, 2, 0}`

### 🔸 Resultado:
O sistema está em estado SEGURO.
Sequência segura: P1 P3 P4 P0 P2
Recursos foram alocados.

yaml
Copiar
Editar

✅ **Sistema continua seguro.**  
✅ **Recursos foram alocados para P1.**

---

## 🧪 Teste 3 — Solicitação do Processo P4

### 🔸 Solicitação:
P4 solicita {3, 3, 0}

markdown
Copiar
Editar

### 🔸 Verificações:
- **Pedido ≤ Need:** ✅
- **Pedido ≤ Available:** ❌ (Pedido em R0 = 3 > Available R0 = 2)

### 🔸 Resultado:
Processo P4 solicita recursos: 3 3 0
Erro: Recursos insuficientes.

yaml
Copiar
Editar

❌ **Solicitação negada por falta de recursos disponíveis.**

---

## 📜 Resumo dos Testes

| Teste                         | Resultado                                | Observação                                               |
|-------------------------------|-------------------------------------------|----------------------------------------------------------|
| 🔸 Estado inicial              | ✅ Seguro                                 | Sequência segura: P1 → P3 → P4 → P0 → P2                |
| 🔸 P1 solicita {1, 0, 2}       | ✅ Atendido, sistema continua seguro      | Recursos alocados                                        |
| 🔸 P4 solicita {3, 3, 0}       | ❌ Negado                                 | Recursos insuficientes (Available insuficiente em R0)    |

---

## 🏁 Conclusão

O sistema iniciou em estado seguro. A solicitação do processo **P1** foi atendida sem comprometer a segurança do sistema.  
No entanto, a solicitação do processo **P4** excedeu os recursos disponíveis no momento e, portanto, foi corretamente negada para evitar um possível **deadlock**.

O **Algoritmo do Banqueiro** demonstrou funcionar corretamente, garantindo a segurança do sistema e prevenindo situações de bloqueio.

---
