#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "Project1.1.c"

typedef struct News{
	char finalCategory[100000];
	char title[1000];
	char link[5000];
	char pubdate[500];
	char description[10000];
	char *category[1000];
	int textnum;/* to show that which text file it is belong to */
	int catnum;/* num of categories */
}news;

void space(void){
	FILE *file , *f;
	int i , j;
	char b[30] , c[30];
	char temp[5000];
	char *text2[100000];
	
	for(i = 0 ; i < 20 ; i++){
		sprintf(b, "RSS %d.txt" ,i);
		file = fopen(b, "r");
		text2[i] = (char *)calloc (5000, sizeof(char));
		sprintf(c , "SpacedRSS %d.txt" ,i);
		f = fopen(c , "w");
		while (fscanf(file, "%s", text2[i]) != EOF)
		{
			/* add spaces to seprate tags */
			for(j = 0 ; j < strlen(text2[i]) ; j++){
				strcpy(temp , text2[i]);
				if(text2[i][j] == '>' || text2[i][j] == ']' || text2[i][j] == '['){
					text2[i][j + 1] = ' ';
					strcpy(text2[i] + j + 2 , temp + j + 1);
				}
				strcpy(temp , text2[i]);
				if( (text2[i][j] == '<' || text2[i][j] == ']' || text2[i][j] == '[' ) && j > 0){
					text2[i][j] = ' ';
					strcpy(text2[i] + j + 1 , temp + j);
					j++;
				}
			}
			fprintf(f ,"%s " , text2[i] );
		}		
		fclose(file);
		fclose(f);
		
	}

}

void replacehttp(void){
	FILE *file , *f;
	int i , j;
	char b[30] , c[30];
	char temp[5000];
	char *text2[100000];
	
	for(i = 0 ; i < 20 ; i++){
		sprintf(b, "SpacedRSS %d.txt" ,i);
		file = fopen(b, "r");
		text2[i] = (char *)calloc (5000, sizeof(char));
		sprintf(c , "httpsSpacedRSS %d.txt" ,i);
		f = fopen(c , "w");
		while (fscanf(file, "%s", text2[i]) != EOF)
		{
			/* add spaces to seprate tags */
			for(j = 0 ; j < strlen(text2[i]) ; j++){
				strcpy(temp , text2[i]);
					if(text2[i][j] == 'h' && text2[i][j + 1] == 't' && text2[i][j + 2] == 't' && text2[i][j + 3] == 'p'){
						if(text2[i][j + 4] != 's'){
							text2[i][j + 4] = 's';
							strcpy(text2[i] + j + 5 , temp + j + 4);
						}
					}
			}
			fprintf(f ,"%s " , text2[i] );
		}		
		
		fclose(file);
		fclose(f);
	}
}


void replacehtmlsymbols(void){
	FILE *file , *f;
	int i , j;
	char b[30] , c[30];
	char temp[5000];
	char *text2[100000];
	int numofchanges = 0;
	
	for(i = 0 ; i < 20 ; i++){
		sprintf(b, "httpsSpacedRSS %d.txt" ,i);
		file = fopen(b, "r");
		text2[i] = (char *)calloc (5000, sizeof(char));
		sprintf(c , "replacesymbolshttpsSpacedRSS %d.txt" ,i);
		f = fopen(c , "w");
		while (fscanf(file, "%s", text2[i]) != EOF)
		{
			/* add spaces to seprate tags */
			for(j = 0 ; j < strlen(text2[i]) ; j++){
				strcpy(temp , text2[i]);
				if(text2[i][j + 3] != '\0' && text2[i][j] == '&' && text2[i][j + 1] == '#'){
					switch(text2[i][j + 2]){
						case '3':
							switch(text2[i][j + 3]){
								case '2':
									text2[i][j] = ' ';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '3':
									text2[i][j] = '!';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '4':
									text2[i][j] = 39;
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '5':
									text2[i][j] = '#';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '6':
									text2[i][j] = '$';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;	
								case '7':
									text2[i][j] = '%';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '8':
									text2[i][j] = '&';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;	
								case '9':
									text2[i][j] = 39;
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;	
							}
						case '4':
							switch(text2[i][j + 3]){
								case '0':
									text2[i][j] = '(';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '1':
									text2[i][j] = ')';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '2':
									text2[i][j] = '*';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '3':
									text2[i][j] = '+';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '4':
									text2[i][j] = '`';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '5':
									text2[i][j] = '-';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '6':
									text2[i][j] = '.';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '7':
									text2[i][j] = '/';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
							}
						case '5':
							switch(text2[i][j + 3]){
								case '8':
									text2[i][j] = ':';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue; 
								case '9':
									text2[i][j] = ';';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
							}
						case '6':
							switch(text2[i][j + 3]){
								case '0':
									text2[i][j] = '<';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '1':
									text2[i][j] = '=';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '2':
									text2[i][j] = '>';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '3':
									text2[i][j] = '?';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '4':
									text2[i][j] = '@';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								}
						case '9':
							switch(text2[i][j + 3]){
								case '1':
									text2[i][j] = '[';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '2':
									text2[i][j] = '\\';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '3':
									text2[i][j] = ']';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '4':
									text2[i][j] = '^';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '5':
									text2[i][j] = '_';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
								case '6':
									text2[i][j] = '`';
									strcpy(text2[i] + j + 1 , temp + j + 5);
									continue;
							}
						case '1':
							switch(text2[i][j + 3]){
								case '2':
									switch(text2[i][j + 4]){
										case '3':
											text2[i][j] = '{';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
										case '4':
											text2[i][j] = '|';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
										case '5':
											text2[i][j] = '}';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
										case '6':
											text2[i][j] = '~';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
									}
								case '8':
									switch(text2[i][j + 4]){
										case '3':
											text2[i][j] = '.';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
										case '7':
											text2[i][j] = '>';
											strcpy(text2[i] + j + 1 , temp + j + 6);
											continue;
									
									}
							}
						case '8':
							switch(text2[i][j + 3]){
								case '2':
									switch(text2[i][j + 4]){
										case '1':
											switch(text2[i][j + 5]){
												case '1':
													text2[i][j] = '-';
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '2':
													text2[i][j] = '_';
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '6':
													text2[i][j] = 39;
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '7':
													text2[i][j] = '`';
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '8':
													text2[i][j] = ',';
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
											}
										case '2':
											switch(text2[i][j + 5]){
												case '0':
													text2[i][j] = 39;
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '1':
													text2[i][j] = 39;
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
												case '2':
													text2[i][j] = 39;
													strcpy(text2[i] + j + 1 , temp + j + 7);
													continue;
											}	
										
									}
							}
							
					}
				}
			}
			fprintf(f ,"%s " , text2[i] );
		}		 
		
		fclose(f);
		fclose(file);
	}
	
}


void replacequ(void){
	FILE *file , *f;
	int i , j;
	char b[30] , c[30];
	char *text2[100000];
	
	for(i = 0 ; i < 20 ; i++){
		sprintf(b, "replacesymbolshttpsSpacedRSS %d.txt" ,i);
		file = fopen(b, "r");
		text2[i] = (char *)calloc (5000, sizeof(char));
		sprintf(c , "finalRSS %d.txt" ,i);
		f = fopen(c , "w");
		while (fscanf(file, "%s", text2[i]) != EOF)
		{
			/* add spaces to seprate tags */
			for(j = 0 ; j < strlen(text2[i]) ; j++){
					if(text2[i][j] == '"'){
						text2[i][j] = '\'';
					}
			}
			fprintf(f ,"%s " , text2[i] );
		}		
		
		fclose(file);
		fclose(f);
	}
}

int newsclassify(news arr[]){
	FILE *file;
	int i , j, flag = 0, flag2 = 0;
	char temp[5000];
	char *text2[100000];
	int newsnum = 0;
	int textnum = 0;
	char b[100];
	int catnum = 0;
	
	for(i = 0 ; i < 20 ; i++){
		sprintf(b, "finalRSS %d.txt" ,i);
		file = fopen(b, "r");
		text2[i] = (char *)calloc (5000, sizeof(char));
		while (fscanf(file, "%s", text2[i]) != EOF)
		{
			if(strcmp(text2[i] , "<item>") == 0){
				arr[newsnum].catnum = 0;
				catnum = 0;
				arr[newsnum].textnum = textnum;
				while( strcmp(text2[i] , "</item>") != 0  &&  fscanf(file, "%s", text2[i]) != EOF){
					
					if(strcmp(text2[i] , "<title>") == 0){
						while( strcmp(text2[i] , "</title>") != 0){
							fscanf(file, "%s", text2[i]);
							if(text2[i][0] != '<' && text2[i][0] != '>'){
								strcat(text2[i], " ");
								strcat(arr[newsnum].title , text2[i]);
							}
						}
						continue;
					}
					
					if(strcmp(text2[i] , "<link>") == 0){
						while( strcmp(text2[i] , "</link>") != 0){
							fscanf(file, "%s", text2[i]);
							if(text2[i][0] != '<' && text2[i][0] != '>'){
								strcat(text2[i], " ");
								strcat(arr[newsnum].link , text2[i]);
							}
						}
						continue;
					}
					
					if(strcmp(text2[i] , "<pubDate>") == 0){
						while( strcmp(text2[i] , "</pubDate>") != 0){
							fscanf(file, "%s", text2[i]);
							if(text2[i][0] == '+') break;
							if(text2[i][0] != '<' && text2[i][0] != '>'){
								strcat(text2[i], " ");
								strcat(arr[newsnum].pubdate , text2[i]);
							}
						}
						continue;
					}
					
					if(strcmp(text2[i] , "<description>") == 0){
						flag = 0;
						while( strcmp(text2[i] , "</description>") != 0){
							fscanf(file, "%s", text2[i]);
							if(text2[i][0] == '<')
								flag = 1;
							if(text2[i][strlen(text2[i]) - 1] == '>')
							{
								flag = 0;
								flag2 = 1;
								continue;
							}
							if(flag == 0 && strcmp(text2[i], "]")!= 0)
							{
								strcat(arr[newsnum].description , text2[i]);
								strcat(arr[newsnum].description , " ");
							}
						}
						
						continue;
					}
					
					if(strcmp(text2[i] , "<category>") == 0){
						while( strcmp(text2[i] , "</category>") != 0){
							fscanf(file, "%s", text2[i]);
							if(text2[i][0] != '<' && text2[i][0] != '>' && strcmp(text2[i] , "CDATA") != 0 && text2[i][0] != ']' && text2[i][0] != '['){
								strcat(text2[i], " ");
								arr[newsnum].category[catnum] = (char *)calloc(10000 , sizeof(char));
								strcat(arr[newsnum].category[catnum] , text2[i]);
								arr[newsnum].catnum++;
								catnum++;
							}
						}
						continue;
					}
				}
				catnum = 0;
				newsnum++;
			}
		}		 
		fclose(file);
		textnum++;
	}
	return newsnum;
}

int main()
{
	GET();
	int i = 0, j = 0, k =0;
	space();
	replacehttp();
	replacehtmlsymbols();
	replacequ();
	news *arr = (news *)calloc(100000 , sizeof(news));
	int newsnum = newsclassify(arr);
	
	for (i = 0; i < newsnum; i++)
	{
		for(j = 0; j < arr[i].catnum; j++)
		{
			int Z = strlen(arr[i].category[j]);
			arr[i].category[j][Z - 1] = '\0';
		}
		for(j = 0; j < arr[i].catnum; j++)
		{
			for(k = 1; k < arr[i].catnum; k++)
			{
				if (strcmp(arr[i].category[k - 1], arr[i].category[k]) > 0) 
				{
					char t[1000];
           			strcpy(t, arr[i].category[k - 1]);
            		strcpy(arr[i].category[k - 1], arr[i].category[k]);
            		strcpy(arr[i].category[k], t);
        		}
			}
		}
		for(j = 0; j < arr[i].catnum; j++)
		{
			strcat((arr+i)->finalCategory, "\"");
			strcat((arr+i)->finalCategory, arr[i].category[j]);
			strcat((arr+i)->finalCategory, "\"");
			if(j != (arr+i)->catnum - 1)
				strcat((arr+i)->finalCategory, ", ");
		}		
		
		POST((arr+i)->title, (arr+i)->pubdate, (arr+i)->link, (arr+i)->description, (arr+i)->finalCategory);		
	}
}
