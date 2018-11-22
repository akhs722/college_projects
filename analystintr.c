#include<stdio.h>
#include<stdlib.h>
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
main()
{
	//diseases vs state		
	FILE *q,*r,*u;
	pat *p;
	p = (pat*)malloc(sizeof(pat));
	int choice=0;
	printf("1.Analysis of a Disease vs States\n2.Analysis of a Disease vs Gender\n3.Analysis of a Disease vs Age\n");
	scanf("%d",&choice);
	switch(choice)
	{
	
					case 1:{
								int i,j,flag=0;
								char state[30][200] = {"uttar pradesh","karnataka","punjab"};
								static int count[30];
								char disease[100];
								printf("Enter the particular disease for analysis: ");
								fflush(stdin);
								gets(disease);
								strcat(disease,"vs");
								strcat(disease,".csv");
								q = fopen("records.bin","rb");
								
								
									a:fread(p,sizeof(pat),1,q);
									if(feof(q))
									goto b;
									for(i=p->locker.top;i>0;i--)
									{
										puts(p->state);
										if(strcmp(p->locker.disease[i],"diabetes")==0)
										{
											flag=1;
											break;
										}
									}
									if(flag==1)
									{
										for(j=0;j<3;j++)
										{
											if(strcmp(p->state,state[j])==0)
											{
												count[j]++;
												break;
											}
									
										}	
									goto a;		
									}
									b:	r = fopen(disease,"wb");
									for(i=0;i<3;i++)
									{
										fprintf(r,"%s,%d\n",state[i],count[i]);
									}
									printf("YOUR DATA IS SORTED,COMPARED AND STORED IN EXCEL SHEET FOR DEMOGRAPHICAL ANALYSIS OF DISEASE.....");
							fclose(r);
					break;							
				}
				
				case 2: {   int i,j,flag=0,cm=0,cf=0;
							char disease[100];
							printf("Enter the particular disease for analysis: ");
							fflush(stdin);
							gets(disease);
							strcat(disease,"vg");
							strcat(disease,".csv");
							q = fopen("records.bin","rb");
							as:fread(p,sizeof(pat),1,q);
							if(feof(q))
							goto bs;
							for(i=p->locker.top;i>0;i--)
									{
										if(strcmp(p->locker.disease[i],"diabetes")==0)
										{
											flag=1;
											break;
										}
									}
										if(flag==1)
										{
											if(strcmp(p->gender,"m")==0||strcmp(p->gender,"male")==0)
											{
												cm++;
												goto as;
											}
										
											else
											{
												cf++;
												goto as;
											}
										}
											bs:	u = fopen(disease,"wb");
											fprintf(u,"%s,%s\n%d,%d","male %","female %",cm,cf);
									printf("YOUR DATA IS SORTED,COMPARED AND STORED IN EXCEL SHEET FOR ANALYSIS OF DISEASE vs GENDER .....");
									fclose(u);
						
						break;
				}
				
				case 3: {
								int i,j,flag=0,age=0,teen=0,young=0,middle=0,senior=0,old=0;
								char disease[100];
								printf("Enter the particular disease for analysis: ");
								fflush(stdin);
								gets(disease);
								strcat(disease,"vage");
								strcat(disease,".csv");
								q = fopen("records.bin","rb");
								ass:fread(p,sizeof(pat),1,q);
								if(feof(q))
								goto bss;
										for(i=p->locker.top;i>0;i--)
										{
											if(strcmp(p->locker.disease[i],"diabetes")==0)
											{
												printf("inside is %d\n",i);
												flag=1;
												break;
											}
										}
										if(flag==1)
										{
											age = 2018 - p->dob.year;	
											if(age>=10&&age<17)
											{
												teen++;
												goto ass;
											}
											
												
											else if(age>=17&&age<30)
											
											{
												young++;
												goto ass;
											}
						
											else if(age>=30&&age<55)
											
											{
												middle++;
												goto ass;
											}
											
											else if(age>=55&&age<75)
											
											{
												senior++;
												goto ass;
											}
						
											else if(age>=75&&age<90)
											
											{
												old++;
												goto ass;
											}
										}
									bss:	u = fopen(disease,"wb");
										fprintf(u,"%s,%s,%s,%s,%s\n%d,%d,%d,%d,%d","Teen %","Young %","Middle %","Senior %","Old %",teen,young,middle,senior,old);
									printf("YOUR DATA IS SORTED,COMPARED AND STORED IN EXCEL SHEET FOR ANALYSIS OF DISEASE vs AGE .....");
									fclose(u);	
						break;
						}	
				
				
}
	
}
	


