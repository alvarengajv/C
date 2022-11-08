#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4
#define TENT 10

void geradorsenha (int senha[]) {

    int i;

    /*senha gerada pelo computador*/
    srand(time(NULL));

    for (i = 0; i < TAM; i++) {
        senha[i] = rand() % 6 + 1;
    }

    /*resposta
    for (i = 0; i < TAM; i++) {
        printf("%d ", senha[i]);
    } */
}

int main (void) {

    int senha[TAM]; /*senha gerada pelo computador*/
    int usuario[TAM]; //vetor que o jogador vai preencher
    int pinosbrancos = 0;
    int pinospretos = 0;
    int i, j;
    int tentativas;
    char continuar;
    int senha1[TAM] = {0, 0, 0, 0};
    int usuario1[TAM] = {0, 0, 0, 0};

    printf("Seja bem vindo ao senha. Seu objetivo e' descobrir qual a senha gerada pelo computador.\n"
           "Regras:\n"
           "1 - Voce tera' no maximo 10 tentativas.\n"
           "2 - As senhas sao compostas de numeros entre 1 e 6.\n"
           "3 - Os algarismos sao digitados um por um\n"
           "4 - O pino 'preto' indica posicao e valor correto.\n"
           "5 - Ja o pino 'branco' indica somente valor correto.\n");

    while (1) {

        tentativas = TENT;

        /*chama a funcao que gera a senha*/
        geradorsenha(senha);

        printf("\n");

        while (tentativas > 0) {
            printf("\nDigite sua senha: (Para cada algarismo digite enter)\n");

            /*senha gerada pelo usuario*/
            for (i = 0; i < TAM; i++) {
                printf("algarismo da posicao %d: ", i + 1);
                scanf("%d", &usuario[i]);
                /*limitador de resposta*/
                while (usuario[i] < 1 || usuario[i] > 6) {
                    printf("!!! Algarismo invalido !!!\n"
                           "min: 1   max: 6\n");
                    printf("algarismo da posicao %d: ", i + 1);
                    scanf("%d", &usuario[i]);
                }
            }

            printf("Senha digitada: %d %d %d %d\n", usuario[0], usuario[1], usuario[2], usuario[3]);

            for (i = 0; i < TAM; i++) {
                if (usuario[i] == senha[i]) {
                    pinospretos++;
                    senha1[i] = 1;
                    usuario1[i] = 1;

                    /*caso de vitória*/
                    if (pinospretos == TAM) {
                        printf("VOCE GANHOU! PARABENS!\n");
                        printf("Numero de tentativas: %d\n", 11 - tentativas);
                        tentativas = 0;
                    }
                }
            }

            for (i = 0; i < TAM; i++) {
                for (j = 0; j < TAM; j++) {
                    if (senha[j] == usuario[i] && senha1[j] == 0 && usuario1[i] == 0) {
                        pinosbrancos++;
                        senha1[j] = 1;
                        usuario1[i] = 1;
                    }
                }
            }

            for (i = 0; i < TAM; i++) {
                senha1[i] = 0;
                usuario1[i] = 0;
            }

            tentativas--;

            /*contador de pinos e tentativas*/
            if (tentativas > 0) {
                printf("Voce tem %d pino(s) preto(s), %d pino(s) branco(s) e %d tentativa(s) restante(s).\n",
                       pinospretos, pinosbrancos, tentativas);
            }
            pinospretos = 0;
            pinosbrancos = 0;
        }

        /*caso de derrota*/
        if (tentativas == 0) {
            printf("NAO FOI DESSA VEZ. VOCE PERDEU, TENTE NOVAMENTE.\n"
                   "Senha do computador: ");
            for (i = 0; i < TAM; i++) {
                printf("%d ", senha[i]);
            }
        }
        printf("\n");

        /*loop para jogar de novo*/
        printf("\nDeseja jogar novamente? [ S ] [ N ]\n");
        scanf("%s", &continuar);
        /*limitador de resposta*/
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
            printf("!!! Caractere invalido !!!\n"
                   "Deseja jogar novamente? [ S ] [ N ]\n");
            scanf("%s", &continuar);
        }
        if (continuar == 's' || continuar == 'S') {
            printf("Reiniciando partida...\n");
            continue;
        } else if (continuar == 'n' || continuar == 'N') {
            printf("Fim de jogo.\n");
            break;
        }
    }
    return 0;
}
