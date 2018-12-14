
#include<stdio.h>
#include<conio.h>
void main()
{
    struct cust
    {
        int sno;
        char firstname[20];
        char sirname[20];
        char email[30];
        char phoneno[10];

    }x[100];
    FILE *pointer;
    pointer=fopen("customer.txt","r");
    int iloopprint;

    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    printf("FirstName\tLastName\tEmailId\t\t\tPhoneNumber\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {



            int count=fscanf(pointer,"%d %s %s %s %s", &x[iloopprint].sno,&x[iloopprint].firstname,&x[iloopprint].sirname,&x[iloopprint].email,&x[iloopprint].phoneno);
             if(count!=-1)
        printf("%-10s\t%-10s\t%-10s\t%-10s\n", x[iloopprint].firstname,x[iloopprint].sirname,x[iloopprint].email,x[iloopprint].phoneno);

    }
    fclose(pointer);
    getch();
}



