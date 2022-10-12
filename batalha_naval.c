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
     printf("\n\t\t\t---------NAVAL BATTLE GAME----------\n");
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

    printf("\n\t\t---------YOU HAVE 25 TRIES  TO WIN THE GAME ----------\n");
    printf("\nATTEMPTS: %d \n",tentativas);

    printf("\nHITS: %d",acertos);

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



    printf("Enter the line with a number between 0-9 :");

    scanf("%i",&tiro[0]);

    printf("Enter the colunm with a number between 0-9 ");

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
void navalBattle()
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

            printf("YOU WIN");

            acertos++;

            system("cls");

            if(ganhou(acertos)==1)

                printf("YOU WIN");



        }

        else

        {

        printf("YOU MISSED");

        system("cls");

        alteraTabuleiro(tiro,navios,tabuleiro);

        }







    }

    while(tentativas<25);
    system("cls");
    printf("IT'S OVER, YOU'RE OUT OF YOUR AMMO\n YOU HAD A TOTAL OF : %d POINTS",acertos);
    int i;
        i=0;
        printf("\n\nDO YOU WANNA PLAY AGAIN?");
        printf("\n----->ENTER[ANY NUMBER]TO YES ");
        printf("\n----->ENTER[2]TO NO \n");
        scanf("%d",&i);
        if(i!=2)
        {
          system("cls");
          navalBattle();
        }
        system("cls");
        printf("----------I'LL SEE YOU  YOU LATER!!----------\n");
        system("pause");
        exit(0);




}

int main()

{
    navalBattle();
}
