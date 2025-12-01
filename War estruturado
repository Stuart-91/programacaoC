#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Definicoes e Constantes ---
#define TAM_NOME 30
#define TAM_COR 10
#define MAX_MISSAO_LEN 100
#define NUM_TERRITORIOS 6
#define JOGADOR_COR "Azul" // Define a cor do jogador principal para verificacao de missao

// Estrutura para representar um territorio
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

// --- Prototipos das Funcoes (Modularizacao Total) ---
// Funcoes de Inicializacao e Gerenciamento
void inicializarMapa(Territorio mapa[], int tamanho);
char* atribuirMissaoAleatoria(char* missoes[], int totalMissoes);
void liberarMemoria(char* missaoJogador); // Apenas libera a missao (alocada dinamicamente)

// Funcoes de Jogo e Logica
void menuPrincipal(Territorio mapa[], int tamanho, char* missaoJogador, int* jogoVencido);
void realizarAtaque(Territorio mapa[], int tamanho);
// const correctness: O atacante e o defensor nao mudam de endereco, mas seus conteudos sim.
void atacar(Territorio* const atacante, Territorio* const defensor); 
// const correctness: Apenas le a missao e o mapa, nao os modifica.
int verificarMissao(const char* missao, const Territorio mapa[], int tamanho);

// Funcoes de Interface e Utilidade (const correctness aplicado)
void exibirMapa(const Territorio mapa[], int tamanho);
void exibirMissao(const char* missao); 

// --- Funcao Principal ---
int main() {
    srand(time(NULL));

    // O mapa eh alocado estaticamente neste nivel para simplificar o gerenciamento de memoria.
    Territorio mapa[NUM_TERRITORIOS]; 
    
    // Alocacao dinamica para a string da missao.
    char* missaoJogador = (char*)malloc(MAX_MISSAO_LEN * sizeof(char));
    if (missaoJogador == NULL) {
        perror("Falha ao alocar memoria para a missao");
        return EXIT_FAILURE;
    }

    // Vetor de missoes pre-definidas
    char* missoes_pre_definidas[] = {
        "Destruir o exercito Verde.",
        "Conquistar 3 territorios.",
        "Controlar exatamente 4 territorios.",
        "Capturar o territorio 'Venezuela'."
    };
    int totalMissoes = sizeof(missoes_pre_definidas) / sizeof(char*);

    // Inicializacao do jogo
    inicializarMapa(mapa, NUM_TERRITORIOS);
    // Copia a string da missao sorteada para a memoria alocada dinamicamente
    strcpy(missaoJogador, atribuirMissaoAleatoria(missoes_pre_definidas, totalMissoes));

    printf("--- BEM-VINDO AO WAR ESTRUTURADO (Nivel Mestre) ---\n");
    exibirMissao(missaoJogador);
    printf("---------------------------------------------------\n");

    int jogoVencido = 0;
    while (!jogoVencido) {
        menuPrincipal(mapa, NUM_TERRITORIOS, missaoJogador, &jogoVencido);
        if (jogoVencido) {
            printf("\n!!! CONDICAO DE VITORIA ATINGIDA !!!\n");
            printf("!!!PARABENS, VOCE VENCEU O JOGO!!!\n");
            exibirMissao(missaoJogador);
        }
    }

    liberarMemoria(missaoJogador);
    return EXIT_SUCCESS;
}

// --- Implementacao das Funcoes ---

/**
 * Exibe o menu principal e processa a escolha do jogador.
 * Passagem por referencia para 'jogoVencido' para modificar o estado do loop principal.
 */
void menuPrincipal(Territorio mapa[], int tamanho, char* missaoJogador, int* jogoVencido) {
    int opcao = -1;
    printf("\n======= MENU PRINCIPAL =======\n");
    exibirMapa(mapa, tamanho);
    printf("Escolha uma opcao:\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missao\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            realizarAtaque(mapa, tamanho);
            // Verificar missao automaticamente apos um ataque
            *jogoVencido = verificarMissao(missaoJogador, mapa, tamanho);
            break;
        case 2:
            exibirMissao(missaoJogador);
            *jogoVencido = verificarMissao(missaoJogador, mapa, tamanho);
            if (!(*jogoVencido)) printf("Missao ainda nao foi cumprida.\n");
            break;
        case 0:
            printf("Saindo do jogo...\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
}

/**
 * Inicializa o mapa do jogo com estados pre-definidos.
 */
void inicializarMapa(Territorio mapa[], int tamanho) {
    if (tamanho >= 6) {
        strcpy(mapa[0].nome, "Brasil"); strcpy(mapa[0].cor, JOGADOR_COR); mapa[0].tropas = 4;
        strcpy(mapa[1].nome, "Argentina");      strcpy(mapa[1].cor, "Vermelho"); mapa[1].tropas = 2;
        strcpy(mapa[2].nome, "Venezuela");    strcpy(mapa[2].cor, "Verde");    mapa[2].tropas = 1;
        strcpy(mapa[3].nome, "Paraguai");         strcpy(mapa[3].cor, JOGADOR_COR); mapa[3].tropas = 3;
        strcpy(mapa[4].nome, "Uruguai");           strcpy(mapa[4].cor, "Vermelho"); mapa[4].tropas = 1;
        strcpy(mapa[5].nome, "Chile");       strcpy(mapa[5].cor, "Verde");    mapa[5].tropas = 2;
    }
}

/**
 * Sorteia uma missao aleatoria do vetor e retorna a string (ponteiro para o literal).
 */
char* atribuirMissaoAleatoria(char* missoes[], int totalMissoes) {
    int indiceSorteado = rand() % totalMissoes;
    return missoes[indiceSorteado];
}

/**
 * Gerencia a interacao do ataque, validacao de entrada e chamada da logica de batalha.
 */
void realizarAtaque(Territorio mapa[], int tamanho) {
    int idAtacante, idDefensor;
    printf("\n--- Realizar Ataque ---\n");
    printf("Escolha os IDs (0 a %d). Atacante precisa de 2+ tropas e ser %s.\n", tamanho - 1, JOGADOR_COR);
    
    printf("ID Atacante: ");
    scanf("%d", &idAtacante);
    printf("ID Defensor: ");
    scanf("%d", &idDefensor);

    // Validacoes robustas antes de chamar a funcao de ataque
    if (idAtacante < 0 || idAtacante >= tamanho || idDefensor < 0 || idDefensor >= tamanho || idAtacante == idDefensor) {
        printf("Erro: IDs invalidos ou iguais.\n");
        return;
    }
    if (strcmp(mapa[idAtacante].cor, JOGADOR_COR) != 0) {
        printf("Erro: Voce so pode atacar com seus proprios territorios (%s).\n", JOGADOR_COR);
        return;
    }
     if (strcmp(mapa[idAtacante].cor, mapa[idDefensor].cor) == 0) {
        printf("Erro: Nao eh possivel atacar um territorio aliado.\n");
        return;
    }
    if (mapa[idAtacante].tropas < 2) {
        printf("Erro: O territorio atacante precisa de no minimo 2 tropas.\n");
        return;
    }

    // Chamada da funcao de ataque com ponteiros para os structs especificos
    atacar(&mapa[idAtacante], &mapa[idDefensor]);
}

/**
 * Simula a logica da batalha usando dados aleatorios.
 * Usa 'const' no primeiro ponteiro para garantir que o ENDERECO nao seja alterado dentro da funcao.
 */
void atacar(Territorio* const atacante, Territorio* const defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("  > Dados: Atacante (%s) tirou %d, Defensor (%s) tirou %d.\n", atacante->nome, dadoAtacante, defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("  > Vitoria do atacante! Territorio capturado.\n");
        strcpy(defensor->cor, atacante->cor);
        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;
    } else {
        printf("  > Vitoria do defensor ou empate. Atacante perde uma tropa.\n");
        atacante->tropas--;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }
}

/**
 * Avalia se a missao do jogador foi cumprida.
 * Usa 'const' em todos os parametros pois a funcao apenas le dados (leitura do estado do jogo).
 */
int verificarMissao(const char* missao, const Territorio mapa[], int tamanho) {
    if (strstr(missao, "Destruir o exercito Verde") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Verde") == 0) {
                return 0; // Ainda existem tropas verdes
            }
        }
        return 1; // Missao cumprida
    }
    
    if (strstr(missao, "Conquistar 3 territorios") != NULL) {
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, JOGADOR_COR) == 0) {
                count++;
            }
        }
        return count >= 3; // Retorna 1 se tiver 3 ou mais, 0 caso contrario
    }

    if (strstr(missao, "Capturar o territorio 'Venezuela'") != NULL) {
         for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].nome, "Asia Central") == 0 && strcmp(mapa[i].cor, JOGADOR_COR) == 0) {
                return 1; // Missao cumprida
            }
        }
        return 0;
    }

    // Caso a logica da missao nao esteja implementada:
    return 0;
}

/**
 * Exibe o estado atual do mapa do jogo.
 * Usa 'const' em todos os parametros pois a funcao apenas le dados.
 */
void exibirMapa(const Territorio mapa[], int tamanho) {
    printf("--- Mapa Atual ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID [%d] | Nome: %-20s | Dono: %-10s | Tropas: %d\n", 
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

/**
 * Exibe a descricao da missao.
 * Usa 'const' no parametro (passagem por valor/copia do ponteiro).
 */
void exibirMissao(const char* missao) {
    printf("Missao Secreta: \"%s\"\n", missao);
}

/**
 * Libera a memoria alocada dinamicamente para a string da missao.
 */
void liberarMemoria(char* missaoJogador) {
    printf("\nLiberando memoria...\n");
    if (missaoJogador != NULL) {
        free(missaoJogador);
        missaoJogador = NULL;
    }
    printf("Memoria liberada. Fim do programa.\n");
}
