/**************************************************************************
                          HEADER FILE OF THE PROGRAM
**************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int a=1,n = 20201010;//GLOBAL VARIABLE
/**************************************************************************
                            STRUCTURE DECLARATION
**************************************************************************/

struct birth//STRUCTURE DELARATION
{
	int day;
	int month;
	int year;
};

struct account//STRUCTURE DECLARATION
{
		int acno;
		int age;
        char name[50];
        char fname[50],address[50];
		float balance;
		int phone;
		char ac_type[15];
		
		struct birth dob;
        
}acc[100];
/**************************************************************************
                            TITLE BAR OF THE PROGRAM
**************************************************************************/
void welcome()
{
	system("cls");
	system("color 5");
	printf("\t*****************************************************************\n");
	printf("\t*****************************************************************\n");
	printf("\t\t     SIMPLE BANK MANAGEMENT SYSTEM\n");
	printf("\t\t\t\t\t         BY -:PROGRAMMER_ABHI\n");
	printf("\t*****************************************************************\n");
	printf("\t*****************************************************************\n");
}

/**************************************************************************
                            OPEN AN ACCOUNT
**************************************************************************/

void open_an_account()//TO CREATE A NEW ACCOUNT OF A PERSON
{
	
    printf("\n\tENTER YOUR NAME -: ");//GIVING DETAILS OF THE PERSON
     fflush(stdin);
     gets(acc[a].name);
    
    printf("\n\tENTER FATHER'S NAME -: ");
     fflush(stdin);
     gets(acc[a].fname);
	printf("\n\tENTER YOUR ADDRESS -: ");
     fflush(stdin);
     gets(acc[a].address);
    printf("\n\tENTER PHONE NUMBER -: ");
	 scanf("%d",&acc[a].phone); 
	printf("\n\tENTER YOUR DATE OF BIRTH -: ");
	scanf("%d/%d/%d",&acc[a].dob.day,&acc[a].dob.month,&acc[a].dob.year);
	printf("\n\tENTER YOUR AGE   -: ");
	 scanf("%d",&acc[a].age);
	printf("\n\tENTER SOME MONEY TO OPEN AN ACCOUNT -: ");
     scanf("%f",&acc[a].balance);
    
	 welcome();
	 printf("\n\t*********NEW ACCOUNT DETAILS*********\n");
	 printf("\n\tNAME OF THE PERSON	-: %s",acc[a].name);
	 printf("\n\tFATHERS'S NAME		-: %s",acc[a].fname);
	 printf("\n\tPERMENANT ADDRESS	-: %s",acc[a].address);
	 printf("\n\tDATE OF BIRTH		-: %d/%d/%d",acc[a].dob.day,acc[a].dob.month,acc[a].dob.year);
	 printf("\n\tAGE                     -: %d",acc[a].age);
	 printf("\n\tACCOUNT NUMBER 		-: %d",n+1);
	 printf("\n\tBANK BALANCE	        -: %.3f",acc[a].balance);
	 acc[a].acno=n+1;
             a++;n++;

 }

/**************************************************************************
                    	DEPOSIT TO  AN ACCOUNT
**************************************************************************/



void deposit()//TO DEPOSIT MONEY TO AN ACCOUNT
{
  	int count,check,b=0;
  	
   	float addmoney;
    welcome();
	printf("\n\tPLEASE ENTER YOUR ACCOUNT NUMBER TO DEPOSIT -:");
    scanf("%d",&check);
    
	for(count=0;count<n;count++)
    {
       if(acc[count].acno==check)
       {
	   		b= count;break;
	   }
	   else
	   		continue;
     }
    if(acc[b].acno==check)
    {
		welcome();
        printf("\n\t NAME OF THE PERSON  -: %s",acc[b].name);
        printf("\n\t FATHER'S NAME       -: %s",acc[b].fname);
		printf("\n\t CURRENT BALANCE     -: %.3f",acc[b].balance);
		printf("\n\t AGE                 -: %d",acc[b].age);
        printf("\n\n\t ENTER THE AMOUNT TO DEPOSIT -: ");
        scanf("%f",&addmoney);
        acc[b].balance+=addmoney;
        welcome();
		printf("\n\tBANK BALANCE AFTER DEPOSITING BECOMES -: %.3f",acc[b].balance);
    }
    else
	{
    	 printf("\n\t!!!NO SUCH ACCOUNT IS AVAILABLE!!!\n");
		
 	}
}

/**************************************************************************
                        WITHDRAWL FROM AN ACCOUNT
**************************************************************************/


 void withdraw()//TO WITHDRAW MONEY THE ACCOUNT
{
   int check,count,b=0;
   float submoney;
   welcome();
   printf("\n\t ENTER YOUR ACCOUNT NUMBER TO WITHDRAW -:");
    scanf("%d",&check);
    
	for(count=0;count<n;count++)
    {
       if(acc[count].acno==check)
	   {
	   		b= count;break;
	   } 
     }
    if(acc[b].acno==check)
    	{
			welcome();
            printf("\n\t NAME OF THE ACCOUNT HOLDER  -: %s",acc[b].name);
            printf("\n\t AGE                         -: %d",acc[b].age);
            printf("\n\t CURRENT BANK BALANCE        -: %.3f",acc[b].balance);
                    
		    printf("\n\n\tENTER AMOUNT TO WITHDRAW -:");
            
			scanf("%f",&submoney);
            
			if(acc[b].balance<submoney)
            {
                printf("\n\t********LOW ACCOUNT BALANCE******\n");
             	
            }
            else
            {
                acc[b].balance-=submoney;
                welcome();
                printf("\n\tACCOUNT BALANCE AFTER WITH DRAWING -:%.3f",acc[b].balance);
            	printf("\n");
			}
        }
        else
        {
        	welcome();
            printf("\n\t NO SUCH ACCOUNT IS AVAILABLE !!!!\n");
            
        }
}


/**************************************************************************
                        GIVING PASSWORD TO THE ACCOUNT
**************************************************************************/

void withdraw_and_pwd_include()//GIVING PASSWORD SECURITY BEFORE WITHDRAWING
{
	welcome();
	char p[10];
	char pass[10]="group001";//YOU CAN CHANGE YOUR PASSWORD IF YOU WANT
    printf("\n\tENTER THE PASSWORD : ");
    fflush(stdin);gets(p);
    if (strcmp(p,pass)==0)
        {
        	system("cls");
        	withdraw();
            //withdraw_and_pwd_include();
        }
    
}
void deposit_and_pwd_include()//GIVING PASSWORD SECURITY BEFORE DEPOSITING
{
	welcome();
	char p[10];
	char pass[10]="group001";//YOU CAN CHANGE YOUR PASSWORD IF YOU WANT
    printf("\n\tENTER THE PASSWORD : ");
    
    fflush(stdin);gets(p);
    if (strcmp(p,pass)==0)
        {
        	system("cls");
            deposit();
        }
    
}

/**************************************************************************
                            DETAILS OF AN ACCOUNT
**************************************************************************/


void check_details_of_acc()//TO SEE ACCOUNT DETAILS OF AN ACCOUNT BY GIVING ACCOUNT NUMBER
{
    int accountno,check,b=0;
    welcome();
    printf("\n\tENTER YOU BANK ACCOUNT NO. -:");
    scanf("%d",&accountno);
    
	for(check=0;check<n;check++)       
    {
        if(acc[check].acno==accountno)
        {
        	b=check;break;
		}
          
     }
    if(acc[b].acno==accountno)
   {
   		welcome();
        printf("\n\t ACCOUNT NUMBER              -: %d",acc[b].acno);
        printf("\n\t NAME OF THE ACCOUNT HOLDER  -: %s",acc[b].name);
        printf("\n\t FATHERS'S NAME              -: %s",acc[b].fname);
        printf("\n\t DATE OF BIRTH 	             -: %d/%d/%d",acc[b].dob.day,acc[b].dob.month,acc[b].dob.year);
		printf("\n\t AGE                         -: %d",acc[b].age);
		printf("\n\t PERMANENT ADDRESS           -: %s",acc[b].address);
		printf("\n\t CURRENT BANK BALANCE        -: %.3f\n\n",acc[b].balance);
	}
    else
    {
    	welcome();
    	fflush(stdin);
      printf("\n\nNO SUCH ACCOUNT AVAILABLE !!!!\n\n");
      
    }
}


/**************************************************************************
                            MAIN FUNCTION
**************************************************************************/


int main()//MAIN FUNCTION OF THE PROGRAM
{
    int ch,option;
    welcome();
	while(1)
    {
    printf("\n\n\n\t********* MAIN MENU ***********");//CHOICES AVAILABLE FOR A PERSON
    printf("\n\t* 1. OPEN AN ACCOUNT\t      *");
    printf("\n\t* 2. DEPOSIT TO AN ACCOUNT    *");
    printf("\n\t* 3. WITHDRAWL FROM AN ACCOUNT*");
    printf("\n\t* 4. DETAILS OF AN ACCOUNT    *");
    printf("\n\t* 5. EXIT\t\t      *");
    printf("\n\t*******************************");
	printf("\n\t  YOUR OPTION -: ");
 	scanf("%d",&option);
 	welcome();
	switch(option)
        {
          case 1: open_an_account();
                    break;
          case 2: deposit_and_pwd_include();
                    break;
          case 3: withdraw_and_pwd_include();
                    break;
          case 4: check_details_of_acc() ;
                    break;
          case 5: printf("\n\n\t\tTHANK YOU FOR VISINTG OUR ACCOUNT\n\n");
		  			return 0;
        default : printf("\n\nINVALID CHOICE!!!\n\n");
                    break;
        }
}
return 0;
}
