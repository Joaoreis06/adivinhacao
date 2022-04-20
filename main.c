#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//CASTING: conversão de tipos de variáveis.
//         void main()
//         {
//            int a = 3;
//            int b = 2;
//            double pontos = a / (double)b;
//            printf("%.1f", pontos);
//         }

void main()
{
    printf("*************************************\n");
    printf("* Bem vindo ao jogo da adivinhacao! *\n");
    printf("*************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numero_rand = rand();
    int numero_secreto = numero_rand % 100;
    int chute;
    int numero_tentativas;
    double pontuacao = 1000;
    int pontos_perdidos;
    int nivel;

    printf("\n\n***NIVEL DE DIFICULDADE***\n\n");
    printf("(1)- Facil | (2) - Medio | (3) - Dificil");
    printf("\nEscolha a sua dificuldade: ");
    scanf("%d", &nivel);

    if(nivel == 3){
        numero_tentativas = 3;
    }
    else if(nivel == 2){
        numero_tentativas = 5;
    }
    else if(nivel == 1){
        numero_tentativas = 10;
    }

    for(int i = 1; i <= numero_tentativas; i++){
        printf("\n\nTentativa: %d", i);
        printf("\nQual e o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d", chute);

        int acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);
        int menor = (chute < numero_secreto);

        if(chute < 0){
            printf("\nVoce NAO PODE chutar numeros negativos!");
            continue;
        }

        if(acertou){
            printf("\nParabens! Voce ACERTOU!.");
            break;
        }

        else{
            if(maior){
                printf("\nVoce ERROU o chute...");
                printf("\nSeu chute foi MAIOR que o numero sorteado.");
            }

            if(menor){
                printf("\nVoce ERROU o chute...");
                printf("\nSeu chute foi MENOR que o numero sorteado.");
            }
        }

        double pontos_perdidos = abs(chute - numero_secreto) / (double)2;
        pontuacao -= pontos_perdidos;

    }
    printf("\n\nPONTUACAO: %.1f pontos", pontuacao);
    printf("\nFINAL do jogo de adivinhacao.");
    printf("\nA resposta certa era: %d", numero_secreto);
}
