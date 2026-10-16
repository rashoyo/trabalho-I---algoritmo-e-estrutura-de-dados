#include <stdio.h>

int main() {
    int historicoPontuacoes[100]; // Vetor para guardar ate 100 lancamentos
    int totalDePartidas = 0;       // Contador de partidas cadastradas
    int opcaoSelecionada;

    do {
        // MENU PRINCIPAL
        printf("\n=== GERENCIADOR DE PONTUACAO DE JOGO ===\n");
        printf("1. Registrar nova pontuacao\n");
        printf("2. Ver placar de pontuacoes\n");
        printf("3. Buscar se atingiu uma pontuacao\n");
        printf("4. Corrigir pontuacao existente\n");
        printf("5. Remover ultima pontuacao\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoSelecionada);

        // 1. CREATE (Adicionar)
        if (opcaoSelecionada == 1) {
            if (totalDePartidas >= 100) {
                printf("Limite de partidas atingido!\n");
            } else {
                int pontosObtidos;
                printf("Digite a quantidade de pontos obtida: ");
                scanf("%d", &pontosObtidos);

                historicoPontuacoes[totalDePartidas] = pontosObtidos;
                totalDePartidas++;
                printf("Pontuacao registrada com sucesso!\n");
            }
        } 
        // 2. READ (Mostrar apenas a lista simples)
        else if (opcaoSelecionada == 2) {
            if (totalDePartidas == 0) {
                printf("Nenhuma pontuacao cadastrada ainda.\n");
            } else {
                printf("\n--- PLACAR DAS PARTIDAS ---\n");
                for (int indicePartida = 0; indicePartida < totalDePartidas; indicePartida++) {
                    printf("Partida %d: %d pontos\n", indicePartida + 1, historicoPontuacoes[indicePartida]);
                }
            }
        } 
        // 3. SEARCH (Buscar)
        else if (opcaoSelecionada == 3) {
            if (totalDePartidas == 0) {
                printf("Nenhuma pontuacao cadastrada ainda.\n");
            } else {
                int pontuacaoBuscada;
                int encontrouPontuacao = 0;
                printf("Digite a pontuacao que deseja buscar no historico: ");
                scanf("%d", &pontuacaoBuscada);

                for (int indicePartida = 0; indicePartida < totalDePartidas; indicePartida++) {
                    if (historicoPontuacoes[indicePartida] == pontuacaoBuscada) {
                        printf("A pontuacao de %d pontos foi alcancada na Partida %d!\n", pontuacaoBuscada, indicePartida + 1);
                        encontrouPontuacao = 1;
                    }
                }

                if (encontrouPontuacao == 0) {
                    printf("Voce nao fez %d pontos em nenhuma partida.\n", pontuacaoBuscada);
                }
            }
        } 
        // 4. UPDATE (Atualizar)
        else if (opcaoSelecionada == 4) {
            if (totalDePartidas == 0) {
                printf("Nenhuma pontuacao para alterar.\n");
            } else {
                int numeroPartida, novaPontuacao;
                printf("Digite o numero da partida que quer corrigir (1 a %d): ", totalDePartidas);
                scanf("%d", &numeroPartida);

                int indiceSubstituir = numeroPartida - 1; // Converte para o indice do vetor (0 a totalDePartidas-1)

                if (indiceSubstituir >= 0 && indiceSubstituir < totalDePartidas) {
                    printf("Digite a nova pontuacao para a Partida %d: ", numeroPartida);
                    scanf("%d", &novaPontuacao);
                    
                    historicoPontuacoes[indiceSubstituir] = novaPontuacao;
                    printf("Pontuacao corrigida com sucesso!\n");
                } else {
                    printf("Partida invalida!\n");
                }
            }
        } 
        // 5. DELETE (Remover ultimo)
        else if (opcaoSelecionada == 5) {
            if (totalDePartidas == 0) {
                printf("Nenhuma pontuacao para remover.\n");
            } else {
                totalDePartidas--; // Descarta o ultimo elemento
                printf("Ultima pontuacao removida com sucesso!\n");
            }
        } 
        // SAIR OU OPCAO INVALIDA
        else if (opcaoSelecionada == 6) {
            printf("Saindo do gerenciador de pontuacao...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcaoSelecionada != 6);

    return 0;
}