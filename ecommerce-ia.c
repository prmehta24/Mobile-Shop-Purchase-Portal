#include<stdio.h>
#include<conio.h>
void main()
{
    struct mobile
    {
        int sno;
        char company[100];
        char model[100];
        int stock;
        int price;
    }x[100];
    FILE *pointer;
    pointer=fopen("data.txt","r");
    int iloopprint;

    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    printf("Company\tModel\tStock\tPrice\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        printf("%s\t%s\t%d\t%d \n", x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
    }
    fclose(pointer);
    getch();
}



