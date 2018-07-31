#include<stdio.h>
#include<string.h>
int main()
{
    int len,number=0,upper=0,other=0;
    char *i;
    char s[100];
    printf("Enter string :::>>>\n");
    gets(s);
    len=strlen(s);
    for(i=&s[0];i<&s[len];i++)
    {
        if(*i>='a'&&*i<='z')printf("");
        else if(*i>='0'&&*i<='9')number++;
        else if(*i>='A'&&*i<='Z')upper++;
        else other++;
    }
    printf("++ Counting Result ++\n");
    printf("Numbers           = %d\n",number);
    printf("Uppercase Letters = %d\n",upper);
    printf("Others            = %d\n",other);
    printf("--++--++ END ++--++--\n");
    return 0;
}
