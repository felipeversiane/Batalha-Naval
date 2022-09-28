#include <stdio.h>

#include <stdlib.h>

void inicializar(int tabuleiro[][10])

{

    for(int i=0;i<10;i++)

    {

        for(int j=0;j<10;j++)

        {

            tabuleiro[i][j]=-1;



        }

    }

}

void mostrar(int tabuleiro[][10],int tentativas, int acertos)

{

    printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10");

    printf("\n");

    for(int i=0;i<10;i++)

    {

        printf("%i",i+1);

        for(int j=0;j<10;j++)

        {

            if(tabuleiro[i][j]==-1)

                printf("\t#");

            if(tabuleiro[i][j]==0)

                printf("\to");

            if(tabuleiro[i][j]==1)

                printf("\tx");



        }

        printf("\n\n\n");





    }

    printf("TENTATIVAS: %d \n",tentativas);

    printf("ACERTOS: %d",acertos);

    printf("\n\n\n");

}

void inicializarNavios(char navios[][10])

{



    int c,l;

    srand(time(NULL));

    int rands = rand()%10;

    c=(rand()%rands);

    l=(rand()%rands);

    for(int k=0;k<4;k++)

    {

        navios[l][c]='W';

        c++;

    }

    l=(rand()%rands);

    c=(rand()%rands);

    for(int k=0;k<3;k++)

    {

        navios[l][c]='W';

        c++;

    }

    l=(rand()%rands);

    c=(rand()%rands);

    for(int k=0;k<3;k++)

    {

        navios[l][c]='W';

        c++;

    }

    l=(rand()%rands);

    c=(rand()%rands);

    for(int k=0;k<2;k++)

    {

        navios[l][c]='W';

        c++;

    }

    l=(rand()%rands);

    c=(rand()%rands);

    for(int k=0;k<2;k++)

    {

        navios[l][c]='W';

        c++;

    }

    l=(rand()%rands);

    c=(rand()%rands);

    navios[l][c]='W';

    l=(rand()%rands);

    c=(rand()%rands);

    navios[l][c]='W';

    l=(rand()%rands);

    c=(rand()%rands);

    navios[l][c]='W';

    l=(rand()%rands);

    c=(rand()%rands);

    navios[l][c]='W';

    l=(rand()%rands);

    c=(rand()%rands);

    navios[l][c]='W';



}



void darTiro(int tiro[])

{



    printf("Digite a linha :");

    scanf("%i",&tiro[0]);

    printf("Digite a coluna ");

    scanf("%d",&tiro[1]);

    tiro[0]--;

    tiro[1]--;

}

int acertou(int tiro[],char navios[][10])

{

    if(navios[tiro[0]][tiro[1]]=='W')

    {

        return 1;

    }

        return 0;

}





void alteraTabuleiro(int tiro[], int navios[][10], int tabuleiro[][10])

{

        if(acertou(tiro,navios)==1)

            tabuleiro[tiro[0]][tiro[1]]=1;

        else

            tabuleiro[tiro[0]][tiro[1]]=0;



}

int ganhou(int acertos)

{

    int p=0;

    if(acertos==17)

    {

        p=1;

        return p;

    }

    return p;



}

int main()

{

   int tabuleiro[10][10],tiro[2],tentativas=0,acertos=0;

   char navios[10][10];

   inicializar(tabuleiro);

   inicializarNavios(navios);



    do

    {

        mostrar(tabuleiro,tentativas,acertos);

        darTiro(tiro);

        tentativas++;



        if(acertou(tiro,navios)==1)

        {

            alteraTabuleiro(tiro,navios,tabuleiro);

            printf("VOCE ACERTOU");

            acertos++;

            system("cls");

            if(ganhou(acertos)==1)

                printf("VOCE GANHOU O JOGO");



        }

        else

        {

        printf("VOCE ERROU");

        system("cls");

        alteraTabuleiro(tiro,navios,tabuleiro);

        }







    }

    while(tentativas<25);

    printf("ACABOU,VOCE ESGOTOU SUA MUNICAO\n Voce teve um total de : %d pontos",acertos);

}

