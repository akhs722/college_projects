#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int entry;

typedef struct Data{
	int admn;
	char usn[12];
	float meal;
    }data;
int n[100];
void createdatabase(int i)
{	
	data *m,*c;
	FILE *p;
	int j,flag,k;
	p = fopen("database.bin","ab+");
	c = (data*)malloc(sizeof(data));
	m = (data*)malloc(sizeof(data));
	printf("\n");
		for(j=0;j<i;j++)
		{   
			
			a:printf("Enter the student's Admission Number and USN -\n");
			scanf("%d",&m->admn);
			if(m->admn==0)
			{
				printf("\t\t\t\t.....ABORTED!!!!\n\n");
				return;
				
			}
			fflush(stdin);
			scanf("%s",m->usn);
			rewind(p);
			for(;;)
			{
				fread(c,sizeof(data),1,p);
				if(feof(p))
				break;
			 	else if((m->admn==c->admn)||(strcmp(m->usn,c->usn)==0))
				{
				printf("\t\t\t\t\tALREADY REGISTERED..give correct credentials again...\n\n");
				goto a;
				}
				else
				flag=1;
			}
			
			m->meal = 0;
			fwrite(m,sizeof(data),1,p);
	}

		fclose(p);
		free(m);
		free(c);
printf("\n\t\t\t\t\t...DATABASE UPDATED SUCCESSFULLY...\n\n");
}

void addmeal()
{
	FILE *d;
	d = fopen("database.bin","rb+");
	data *m;
	int i,j,h=0,flag=0,adn,z,key;
system("cls");
printf("\n");
m =(data*)malloc(sizeof(data));
while(1)
{
	rewind(d);
		printf("Scan the Id - ");
		scanf("%d",&adn);
		
				if(adn==17797)
				{
					printf("\t\t\t\t\t\t......SESSION OVER\n\n");
					fclose(d);
					free(m);
					return;
				}
		for(z=0;z<100;z++)
		{
			if(adn==n[z])
			{
				key=0;
				break;
			}
			else
			key=1;
		}
	
	switch(key)
		{	
			
			case 0: printf("\t\t\t\t\t\tACCESS DENIED....\n");
					break;
			
			
			case 1:{
					for(j=0;j<5;j++)
    				{
						fread(m,sizeof(data),1,d);
							if(m->admn==adn)
							{
								flag=1;
								break;
							}
							else
							flag=0;
					}
			if(flag==1) 
		{
			m->meal=m->meal+16;
			fseek(d,-(sizeof(data)),SEEK_CUR);
			fwrite(m,sizeof(data),1,d);
			fseek(d,(sizeof(data)),SEEK_CUR);
		} 
		
		 else
		{
				printf("\t\t\t\t\tREGISTRATION REQUIRED CONTACT ADMINISTRATION\n");
		}
break;
}
}
	n[h]=adn;
	h++;	
}
}

void clearbill()
{
	FILE *s,*fpt;
	int ch,admn,ca;
	char method[20],tid[20];
	s = fopen("database.bin","rb+");
	data *x;
 	int flag=0,i,c;
 	float due,amount;
 	x = (data*)malloc(sizeof(data));
 	agains:printf("1.Proceed to pay\t\t2.Exit\n");
 	scanf("%d",&c);
 	//rewind(s);
	switch(c)
	{
	case 1:{
				printf("Scan the ID - ");
			scanf("%d",&admn);
			for(;;)
			{	
				
				fread(x,sizeof(data),1,s);
				if(feof(s))
				break;
				if(admn==x->admn)
				{
					flag = 1;
					printf("\nCalculating....\n");
					Sleep(1000);
					printf("\n%d\tRs.%.2f",x->admn,x->meal);
					printf("\nWant to pay now(1/0)\n");
					scanf("%d",&ch);
					
					if(ch==1)
					{       printf("1.Cash\t\t\t2.Other\n");
							scanf("%d",&ca);
							switch(ca)
							{
								case 1: {
												printf("\nAmount to be paid : Rs.");
												scanf("%f",&amount);
												due = x->meal - amount;
												x->meal = due;
												fseek(s,-(sizeof(data)),SEEK_CUR);
												fwrite(x,sizeof(data),1,s);
												fseek(s,(sizeof(data)),SEEK_CUR);
												printf("\t\t\t\t\t\tSUCCESS!!!!");
												printf("\n\n");
												break;
										}
							
								case 2: { 		
												fpt =  fopen("transaction.csv","a");
												printf("\nAmount to be paid : Rs.");
												scanf("%f",&amount);
												due = x->meal - amount;
												x->meal = due;
												fseek(s,-(sizeof(data)),SEEK_CUR);
												fwrite(x,sizeof(data),1,s);
												fseek(s,(sizeof(data)),SEEK_CUR);
												printf("Give Method and Transaction ID - ");
												scanf("%s%s",method,tid);
												fprintf(fpt,"%d,Rs.%.2f,%s,%s\n",x->admn,amount,method,tid);
												printf("\t\t\t\tSUCCESS,DETAILS STORED IN EXCEL FILE MINIPROJECT->TRANSCATION");
												printf("\n\n");
												fclose(fpt);
												break;
										}
							
							}
							
					}
				else if(ch==0)
				{	
					fclose(s);
					free(x);
 					return;	
					break;
					
				}	
			}
}
		if(flag==0)
			{
				printf("\n\t\t");
				printf("\t\t\t......NO SUCH RECORD FOUND......\n\n");
				fclose(s);
					free(x);
 					return;	
					break;
		 }
}
    case 2: {
				fclose(s);
				free(x);
 				return;	
				break;
 		 	}
}
//system("cls");
goto agains;
}

record()
{
	FILE *p,*rec;
	data *m;
	p = fopen("database.bin","rb");
 	rec = fopen("record.csv","w");  
 	 system("cls"); 
	m=(data*)malloc(sizeof(data));
	printf("\t\t\t\t\t\tFETCHING DETAILS WAIT.....\n");
	Sleep(1000);
	for(;;)
		{
			fread(m,sizeof(data),1,p);
			if(feof(p))
			break;
			printf("%d\t\t%s\t\tRs.%.2f\n",m->admn,m->usn,m->meal);
			fprintf(rec,"%d,%s,Rs.%.2f\n",m->admn,m->usn,m->meal);
		}
		printf("\n\t\t\t.....TO VIEW YOUR EXCEL SHEET move to folder MINIPROJECT->RECORD.CSV\n\n");
		fclose(rec);
	fclose(p);
	free(m);
}


void main()

{
int admin;
int i;	
	printf("\t\t\t\t\t\t  MESS MANAGEMENT SYSTEM\t\t\t\t\n\n\n\n");
	int choice,admn,key;
	first:printf("Scan Admin Id -\t");
	scanf("%d",&admin);
	if(admin==17797)
	{
	printf("\t\t\t\t\t\t......Loading....\n");
	Sleep(1000);	
	system("cls");
	printf("\t\t\t\t\t\t  MESS MANAGEMENT SYSTEM\t\t\t\t\n\n\n\n");
	again:printf("\t\t1.Create Database\t2.Add Meal\t3.Records\t4.Clear Bill\t\t5.Exit\n\n");
	scanf("%d",&choice);
	
switch(choice)
{
	case 1:
		{
			printf("\n-> Give the number of entries:\t");
			scanf("%d",&entry);
			system("cls");
			createdatabase(entry);
			
		    break;
		}

	
	case 2:
		{
		 addmeal();
		 break;
		}	
	case 3:
		{
			record();
			break;
		}
	
	case 4:
		{
			system("cls");
			printf("\n");
			clearbill();
			break;
		}
		
	 case 5:
	 exit(0);
	 break;	

default:
printf("\t\t\t\t\t\tGIVE CORRECT INPUT\n\n");
break;

}
goto again;
}

else
{   
    printf("\a");
	printf("\nACCESS DENIED.......\n\n");
	goto first;
}
}

