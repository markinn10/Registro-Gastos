#include <stdio.h>
#include <stdlib.h>
#include <string.h>

      struct Gasto {char nome[50];float valor;
    char data[20];
};

void inserirGasto(struct Gasto *gastos, int *numGastos);
void listarGastos(struct Gasto *gastos, int numGastos);
void buscarGasto(struct Gasto *gastos, int numGastos);
void editarGasto(struct Gasto *gastos, int numGastos);
void removerGasto(struct Gasto *gastos, int *numGastos);
void mostrarSomaEMedia(struct Gasto *gastos, int numGastos);
void salvarEmArquivo(struct Gasto *gastos, int numGastos);

int main() {
    struct Gasto gastos[100]; 
    int numGastos = 0; 
    int opcao; 

    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo gasto\n");
        printf("2. Listar gastos\n");
        printf("3. Buscar gasto\n");
        printf("4. Editar gasto\n");
        printf("5. Remover gasto\n");
        printf("6. Mostrar soma e media dos gastos\n");
        printf("7. Salvar em arquivo\n");
        printf("0. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirGasto(gastos, &numGastos);
                break;
            case 2:
                listarGastos(gastos, numGastos);
                break;
            case 3:
                buscarGasto(gastos, numGastos);
                break;
            case 4:
                editarGasto(gastos, numGastos);
                break;
            case 5:
                removerGasto(gastos, &numGastos);
                break;
            case 6:
                mostrarSomaEMedia(gastos, numGastos);
                break;
            case 7:
                salvarEmArquivo(gastos, numGastos);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para inserir um novo gasto
void inserirGasto(struct Gasto *gastos, int *numGastos) {
    printf("Digite o nome do gasto: ");
    scanf("%s", gastos[*numGastos].nome);
    printf("Digite o valor do gasto: ");
    scanf("%f", &gastos[*numGastos].valor);
    printf("Digite a data do gasto (DD/MM/AAAA): ");
    scanf("%s", gastos[*numGastos].data);
    

    (*numGastos)++;
}

// Função para listar todos os gastos
void listarGastos(struct Gasto *gastos, int numGastos) {
    printf("\nLista de Gastos:\n");
    printf("%-20s%-10s%-15s\n", "Nome", "Valor", "Data");
    for (int i = 0; i < numGastos; i++) {
        printf("%-20s%-10.2f%-15s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
    }
}

// Função para buscar um gasto pelo nome
void buscarGasto(struct Gasto *gastos, int numGastos) {
    char nomeBusca[50];
    printf("Digite o nome do gasto a ser buscado: ");
    scanf("%s", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeBusca) == 0) {
            printf("Gasto encontrado:\n");
            printf("%-20s%-10s%-15s\n", "Nome", "Valor", "Data");
            printf("%-20s%-10.2f%-15s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Gasto não encontrado.\n");
    }
}

// Função para editar um gasto
void editarGasto(struct Gasto *gastos, int numGastos) {
    char nomeEdit[50];
    printf("Digite o nome do gasto a ser editado: ");
    scanf("%s", nomeEdit);

    int encontrado = 0;
    for (int i = 0; i < numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeEdit) == 0) {
            printf("Digite as novas informações do gasto:\n");
            printf("Nome: ");
            scanf("%s", gastos[i].nome);
            printf("Valor: ");
            scanf("%f", &gastos[i].valor);
            printf("Data (DD/MM/AAAA): ");
            scanf("%s", gastos[i].data);
            printf("Gasto editado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Gasto não encontrado.\n");
    }
}

// Função para remover um gasto
void removerGasto(struct Gasto *gastos, int *numGastos) {
    char nomeRemover[50];
    printf("Digite o nome do gasto a ser removido: ");
    scanf("%s", nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < *numGastos; i++) {
        if (strcmp(gastos[i].nome, nomeRemover) == 0) {
            // Sobrescrever o gasto a ser removido com o último gasto na lista
            gastos[i] = gastos[*numGastos - 1];
            (*numGastos)--;
            printf("Gasto removido com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Gasto não encontrado.\n");
    }
}

// Função para mostrar a soma e a média dos gastos
void mostrarSomaEMedia(struct Gasto *gastos, int numGastos) {
    float soma = 0;
    for (int i = 0; i < numGastos; i++) {
        soma += gastos[i].valor;
    }

    if (numGastos > 0) {
        printf("Soma dos gastos: %.2f\n", soma);
        printf("Média dos gastos: %.2f\n", soma / numGastos);
    } else {
        printf("Não há gastos cadastrados.\n");
    }
}

// Função para salvar os gastos em um arquivo
void salvarEmArquivo(struct Gasto *gastos, int numGastos) {
    FILE *arquivo;
    arquivo = fopen("gastos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numGastos; i++) {
        fprintf(arquivo, "%s %.2f %s\n", gastos[i].nome, gastos[i].valor, gastos[i].data);
    }

    fclose(arquivo);
    printf("Dados salvos em arquivo com sucesso.\n");
}
