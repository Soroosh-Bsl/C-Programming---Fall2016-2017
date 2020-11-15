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
