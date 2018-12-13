#include<stdio.h>
void main()
{
    struct pay
    {
         int sno;
        char cccompany[20];
        char cctype[20];
        char firstname[20];
        char lastname[20];
        int expirymonth;
        int expiryyear;
        char creditcardno[16];
    }x[100];
    FILE *pointer;
    pointer=fopen("pay.txt","w");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
    printf("\n Enter card details %d \n",(iloopprint+1));
    x[iloopprint].sno=(iloopprint+1);
    printf("Enter the credit card company(one word only)\n");
    gets(x[iloopprint].cccompany);
    printf("Enter the credit card type(credit/debit)\n");
    gets(x[iloopprint].cctype);
    printf("Enter the first name on the card\n");
    gets(x[iloopprint].firstname);
    printf("Enter the last name on the card\n");
    gets(x[iloopprint].lastname);
    printf("Enter the expiry month on the card(in digits)\n");
    scanf("%d" ,&x[iloopprint].expirymonth);
    fflush(stdin);
    printf("Enter the expiry year on the card(in 4 digit form)\n");
    scanf("%d" ,&x[iloopprint].expiryyear);
    fflush(stdin);
    printf("Enter the credit card number\n");
  gets(x[iloopprint].creditcardno);

    fprintf(pointer," %d %s %s %s %s %d %d %s",x[iloopprint].sno,x[iloopprint].cccompany,x[iloopprint].cctype,x[iloopprint].firstname,x[iloopprint].lastname,x[iloopprint].expirymonth,x[iloopprint].expiryyear,x[iloopprint].creditcardno);
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



