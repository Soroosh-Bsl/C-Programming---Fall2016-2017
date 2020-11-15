#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void GET()
{
	
	CURL *curl;
  	CURLcode res;
  	FILE *file, *RSS[100000];
  	int i = 0;
  	char *text[10000];
  	char c[10], d[5];
  	
	curl = curl_easy_init();
  	if(curl)
	{
   	 	curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/news/get-urls/?phase=2");
   	 	
   	 	/*login into server by curl*/
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_BASIC);
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77");
    	
		/* fop-project.ir is maybe redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
   		/* Perform the request, res will get the return code */ 
   		file = fopen("URLS.txt", "w");
   		curl_easy_setopt( curl, CURLOPT_WRITEDATA, file) ;
   	 	res = curl_easy_perform(curl);
   	 	
   	 	/* Check for errors */ 
   	 	if(res != CURLE_OK)
   	   		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
   	   		
 	  	/* always cleanup */ 
   	 	curl_easy_cleanup(curl);
   	 	fclose(file);
   
	}
  
  	file = fopen("URLS.txt", "r");
  	for(i = 0; i < 100000; i++)
	{
		text[i] = calloc (1000, sizeof(char));
		if (fscanf(file, "%s", text[i]) != EOF)
		{
			RSS[i] = calloc(1, sizeof(FILE));
			curl = curl_easy_init();
		  	if(curl)
			{
   			 	curl_easy_setopt(curl, CURLOPT_URL, text[i]);   			
  			}
    	
			/* fop-project.ir is maybe redirected, so we tell libcurl to follow redirection */ 
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
			
   			sprintf(c , "RSS %d.txt" , i);
   			
   			/* Perform the request, res will get the return code */ 
   			RSS[i] = fopen(c, "w");
   			curl_easy_setopt( curl, CURLOPT_WRITEDATA, RSS[i]) ;
   		 	res = curl_easy_perform(curl);
   		 	
   		 	/* Check for errors */ 
   		 	if(res != CURLE_OK)
   		   		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));	
			/* always cleanup */ 
   		 	curl_easy_cleanup(curl);
			fclose(RSS[i]);
		}		
		else
		{
			break;
		}
	}
	fclose(file);
}

void GETUNK()
{
	
	CURL *curl;
  	CURLcode res;
  	FILE *file, *RSS[100000];
  	int i = 0;
  	char *text[10000];
  	char c[10], d[5];
  	
	curl = curl_easy_init();
  	if(curl)
	{
   	 	curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/news/get-urls/?phase=3");
   	 	
   	 	/*login into server by curl*/
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_BASIC);
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77");
    	
		/* fop-project.ir is maybe redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
   		/* Perform the request, res will get the return code */ 
   		file = fopen("URLSS.txt", "w");
   		curl_easy_setopt( curl, CURLOPT_WRITEDATA, file) ;
   	 	res = curl_easy_perform(curl);
   	 	
   	 	/* Check for errors */ 
   	 	if(res != CURLE_OK)
   	   		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
   	   		
 	  	/* always cleanup */ 
   	 	curl_easy_cleanup(curl);
   	 	fclose(file);
   
	}
  
  	file = fopen("URLSS.txt", "r");
  	for(i = 0; i < 100000; i++)
	{
		text[i] = calloc (1000, sizeof(char));
		if (fscanf(file, "%s", text[i]) != EOF)
		{
			RSS[i] = calloc(1, sizeof(FILE));
			curl = curl_easy_init();
		  	if(curl)
			{
   			 	curl_easy_setopt(curl, CURLOPT_URL, text[i]);   			
  			}
    	
			/* fop-project.ir is maybe redirected, so we tell libcurl to follow redirection */ 
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
			
   			sprintf(c , "RSSU %d.txt" , i);
   			
   			/* Perform the request, res will get the return code */ 
   			RSS[i] = fopen(c, "w");
   			curl_easy_setopt( curl, CURLOPT_WRITEDATA, RSS[i]) ;
   		 	res = curl_easy_perform(curl);
   		 	
   		 	/* Check for errors */ 
   		 	if(res != CURLE_OK)
   		   		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));	
			/* always cleanup */ 
   		 	curl_easy_cleanup(curl);
			fclose(RSS[i]);
		}		
		else
		{
			break;
		}
	}
	fclose(file);
}

void POST(char titleGOT[], char dateGOT[], char linkGOT[], char descriptionGOT[], char categoriesGOT[])
{
	int nsent;
	char title[500], date[500], description[150000], categorized[500], category[500], answer[150000], link[1000];
	CURL *curl;
  	CURLcode res;
  	
	strcpy(title, "\"title\" : \"");
	strcpy(link, "\"link\" : \"");
	strcpy(date, "\"date\" : \"");
	strcpy(description, "\"description\" : \"");
	strcpy(categorized, "\"categorized\" : ");
	strcpy(category, "\"categories\" : [ ");
	
	strcat(title, titleGOT);
	strcat(link, linkGOT);
	strcat(date, dateGOT);
	strcat(description, descriptionGOT);
	strcat(categorized, "false");
	strcat(category, categoriesGOT);
	strcat(category, " ]");
	
	strcat(title, " \"");
	strcat(link, " \"");
	strcat(date, " \"");
	strcat(description, " \"");
	
	strcpy(answer, "{ ");
	strcat(answer, title);
	strcat(answer, ", ");
	strcat(answer, link);
	strcat(answer, ", ");
	strcat(answer, date);
	strcat(answer, ", ");
	strcat(answer, description);
	strcat(answer, ", ");
	strcat(answer, categorized);
	strcat(answer, ", ");
	strcat(answer, category);
	strcat(answer, " }");
	
	const int len = strlen(answer);
	char Answer[len + 1];
	
	char l[50], l2[50], l3[50];
	strcpy(Answer, answer);

	curl = curl_easy_init();
  	if(curl)
	  {
	  	struct curl_slist *list = NULL;

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Answer);
  		list = curl_slist_append(list, "X-Requested-With:XMLHttpRequest");
  		list = curl_slist_append(list, "Content-Type:application/json");
  		list = curl_slist_append(list, "Accept:application/json");
  		list = curl_slist_append(list, "Authoriation:application/json");
  		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
		curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/news");
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77"); 
  			 	            
   	 	res = curl_easy_perform(curl);
   	 
   	 	if(res != CURLE_OK)
   	   		fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
   	   		
		printf("\n");
	    /* always cleanup */ 
	 	curl_easy_cleanup(curl);
	  }
	curl_global_cleanup();
}

