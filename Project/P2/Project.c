#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

void detect1(char *text[], int maximum)
{
	int i = 0, j = 0, k = 0, max = 0, number[100000];
	char strMax[500], answer[600];
	for (j = 0; j < 100000; j++)
  	{
  		number[j] = 0;
  	}
  	/*checking number of repeat for each word*/
	for(j = 0; j < maximum; j++)
	{
		for(k = j; k < maximum; k++)
		{
			if(!strcmp(text[j], text[k]))
			{
				number[j] += 1;
			}
		}
	}
	/*finding the most frequent word which is less alphabetically as well*/
	max = number[0];
	strcpy(strMax, text[0]);
	for(i = 0; i < maximum; i++)
	{
		if (number[i] >= max && strcmp(text[i], strMax) < 0)
		{
			max = number[i];
			strcpy(strMax , text[i]);
		}
	}	
	
	/*saving the answer into answer just to send in the server requested format*/
	strcpy(answer, "member=1&answer=");
	strcat(answer,strMax);
	
	CURL *curl;
 	CURLcode res;
 
	/* In windows, this will init the winsock stuff */ 
  	curl_global_init(CURL_GLOBAL_ALL);
 
	/* get a curl handle */ 
  	curl = curl_easy_init();
  	if(curl)
	  {
   	 	/* First set the URL that is about to receive our POST. This URL can
   	    	just as well be a https:// URL if that is what should receive the
   	    	data. */ 
   	 	curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/phase0");
   	 	
		/*login into server by curl*/
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_BASIC);
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77");
    	
    	/* Now specify the POST data */ 
   	 	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, answer);
	 
   		/* Perform the request, res will get the return code */ 
   	 	res = curl_easy_perform(curl);
   	 	
   	 	/* Check for errors */ 
   	 	if(res != CURLE_OK)
   	   	fprintf(stderr, "curl_easy_perform() failed: %s\n",
   	           curl_easy_strerror(res));
	 	
	    /* always cleanup */ 
	 	curl_easy_cleanup(curl);
	  }
	curl_global_cleanup();
}

int detect2(char *text[], int maximum){
//  printf("Hello to detect2\n");
	int i = 0 , repeatarranger = 0 , k = 0 , counter = 0; /* repeat arranger to examine that the string is new! */
	int maxletter = 0; /* to find the most letters in a word */
	char answer[600];
	
	for(i = 0 ; i < maximum ; i++){
		if(strlen(text[i]) > maxletter){
			maxletter = strlen(text[i]);
		}
	}
	
	for(i = 0 ; i < maximum ; i++){
		if(strlen(text[i]) == maxletter){
			for(k = 0 ; k < i ; k++){
				if(strcmp(text[i] , text[k]) == 0){
					repeatarranger = 1;
					break;
				}
			}
			
			if(repeatarranger != 1){
				counter++;
			}
			repeatarranger = 0;
		}
	}
	
	/*saving the answer into answer just to send in the server requested format*/
	sprintf(answer, "member=2&answer=%d" , counter);
	
	CURL *curl;
 	CURLcode res;
 
	/* In windows, this will init the winsock stuff */ 
  	curl_global_init(CURL_GLOBAL_ALL);
 
	/* get a curl handle */ 
  	curl = curl_easy_init();
  	if(curl)
	  {
   	 	/* First set the URL that is about to receive our POST. This URL can
   	    	just as well be a https:// URL if that is what should receive the
   	    	data. */ 
   	 	curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/phase0");
   	 	
		/*login into server by curl*/
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_BASIC);
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77");
    	
    	/* Now specify the POST data */ 
   	 	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, answer);
	 
   		/* Perform the request, res will get the return code */ 
   	 	res = curl_easy_perform(curl);
   	 	
   	 	/* Check for errors */ 
   	 	if(res != CURLE_OK)
   	   	fprintf(stderr, "curl_easy_perform() failed: %s\n",
   	           curl_easy_strerror(res));
	 	
	    /* always cleanup */ 
	 	curl_easy_cleanup(curl);
	  }
	curl_global_cleanup();
}


int main()
{
	int i = 0,j = 0;
 	CURL *curl;
  	CURLcode res;
  	FILE *file;
  	char *text[100000];
  	
	curl = curl_easy_init();
  	if(curl)
	{
   	 	curl_easy_setopt(curl, CURLOPT_URL, "http://fop-project.ir/phase0");
   	 	
   	 	/*login into server by curl*/
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_BASIC);
    	curl_easy_setopt(curl, CURLOPT_USERNAME, "team36");
    	curl_easy_setopt(curl, CURLOPT_PASSWORD, "SorAsh77");
    	
		/* fop-project.ir is maybe redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
   		/* Perform the request, res will get the return code */ 
   		file = fopen("Text.txt", "w");
   		curl_easy_setopt( curl, CURLOPT_WRITEDATA, file) ;
   	 	res = curl_easy_perform(curl);
   	 	
   	 	/* Check for errors */ 
   	 	if(res != CURLE_OK)
   	   		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
   	   		
 	  	/* always cleanup */ 
   	 	curl_easy_cleanup(curl);
   	 	fclose(file);
  	}
  	file = fopen("Text.txt", "r");
  	
  	/*scanning word by word*/
	for(i = 0; i < 100000; i++)
	{
		text[i] = calloc (500, sizeof(char));
		if (fscanf(file, "%s", text[i]) != EOF)
		{
			
		}
		else
		{
			i++;
			break;
		}
	}
	fclose(file);

	detect1(text, i);
	detect2(text, i);
	
  	return 0;
}
