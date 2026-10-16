#include <stdio.h>

int main() {
    int pontos[100]; // Vetor para guardar ate 100 lancamentos de pontos
    int total = 0;   // Contador de quantos pontos estao salvos
    int opcao;

    do {
        // MENU PRINCIPAL
        printf("\n=== SISTEMA DE PONTUACAO ===\n");
        printf("1. Adicionar pontos\n");
        printf("2. Mostrar historico de pontos\n");
        printf("3. Buscar ponto especifico\n");
        printf("4. Atualizar um ponto\n");
        printf("5. Remover ultimo ponto\n");
        printf("6. Relatorio\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // 1. CREATE (Adicionar)
        if (opcao == 1) {
            if (total >= 100) {
                printf("Vetor cheio! Nao e possivel adicionar mais.\n");
            } else {
                int valor;
                printf("Digite a quantidade de pontos: ");
                scanf("%d", &valor);

                if (valor > 0) {
                    pontos[total] = valor;
                    total++;
                    printf("Pontos adicionados com sucesso!\n");
                } else {
                    printf("Valor invalido! Digite um valor maior que zero.\n");
                }
            }
        } 
        // 2. READ (Mostrar todos)
        else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum ponto cadastrado.\n");
            } else {
                printf("\n--- HISTORICO DE PONTOS ---\n");
                for (int i = 0; i < total; i++) {
                    printf("Posicao %d: +%d pontos\n", i, pontos[i]);
                }
            }
        } 
        // 3. BUSCAR
        else if (opcao == 3) {
            if (total == 0) {
                printf("Nenhum ponto cadastrado.\n");
            } else {
                int busca;
                int achou = 0;
                printf("Digite o valor do ponto que quer buscar: ");
                scanf("%d", &busca);

                for (int i = 0; i < total; i++) {
                    if (pontos[i] == busca) {
                        printf("Ponto %d encontrado na posicao %d\n", busca, i);
                        achou = 1;
                    }
                }

                if (achou == 0) {
                    printf("Ponto nao encontrado.\n");
                }
            }
        } 
        // 4. UPDATE (Atualizar)
        else if (opcao == 4) {
            if (total == 0) {
                printf("Nenhum ponto cadastrado.\n");
            } else {
                int posicao, novoValor;
                printf("Digite a posicao que deseja alterar (0 a %d): ", total - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < total) {
                    printf("Digite o novo valor de pontos: ");
                    scanf("%d", &novoValor);
                    
                    if (novoValor > 0) {
                        pontos[posicao] = novoValor;
                        printf("Ponto alterado com sucesso!\n");
                    } else {
                        printf("Valor invalido!\n");
                    }
                } else {
                    printf("Posicao invalida!\n");
                }
            }
        } 
        // 5. DELETE (Remover ultimo)
        else if (opcao == 5) {
            if (total == 0) {
                printf("Nenhum ponto para remover.\n");
            } else {
                total--; // Apenas diminui o total para descartar o ultimo elemento
                printf("Ultimo ponto removido com sucesso!\n");
            }
        } 
        // 6. RELATORIO
        else if (opcao == 6) {
            if (total == 0) {
                printf("Sem dados para relatorio.\n");
            } else {
                int soma = 0;
                int maior = pontos[0];
                int menor = pontos[0];

                for (int i = 0; i < total; i++) {
                    soma += pontos[i];

                    if (pontos[i] > maior) {
                        maior = pontos[i];
                    }
                    if (pontos[i] < menor) {
                        menor = pontos[i];
                    }
                }

                float media = (float)soma / total;

                printf("\n--- RELATORIO ---\n");
                printf("Total de lancamentos: %d\n", total);
                printf("Soma total de pontos: %d\n", soma);
                printf("Media de pontos: %.2f\n", media);
                printf("Maior pontuacao: %d\n", maior);
                printf("Menor pontuacao: %d\n", menor);
            }
        } 
        // SAIR OU OPCAO INVALIDA
        else if (opcao == 7) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 7);

    return 0;
}