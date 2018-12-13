#include<stdio.h>
void main()
{
    struct mobile
    {
        int sno;
        char firstname[20];
        char sirname[20];
        char email[30];
        char phoneno[10];
    }x[100];
    FILE *pointer;
    pointer=fopen("customer.txt","w");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
    printf("\n Enter details of customer %d\n",(iloopprint+1));
    x[iloopprint].sno=(iloopprint+1);
    printf("Enter your first name\n");
    gets(x[iloopprint].firstname);
    printf("Enter your last name\n");
    gets(x[iloopprint].sirname);
    printf("Enter your email\n");
    gets(x[iloopprint].email);
    printf("Enter your phone number\n");
    gets(x[iloopprint].phoneno);

    fprintf(pointer," %d %s %s %s %s ", x[iloopprint].sno,x[iloopprint].firstname,x[iloopprint].sirname,x[iloopprint].email,x[iloopprint].phoneno);
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



