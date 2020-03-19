#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menuJogo();

void limpaTela(){
    system("CLS");
}

void criaTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;
    for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<3; coluna++){
            tabuleiro[linha][coluna]= '-';
        }
    }
}

void instrucoesdeJogo(char *nomeDoJogadorUm, char *nomeDoJogadorDois, int rodada, int pontuacaoJogadorUm, int pontuacaoJogadorDois){
    printf("\n\n  | 7 | 8 | 9 |  \n");
    printf("  | 4 | 5 | 6 |  \n");
    printf("  | 1 | 2 | 3 |  ");

    printf("\nJogador %s , sera X.\n", nomeDoJogadorUm);
    printf("E o jogador %s , sera O.\n", nomeDoJogadorDois);
    printf("\n\n");
    printf("Rodada numero: %d\n\n", rodada);
    printf("\nPontuação: %s %d X %d %s \n\n", nomeDoJogadorUm, pontuacaoJogadorUm, pontuacaoJogadorDois ,nomeDoJogadorDois);
}

void mostraTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;
    for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<3; coluna++){
            printf("  %c", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int confereTabuleiro(char tabuleiro[3][3]){

        int linha, coluna;

        //return = 1, X ganhou
        //return = 2, O ganhou
        // returna = 0, segue o jogo

        // ganha com linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X'
               && tabuleiro[linha][0] == tabuleiro[linha][1]
               && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }
            else if(tabuleiro[linha][0] == 'O'
                    && tabuleiro[linha][0] == tabuleiro[linha][1]
                    && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //ganha com colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X'
               && tabuleiro[0][coluna] == tabuleiro[1][coluna]
               && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O'
                     && tabuleiro[0][coluna] == tabuleiro[1][coluna]
                     && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //diagonal
        if(tabuleiro[0][0] != '-'
           && tabuleiro[0][0] == tabuleiro[1][1]
           && tabuleiro[1][1] == tabuleiro[2][2]){

            if(tabuleiro[0][0] == 'X'){
               return 1;
            }else{
               return 2;
            }
        }

        //diagonal
        if(tabuleiro[0][2] != '-'
           && tabuleiro[0][2] == tabuleiro[1][1]
           && tabuleiro[1][1] == tabuleiro[2][0]){

            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
               return 2;
            }
        }

        return 0;
}

void estruturaDoJogo(char *nomeDoJogadorUm, char *nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    char tabuleiro[3][3], itemPassado;
    int posicaoJogada=0, turnoDoJogador=1, statusDoJogo=0, rodada =0, selecao=0;
    int jogadaValida= 0;
    limpaTela();

    criaTabuleiro(tabuleiro);

    while(rodada < 9 && statusDoJogo == 0){
        limpaTela();

        instrucoesdeJogo(nomeDoJogadorUm,nomeDoJogadorDois,rodada,pontuacaoJogadorUm, pontuacaoJogadorDois);

        mostraTabuleiro(tabuleiro);
        printf("\n");

    jogadaValida = 0;

       while(jogadaValida == 0) {
        if(turnoDoJogador == 1){
            printf("Jogador %s, Escolha aonde irá inserir o X:", nomeDoJogadorUm );
            scanf("%d", &posicaoJogada);
            itemPassado = 'X';
        }
        else{
            printf("Jogador %s, Escolha aonde irá inserir a O:", nomeDoJogadorDois );
            scanf("%d", &posicaoJogada);
            itemPassado = 'O';
        }

        switch(posicaoJogada){
            case 1:
            if(tabuleiro[2][0] == '-'){
            jogadaValida = 1;
            tabuleiro[2][0] = itemPassado;
            break;
            }
            else{
            break;
            }

            case 2:
            if(tabuleiro[2][1] == '-'){
            tabuleiro[2][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
                };

            case 3:
            if(tabuleiro[2][2] == '-'){
            tabuleiro[2][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 4:
            if(tabuleiro[1][0] == '-'){
            tabuleiro[1][0] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 5:
            if(tabuleiro[1][1] == '-'){
            tabuleiro[1][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 6:
            if(tabuleiro[1][2] == '-'){
            tabuleiro[1][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 7:
            if(tabuleiro[0][0] == '-'){
            tabuleiro[0][0] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 8:
            if(tabuleiro[0][1] == '-'){
            tabuleiro[0][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 9:
            if(tabuleiro[0][2] == '-'){
            tabuleiro[0][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

        }

        }

    if(turnoDoJogador == 1){
            turnoDoJogador = 2;
    }

    else{
        turnoDoJogador =1;
    }

    rodada++;

    if(confereTabuleiro(tabuleiro) == 1){
        printf("Jogador %s venceu!!!", nomeDoJogadorUm);
        statusDoJogo++;
        pontuacaoJogadorUm++;
    }
    else if (confereTabuleiro(tabuleiro) == 2){
        printf("Jogador %s venceu!!!", nomeDoJogadorDois);
        statusDoJogo++;
        pontuacaoJogadorDois++;
    }
    else if (rodada == 9){
        printf("Empate!!!");
    }

    }

    printf("\n");
    mostraTabuleiro(tabuleiro);
    printf("\n");

    printf("Fim de Jogo!\n");

    printf("O que deseja Fazer?\n");
    printf("1- Continuar Jogando\n");
    printf("2- Retornar menu principal\n");
    printf("3- Sair\n");
    scanf("%d", &selecao);

    if(selecao == 1){
        estruturaDoJogo(nomeDoJogadorUm, nomeDoJogadorDois, pontuacaoJogadorUm, pontuacaoJogadorDois);
    }
    else if(selecao == 2){
        menuJogo();
    }


}

void menuJogo(){

    int opcaoEscolhida = 0, pontuacaoJogadorUm, pontuacaoJogadorDois;
    char nomeDoJogadorUm[15], nomeDoJogadorDois[15];

    while(opcaoEscolhida < 1 || opcaoEscolhida > 3){
    void limpaTela();

    printf("Bem-Vindo ao Jogo da Velha\n\n\n");
    printf("Escolha uma da opções a baixo");
    printf("\n1- Jogar");
    printf("\n2- Sobre");
    printf("\n3- Sair");
    printf("\nDigite da opção e aperte Enter:");
    scanf("%d", &opcaoEscolhida);

    switch(opcaoEscolhida){
        case 1:
            printf("Digite o nome do Jogador 1:");
            scanf("%s",&nomeDoJogadorUm);
            printf("Digite o nome do Jogador 2:");
            scanf("%s", &nomeDoJogadorDois);
            estruturaDoJogo(nomeDoJogadorUm,nomeDoJogadorDois,0,0);
        break;

        case 2:
            printf("\n\nJogo desenvolvido por:\nHiago Silva da Silva\nLeonardo Oliveira de Farias\nGabriel Luis Mendes\n"
                   "Jogo desenvolvido para o trabalho de Praticas de Programação 2020/01\n"
                   "Jogo da Velha, para efetuar as escolhas de 'X' ou 'O', utilize o teclado numérico.\n\n");
                   printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Sair \n Escolha e aperte Enter: ");
                   int opcao;
                   scanf("%d", &opcao);
                   if(opcao ==1){
                        limpaTela();
                        menuJogo();
                   }else{
                   break;
                   }
        break;

        case 3:
            printf("\n\nAté mais!\n\n");
        break;
    }




 }

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    menuJogo();

    return 0;
}
