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
						
						
int authorize()
{
	
}						
main()
{
	FILE *q,*l,*e;
	pat *p,*c;
	dl *doc;
	int flag=0,flag1=0,press=0,choice,flag2=0,flag3=0;
	doc = (dl*)malloc(sizeof(dl));
	p = (pat*)malloc(sizeof(pat));
	c = (pat*)malloc(sizeof(pat));
	
	char licence[20],id[20];
	l = fopen("licence.bin","rb");
	again1:printf("1.Address your patient\n2.Refer to another doctor\n3.Logout\n");
	scanf("%d",&choice);
switch(choice)
{
							case 1: //ye bada wala ka 1st hai
							{
							
							again:printf("Enter your valid licence number\n");
							fflush(stdin);
							gets(licence);
							if(strcmp(licence,"0")==0)
							{
								break;
							}
							
							rewind(l);
							for(;;)
							{
								fread(doc,sizeof(dl),1,l);
								if(feof(l))
								break;
								else if(strcmp(doc->licence,licence)==0)
								flag=1;
							}									}
							if(flag==0)
							{
								goto again;
							}
							else if(flag==1)
									{
										q = fopen("records.bin","rb");
										a:printf("Enter the id given by the patient\n");
										fflush(stdin);
										gets(id);
										if(strcmp(id,"0")==0)
										goto again1;
										
										rewind(q);
										for(;;)
										{
											fread(p,sizeof(pat),1,q);
											if(feof(q))
											break;
											else if(strcmp(p->id,id)==0)
											{
												flag2=1;
												break;
											}
										}
										if(flag2==0)
										{
											printf("Wrong credentials.....");
											goto a;
										}
										
										else if(flag2==1)
										{
											//bande ki id wagerah(city,state,dob etc) likhna hoga wo end mein sochna kaise dikhaoge i mean kis pattern mein
											
											fclose(q);
											free(p);
											p = (pat*)malloc(sizeof(pat));		
										re1:printf("\n1.Show medical record\n2.Update Symptoms\n3.Update test results\n4.Update disease\n5.Prescribe medicines\n6.Update allergies\n7.Update height and weight\n8.Main menu\n");
											printf("Give your choice: ");
											fflush(stdin);
											scanf("%d",&press);										
											
									switch(press)
									{
											case 1: {	
														system("cls");
														int w;
														e = fopen("records.bin","rb");
														for(;;)
														{			
															fread(c,sizeof(pat),1,e);
															if(feof(e))
															break;
														else if(strcmp(c->id,id)==0)
														{
															flag3=1;
															break;
														}
														}	
														if(flag3==1)
														{
															int i,j;
															printf("Name: ");
															puts(c->name);
															printf("Gender: ");
															puts(c->gender);
															printf("State: ");
															puts(c->state);
															
															printf("\nyour Height and Weight are: %f and %f\n",c->locker.height,c->locker.weight);
															
															printf("\nTests undertaken by you are:\n");
															for(i=c->locker.test.top2;i>=1;i--)
															{																				
																printf("%s\n",c->locker.test.tname[i]);												
																printf("%s\n",c->locker.test.toutcome[i]);
															}
															printf("\nRecorded symptoms are:\n");
															for(i=c->locker.here;i>0;i--)
																printf("%s\n",c->locker.symptoms[i]);
															printf("\nThe diseases past and previous in ordered form are:\n");
															for(i=c->locker.top;i>=1;i--)
																printf("%s\n",c->locker.disease[i]);
															printf("\nThe medicines taken till now in order are:\n");	
															for(i=c->locker.top1;i>=1;i--)	
																printf("%s\n",c->locker.med[i]);
															
															printf("\nProbable allergies are:\n");	
										
															for(i=c->locker.now;i>=1;i--)
															{
																printf("%s\t",c->locker.allergies[i]);
																printf("%s\n",c->locker.amed[i]);
															}	
																printf("\n");																	
														}
														fclose(e);
														printf("Press '1' to go back.....");
														ad:scanf("%d",&w);
														if(w==1)
														{
															system("cls");
															break;
														}
														else
														{
															printf("Wrong input.....Give again\n");
															goto ad;
														}
															
														}	
													
												case 2:{
													system("cls");
															int m,j;
															q = fopen("records.bin","rb+");
														for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
															else if(strcmp(p->id,id)==0)
															{
																flag3=1;
																break;
															}
														}
														if(flag3==1)
														{														
															printf("How many symptoms?");
															scanf("%d",&m);
															
															for(j=0;j<m;j++)
															{
																fflush(stdin);
																scanf("%[^\n]",p->locker.symptoms[++p->locker.here]);																
															}
															
														}
															fseek(q,-(sizeof(pat)),SEEK_CUR);
															fwrite(p,sizeof(pat),1,q);		
															fseek(q,sizeof(pat),SEEK_CUR);				
															fclose(q);
													break;
												}
													
											case 3: {	
											system("cls");
														q = fopen("records.bin","rb+");
														for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
														else if(strcmp(p->id,id)==0)
														{
															flag3=1;
															break;
														}
														}
														if(flag3==1)
														{														
															printf("Enter the Test name\n");
															fflush(stdin);
															scanf("%[^\n]",p->locker.test.tname[++p->locker.test.top2]);
															printf("Enter the outcome\n");
															fflush(stdin);
															scanf("%[^.]",p->locker.test.toutcome[p->locker.test.top2]);
														
															fseek(q,-(sizeof(pat)),SEEK_CUR);
															fwrite(p,sizeof(pat),1,q);		
															fseek(q,sizeof(pat),SEEK_CUR);				
															fclose(q);
														}
														break;
														}
														
													
										
											case 4: { 
											system("cls");
														q = fopen("records.bin","rb+");
														for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
														else if(strcmp(p->id,id)==0)
														{
															flag3=1;
															break;
														}
														}
														if(flag3==1)
														{														
														printf("Enter The disease\n");
							           					fflush(stdin);
									   					scanf("%[^\n]",p->locker.disease[++p->locker.top]); 
														fseek(q,-(sizeof(pat)),SEEK_CUR);
															fwrite(p,sizeof(pat),1,q);		
															fseek(q,sizeof(pat),SEEK_CUR);				
															fclose(q);
														}
														break;															
													}
											case 5:
												
												{	
												system("cls");
													q = fopen("records.bin","rb+");
														for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
														else if(strcmp(p->id,id)==0)
														{
															flag3=1;
															break;
														}
														}
														if(flag3==1)
														{														
																printf("Enter the medicines with dosage in mg\n");
																fflush(stdin);
																scanf("%[^\n]",p->locker.med[++p->locker.top1]);					
																fseek(q,-(sizeof(pat)),SEEK_CUR);
																fwrite(p,sizeof(pat),1,q);		
																fseek(q,sizeof(pat),SEEK_CUR);				
																fclose(q);	
														}							
													break;
												}													
											case 6:
												{
													system("cls");
														q = fopen("records.bin","rb+");
														for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
														else if(strcmp(p->id,id)==0)
														{
															flag3=1;
															break;
														}
														}
														if(flag3==1)
														{	int i,n;
															printf("How many allergies are encountered by the patient\n");
															scanf("%d",&n);												
															for(i=0;i<n;i++)
															{
																printf("Allergy Effects: ");
																fflush(stdin);
																scanf("%[^\n]",p->locker.allergies[++p->locker.now]);
																printf("Suspected Medicine: ");
																fflush(stdin);
																scanf("%[^\n]",p->locker.amed[p->locker.now]);															
															}
																fseek(q,-(sizeof(pat)),SEEK_CUR);
																fwrite(p,sizeof(pat),1,q);		
																fseek(q,sizeof(pat),SEEK_CUR);				
																fclose(q);	
														}
												break;
												}
										case 7:
											{
												system("cls");
												q = fopen("records.bin","rb+");
												for(;;)
														{			
															fread(p,sizeof(pat),1,q);
															if(feof(q))
															break;
														else if(strcmp(p->id,id)==0)
														{
															flag3=1;
															break;
														}
														}
														if(flag3==1)
														{	
																											
															printf("Enter the new weight: ");
															scanf("%f",&p->locker.weight);
																printf("Enter the new height: ");
																scanf("%f",&p->locker.height);
																fseek(q,-(sizeof(pat)),SEEK_CUR);
																fwrite(p,sizeof(pat),1,q);		
																fseek(q,sizeof(pat),SEEK_CUR);				
																fclose(q);	
														}
													
																break;
											}
									
										
										case 8:	system("cls");
										 			goto again1;		
						
						
						
										default: printf("Invalid input.....Give again");
												break;
											}
						goto re1;
					case 2: exit(0);    ///ye bada wala ka second hai	
		
					default: printf("Invalid input.....Give again\n");
												break;
		
		}	

	
}

}
goto again1;
}
