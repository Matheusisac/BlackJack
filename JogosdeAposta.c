#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
    int l, c, tiro[2], chance;
    int i;
    int soma[2], n, opcao;
    int jog1[8];
    int dealer[8];
    int pal;
    float aposta;
    float casa = 1000;
    int t1, t2;
    int tabuleiro [5][5];
    int x;

struct cadastro{
        char login[30];
        char senha[30];
        };
char mostrar_tabuleiro (){
    int l,c;
        printf("\n \t1 \t2 \t3 \t4 \t5 \n");
        for(l=0; l<5; l++){
            printf("%d", l+1);
            for(c=0; c<5; c++){
                if(tabuleiro[l][c]==2){
                    printf("\t@");
                }else{
                    if(tabuleiro[l][c]==1){
                    printf("\tX");
                    }else{
                        printf("\t~");
                    }
                }
        }
        printf("\n");
    }
}
    int tabuleiro_com_valor(){
        int c, l, test;
        test=0;
        for(c=0; c<5; c++){
            for(l=0; l<5; l++){
                tabuleiro[c][l]=-1;
            }
        }
        srand(time(NULL));
        tabuleiro[rand()%4][rand()%4]=0;
        tabuleiro[rand()%4][rand()%4]=0;
        for(c=0; c<5; c++){
            for(l=0; l<5; l++){
                test=test+tabuleiro[c][l];
            }
        }
        while(test==-24){
            tabuleiro[rand()%4][rand()%4]=0;
            tabuleiro[rand()%4][rand()%4]=0;
            test=0;
            for(c=0; c<5; c++){
                for(l=0; l<5; l++){
                    test=test+tabuleiro[c][l];
                }
            }
        }
    }
    int comparar(int t1, int t2){
        int test;
        if(tabuleiro[t1][t2]==0){
            tabuleiro[t1][t2]=2;
        }
        else{
            tabuleiro[t1][t2]=1;
        }
}

int main(){
    system("color 2");
    setlocale(LC_ALL, "Portuguese");
    int opcaoo, certo = 0, cartao, escolha, ganhou;
    char login[30], senha[30];
    float dinheiro;
    char string1[30], string2[30];
    struct cadastro conta;
    FILE *entrada;
    FILE *saida;
    FILE *entradadinheiro;
    FILE *saidadinheiro;
    printf("\n  @@@@      @@@@ \t @@@@@@@@@@@@@@  \t @@@@@             ");
    printf("\n  @@@@@    @@@@@ \t @@@@@    @@@@@  \t @@@@@             ");
    printf("\n  @@@@@@  @@@@@@ \t @@@@@    @@@@@  \t @@@@@             ");
    printf("\n  @@@@@@@@@@@@@@ \t @@@@@@@@@@@@@@  \t @@@@@             ");
    printf("\n  @@@@ @@@@ @@@@ \t @@@@@    @@@@@  \t @@@@@             ");
    printf("\n  @@@@  @@  @@@@ \t @@@@@     @@@@@ \t @@@@@@@@@@@@@@    ");
    printf("\n  @@@@      @@@@ \t @@@@@      @@@@@\t @@@@@@@@@@@@@@    ");
    printf("\n\n");
	printf("\n                  \t @@@@@@@@@@@@@@                    ");
    printf("\n                  \t @@@@@      @@@                    ");
    printf("\n                  \t @@@@@                             ");
    printf("\n                  \t @@@@@   @@@@@@                    ");
    printf("\n                  \t @@@@@      @@@                    ");
    printf("\n                  \t @@@@@@@@@@@@@@                    ");
    printf("\n                  \t @@@@@@@@@@@@@@                    ");
	printf("\n\n");
    printf("\n  @@@@      @@@@ \t         @@@@@@ \t @@@@@               ");
    printf("\n  @@@@@    @@@@@ \t          @@@@  \t @@@@@               ");
    printf("\n  @@@@@@  @@@@@@ \t          @@@@  \t @@@@@               ");
    printf("\n  @@@@@@@@@@@@@@ \t          @@@@  \t @@@@@               ");
	printf("\n  @@@@ @@@@ @@@@ \t @@@      @@@@  \t @@@@@               ");
    printf("\n  @@@@  @@  @@@@ \t @@@@@@@@@@@@@  \t @@@@@@@@@@@@@@      ");
    printf("\n  @@@@      @@@@ \t @@@@@@@@@@@@@  \t @@@@@@@@@@@@@@      ");
    printf("\n\n\n\n\n");
    do{
        printf("<1> Criar uma conta.\n");
        printf("<2> Entrar\n");
        printf("opcao--> ");
        scanf("%d", &opcaoo);
        switch(opcaoo){
            case 1:
                system("cls");
                fflush(stdin);
                printf("Login: ");
                scanf("%s", conta.login);
                printf("Senha : ");
                scanf("%s", conta.senha);
                saida = fopen("cadastro.txt", "a");
                fprintf(saida,"%s\n", conta.login);
                fprintf(saida,"%s\n", conta.senha);
                fclose(saida);
                printf("Conta feita com sucesso!\n");
                 break;
             case 2:
                 system("cls");
                 entrada = fopen("cadastro.txt", "r");
                 do{
                     printf("\nLogin: ");
                     scanf("%s", login);
                     printf("Senha: ");
                     scanf("%s", senha);
                     entrada = fopen("cadastro.txt", "r");
                     while ((fscanf (entrada, "%s %s", string1, string2)) != EOF){
                            if((strcmp(login, string1) == 0) && (strcmp(senha, string2) == 0)){
                            certo++;
                            }
                    }
                    if(certo==0){
                        printf("Login ou senha inválido!");
                    }
                }while(certo==0);
                fclose(entrada);
                printf("Bem vindo!\n");
                printf("Digite o valor: ");
                scanf("%f", &dinheiro);
                printf("Digite o número do seu cartão de débito ou crédito: \n");
                scanf("%d", &cartao);
                printf("Transação feita com sucesso.\n");
                saidadinheiro = fopen("extrato.txt", "a");
                fprintf(saidadinheiro,"%f\n", dinheiro);
                fclose(saidadinheiro);
                printf("\n***** menu *****\n");
        }
        }while(opcaoo != 2);
        do{
        printf("\n<1> - 21\n");
        printf("\n<2> - Batalha naval\n");
        printf("\n<3> - Configurações de cores\n");
        printf("\n<4> - Sair");
        printf("\n opcao--> ");
        scanf("%d", &opcao);
        switch(opcao){

            case 1:
            srand(time(NULL));
            entradadinheiro = fopen("extrato.txt", "r");
            fscanf (entradadinheiro, "%.2f ", &dinheiro);
            printf("\n Conta: %.2fR$", dinheiro);
            printf("\n <1> Continuar Jogando ");
            printf("\n <2> Sair ");
            printf("\n Opcao: ");
            scanf("%d", &pal);
            if(dinheiro < 0.1) {
                printf("\n Saldo insuficiente \n");
                pal = 2;
                system("pause");
            }
            while(pal != 2){

    do {
        printf("\n Digite a sua aposta (min = 0.10R$): \n");
        scanf("%f", &aposta);
        }while ((aposta < 0.10) || (aposta > dinheiro));

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
                printf("\n                   Casa Ganha           \n\n ");
                casa= casa + aposta;
                dinheiro = dinheiro - aposta;
                entrada = fopen("extrato.txt", "w");
                fprintf(saida,"%f", dinheiro);
                fclose(saida);
            }
            if(soma[0] > soma[1]){
                printf("\n                 Jogador Ganha           \n\n ");
                dinheiro = aposta + (aposta * 0.9);
                casa = casa - (aposta * 0.9);
            }
            if(soma[1] == soma[0]){
                printf("\n                     Empate               \n\n ");
                casa = casa - (aposta * 0.1);
            }
        system("pause");
        system("cls");
        printf("\n Conta: %.2fR$", dinheiro);
        printf("\n <1> Continuar Jogando ");
        printf("\n <2> Sair ");
        printf("\n Opcao: ");
        scanf("%d", &pal);

        if(dinheiro < 0.1) {
            printf("\n Saldo insuficiente \n");
            pal = 2;
            system("pause");
        }
    }
    system("cls");
            break;
            case 2:
                tabuleiro_com_valor();
                chance=3;
                printf("Ola\n\n");
                while(chance!=0){
                    printf("@ acertou; X errou; ~ representa nao ter tiro\n");
                    mostrar_tabuleiro();
                    printf("\nLinha: ");
                    scanf("%d", &t1);
                    t1=t1-1;
                    printf("\nColuna: ");
                    scanf("%d", &t2);
                    t2=t2-1;
                    comparar(t1, t2);
                    chance--;
                    getchar();
                    }
                mostrar_tabuleiro();
                printf("\n DIGITE ALGO PARA CONCLUIR A RODADA!");
                getchar();
                ganhou=0;
                for(c=0; c<5; c++){
                  for(l=0; l<5; l++){
                     ganhou=ganhou+tabuleiro[c][l];
                  }
                }
                if(ganhou>=-16){
                   printf("\nPARABENS! VOCE GANHOU!");
                }
                else{
                  printf("\nSUAS CHANCES ACABARAM! VOCE PERDEU!");
                }

              system("pause");
              system("cls");
              break;

                case 3:
                printf ("Cores: 1 = Fundo Branco e Fonte Cinza\n");
                printf ("Cores: 2 = Fundo Azul e Fonte Branca\n");
                printf ("Cores: 3 = Fundo Verde Água e Fonte Preta\n");
                printf ("Cores: 4 = Fundo Branco e Fonte Azul Claro\n");
                printf ("Cores: 5 = Fundo Cinza e Fonte Preta\n");
                printf ("Digite 10 para finalizar\n\n\n");
                printf("\nDigite a cor desejada: \n");
                scanf("%i", &x);
                while (x > 0 && x < 6){
                        if (x == 1)
                        system ("color F8");
                        else if (x == 2)
                                system ("color 1F");
                        else if (x == 3)
                                system("color 30");
                        else if (x == 4)
                                system("color F9");
                        else if (x == 5)
                                system("color 80");
                        printf("\nDigite a cor desejada: \n");
                        scanf("%i", &x);
                    }
                    if (x == 10)
                        printf ("Obrigado\n");
                    else if (x != 10)
                            printf("\nNúmero Inválido\n");
                break;
                case 4:
                printf("Obrigado");
                break;
                default:
                printf("Opcao Inexistente.");
                break;
    }
    fclose(entradadinheiro);
        }while(opcao!=4);
}
