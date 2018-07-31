#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,kx,ky,a[10][10],i,j,k,score=0;
time_t t;
char c;
void dun(char c)
{
    int i,j,k,tmp;
    if(c=='D')
    {
         for(i=1;i<=4;i++)
         {
             for(j=4;j>=1;j--)
             {
                 if(a[i][j]!=0)
                 {
                     tmp=a[i][j];
                     a[i][j]=0;
                     for(k=j;k<=4;k++)if(a[i][k]!=0)break;
                     a[i][k-1]=tmp;
                 }
             }
         }
    }
    else if(c=='A')
    {
        for(i=1;i<=4;i++)
         {
             for(j=1;j<=4;j++)
             {
                 if(a[i][j]!=0)
                 {
                     tmp=a[i][j];
                     a[i][j]=0;
                     for(k=j;k>=1;k--)if(a[i][k]!=0)break;
                     a[i][k+1]=tmp;
                 }
             }
         }
    }
    else if(c=='W')
    {
        for(j=1;j<=4;j++)
        {
            for(i=1;i<=4;i++)
            {
                if(a[i][j]!=0)
                {
                    tmp=a[i][j];
                    a[i][j]=0;
                    for(k=i;k>=1;k--)if(a[k][j]!=0)break;
                    a[k+1][j]=tmp;
                }
            }
        }
    }
    else if(c=='S')
    {
        for(j=1;j<=4;j++)
        {
            for(i=4;i>=1;i--)
            {
                if(a[i][j]!=0)
                {
                    tmp=a[i][j];
                    a[i][j]=0;
                    for(k=i;k<=4;k++)if(a[k][j]!=0)break;
                    a[k-1][j]=tmp;
                }
            }
        }
    }
}
void sum(char c)
{
    int i,j,k,tmp;
    if(c=='D')
    {
        for(i=1;i<=4;i++)
        {
            for(j=4;j>=1;j--)
            {
                if(a[i][j-1]==a[i][j]){a[i][j]*=2;a[i][j-1]=0;score+=a[i][j];}
            }
        }
    }
    else if(c=='A')
    {
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(a[i][j+1]==a[i][j]){a[i][j]*=2;a[i][j+1]=0;score+=a[i][j];}
            }
        }
    }
    else if(c=='W')
    {
        for(j=1;j<=4;j++)
        {
            for(i=1;i<=4;i++)
            {
                if(a[i][j]==a[i+1][j]){a[i][j]*=2;a[i+1][j]=0;score+=a[i][j];}
            }
        }
    }
    else if(c=='S')
    {
        for(j=1;j<=4;j++)
        {
            for(i=4;i>=1;i--)
            {
                if(a[i][j]==a[i-1][j]){a[i][j]*=2;a[i-1][j]=0;score+=a[i][j];}
            }
        }
    }
}
int check()
{
    int i,j;
    for(i=1;i<=4;i++)for(j=1;j<=4;j++)if(a[i][j]==2048)return 1;
    return 0;
}
int main()
{
    int i,j,con,f;
    char s;
    printf("WELCOME TO 2048 GAME\n\nSlide up    ENTER W\nSlide down  ENTER S\nSlide left  ENTER A\nSlide right ENTER D\n\n\n");
    srand((unsigned)time(&t));
    kx=rand()%4+1; ky=rand()%4+1;
    a[kx][ky]=2;
    while(1)
    {
        con=0;
        while(con==0)
        {
            kx=rand()%4+1; ky=rand()%4+1;
            if(a[kx][ky]==0)
            {
                con=1;a[kx][ky]=2;
            }
        }
        int i,j;
        if(f==0)f=check();
        if(f==1)
        {
            printf("******************************************\n");
            printf("*Congratulations You WIN the game 2048 !!*\n");
            printf("******************************************\n\n");
            printf("Keep going ENTER K , End the game ENTER E :");
            scanf(" %c",&s);
            if(s=='K')f=2;
            else return 0;
        }
        printf("---");
        for(i=1;i<4;i++)printf("------");printf("\n");
        for(i=1;i<=4;i++)
        {

            printf("|");
            for(j=1;j<=4;j++)printf("%4d|",a[i][j]);
            printf("\n");
        }
        printf("---");
        for(i=1;i<4;i++)printf("------");printf("\n");
        printf("Score : %d\n",score);
        printf("Slide : ");
        //scanf(" %c",&c);
        c=getch();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        dun(c);sum(c);dun(c);
    }
    return 0;
}
