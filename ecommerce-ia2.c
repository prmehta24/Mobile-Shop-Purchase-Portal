#include<stdio.h>
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
    pointer=fopen("data.txt","w");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        printf("%s\t%s\t%d\t%d \n", x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {

    printf("\n Enter item %d\n",(iloopprint+1));
    x[iloopprint].sno=(iloopprint+1);
    printf("Enter the phone company\n");
    gets(x[iloopprint].company);
    printf("Enter phone model(one word only)\n");
    gets(x[iloopprint].model);
    printf("Enter the number in stock\n");
    scanf("%d" ,&x[iloopprint].stock);
    fflush(stdin);
    printf("Enter the MRP of the phone\n");
    scanf("%d" ,&x[iloopprint].price);

fflush(stdin);
        fprintf(pointer," %d %s %s %d %d ", x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
int exitchoice=0;
        printf("Enter 1 if you are done entering items\n");
        scanf("%d",&exitchoice);
        fflush(stdin);
        if(exitchoice==1)
            break;
    }
    fclose(pointer);
    getch();
}



