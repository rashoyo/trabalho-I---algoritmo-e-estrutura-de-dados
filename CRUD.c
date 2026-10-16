#include <stdio.h>

int main() {
    int pontos[100]; // Vetor para guardar ate 100 lancamentos de pontos
    int total = 0;   // Contador de quantos pontos estao salvos
    int opcao;

    do {
        // MENU PRINCIPAL
        printf("\n=== GERENCIADOR DE PONTUACAO DE JOGO ===\n");
        printf("1. Registrar nova pontuacao\n");
        printf("2. Ver placar e total acumulado\n");
        printf("3. Buscar se atingiu uma pontuacao\n");
        printf("4. Corrigir pontuacao existente\n");
        printf("5. Remover ultima pontuacao\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // 1. CREATE (Adicionar)
        if (opcao == 1) {
            if (total >= 100) {
                printf("Limite de partidas atingido!\n");
            } else {
                int valor;
                printf("Digite a quantidade de pontos obtida: ");
                scanf("%d", &valor);

                if (valor > 0) {
                    pontos[total] = valor;
                    total++;
                    printf("Pontuacao registrada com sucesso!\n");
                } else {
                    printf("Valor invalido! Digite um valor maior que zero.\n");
                }
            }
        } 
        // 2. READ (Mostrar placar + resumo)
        else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhuma pontuacao cadastrada ainda.\n");
            } else {
                int soma = 0;
                printf("\n--- PLACAR DAS PARTIDAS ---\n");
                for (int i = 0; i < total; i++) {
                    printf("Partida %d: +%d pontos\n", i + 1, pontos[i]);
                    soma += pontos[i];
                }
                
                // Resumo direto na mesma tela
                float media = (float)soma / total;
                printf("---------------------------\n");
                printf("Pontos Totais: %d | Media por partida: %.1f\n", soma, media);
            }
        } 
        // 3. SEARCH (Buscar)
        else if (opcao == 3) {
            if (total == 0) {
                printf("Nenhuma pontuacao cadastrada ainda.\n");
            } else {
                int busca;
                int achou = 0;
                printf("Digite a pontuacao que deseja buscar no historico: ");
                scanf("%d", &busca);

                for (int i = 0; i < total; i++) {
                    if (pontos[i] == busca) {
                        printf("A pontuacao de %d pontos foi alcancada na Partida %d!\n", busca, i + 1);
                        achou = 1;
                    }
                }

                if (achou == 0) {
                    printf("Voce ainda nao fez %d pontos em nenhuma partida.\n", busca);
                }
            }
        } 
        // 4. UPDATE (Atualizar)
        else if (opcao == 4) {
            if (total == 0) {
                printf("Nenhuma pontuacao para alterar.\n");
            } else {
                int partida, novoValor;
                printf("Digite o numero da partida que quer corrigir (1 a %d): ", total);
                scanf("%d", &partida);

                int indice = partida - 1; // Converte para o indice do vetor (0 a total-1)

                if (indice >= 0 && indice < total) {
                    printf("Digite a nova pontuacao para a Partida %d: ", partida);
                    scanf("%d", &novoValor);
                    
                    if (novoValor > 0) {
                        pontos[indice] = novoValor;
                        printf("Pontuacao corrigida com sucesso!\n");
                    } else {
                        printf("Valor invalido!\n");
                    }
                } else {
                    printf("Partida invalida!\n");
                }
            }
        } 
        // 5. DELETE (Remover ultimo)
        else if (opcao == 5) {
            if (total == 0) {
                printf("Nenhuma pontuacao para remover.\n");
            } else {
                total--; // Descarta o ultimo elemento
                printf("Ultima pontuacao removida com sucesso!\n");
            }
        } 
        // SAIR OU OPCAO INVALIDA
        else if (opcao == 6) {
            printf("Saindo do gerenciador de pontuacao...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}