#include <stdio.h>
#include "estado.h"


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e, int *contaX,int *contaO)
{
    char c = ' ';
    *contaX = 0;
    *contaO = 0;
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ",i+1);
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    (*contaO) ++;
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    (*contaX) ++;
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}

void poepeca (ESTADO *e,int x, int y){
    e->grelha[x][y] = e->peca;
}

void joga (ESTADO *e, int x, int y){
    int c=y,l=x;
    VALOR p;
    if (e->peca == VALOR_X) p = VALOR_O; // p -> peça contrária
    else p = VALOR_X;

    // modificar para a direita--------------------------
    while (e->grelha[l][c+1] == p && c < 8) c++;
    if (c==8);
    else if (e->grelha[l][c+1] == e->peca) for(;c!=y;c--) e->grelha[l][c] = e->peca;
    else;
    //----------------------------------------------------
    c=y,l=x;

    // modificar para a esquerda-------------------------
    while (e->grelha[l][c-1] == p && c > 0) c--;
    if (c==0);
    else if (e->grelha[l][c-1] == e->peca) for (;c!=y;c++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar para baixo--------------------------------
    while (e->grelha[l+1][c] == p && l < 8) l++;
    if (l == 8);
    else if (e->grelha[l+1][c] == e->peca) for (;l!=x;l--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar para cima
    while (e->grelha[l-1][c] == p && l > 0) l--;
    if (l == 0);
    else if (e->grelha[l-1][c] == e->peca) for (;l!=x;l++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar cima direita
    while (e->grelha[l-1][c+1] == p && c < 8 && l > 0) {
        l--;
        c++;
    }
    if (l == 0 || c == 8 );
    else if (e->grelha[l-1][c+1] == e->peca) for (;l!=x;l++,c--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar cima esquerda
    while (e->grelha[l-1][c-1] == p && c > 0 && l > 0) {
        l--;
        c--;
    }
    if (l == 0 || c == 0 );
    else if (e->grelha[l-1][c-1] == e->peca) for (;l!=x;l++,c++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar baixo esquerda
    while (e->grelha[l+1][c-1] == p && c > 0 && l < 8) {
        l++;
        c--;
    }
    if (l == 8 || c == 0 );
    else if (e->grelha[l+1][c-1] == e->peca) for (;l!=x;c++,l--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar baixo direita
    while (e->grelha[l+1][c+1] == p && c < 8 && l < 8) {
        l++;
        c++;
    }
    if (l == 8 || c == 8 );
    else if (e->grelha[l+1][c+1] == e->peca) for (;l!=x;l--,c--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
}

int verificajogada (ESTADO *e, int x, int y) {
    int flag = 0;
    if (e->grelha[x][y] != VAZIA);
    else {
        int l = x, c = y;
        VALOR p;
        if (e->peca == VALOR_X) p = VALOR_O; // p -> peça contrária
        else p = VALOR_X;

        //direita
        if (e->grelha[x][y + 1] == p) {
            while (e->grelha[l][c + 1] == p && c < 8) c++;
            if (e->grelha[l][c + 1] == e->peca && c < 8) flag = 1;
        }
        l = x, c = y;

        //esquerda
        if (e->grelha[x][y - 1] == p && flag == 0) {
            while (e->grelha[l][c - 1] == p && c > 0) c--;
            if (e->grelha[l][c - 1] == e->peca && c > 0) flag = 1;
        }
        l = x, c = y;

        //cima
        if (e->grelha[x - 1][y] == p && flag == 0) {
            while (e->grelha[l - 1][c] == p && l > 0) l--;
            if (e->grelha[l - 1][c] == e->peca && l > 0) flag = 1;
        }
        l = x, c = y;

        //baixo
        if (e->grelha[x + 1][y] == p && flag == 0) {
            while (e->grelha[l + 1][c] == p && l < 8) l++;
            if (e->grelha[l + 1][c] == e->peca && l < 8) flag = 1;
        }
        l = x, c = y;

        //cima direita
        if (e->grelha[x - 1][y + 1] == p && flag == 0) {
            while (e->grelha[l - 1][c + 1] == p && l > 0 && c < 8) {
                l--;
                c++;
            }
            if (e->grelha[l - 1][c + 1] == e->peca && l > 0 && c < 8) flag = 1;
        }
        l = x, c = y;

        //baixo direita
        if (e->grelha[x + 1][y + 1] == p && flag == 0) {
            while (e->grelha[l + 1][c + 1] == p && l < 8 && c < 8) {
                l++;
                c++;
            }
            if (e->grelha[l + 1][c + 1] == e->peca && l < 8 && c < 8) flag = 1;
        }
        l = x, c = y;

        //baixo esquerda
        if (e->grelha[x + 1][y - 1] == p && flag == 0) {
            while (e->grelha[l + 1][c - 1] == p && l < 8 && c > 0) {
                l++;
                c--;
            }
            if (e->grelha[l + 1][c - 1] == e->peca && l < 8 && c > 0) flag = 1;
        }
        l = x, c = y;

        //cima esquerda
        if (e->grelha[x - 1][y - 1] == p && flag == 0) {
            while (e->grelha[l - 1][c - 1] == p && l > 0 && c > 0) {
                l--;
                c--;
            }
            if (e->grelha[l - 1][c - 1] == e->peca && l > 0 && c > 0) flag = 1;
        }
    }

    return flag;
}
void readGame (ESTADO *e, char linha[]) {
    FILE *file;
    char modo;
    char peca;
    char ficheiro[50];
    int i, k, j;
    sscanf(linha, "%c %s", &modo, ficheiro);
    file = fopen(strcat(ficheiro, ".txt"), "r");
    if (file == NULL) printf("O ficheiro não existe");
    else {
        fscanf(file, "%c %c", &modo, &peca);
        if (modo == 'M') e->modo = 0;
        else e->modo = 1;
        if (peca == 'X') e->peca = VALOR_X;
        else e->peca = VALOR_O;
        fseek(file, 1, SEEK_CUR);
        for (i = 0; i < 8; i++) {
            fgets(linha, 50, file);
            j = 0;
            for (k = 0; linha[k] != '\n' && j < 8; k++) {
                if (linha[k] == 'X') {
                    e->grelha[i][j] = VALOR_X;
                    j++;
                } else if (linha[k] == 'O') {
                    e->grelha[i][j] = VALOR_O;
                    j++;
                } else if (linha[k] == '-' || linha[k] == '.') {
                    e->grelha[i][j] = VAZIA;
                    j++;
                }
            }

        }
        fclose(file);

    }
}

void guardajogo (ESTADO *e , char linha[]) {
    FILE *file;
    char modo;
    char peca;
    char ficheiro[50];
    int i,k;
    sscanf(linha,"%c %s",&modo, ficheiro);
    file = fopen(strcat(ficheiro, ".txt"), "w");

    if (e->modo == 0) modo = 'M';
    else modo = 'A';
    if (e->peca == VALOR_X) peca = 'X';
    else peca = 'O';

    fprintf(file,"%c %c\n",modo,peca);
    for (i = 0;i<8;i++){
        for (k = 0; k<8;k++){
            if (e->grelha[i][k] == VALOR_X) fprintf(file,"X ");
            else if (e->grelha[i][k] == VALOR_O) fprintf(file,"O ");
            else if (verificajogada(e,i,k)) fprintf(file,". ");
            else fprintf(file,"- ");
        }
        fprintf(file,"\n");
    }
    fclose(file);
}

void whereCanIPut (ESTADO *e){
    int i,k;
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++){
        printf("%d ",i+1);
        for (k = 0; k<8;k++){
            if (e->grelha[i][k] == VALOR_X) printf("X ");
            else if (e->grelha[i][k] == VALOR_O) printf("O ");
            else if (verificajogada(e,i,k)) printf(". ");
            else printf("- ");
        }
        putchar('\n');
    }
}

void novoEstado (ESTADO *e, char linha[]){
    int i,k;
    char c1,c2;
    e->ant = NULL;
    for (i=0;i<8;i++){
        for (k=0;k<8;k++){
            e->grelha[i][k] = VAZIA;
        }
    }
    e->modo = 0;
    // estado inicial do tabuleiro. Inicio do jogo!
    e->grelha[3][4] = VALOR_X;
    e->grelha[4][3] = VALOR_X;
    e->grelha[3][3] = VALOR_O;
    e->grelha[4][4] = VALOR_O;
    sscanf(linha,"%c %c",&c1,&c2);
    if (toupper(c2) == 'X') e->peca = VALOR_X;
    else e->peca = VALOR_O;
}

void copyEstado (ESTADO *e, ESTADO *aux){
    aux->peca = e->peca;
    aux->modo = e->modo;
    int i,k;
    for (i=0;i<8;i++){
        for (k=0;k<8;k++){
            aux->grelha[i][k] = e->grelha[i][k];
        }
    }
    aux->ant = e->ant;
}

void giveHint (ESTADO *e){
    int max = 0;
    int temp;
    int i,k;
    int l,col;
    for (i=0;i<8;i++){
        for (k=0;k<8;k++){
            if (verificajogada(e,i,k)){
                temp = killCount(e,i,k);
                if (temp > max) {
                    max = temp;
                    l = i;col=k;
                }
            }
        }
    }
    char c = ' ';
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0; i < 8; i++) {
        printf("%d ",i+1);
        for (k = 0; k < 8; k++) {
            switch (e->grelha[i][k]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X : {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            if (i==l && k == col) printf("? ");
            else printf("%c ", c);

        }
        printf("\n");
    }
}

int killCount (ESTADO *e,int x,int y){
        int c=y,l=x;
        VALOR p;
        int contagem = 0;
        if (e->peca == VALOR_X) p = VALOR_O; // p -> peça contrária
        else p = VALOR_X;

        // modificar para a direita--------------------------
        while (e->grelha[l][c+1] == p && c < 8) c++;
        if (c==8) ;
        else if (e->grelha[l][c+1] == e->peca) for(;c!=y;c--) contagem ++;

        else;
        //----------------------------------------------------
        c=y,l=x;

        // modificar para a esquerda-------------------------
        while (e->grelha[l][c-1] == p && c > 0) c--;
        if (c==0);
        else if (e->grelha[l][c-1] == e->peca) for (;c!=y;c++) contagem ++;

        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar para baixo--------------------------------
        while (e->grelha[l+1][c] == p && l < 8) l++;
        if (l == 8);
        else if (e->grelha[l+1][c] == e->peca) for (;l!=x;l--) contagem ++;
        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar para cima
        while (e->grelha[l-1][c] == p && l > 0) l--;
        if (l == 0);
        else if (e->grelha[l-1][c] == e->peca) for (;l!=x;l++) contagem ++;

        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar cima direita
        while (e->grelha[l-1][c+1] == p && c < 8 && l > 0) {
            l--;
            c++;
        }
        if (l == 0 || c == 8 );
        else if (e->grelha[l-1][c+1] == e->peca) for (;l!=x;l++,c--) contagem ++;

        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar cima esquerda
        while (e->grelha[l-1][c-1] == p && c > 0 && l > 0) {
            l--;
            c--;
        }
        if (l == 0 || c == 0 );
        else if (e->grelha[l-1][c-1] == e->peca) for (;l!=x;l++,c++) contagem ++;

        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar baixo esquerda
        while (e->grelha[l+1][c-1] == p && c > 0 && l < 8) {
            l++;
            c--;
        }
        if (l == 8 || c == 0 );
        else if (e->grelha[l+1][c-1] == e->peca) for (;l!=x;c++,l--) contagem ++;

        else;
        //-----------------------------------------------------
        c=y,l=x;

        // modificar baixo direita
        while (e->grelha[l+1][c+1] == p && c < 8 && l < 8) {
            l++;
            c++;
        }
        if (l == 8 || c == 8 );
        else if (e->grelha[l+1][c+1] == e->peca) for (;l!=x;l--,c--) contagem ++;
        else;
        //-----------------------------------------------------
    return contagem;

}

int gameOver (ESTADO *e, int *contaX, int *contaO) {
    int resultado = 0;
    if (*contaX + *contaO == 64) {
        if (*contaX > *contaO) {
            printf("Vencedor ! : X\n");
            resultado = 1;
        } else if (*contaX < *contaO) {
            printf("Vencedor ! : O\n");
            resultado = 1;
        } else {
            printf("Empate!\n");
            resultado = 1;
        }
    } else {
        if (!checkIfPlayable(e)) {
            resultado = 1;
            if (*contaX > *contaO) printf("Vencedor ! : X\n");
            else if (*contaX < *contaO) printf("Vencedor ! : O\n");
            else printf("Empate!\n");
        }

    }
    return resultado;
}
int checkIfPlayable (ESTADO *e){
    int flag1 = 0,flag2 = 0;
    int resultado = 0;
    flag1 = playerPlayable(e);
    trocapeca(e);
    flag2 = playerPlayable(e);
    trocapeca(e);
    if (flag1 == 0 && flag2 == 0) resultado = 0;
    else resultado = 1;
    return resultado;
}

int playerPlayable (ESTADO *e){
    int i,k;
    int flag1 = 0;
    for (i=0;i<8 && flag1 == 0;i++){
        for (k=0;k<8 && flag1 == 0;k++){
            if (verificajogada(e,i,k)) flag1 = 1;
        }
    }
    return flag1;
}
void trocapeca (ESTADO *e){
    if (e->peca == VALOR_X) e->peca = VALOR_O;
    else e->peca = VALOR_X;
}
void interface (){
    printf("N <peca> // novo jogo em que o primeiro a jogar é o jogador com peça\n");
    printf("L <ficheiro> // ler um jogo de ficheiro\n");
    printf("E <ficheiro> // Guardar jogo\n");
    printf("J <L> <C> // Jogar [linha] [coluna]\n");
    printf("S // Colocar pontos nos locais de jogada válida\n");
    printf("P // Imprimir estado do jogo\n");
    printf("H // Dar sugestão de jogada\n");
    printf("U // Desfazer jogada anterior\n");
}
