#include<stdio.h>
#include<dos.h>
#include<conio.h>
add();
search();
sell();
struct product
{
    char ID[20];
    char name[20];
    int uprice;
    int quantity;
}pt;
main()
{
    system("cls");
    system("color E");
   int option;
   printf("[1].  --->  Add new Product\n");
   printf("[2].  --->  Search Product\n");
   printf("[3].  --->  Selling Products\n");
   printf("[4].  --->  EXIT\n");
   printf("\n\n");
   printf("Enter Your Option: ");
   scanf("%d",&option);
   printf("\n\n");
   system("pause");
   system("cls");
   printf("\n\n");
   switch(option)
   {
   case 1:
       printf("\t\t\t\t***************************************\n");
       printf("\t\t\t\t  -----Welcome To Adding Option-----\n");
       printf("\t\t\t\t***************************************\n\n");
       add();
       break;
   case 2:
       printf("\t\t\t\t*****************************************\n");
       printf("\t\t\t\t  -----Welcome To Searching Option-----\n");
       printf("\t\t\t\t*****************************************\n\n");
       search();
       break;
   case 3:
       printf("\t\t\t\t***************************************\n");
       printf("\t\t\t\t  -----Welcome To Selling Option-----\n");
       printf("\t\t\t\t***************************************\n\n");
       sell();
       break;
   case 4:
       return 0;
       break;
   default:
    printf("Please Enter Right Option\n");
    system("pause");
    main();
   }
   return 0;
}


add()
{
    system("color B");
 FILE *fp1;
 fp1=fopen("products.txt","a");
 printf("Enter ID: ");
 scanf("%s",&pt.ID);
 printf("Enter Name: ");
 scanf("%s",&pt.name);
 printf("Enter Unit price: ");
 scanf("%d",&pt.uprice);
 printf("Enter Quantity: ");
 scanf("%d",&pt.quantity);
 fwrite(&pt,sizeof(pt),1,fp1);
 fclose(fp1);
 printf("\n\n");
 system("pause");
 main();
}


sell()
{
    system("color A");
    FILE *fp2;
    char i='Y',name[20];
    int cash,back;
    int total=0,sum,q,d,dtotal,v,vtotal,cb,B;
    while(i=='Y')
    {
    fp2=fopen("products.txt","rb+");
    printf("Enter product Name: ");
    scanf("%s",&name);
    printf("Enter Quantity: ");
    scanf("%d",&q);
    while(fread(&pt,sizeof(pt),1,fp2))
    {
        if(strcmp(name,pt.name)==0)
        {
            sum=pt.uprice*q;
            printf("\t\t\t\t\t  || %s %s %d*%d=%d\n",pt.ID,pt.name,pt.uprice,q,sum);
            total=total+sum;
            pt.quantity=pt.quantity-q;
            fseek(fp2,-sizeof(pt),SEEK_CUR);
		    fwrite(&pt,sizeof(pt),1,fp2);

		fseek(fp2,-sizeof(pt),SEEK_CUR);
		fread(&pt,sizeof(pt),1,fp2);

        }
    }
    fclose(fp2);
   printf("'Y' for continue & 'N' for stop: \t  ||\n");
   scanf("%s",&i);
    }
    printf("-------------------------------------------------\n");
    printf("\t\t\t\tTotal\t  || =%d\n",total);
    printf("Available Discount Percentage:\t\t  || -");
    scanf("%d",&d);
    dtotal=total-(total*d/100);
    printf("Discounted Bill:\t\t\t  || =%d\n",dtotal);
    printf("Available Vat percentage:\t\t  || +");
    scanf("%d",&v);
    vtotal=dtotal+(total*v/100);
    printf("Bill after charging %d percent vat:\t  || =%d\n",v,vtotal);
    printf("Cash Back Bonus:\t\t\t  || -");
    scanf("%d",&cb);
    B=vtotal-cb;
    printf("Bill to be paid:\t\t\t  || =%d\n",B);
    printf("-------------------------------------------------\n");
    printf("Cash taken from Customer:\t\t  ||  ");
    scanf("%d",&cash);
    back=cash-B;
    printf("Return Amount:\t\t\t\t  || %d-%d= %d",cash,B,back);
    printf("\n\n");
    system("pause");
    main();
}

search()
{
    system("color D");
    FILE *fp3;
    char id[20];
    fp3=fopen("products.txt","r");
    printf("Enter ID: ");
    scanf("%s",&id);
    printf("ID:\tNAME:\tUNITPRICE:\tAVAILLABLE:\n");
    while(fread(&pt,sizeof(pt),1,fp3))
    {
        if(strcmp(id,pt.ID)==0)
            printf("%s \t%s\t %d\t\t [%d] ",pt.ID,pt.name,pt.uprice,pt.quantity);
    }
    fflush(stdin);
    fclose(fp3);
    printf("\n\n");
    system("pause");
    main();
}


