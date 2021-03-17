#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int soma[2], n, opcao;
    int jog1[8];
    int dealer[8];
    int pal;

    srand(time(NULL));
    printf("\n <1> Continuar Jogando ");
    printf("\n <2> Sair ");
    printf("\n Opcao: ");
    scanf("%d", &pal);
    while(pal != 2){

        printf("\n\n Jogador 1:");
        for(i=0; i<2; i++){
            jog1[i] = rand() % 13;
            if ((jog1[i] >= 10) || (jog1[i] == 0)){
                if(jog1[i] == 0){
                    printf("   A     ");
                }
                if(jog1[i] == 10){
                    printf("   J     ");
                }
                if(jog1[i] == 11){
                    printf("   Q     ");
                    jog1[i] = jog1[i] - 1;
                }
                if(jog1[i] == 12){
                    printf("   K     ");
                    jog1[i] = jog1[i] - 2;
                }
            }
            else{
                jog1[i] = jog1[i] + 1;
                printf("   %d    ", jog1[i]);
            }
            if (i == 1){
                printf("\n\n");
            }
        }
        if (jog1[0] == 0){
            while ((jog1[0] != 1) && (jog1[0] != 10)) {
                printf("\n Qual valor que vc quer de A(1 ou 10): ");
                scanf("%d", &jog1[0]);
            }
        }
        if (jog1[1] == 0){
            while ((jog1[1] != 1) && (jog1[1] != 10)) {
                printf("\n Qual valor que vc quer de A(1 ou 10): ");
                scanf("%d", &jog1[1]);
            }
        }
        soma[0] = jog1[0] + jog1[1];
        do{
            printf("\n <1> mais uma carta");
            printf("\n <2> parar");
            printf("\n opcao--> ");
            scanf("%d", &opcao);
            if(opcao == 1){
                n=1;
                n++;
                jog1[n] = rand() % 13;
                if ((jog1[n] >= 10) || (jog1[n] == 0)){
                    if(jog1[n] == 0){
                        printf("             A          ");
                    }
                    if(jog1[n] == 10){
                        printf("             J           ");
                    }
                    if(jog1[n] == 11){
                        printf("             Q           ");
                        jog1[n] = jog1[n] - 1;
                    }
                    if(jog1[n] == 12){
                        printf("              K          ");
                        jog1[n] = jog1[n] - 2;
                    }
                }
                else{
                    jog1[n] = jog1[n] + 1;
                    printf("         **%d** ", jog1[n]);
                }
                if (jog1[n] == 0){
                    while ((jog1[n] != 1) && (jog1[n] != 10)) {
                    printf("\n Qual valor que vc quer de A(1 ou 10): ");
                    scanf("%d", &jog1[n]);
                    }
                }
                soma[0] = soma[0] + jog1[n];
            }
            printf("\n soma= %d \n\n", soma[0]);
            }while((soma[0] < 21) && (opcao != 2));
            if(soma[0] > 21){
                printf("\n\n      Perdeu: Voce estourou          \n\n ");
                soma[0] = 0;
            }
            if(soma[0] == 21){
                printf("\n\n             BlackJack               \n\n ");
            }
            system("pause");
            system("cls");




            printf("\n\n Dealer:");
            for(i=0; i<2; i++){
                dealer[i] = rand() % 13;
                if ((dealer[i] >= 10) || (dealer[i] == 0)){
                    if(dealer[i] == 0){
                    printf("   A     ");
                }
                if(dealer[i] == 10){
                    printf("   J     ");
                }
                if(dealer[i] == 11){
                    printf("   Q     ");
                    dealer[i] = dealer[i] - 1;
                }
                if(dealer[i] == 12){
                    printf("   K     ");
                    dealer[i] = dealer[i] - 2;
                }
            }
            else{
                dealer[i] = dealer[i] + 1;
                printf("   %d    ", dealer[i]);
            }
            if (i == 1){
                printf("\n\n");
            }
        }
        soma[1] = dealer[0] + dealer[1];
        if ((dealer[0] == 0) || (dealer[1] == 0)){
            if((soma[1] <= 8) && (dealer[0] == 0)){
                dealer[0] = 10;
            }
            if((soma[1] <= 8) && (dealer[1] == 0)){
                dealer[1] = 10;
            }
            if((soma[1] > 8) && (dealer[0] == 0)){
                dealer[0] = 1;
            }
            if((soma[1] > 8) && (dealer[1] == 0)){
                dealer[1] = 1;
            }
            if((dealer[1] == 0) && (dealer[0] == 0)){
                dealer[1] = 10;
                dealer[0] = 10;
            }
            soma[1] = dealer[0] + dealer[1];
        }
        while(soma[1] <= soma[0]){
            n=1;
            n++;
            dealer[n] = rand() % 13;
            if ((dealer[n] >= 10) || (dealer[n] == 0)){
                if(dealer[n] == 0){
                    printf("             A          ");
                }
                if(dealer[n] == 10){
                    printf("             J           ");
                }
                if(dealer[n] == 11){
                    printf("             Q           ");
                    dealer[n] = dealer[n] - 1;
                }
                if(jog1[n] == 12){
                    printf("              K          ");
                    dealer[n] = dealer[n] - 2;
                }
                }
                else{
                    dealer[n] = dealer[n] + 1;
                    printf("        **%d**    ", dealer[n]);
                }
                if (dealer[n] == 0){
                    if (soma[1] <= 11){
                        dealer[n] = 10;
                    }
                    else{
                        dealer[n] = 1;
                    }
                }
                soma[1] = soma[1] + dealer[n];
                printf("\n soma= %d \n\n", soma[1]);
            }
            printf("\n soma do Jogador= %d \n\n", soma[0]);
            printf("\n soma da Casa= %d \n\n", soma[1]);
            if(soma[1] > 21){
                printf("\n A casa Estourou  \n");
                soma[1] = 0;
            }
            if(soma[1] > soma[0]){
                printf("\n                   Casa Ganha        \n\n ");
            }
            if(soma[0] > soma[1]){
                printf("\n                 Jogador Ganha        \n\n ");
            }
            if(soma[1] == soma[0]){
                printf("\n                     Empate            \n\n ");
            }
        system("pause");
        system("cls");
        printf("\n <1> Continuar Jogando ");
        printf("\n <2> Sair ");
        printf("\n Opcao: ");
        scanf("%d", &pal);
    }
}
