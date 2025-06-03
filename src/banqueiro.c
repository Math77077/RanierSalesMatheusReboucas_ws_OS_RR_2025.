#include <stdio.h>
#include <stdbool.h>

#define P 5 // Número de processos
#define R 3 // Número de recursos

// Dados do sistema
int available[R] = {3, 3, 2}; // Recursos disponíveis
int max[P][R] = {             // Máximo de cada processo
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int allocation[P][R] = {      // Recursos já alocados
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int need[P][R];               // Recursos necessários (max - allocation)

// Função para calcular a matriz need
void calculateNeed() {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Verifica se o sistema está em estado seguro
bool isSafe() {
    int work[R];
    bool finish[P] = {0};

    // Inicializa work com os recursos disponíveis
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    int safeSeq[P];
    int count = 0;

    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j])
                        break;
                }

                if (j == R) {
                    // Processo pode ser finalizado
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[p][k];

                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("O sistema nao esta em estado seguro!\n");
            return false;
        }
    }

    printf("O sistema esta em estado SEGURO!!\nSequencia segura: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n\n");
    return true;
}

// Função para solicitar recursos
bool requestResources(int processID, int request[]) {
    printf("Processo P%d solicita recursos: ", processID);
    for (int i = 0; i < R; i++)
        printf("%d ", request[i]);
    printf("\n\n");

    // Verifica se pedido não excede o máximo necessário
    for (int i = 0; i < R; i++) {
        if (request[i] > need[processID][i]) {
            printf("Erro: Processo pediu mais do que o necessario.\n");
            return false;
        }
    }

    // Verifica se recursos estão disponíveis
    for (int i = 0; i < R; i++) {
        if (request[i] > available[i]) {
            printf("Erro: Recursos insuficientes.\n");
            return false;
        }
    }

    // Faz alocação temporária (simulação)
    for (int i = 0; i < R; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    // Verifica se sistema continua seguro
    if (isSafe()) {
        printf("Recursos foram alocados.\n\n");
        return true;
    }

    // Caso não esteja seguro, desfaz a alocação
    for (int i = 0; i < R; i++) {
        available[i] += request[i];
        allocation[processID][i] -= request[i];
        need[processID][i] += request[i];
    }

    printf("Recursos nao foram alocados para evitar deadlock.\n");
    return false;
}


int main() {
    calculateNeed();
    isSafe();

    // Exemplo de solicitação
    int request1[R] = {1, 5, 2}; // P1 solicita recursos
    requestResources(1, request1);

    int request2[R] = {3, 3, 0}; // P4 solicita recursos
    requestResources(4, request2);

    return 0;
}
