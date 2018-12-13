#include<stdio.h>
#include<conio.h>
void pay()
{
    struct pay
    {
        int sno;
        char cccompany[30];
        char cctype[20];
        char firstname[20];
        char lastname[20];
        int expirymonth;
        int expiryyear;
        char creditcardno[16];

    }x[100];
    FILE *pointer;
    pointer=fopen("pay.txt","r");
    int iloopprint;

    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    printf("CreditCardCompany\tCreditCardType\t\tFirstName\tLastName\tExpiryMonth/ExpiryYear\t\tCreditCardNo\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
       int count= fscanf(pointer," %d %s %s %s %s %d %d %s", &x[iloopprint].sno,&x[iloopprint].cccompany,&x[iloopprint].cctype,&x[iloopprint].firstname,&x[iloopprint].lastname,&x[iloopprint].expirymonth,&x[iloopprint].expiryyear,&x[iloopprint].creditcardno);
if(count!=-1)
        printf("%-23s %-23s %-15s %-24s %2d/%-19d %s\n",x[iloopprint].cccompany,x[iloopprint].cctype,x[iloopprint].firstname,x[iloopprint].lastname,x[iloopprint].expirymonth,x[iloopprint].expiryyear,x[iloopprint].creditcardno);
    }
    fclose(pointer);
    getch();
}



