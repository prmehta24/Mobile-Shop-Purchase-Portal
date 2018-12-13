#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct order{
    int orderno;
    int productsrnum;
    int productqty;
    char prodnm[40];
    int custsno;
    char custnm[40];
    int amt;
    char paytype[20];
    }y[100];

void printorder(int limit)
{
    int looper=0;
    y[0].orderno = rand()*1000;
    printf("Order Number - %d\n",y[0].orderno);
    printf("Customer Name - %s\n",y[0].custnm);
    printf("Customer Number - %d\n",y[0].custsno);
    printf("Amount Payable - %d\n",y[0].amt);
    printf("Credit Card Type - %s\n",y[0].paytype);
    for(looper=0;looper<limit;looper++)
    {
        printf("Product Name - %s\n",y[looper].prodnm);
        printf("Product Number - %d\n",y[looper].productsrnum);
        printf("Product Quantity - %d\n",y[looper].productqty);

    }




}
void pay()
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
    pointer=fopen("pay.txt","a+");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
         int count= fscanf(pointer," %d %s %s %s %s %d %d %s", &x[iloopprint].sno,&x[iloopprint].cccompany,&x[iloopprint].cctype,&x[iloopprint].firstname,&x[iloopprint].lastname,&x[iloopprint].expirymonth,&x[iloopprint].expiryyear,&x[iloopprint].creditcardno);
if(count==-1)
    break;
    }
    printf(" Enter card details %d \n",(iloopprint));
    x[iloopprint].sno=(iloopprint+1);

    printf("Enter the credit card company(one word only)\n");
    gets(x[iloopprint].cccompany);
    printf("Enter the credit card type(credit/debit)\n");
    gets(x[iloopprint].cctype);
    strcpy(y[0].paytype,x[iloopprint].cctype);
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



    fclose(pointer);
    getch();
}

int* choosestock(int SNoarr[],int limit,int SNostock[])
{

    int check=0;
    int loop1=0;
    int countitemsdone=0;
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
    printf("SNo\tCompany\tModel\tStock\tPrice\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {
            check=0;
           for(loop1=0;loop1<limit;loop1++)
           {
               //printf("s=%d x=%d",SNoarr[loop1],x[iloopprint].sno);
               if(SNoarr[loop1]==x[iloopprint].sno)
               {
                check=1;
                break;
               }
           }
           if(check==1)
           {
               int tempstock=0;
            printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
            snprintf(y[countitemsdone].prodnm, sizeof(y[countitemsdone].prodnm), "%s %s %s", x[iloopprint].company, "-", x[iloopprint].model);
            inputquantity:
            printf("Enter the quantity you want for product %d\n",x[iloopprint].sno);
            scanf("%d",&tempstock);
            if(tempstock<=x[iloopprint].stock)
            {
            y[0].amt+=tempstock*x[iloopprint].price;
            y[countitemsdone].productqty=tempstock;
            SNostock[countitemsdone++]=tempstock;
            }
            else
            {
                printf("Invalid Input. Please try again.\n");

            goto inputquantity;
            }



           }
        }
        if(countitemsdone==limit)
            break;
    }
    fclose(pointer);
    getch();

    //add to order structure


    return SNostock;
}

void cust()
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
    pointer=fopen("customer.txt","a+");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }
     for(iloopprint=0;iloopprint<100;iloopprint++)
    {



            int count=fscanf(pointer,"%d %s %s %s %s", &x[iloopprint].sno,&x[iloopprint].firstname,&x[iloopprint].sirname,&x[iloopprint].email,&x[iloopprint].phoneno);
             if(count==-1)
             break;

    }


    printf("Enter details of customer %d\n",(iloopprint+1));
    x[iloopprint].sno=(iloopprint+1);
    y[0].custsno=x[iloopprint].sno;
    printf("Enter your first name\n");
     fflush(stdin);
    gets(x[iloopprint].firstname);
    printf("Enter your last name\n");
     fflush(stdin);
     snprintf(y[0].custnm, sizeof(y[0].custnm), "%s %s %s", x[iloopprint].firstname, " ", x[iloopprint].sirname);
    gets(x[iloopprint].sirname);
    printf("Enter your email\n");
     fflush(stdin);
    gets(x[iloopprint].email);
    printf("Enter your phone number\n");
     fflush(stdin);
    gets(x[iloopprint].phoneno);
    fprintf(pointer," %d %s %s %s %s ", x[iloopprint].sno,x[iloopprint].firstname,x[iloopprint].sirname,x[iloopprint].email,x[iloopprint].phoneno);


    fclose(pointer);
    getch();
}

void search()
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
    char searchcompany[20];
    int priceceiling;
    int searchchoice;
    printf("Search Options:-\n");
    printf("1-Company\n");
    printf("2-Price Limit\n");
    printf("3-Both\n");
    printf("Enter your choice\n");
    scanf("%d",&searchchoice);
    switch(searchchoice)
    {
    case 3:
        {

        }
    case 1:
        {
            printf("Enter phone company \n");
            scanf("%s",&searchcompany);
            if(searchchoice==1)
            break;
        }
    case 2:
        {
            printf("Enter Price Limit\n");
            scanf("%d",&priceceiling);
           break;
        }
    default:
        {
         printf("List will be printed as is.");
        }
    }
    printf("Company\tModel\tStock\tPrice\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {
            int companycompare=strcmpi(x[iloopprint].company,searchcompany);
        if((companycompare==0&&searchchoice==1)||(searchchoice==2&&(x[iloopprint].price<=priceceiling))||(searchchoice>=4)||(searchchoice==3&&companycompare==0&&(priceceiling<=x[iloopprint].price)))
        printf("%s\t%s\t%d\t%d \n", x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        }
    }
    fclose(pointer);
    getch();
}

void printlist()
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
    printf("SNo\tCompany\tModel\tStock\tPrice\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
    }
    fclose(pointer);
    getch();
}
void main()
{
  start:
printf("Welcome to Hotspot - The Mobile Hub \n");

/*int admin=0;
char username[]={"admin"};
char password[]={"admin"};

printf("Press 1 if you want to log in(to edit inventory)\n");
scanf("%d",&admin);
if(admin==1)
{
    char usernameinput[20];
    char passwordinput[20];
    printf("Enter username\n");
    scanf("%s",&usernameinput);
    printf("Enter password\n");
    scanf("%s",&passwordinput);
    int usercheck=strcmp(username,usernameinput);
    int passwordcheck=strcmp(password,passwordinput);
    if((usercheck==0)&&(passwordcheck==0))
        printf("Logged in as admin\n");
    else{
        printf("Wrong username or password\n");
    }
}*/
int menuuserchoice;

printf("Welcome Customer\n");
basicmenu:
printf("Basic Menu:-\n");
printf("1-Look at entire product list\n");
printf("2-Search for a product\n");
printf("3-Return to Log In\n");
printf("4-Exit\n");
printf("Enter your choice\n");
scanf("%d",&menuuserchoice);
switch(menuuserchoice)
{
   case 1:
       {
        printlist();
        break;
       }
   case 2:
    {
       search();
        break;
    }
   case 3:
    {
        goto start;
        break;
    }
   case 4:
    {
        goto end;
        break;
    }
   default:
    {
     printf("Error. No such option available. Please choose another.\n");
     goto basicmenu;
    }

}
int exitloopSNo=0;
int loop;
int itemSNo[100];
int countitems2purchase=0;
int purchaseitemchoice;
int* stockarrpointer;
menu2purchase:
printf("Menu2:-\n");
printf("1-Purchase items\n");
printf("2-Return to Basic Menu\n");
printf("3-Return to Log In\n");
printf("4-Exit\n");
printf("Enter your choice\n");
scanf("%d",&purchaseitemchoice);
switch(purchaseitemchoice)
{
    case 1:
    {


       for(loop=0;loop<100;loop++)
       {
            fflush(stdin);
            printf("Enter the SNo of an item you want to buy\n");
            fflush(stdin);
            scanf("%d",&itemSNo[loop]);
            y[loop].productsrnum=itemSNo[loop];
            fflush(stdin);
            countitems2purchase++;
            printf("Press 1 if you are done entering items\n");
            scanf("%d",&exitloopSNo);
            if(exitloopSNo==1)
                break;
       }
       int SNostock[100];

       stockarrpointer=choosestock(itemSNo,countitems2purchase,SNostock);
       cust();
        pay();
        printorder(countitems2purchase);

        break;
           }
    case 2:
        {
            goto basicmenu;
        break;
        }
    case 3:
        {
            goto start;
        break;
        }
    case 4:
            {
                goto end;
            break;
            }
    default:
            {
               printf("Invalid Option. Please choose another.");
               goto menu2purchase;
            }
}

end:
    printf("Goodbye.\n");
}
