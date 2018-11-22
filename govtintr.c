#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patients{
				char id[13];
				char name[80];
				char gender[7];
				struct birth{
					int date;
					int month;
					int year;
				}dob;
				char fname[80];
				char address[1000];
				char city[40];
				char state[80];
					
 struct medilocker{
						
						float weight;
						float height;
						int a;
						char lic[30][100];
						char symptoms[100][200];
						char disease[50][200];
						struct test
						{
									int top2;
									char tname[50][100];			
									char toutcome[50][1000];
						}test;
						int top,now,top1,here,thi;						
						char allergies[20][100];
						char amed[20][200];
						char med[50][200];
				 }locker;						

}pat;
typedef struct doclicence{
							char docname[80];
							char licence[20];
							char clinicname[200];		
						}dl;
						
						
int main()
{
	
	FILE *p,*l;
	int choice,n,i,flag=0,flag1=0;
	
	
	pat *q,*c;
	dl *doc;
	char licence[20];
	q = (pat*)malloc(sizeof(pat));
	c = (pat*)malloc(sizeof(pat));
	doc = (dl*)malloc(sizeof(dl));
	again2:system("cls");
	printf("1.Register citizen in database\n2.Register Doctor details\n3.Exit\n");
	scanf("%d",&choice);
	strcpy(c->id,"0");
	switch(choice)
	{
		case 1:{  
					p = fopen("records.bin","ab+");
					
					printf("How many entries?");
					scanf("%d",&n);
					printf("Give details of the people\n\n");
					for(i=0;i<n;i++)
					{
		
					a:printf("Id: ");
					fflush(stdin);
					gets(q->id);
						if(strcmp(q->id,"0")==0)
						break;
						rewind(p);
						for(;;)
						{
							fread(c,sizeof(pat),1,p);
							if(feof(p))
							break;
							if(strcmp(c->id,q->id)==0)
							{
								printf("Already registered...");
								goto a;
							}
						}
							printf("Name: ");
							gets(q->name);
							fflush(stdin);
							printf("Gender: ");
							gets(q->gender);
							printf("Enter date(dd): ");
							scanf("%d",&q->dob.date);
							printf("Enter Month(mm): ");
							scanf("%d",&q->dob.month);
							printf("Enter Year(yyyy): ");
							scanf("%d",&q->dob.year);
							fflush(stdin);
							printf("Father's Name: ");
							gets(q->fname);
							fflush(stdin);
							printf("Current Address: ");
							gets(q->address);
							fflush(stdin);
							printf("Enter State: ");
							gets(q->state);
							fflush(stdin);
							printf("Enter City: ");
							gets(q->city);
							printf("\n");
							fwrite(q,sizeof(pat),1,p);
							
						}
		
			
					break;
				}
		case 2:{	l = fopen("licence.bin","wb");
					printf("How many registrations?\n");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("Enter the doctot's name\n");
						fflush(stdin);
						gets(doc->docname);
						printf("Enter Licence no.\n");
						fflush(stdin);
						gets(doc->licence);
						printf("Enter clinic name\n");
						fflush(stdin);
						gets(doc->clinicname);
						fwrite(doc,sizeof(dl),1,l);
						fclose(l);		
					}	
						break;
		  		}		 
		  
		case 3:exit(0);
	}
	
goto again2;
}
