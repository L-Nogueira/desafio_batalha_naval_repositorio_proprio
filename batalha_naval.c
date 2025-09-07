#include <stdio.h>

int main(){

printf("Bem vindo à batalha naval...\n\n");
// declaração e inicialização do tabuleiro
int tabuleiro[10][10] = {
    {0,0,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

//Criação das matrizes de habilidades
int hablidade_cone[5][5] = {
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,1,1,1,0},
    {1,1,1,1,1},
    {0,0,0,0,0}
};

int hablidade_cruz[5][5] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,1,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

int hablidade_octaedro[5][5] = {
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,1,1,1,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
};

// Criação dos labels de linhas e colunas
char colunas[11] = {' ','A','B','C','D','E','F','G','H','I','J'};
int linhas[10] = {1,2,3,4,5,6,7,8,9,10};

for(int i = 0; i < 11; i++){
    printf("%2c", colunas[i]);
}
printf("\n");

//posicionamento dos navios
for(int i = 0; i < 3; i++) {
    tabuleiro[4][6 + i] = 3;
}

for(int i = 0; i < 3; i++) {
    tabuleiro[3 + i][2] = 3;
}

for(int i = 0; i < 3; i++) {
    tabuleiro[0 + i][1 + i] = 3;
}

for(int i = 0; i < 3; i++) {
    tabuleiro[7 + i][6 - i] = 3;
}

//introdução da habilidade cone no tabuleiro
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        
        if(hablidade_cone[i][j] == 1) {
            int linha = 0 - 1 + i;
            int coluna = 0 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (tabuleiro[linha][coluna] == 3) {
                tabuleiro[linha][coluna] = 5;
                } else {
                    tabuleiro[linha][coluna] += 1;
                }
            }
        }
    }       
}        

//introdução da habilidade cruz no tabuleiro
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {

        if(hablidade_cruz[i][j] == 1) {
            int linha = 6 - 1 + i;
            int coluna = 5 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (tabuleiro[linha][coluna] == 3) {
                tabuleiro[linha][coluna] = 5;
                } else {
                    tabuleiro[linha][coluna] += 1;
                }
            }
        }
    }       
}

//introdução da habilidade octaedro no tabuleiro
for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
        if(hablidade_octaedro[i][j] == 1) {
            int linha = 4 - 1 + i;
            int coluna = 2 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (tabuleiro[linha][coluna] == 3) {
                tabuleiro[linha][coluna] = 5;
                } else {
                    tabuleiro[linha][coluna] += 1;
                }
            }
        }
    }       
}

//impressão do tabuleiro
for(int i = 0, j = 0; i < 10, j < 10; i++, j++) {
    printf("%2d ", linhas[j]);

    for(int j = 0; j < 10; j++) {
        printf ("%d ", tabuleiro[i][j]);
    } 
    printf("\n");
}

printf("\n");

return 0;
}