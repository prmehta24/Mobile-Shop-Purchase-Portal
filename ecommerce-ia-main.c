#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
int totalitems;
struct order
{
    int orderno;
    int productsrnum;
    int productqty;
    char prodnm[40];
    int custsno;
    char custnm[40];
    int amt;
    char paytype[20];
    }y[100];
void addprod()
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
    pointer=fopen("data.txt","a+");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("\nERROR:file data.txt can not be opened");
        exit(0);
    }
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count==-1)
        break;
    }
    printf("======================================================================\n");
    for(;iloopprint<100;iloopprint++)
    {

    printf("\nEnter product details for # %d\n",(iloopprint+1));
    x[iloopprint].sno=(iloopprint);
    printf("Enter the phone company: ");
    fflush(stdin);
    gets(x[iloopprint].company);
    printf("Enter phone model(one word only): ");
    fflush(stdin);
    gets(x[iloopprint].model);
    stock:
    printf("Enter the number in stock: ");
    fflush(stdin);
    scanf("%d" ,&x[iloopprint].stock);
    fflush(stdin);
    if (x[iloopprint].stock < 0)
    {
        printf("\nERROR: Stock must be >= 0.\n");
        goto stock;
    }
    printf("Enter the MRP of the phone: ");
    scanf("%d" ,&x[iloopprint].price);

fflush(stdin);
        fprintf(pointer," %d %s %s %d %d ", x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
int exitchoice=0;
        printf("Do you want to enter another item? (1=No,0=Yes) : ");
        scanf("%d",&exitchoice);
        fflush(stdin);
        if(exitchoice==1)
            break;
    }
    fclose(pointer);
    printf("\nNew products added successfully.\n");
    printf("======================================================================\n");
    //getch();
}





void editprod()
{
     int lines=0;
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
        printf("\nERROR:file data.txt can not be opened");
        exit(0);
    }

    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int loopin=0;
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {
            lines++;

printf("======================================================================\n");
        printf("SNo\tCompany\tModel\tStock\tPrice\n");
printf("======================================================================\n\n");
        printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        printf("Press 1 to edit, 0 to skip to next product,\n");
printf("======================================================================\n");
        int editchoice=0;
        scanf("%d",&editchoice);
        if(editchoice==1)
        {
            printf("Enter new stock total: ");
            scanf("%d",&x[iloopprint].stock);
            printf("Enter new price: ");
            scanf("%d",&x[iloopprint].price);
        }

        }
        else
        break;


    }
    fclose(pointer);

    pointer=fopen("data.txt","w");
    iloopprint=0;

    if(pointer==NULL)
    {
        printf("\nERROR:file data.txt can not be opened");
        exit(0);
    }

    for(iloopprint=0;iloopprint<lines;iloopprint++)
    {


          fprintf(pointer," %d %s %s %d %d ", x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        //printf("SNo\tCompany\tModel\tStock\tPrice\n");
        //printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);





    }
    fclose(pointer);
    printf("Product updated successfully.\n");
printf("======================================================================\n");
    }
void readorders()
{

                     FILE *pointer;
    pointer=fopen("order.txt","r");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("\nERROR:file order.txt can not be opened");
        exit(0);
    }


    struct order2{
    int orderno;
    int limit2;
    int productsrnum;
    int productqty;
    char prodnm[40];
    int custsno;
    char custnm[40];
    int amt;
    char paytype[20];
    }y2[1];
     int count= fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
     if(count!=-1)
     {

printf("======================================================================\n");
     printf("Order No\tItems Ordered\tCustomer Number\tCustomer Name\tAmount Payed\tPayment Type\t\n");
     printf("======================================================================\n\n");
     printf("%-16d%-16d%-16d%-16s%-16d%-16s\n", y2[0].orderno,y2[0].limit2,y2[0].custsno,y2[0].custnm,y2[0].amt,y2[0].paytype);
     //printf("\n======================================================================\n");
     }
     //printf("while start");
    while(count!=-1)
    {
        int i=0;
        char nm[40];
        int qnty;
        int serial;

        if(count!=-1)
         {


             printf("Items:\n");
         }
        for(i=0;i<y2[0].limit2;i++)
        {
           count=fscanf(pointer," %d %s %d",&serial,&nm,&qnty );



if(count!=-1)

           {
        printf("Product Serial Number: %d\n",serial );
           printf("Product Name: %s\n",nm);
           printf("Product Quantity Bought: %d\n",qnty);
           }
           //printf("for loop %d\n", i);
           //printf("count=%d\n",count);
           if(count==-1)
            break;
        }


        //printf("Out of inner loop - count=%d\n",count);
        if(count!=-1)
        {
            count=fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
            if(count!=-1)
            {


            if(count!=-1)
            {

printf("======================================================================\n");
            printf("Order No\tItems Ordered\tCustomer Number\tCustomer Name\tAmount Payed\tPayment Type\t\n");
     printf("======================================================================\n\n");
     printf("%-16d%-16d%-16d%-16s%-16d%-16s\n", y2[0].orderno,y2[0].limit2,y2[0].custsno,y2[0].custnm,y2[0].amt,y2[0].paytype);
     //printf("\n======================================================================\n");
            }
            }
        }

    }

   // printf("Out of reading\n");*
}
void readpay()
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
        printf("\nERROR:file pay.txt can not be opened");
        exit(0);
    }
    printf("======================================================================\n");
    printf("CreditCardCompany\tCreditCardType\t\tFirstName\tLastName\tExpiryMonth/ExpiryYear\t\tCreditCardNo\n");
    printf("======================================================================\n\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
       int count= fscanf(pointer," %d %s %s %s %s %d %d %s", &x[iloopprint].sno,&x[iloopprint].cccompany,&x[iloopprint].cctype,&x[iloopprint].firstname,&x[iloopprint].lastname,&x[iloopprint].expirymonth,&x[iloopprint].expiryyear,&x[iloopprint].creditcardno);
if(count!=-1)
        printf("%-23s %-23s %-15s %-24s %2d/%-19d %s\n",x[iloopprint].cccompany,x[iloopprint].cctype,x[iloopprint].firstname,x[iloopprint].lastname,x[iloopprint].expirymonth,x[iloopprint].expiryyear,x[iloopprint].creditcardno);
    }
    fclose(pointer);
printf("\n======================================================================\n");
}

void custread()
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
        printf("\nERROR:file customer.txt can not be opened");
        exit(0);
    }
    printf("======================================================================\n");
    printf("FirstName\tLastName\tEmailId\t\t\tPhoneNumber\n");
    printf("======================================================================\n\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {



            int count=fscanf(pointer,"%d %s %s %s %s", &x[iloopprint].sno,&x[iloopprint].firstname,&x[iloopprint].sirname,&x[iloopprint].email,&x[iloopprint].phoneno);
             if(count!=-1)
        printf("%-16s%-16s%-24s%s\n", x[iloopprint].firstname,x[iloopprint].sirname,x[iloopprint].email,x[iloopprint].phoneno);

    }
    fclose(pointer);
    printf("\n======================================================================\n");
    //getch();
}




void changeorder(int limit)
{
    int lines=0;
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
        printf("\nERROR:file data.txt can not be opened");
        exit(0);
    }

    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int loopin=0;
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {
            lines++;
          for(loopin=0;loopin<limit;loopin++)
          {
              if(x[iloopprint].sno==y[loopin].productsrnum)
              {
                  x[iloopprint].stock-=y[loopin].productqty;
              }
          }
        //printf("SNo\tCompany\tModel\tStock\tPrice\n");
        //printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);


        }
        else
            break;


    }
    fclose(pointer);

    pointer=fopen("data.txt","w");
    iloopprint=0;

    if(pointer==NULL)
    {
        printf("file cant be opened");
        exit(0);
    }

    for(iloopprint=0;iloopprint<lines;iloopprint++)
    {


          fprintf(pointer," %d %s %s %d %d ", x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        //printf("SNo\tCompany\tModel\tStock\tPrice\n");
        //printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);





    }
    fclose(pointer);



}
int checkemail(char email[40])
{
    int length=strlen(email);
    //char (*ptr2)[length];
    //ptr2=&email;
    //printf("String: %s\n",email);
    int lp;
    int chkat=0;
    int chkcom=0;



        if((strstr(email,"@"))!=NULL)
        {

            chkat=1;

        }
    if((strstr(email,".com"))!=NULL)
        chkcom=1;
        //printf("chkcom=%d\n",chkcom);
        //printf("chkat=%d\n",chkat);
    if(chkcom==1&&chkat==1)
        return 1;
    else
        return 0;

}
void countitems()
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
        printf("\nERROR:file data.txt can not be opened");
        exit(0);
        totalitems=0;
    }

    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer," %d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {

        totalitems++;

    }
    }
    fclose(pointer);

}
void searchorder()
                 {
                     int ordersearchchoice;
                     char custfsnm[20];
                     char custlsnm[20];
                     char custflnm[50];
                     int ordernum;
                     searchmenu:
                         printf("======================================================================\n");
                     printf("Search Menu\n");
                     printf("======================================================================\n");
                     printf("1-By Order Number\n");
                     printf("2-By Name\n");
                     printf("======================================================================\n");
                     printf("Enter your choice : ");
                     scanf("%d",&ordersearchchoice);

                     switch(ordersearchchoice)
                     {
                     case 1:
                        {
                            fflush(stdin);
                            printf("Enter your order number: ");
                            scanf("%d",&ordernum);

                            printf("\nOrder Number: %d \n",ordernum);
                            break;
                        }
                     case 2:
                         {
                             printf("Enter your first name: ");
                             scanf(" %s",&custfsnm);

                             printf("Enter your last name: ");
                             scanf(" %s",&custlsnm);

                             snprintf(custflnm, sizeof(custflnm), "%s%s%s", custfsnm, "-",custlsnm);
                             printf("Full Name: %s\n",custflnm);
                             break;
                         }
                        default:
                            {
                                printf("\nERROR:Invalid Input. Please try again.\n");
                                goto searchmenu;
                            }
                     }
                     FILE *pointer;
    pointer=fopen("order.txt","r");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("\nERROR: file order.txt can not be opened");
        exit(0);
    }


    struct order2{
    int orderno;
    int limit2;
    int productsrnum;
    int productqty;
    char prodnm[40];
    int custsno;
    char custnm[40];
    int amt;
    char paytype[20];
    }y2[1];
     int count= fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
     if(((ordersearchchoice==1)&&(ordernum==y2[0].orderno))||((ordersearchchoice==2)&&(strcmpi(y2[0].custnm,custflnm)==0)))
     {
printf("======================================================================\n");

     printf("Order No\tItems Ordered\tCustomer Number\tCustomer Name\tAmount Payed\tPayment Type\t\n");

printf("======================================================================\n\n");
     printf("%-16d%-16d%-16d%-16s%-16d%-16s\n", y2[0].orderno,y2[0].limit2,y2[0].custsno,y2[0].custnm,y2[0].amt,y2[0].paytype);
printf("\n======================================================================\n");

     }
     //printf("while start");
    while(count!=-1)
    {
        int i=0;
        char nm[40];
        int qnty;
        int serial;

        if(((ordersearchchoice==1)&&(ordernum==y2[0].orderno))||((ordersearchchoice==2)&&(strcmpi(y2[0].custnm,custflnm)==0)))
         {

//printf("======================================================================\n");
             printf("Items:\n");
//printf("======================================================================\n");
         }
        for(i=0;i<y2[0].limit2;i++)
        {
           count=fscanf(pointer," %d %s %d",&serial,&nm,&qnty );



if(((ordersearchchoice==1)&&(ordernum==y2[0].orderno))||((ordersearchchoice==2)&&(strcmpi(y2[0].custnm,custflnm)==0)))

           {
printf("======================================================================\n");
           printf("Product Serial Number: %d\n",serial );
           printf("Product Name: %s\n",nm);
           printf("Product Quantity Bought: %d\n",qnty);
           }
           //printf("for loop %d\n", i);
           //printf("count=%d\n",count);
           if(count==-1)
            break;
        }


        //printf("Out of inner loop - count=%d\n",count);
        if(count!=-1)
        {
            count=fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
            if(((ordersearchchoice==1)&&(ordernum==y2[0].orderno))||((ordersearchchoice==2)&&(strcmpi(y2[0].custnm,custflnm)==0)))
            {


            if(count!=-1)
            {
printf("======================================================================\n");

            printf("Order No\tItems Ordered\tCustomer Number\tCustomer Name\tAmount Payed\tPayment Type\t\n");
     printf("======================================================================\n\n");
     printf("%-16d%-16d%-16d%-16s%-16d%-16s\n", y2[0].orderno,y2[0].limit2,y2[0].custsno,y2[0].custnm,y2[0].amt,y2[0].paytype);
printf("\n======================================================================\n");
            }
            }
        }

    }

   // printf("Out of reading\n");*

                 }
void printorder(int limit)
{
    srand ( time(NULL) );
    int looper=0;
    y[0].orderno = rand()*10;
    printf("======================================================================\n");
    printf("Order summary\n");
    printf("======================================================================\n");
    printf("Order Number     : %d\n",y[0].orderno);
    printf("Customer Name    : %s\n",y[0].custnm);
    printf("Customer Number  : %d\n",y[0].custsno);
    printf("Amount Payable   : %d\n",y[0].amt);
    printf("Credit Card Type : %s\n",y[0].paytype);
    printf("Product Details:\n");
    printf("========================\n");
    for(looper=0;looper<limit;looper++)
    {
        printf("Product Name     : %s\n",y[looper].prodnm);
        printf("Product Number   : %d\n",y[looper].productsrnum);
        printf("Product Quantity : %d\n",y[looper].productqty);
        printf("========================\n");
    }

FILE *pointer;
    pointer=fopen("order.txt","a+");
    int iloopprint;
    if(pointer==NULL)
    {
        printf("\nERROR:file order.txt can not be opened");
        exit(0);
    }

    /*
    struct order2{
    int orderno;
    int limit2;
    int productsrnum;
    int productqty;
    char prodnm[40];
    int custsno;
    char custnm[40];
    int amt;
    char paytype[20];
    }y2[1];
     int count= fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
printf(" %d %d %d %s %d %s\n", y2[0].orderno,y2[0].limit2,y2[0].custsno,y2[0].custnm,y2[0].amt,y2[0].paytype);
     printf("while start");
    while(count!=-1)
    {
        int i=0;
        char nm[40];
        int qnty;
        int serial;
        for(i=0;i<y2[0].limit2;i++)
        {
           count=fscanf(pointer," %d %s %d",&serial,&nm,&qnty );
           printf(" %d %s %d\n",serial,nm,qnty );
           printf("for loop %d\n", i);
           printf("count=%d\n",count);
           if(count==-1)
            break;
        }

        printf("Out of inner loop - count=%d\n",count);
        if(count!=-1)
        {
            count=fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
            fscanf(pointer," %d %d %d %s %d %s", &y2[0].orderno,&y2[0].limit2,&y2[0].custsno,&y2[0].custnm,&y2[0].amt,&y2[0].paytype);
        }

    }

    printf("Out of reading\n");*/
    int i;
    fprintf(pointer," %d %d %d %s %d %s", y[0].orderno,limit,y[0].custsno,y[0].custnm,y[0].amt,y[0].paytype);
     //printf("Finished writing part 1\n");
     for(i=0;i<limit;i++)
        {
           fprintf(pointer," %d %s %d",y[i].productsrnum,y[i].prodnm,y[i].productqty);
        }

  //printf("Complete\n");
    fclose(pointer);

printf("Thank you for your order.\n");
printf("======================================================================\n");

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
        printf("\nERROR:file pay.txt can not be opened\n");
        exit(0);
    }
    printf("======================================================================\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
         int count= fscanf(pointer," %d %s %s %s %s %d %d %s", &x[iloopprint].sno,&x[iloopprint].cccompany,&x[iloopprint].cctype,&x[iloopprint].firstname,&x[iloopprint].lastname,&x[iloopprint].expirymonth,&x[iloopprint].expiryyear,&x[iloopprint].creditcardno);
if(count==-1)
    break;
    }
    printf("Enter card details\n");
    printf("======================================================================\n");
    x[iloopprint].sno=(iloopprint+1);
    cardtype:
    printf("Enter the card company(visa/mastercard)\n");
    gets(x[iloopprint].cccompany);
    if((strcmpi(x[iloopprint].cccompany,"visa")==0)||(strcmpi(x[iloopprint].cccompany,"mastercard")==0))
    {


    }
    else
    {
        printf("\nERROR:Invalid Input.Valid inputs are visa or mastercard.Please try again.\n");
        goto cardtype;
    }


    card:
    printf("Enter the card type(credit/debit)\n");
    scanf("%s",&x[iloopprint].cctype);
    if((strcmpi(x[iloopprint].cctype,"credit")==0)||(strcmpi(x[iloopprint].cctype,"debit")==0))
    {


    }
    else
    {
        printf("\nERROR:Invalid Input.Valid inputs are credit or debit.Please try again.\n");
        goto card;
    }



    strcpy(y[0].paytype,x[iloopprint].cctype);
    fflush(stdin);
    printf("\nEnter the first name on the card: ");
    gets(x[iloopprint].firstname);
    fflush(stdin);
    printf("\nEnter the last name on the card: ");
    gets(x[iloopprint].lastname);
    date:
    month:
    printf("Enter the expiry month on the card(in digits): ");
    scanf(" %d" ,&x[iloopprint].expirymonth);
    if(x[iloopprint].expirymonth<1||x[iloopprint].expirymonth>12)
    {
        printf("\nERROR:Invalid Input.Valid months are 1 to 12.Please try again.\n");
        goto month;
    }


    fflush(stdin);
    year:
    printf("Enter the expiry year on the card(in 4 digit format)\n");
    scanf(" %d" ,&x[iloopprint].expiryyear);
    if(x[iloopprint].expiryyear<2017||x[iloopprint].expiryyear>2050)
    {
        printf("\nERROR:Invalid Input(Card May have Expired).Please try again.\n");
        goto year;
    }
    if((x[iloopprint].expiryyear==2017)&&(x[iloopprint].expirymonth<4))
    {
        printf("\nERROR:This card has expired. Please try again.\n");
        goto date;
    }

    ccnum:
    fflush(stdin);

    printf("Enter the credit card number\n");
  gets(x[iloopprint].creditcardno);
  int cclen=strlen(x[iloopprint].creditcardno);
  if(cclen!=16)
  {
      printf("\nERROR:Invalid Number. Credit card must be 16 digit number. Please reenter.\n");
      goto ccnum;
  }

    fprintf(pointer," %d %s %s %s %s %d %d %s",x[iloopprint].sno,x[iloopprint].cccompany,x[iloopprint].cctype,x[iloopprint].firstname,x[iloopprint].lastname,x[iloopprint].expirymonth,x[iloopprint].expiryyear,x[iloopprint].creditcardno);


printf("======================================================================\n");
    fclose(pointer);

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
    pointer=fopen("data.txt","r+");
    int iloopprint;

    if(pointer==NULL)
    {
        printf("\nERROR:file cant be opened\n");
        exit(0);
    }
    printf("======================================================================\n");
    printf("SNo\tCompany\tModel\tStock\tPrice\n");
    printf("======================================================================\n");
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
            snprintf(y[countitemsdone].prodnm, sizeof(y[countitemsdone].prodnm), "%s%s%s", x[iloopprint].company, "-", x[iloopprint].model);
            inputquantity:
            printf("Enter the quantity you want for product # %d: ",x[iloopprint].sno);
            scanf(" %d",&tempstock);

            if(tempstock<=x[iloopprint].stock)
            {
            y[0].amt+=tempstock*x[iloopprint].price;
            y[countitemsdone].productqty=tempstock;
            SNostock[countitemsdone++]=tempstock;
            //x[iloopprint].stock-=tempstock;

            }
            else
            {
                printf("\nERROR:Invalid Input. Quantity must be less or equal to stock available.Please try again.\n");

            goto inputquantity;
            }



           }
        }
        //fprintf(pointer," %d %s %s %d %d ", x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        if(countitemsdone==limit)
            break;
    }
    fclose(pointer);

printf("======================================================================\n");
    //add to order structure

         changeorder(limit);
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
        printf("\nERROR:file customer.txt can not be opened");
        exit(0);
    }
     for(iloopprint=0;iloopprint<100;iloopprint++)
    {



            int count=fscanf(pointer,"%d %s %s %s %s", &x[iloopprint].sno,&x[iloopprint].firstname,&x[iloopprint].sirname,&x[iloopprint].email,&x[iloopprint].phoneno);
             if(count==-1)
             break;

    }

    printf("======================================================================\n");
    printf("Enter details of customer # %d\n",(iloopprint+1));
    printf("======================================================================\n");
    x[iloopprint].sno=(iloopprint+1);
    y[0].custsno=x[iloopprint].sno;
    printf("Enter your first name: ");
     fflush(stdin);
    gets(x[iloopprint].firstname);
    printf("Enter your last name: ");
     fflush(stdin);
     gets(x[iloopprint].sirname);
    snprintf(y[0].custnm, sizeof(y[0].custnm), "%s%s%s",x[iloopprint].firstname,"-", x[iloopprint].sirname);
    mail:
    printf("Enter your email: ");
     fflush(stdin);
    gets(x[iloopprint].email);
    int chkmail=checkemail(x[iloopprint].email);
    if(chkmail==0)
    {
        printf("\nERROR:The email given is not in proper format. Please re-enter email.\n");
        goto mail;
    }
    phoneno:
    printf("Enter your phone number(8-12 digits)\n");
     fflush(stdin);
    gets(x[iloopprint].phoneno);
    int phonenol=strlen(x[iloopprint].phoneno);
    if((phonenol<8)||(phonenol>12))
    {
        printf("\nERROR:Invalid Number. Please enter minimum 8 digit or maximum 12 digit number.\n");
        goto phoneno;
    }
    fprintf(pointer," %d %s %s %s %s ", x[iloopprint].sno,x[iloopprint].firstname,x[iloopprint].sirname,x[iloopprint].email,x[iloopprint].phoneno);

printf("======================================================================\n");
    fclose(pointer);

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
        printf("\nERROR:file data.txt can not be opened\n");
        exit(0);
    }
    char searchcompany[20];
    int priceceiling;
    int searchchoice;
    printf("======================================================================\n");
    printf("Search Options:\n");
    printf("======================================================================\n");
    printf("1-Company\n");
    printf("2-Price Limit\n");
    printf("3-Both\n");
    printf("======================================================================\n");
    printf("\nEnter your choice: ");
    scanf(" %d",&searchchoice);

    switch(searchchoice)
    {
    case 3:
        {

        }
    case 1:
        {
            printf("Enter Phone Company: ");
            scanf(" %s",&searchcompany);

            if(searchchoice==1)
            break;
        }
    case 2:
        {
            printf("Enter Price Limit: ");
            scanf(" %d",&priceceiling);

           break;
        }
    default:
        {
         printf("No valid option (1-3) is selected. Display all results.");
        }
    }
    printf("======================================================================\n");
    printf("Search Results:\n");
    printf("======================================================================\n");
    printf("SNo\tCompany\tModel\tStock\tPrice\n");
    printf("======================================================================\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer,"%d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {
            int companycompare=strcmpi(x[iloopprint].company,searchcompany);
        if((companycompare==0&&searchchoice==1)||(searchchoice==2&&(x[iloopprint].price<=priceceiling))||(searchchoice>=4)||(searchchoice==3&&companycompare==0&&(priceceiling<=x[iloopprint].price)))
        printf("%d\t%s\t%s\t%d\t%d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
        }
    }
    fclose(pointer);
    printf("======================================================================\n");
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
        printf("\nERROR:file data.txt can not be opened\n");
        exit(0);
    }
    printf("======================================================================\n");
    printf("%-16s%-16s%-16s%-16s%-16s \n","SNo","Company","Model","Stock","Price");
    printf("======================================================================\n");
    for(iloopprint=0;iloopprint<100;iloopprint++)
    {
        int count=fscanf(pointer," %d %s %s %d %d", &x[iloopprint].sno,&x[iloopprint].company,&x[iloopprint].model,&x[iloopprint].stock,&x[iloopprint].price);
        if(count!=-1)
        {


        printf("%-16d%-16s%-16s%-16d%-16d \n",x[iloopprint].sno,x[iloopprint].company,x[iloopprint].model,x[iloopprint].stock,x[iloopprint].price);
    }
    }
    printf("======================================================================\n");
    fclose(pointer);

}
void main()
{
start:

printf("%-10s%-30s%10s\n","***","Welcome to Hotspot - The Mobile Hub","***");
printf("======================================================================\n");
int checkadmin=0;
int admin=0;
char username[]={"admin"};
char password[]={"admin"};

printf("\n\n");
printf("Admin can add, edit and view details of customer, product, order etc. \n");
printf("Customer can view and purchase products. \n");
printf("\n\n");
printf("Admin - Press 1, Customer - Press 2, Exit Program - Press 3 \n");
printf("======================================================================\n");
printf("Your choice: ");
scanf("%d",&admin);

if(admin==1)
{
    char usernameinput[20];
    char passwordinput[20];
    printf("\nYou have entered 1. Please enter login details.\n\n");
    printf("Admin Login\n");
    printf("============\n\n");

admin:

    printf("Enter user name: ");
    scanf(" %s",&usernameinput);
    printf("Enter password: ");
    scanf(" %s",&passwordinput);

    int usercheck=strcmp(username,usernameinput);
    int passwordcheck=strcmp(password,passwordinput);
    if((usercheck==0)&&(passwordcheck==0))
    {
        printf("\n\nYou have successfully logged in as Admin.\n\n");
        checkadmin=1;
    }
    else{
        printf("\n\nERROR: Wrong user name or password. Please enter again.\n\n");
        goto admin;
    }

if(checkadmin==1)
{
    adminmenu:


    printf("Admin Menu\n");
    printf("======================================================================\n\n");
    int adminchoice;
    printf("1-View Product Details\n");
    printf("2-View Customer Details\n");
    printf("3-View Payment Details\n");
    printf("4-View Order Details\n");
    printf("5-Edit Product Details\n");
    printf("6-Add Product Details\n");
    printf("7-Logout\n");


    printf("======================================================================\n\n");
    printf("Enter your choice:");
    scanf("%d",&adminchoice);
    printf("======================================================================\n\n");
    switch(adminchoice)
    {
    case 1:
        {
        printf("Product Details\n");
        printf("======================================================================\n\n");
        printlist();
        break;
        }
        case 2:
        {
        printf("Customer Details\n");
        printf("======================================================================\n\n");
        custread();

        break;
        }
        case 3:
        {
        printf("Payment Details\n");
        printf("======================================================================\n\n");
         readpay();

        break;
        }
        case 4:
        {
        printf("Order Details\n");
        printf("======================================================================\n\n");
        readorders();

        break;
        }
        case 5:
        {
        printf("Edit Product Details\n");
        printf("======================================================================\n\n");
         editprod();

        break;
        }
        case 7:
        {

        goto start;

        break;
        }
/*        case 8:
        {

        goto end;
        break;
        }*/
        case 6:
            {
                printf("Add Product Details\n");
                printf("======================================================================\n\n");
             addprod();
             break;
            }
        default:
        {
        printf("Invalid Input (Valid values 1-8). Please try again.\n");
        printf("======================================================================\n\n");
        goto adminmenu;

        break;
        }

    }
    goto adminmenu;
}
}
if (admin==2)
{


int menuuserchoice;

printf("======================================================================\n\n");
printf("You have selected Customer mode, Welcome to my shop.\n");
printf("======================================================================\n\n");
basicmenu:
printf("Basic Menu:\n");
printf("======================================================================\n\n");
printf("1-View all products\n");
printf("2-Search for a product\n");
printf("3-Search for a previous order\n");
printf("4-Log out\n");
printf("======================================================================\n\n");
printf("Enter your choice:");
scanf(" %d",&menuuserchoice);

switch(menuuserchoice)
{
   case 1:
       {
           printf("\nProduct Details:\n");
           printf("======================================================================\n\n");
        printlist();
        break;
       }
   case 2:
    {
           printf("Search Product:\n");
           printf("======================================================================\n\n");
       search();
        break;
    }
   case 4:
    {
        goto start;
        break;
    }
   /*case 4:
    {
        goto end;
        break;
    }*/
   case 3:
    {
        printf("Search Order:\n");
        printf("======================================================================\n\n");
        searchorder();
        break;
    }
   default:
    {
     printf("\n\nERROR: No such option available. Please choose valid option (1-4).\n");
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

printf("======================================================================\n\n");
printf("Menu:\n");
printf("======================================================================\n\n");
printf("1-Purchase items\n");
printf("2-Return to Basic Menu\n");
printf("3-Log out\n");
printf("======================================================================\n\n");
printf("\n\nEnter your choice: ");
scanf(" %d",&purchaseitemchoice);
countitems();
switch(purchaseitemchoice)
{
    case 1:
    {


       for(loop=0;loop<100;loop++)
       {
           SNo:
            fflush(stdin);
            printf("Enter the SNo of an item you want to buy: ");
            fflush(stdin);
            scanf(" %d",&itemSNo[loop]);

            //printf("Total Items: %d\n",totalitems);
            if(itemSNo[loop]>(totalitems-1))
            {
                printf("\nERROR:The SNo you have entered does not exist. Please try again.\n");
                goto SNo;
            }


            y[loop].productsrnum=itemSNo[loop];
            fflush(stdin);
            countitems2purchase++;
            printf("\nDo you want to purchase another item? (1=No,0=Yes): \n");
            scanf(" %d",&exitloopSNo);

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
    /*case 4:
            {
            goto end;
            break;
            }*/
    default:
            {
               printf("\n\nERROR:Invalid Option. Please choose valid options (1-4).");
               goto menu2purchase;
            }
}
}
if (admin==3)
{


end:
    printf("Thanks for visiting my shop. Come again...\n");
}
}
