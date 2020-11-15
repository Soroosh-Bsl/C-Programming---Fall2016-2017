#include "Project1.1.c"
#include "Project1.2.c"
#include<math.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

double bord[7][3500], andazeha[7];
char *cats[7];
int u ;

void capitals( news * arr , int newsnum){
	int i;
	int j;
	for(i = 0 ;  i < newsnum ; i++)
	{
		strlwr(arr[i].description);
		strlwr(arr[i].title);
		strlwr(arr[i].category[0]);
	} 
}

void puncremove ( news * arr , int newsnum){
	int i;
	int j;
	for(i = 0 ;  i < newsnum ; i++){
		for(j = 0 ; j < strlen(arr[i].description) ; j++){
			
			if (((arr + i)->description[j] < 97 || (arr + i)->description[j] > 122) && (arr + i)->description[j] != 32){
				(arr + i)->description[j] = ' ';
			} 
		} 
		for(j = 0 ; j < strlen(arr[i].title) ; j++){
			if (((arr + i)->title[j] < 97 || (arr + i)->title[j] > 122) && (arr + i)->title[j] != 32){
				(arr + i)->title[j] = ' ';
			} 
		} 
	}
}

// trie node
struct TrieNode
{
    struct TrieNode *children[26];
    int numOfNews[7];
    int newsNum;
    int isLeaf[7];
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 		
 		for(i = 0; i < 7; i++)
 		{
        	pNode->isLeaf[i] = 0;
        	pNode->numOfNews[i] = 0;
        	pNode->newsNum = -1;
 		}
 		
        for (i = 0; i < 26; i++)
        {
        	pNode->children[i] = NULL;	
        }
            
    }
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key, int cat, int numberOfKhabar)
{
    int level;
    int length = strlen(key);
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = key[level] - 97;
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isLeaf[cat] += 1;
    
    if (numberOfKhabar != pCrawl->newsNum)
    {
    	pCrawl->numOfNews[cat] += 1;
    	pCrawl->newsNum = numberOfKhabar;
    }
}

int searching(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return 0; 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isLeaf);
}

int searchWHOLE(struct TrieNode *root, const char *key, int cat)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isLeaf[cat]);
}

int searchNEWS(struct TrieNode *root, const char *key, int cat)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->numOfNews[cat]);
}

struct importantWords
{
	char Word[20];
	double value;
	char Category[10];
};
struct TrieNode *head = NULL;
void detectionImpWords(news* arr, int newsnum)
{
	FILE *file;
	int i = 0, j = 0, ID = 0, k = 0, q = 0, flag = 0, numberOfKhabars[7], maxCat = 0;
	char word[50], name[50];
	int z;
	int catnews[7];
	char temp[1000];
	double maxValue, value[7];
	struct TrieNode *root = getNode();

	head = root;

	for (i = 0; i < 7; i++)
	{
		cats[i] = (char*)calloc(50 , sizeof(char));
	}

	for (i = 0; i < newsnum; i++)
	{
		if (arr[i].category[0] == NULL)
			continue;

		flag = 0;
		for (j = 0; j < 7; j++)
		{
			if (strcmp((arr + i)->category[0], cats[j]) == 0)
			{
				ID = j;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			strcpy(cats[q], arr[i].category[0]);
			ID = q;
			q++;
		}
		
		sprintf(name, "NEWS %d.txt" ,i);
		file = fopen(name, "r");
		while (fscanf(file, "%s", word) != EOF)
		{
			insert(root, word, ID, i);
		}
		fclose(file);
	}

	for (i = 0; i < newsnum; i++)
	{

		if(arr[i].category[0] == NULL)
			continue;
		for (j = 0; j < 7; j++)
		{	
			if (strcmp((arr + i)->category[0], cats[j]) == 0)
				numberOfKhabars[j] += 1; 
		}
	}
	
	for(z = 0 ; z < newsnum ; z++)
	{
		if ((arr + z) -> category[0] == NULL)
			continue;
		strcpy(temp , (arr + z) -> category[0]);
		for( i = 0  ; i < 7 ; i++){
			if(strcmp(temp , cats[i]) == 0){
				catnews[i]++;
				break;
			}
		}

	}
	
	int n = 500; //evaluated number of keywords
	struct importantWords *finalwords[7];
	int reparrang = 0 , tetonewoco = 0 , conum = 0 , total = 0; // temp total news that contains the word = tetonewoco; 
	double tempvalue = 0 , a = 0;
	
	for(i = 0 ; i < 7 ; i++)
	{
		finalwords[i] = (struct importantWords *)calloc(n , sizeof(struct importantWords));
		for(j = 0 ; j < n ; j++){
			finalwords[i][j].value = 0;
		}
	}
	
	int counter[7];
	
	for(i = 0 ; i < 7 ; i++){
		counter[i] = 0;
	}
	
	for(i = 0 ; i < newsnum ; i++)
	{
		if(arr[i].category[0] == NULL)
			continue;
		sprintf(name, "NEWS %d.txt" ,i);
		file = fopen(name, "r");
		while (fscanf(file, "%s", word) != EOF)
		{
			for(k = 0 ; k < 7 ; k++){
				tetonewoco += searchNEWS(root , word , k);
				total += searchWHOLE(root, word , k);
			}
			for(k = 0 ; k < 7 ; k++){
				for(j = 0 ; j < n ; j++){
					if(strcmp(word , finalwords[k][j].Word) == 0){
						reparrang = 1;
						break;
					}
				}
			
				if(reparrang == 0){
					conum = 0;
					tempvalue = 0;
					if(tetonewoco > 2 && tetonewoco < ( (double)newsnum * 1 / 30) && strlen(word) > 3 && strlen(word) < 20){
						conum = searchNEWS(root , word , k);
						a = 0;
						if(conum)
						{
							a += ((double)conum / (double)tetonewoco) * pow(1.01 , (double)conum / (double)tetonewoco);
							a -= (1 - (double)conum / (double)tetonewoco) * pow(1.01 , (double)conum / (double)tetonewoco);
							a +=  ((double)searchWHOLE(root, word , k)) / (double)total * pow(1.002 ,  ((double)searchWHOLE(root, word , k)));
							tempvalue = a;
							a = 0;
						}
						
						int minfinalwoplace = 0;
			
						if(counter[k] >= n){
							for(j = 1 ; j < n ; j++){
								if(finalwords[k][minfinalwoplace].value > finalwords[k][j].value){
									minfinalwoplace = j;
								}
							}
					
							if(tempvalue > finalwords[k][minfinalwoplace].value){
								strcpy(finalwords[k][minfinalwoplace].Word , word);
								finalwords[k][minfinalwoplace].value = tempvalue;
							}
						}
					
						else if(counter[k] < n){
							strcpy(finalwords[k][counter[k]].Word , word);
							finalwords[k][counter[k]].value = tempvalue;
							counter[k]++;
						}
					}
					
					
				}
				
				reparrang = 0;
				tempvalue = 0;
				conum = 0;
				a = 0;

			} 
			
			total = 0;
			tetonewoco = 0;
			
		}
		fclose(file);	
	}

	for(k = 0 ; k < 7 ; k++){
		char a[50];
		sprintf(a , "Keywords %d.txt" ,k);
		file = fopen(a, "w");
		for(i = 0 ; i < n ; i++)
		{
			fprintf(file , "%s\n" , finalwords[k][i].Word);
		}
		fclose(file);
	}
}

void writeNews(news* arr, int newsnum)
{
	int i = 0;
	char name[30];
	FILE* file;
	for (i = 0; i < newsnum; i++)
	{
		sprintf(name, "NEWS %d.txt" ,i);
		file = fopen(name, "w");
		fprintf(file, "%s %s", arr[i].description, arr[i].title);
		fclose(file);
	}
}

void writeNewsUNK(news* arr, int newsnum)
{
	int i = 0;
	char name[30];
	FILE* file;
	for (i = 0; i < newsnum; i++)
	{
		sprintf(name, "NEWSUNK %d.txt" ,i);
		file = fopen(name, "w");
		fprintf(file, "%s %s\n", arr[i].description, arr[i].title);
		fclose(file);
	}
}

void bordarCat(int newsnum, news arr[], char* cats[])
{
	FILE* file, *file2;
	int i = 0, z = 0, k = 0, q = 0, j = 0, ID = 0;
	char a[30], b[30], keywords[50], checkWord[100];
	int DF, TF;
	
	for(i = 0; i < 7; i++)
	{
		for (j = 0; j < 3500; j++)
			bord[i][j] = 0;
	}
	for (j = 0; j < newsnum; j++)
	{	
		for (k = 0; k < 7; k++)
		{
			if (arr[j].category[0] != NULL && strcmp(arr[j].category[0], cats[k]) == 0)
			{
				ID = k;
				break;
			}
		}
		
		struct TrieNode* Khabar = getNode();
		sprintf(b, "NEWS %d.txt", j);
		file2 = fopen(b, "r");
		while(fscanf(file2, "%s", checkWord) != EOF)
		{
			insert(Khabar, checkWord, 0, 0);			
		}
		fclose(file2);
		q = 0;
		for(i = 0; i < 7; i++)
		{
			sprintf(a, "Keywords %d.txt", i);
			file = fopen(a, "r");
			while(fscanf(file, "%s", keywords) != EOF)
			{
				DF = 0;
				for (z = 0; z < 7; z++)
					DF += searchNEWS(head, keywords, z);
				if (searching(Khabar, keywords))
					TF = searchWHOLE(Khabar, keywords, 0);
				else
					TF = 0;					
				bord[ID][q] += (double)TF * (log( (double) DF)/(double) newsnum);
				q++;
			}
			fclose(file);
			
		}
	}
		
	for ( i =0; i < 7;  i++)
	{
		for (j = 0; j < 3500; j++)
		{
			andazeha[i] += pow(bord[i][j], 2.);
		}
		andazeha[i] = sqrt(andazeha[i]); 
	}
}
			
void detectCAT(int newsnum, news brr[], char* cats[], double andazz[])
{
	FILE* file, *file2;
	int i = 0, z = 0, k = 0, q = 0, j = 0, t = 0, c = 0, indexCat, havij = 0;
	char a[30], b[30], keywords[50], checkWord[100];
	int DF, TF;
	double tempBord[3500], andaze = 0., evaluate[7], max = 0.;
	for (j = 0; j < newsnum; j++)
	{			
		for (c = 0; c < 3500; c++)
		{
			tempBord[c] = 0.;
		}
		struct TrieNode* Khabar = getNode();
		sprintf(b, "NEWSUNK %d.txt", j);
		file2 = fopen(b, "r");
		while(fscanf(file2, "%s", checkWord) != EOF)
		{
			insert(Khabar, checkWord, 0, 0);			
		}
		fclose(file2);
		q = 0;
		for(i = 0; i < 7; i++)
		{
			sprintf(a, "Keywords %d.txt", i);
			file = fopen(a, "r");
			while(fscanf(file, "%s", keywords) != EOF)
			{
				DF = 0;
				for (z = 0; z < 7; z++)
					DF += searchNEWS(head, keywords, z);
				if (searching(Khabar, keywords))
					TF = searchWHOLE(Khabar, keywords, 0);
				else
					TF = 0;					
				tempBord[q] = (double)TF * (log( (double) DF)/(double) newsnum); 
				q++;
			}
			fclose(file);

		}
		andaze = 0.;
		for (c = 0; c < 3500; c++)
		{
			if (tempBord[c] != 0.)
			{
				andaze += pow(tempBord[c], 2.);
			}
		}
		
		andaze = sqrt(andaze);			
		for (t = 0; t < 7; t++)
		{
			evaluate[t] = 0;
			for ( c = 0; c < 3500; c++)
			{
				evaluate[t] += bord[t][c]*tempBord[c];
			}
			evaluate[t] /= (andaze * andazz[t]);
		}
		
		max = evaluate[0];
		indexCat = 0;
		for (t = 1; t < 7; t++)
		{
			if (evaluate[t] > max)
			{
					max = evaluate[t];
					indexCat = t;
			}
		}
		strcpy(brr[j].category[0], cats[indexCat]);
		strcpy(brr[j].finalCategory, "\"");
		strcat(brr[j].finalCategory, brr[j].category[0]);
		brr[j].finalCategory[strlen(brr[j].finalCategory) - 1] = '"';
		
//		printf("j = %d\n%s\n", j, brr[j].finalCategory);
		
		

	}
//	printf("%d", u);
}

char * spaceremove(char * input){
	int i;
	for(i = 0 ; i < strlen(input) ; i++){
		if(input[i] == ' ' && input[i + 1] == ' '){
			strcpy(input + i , input + i + 1);
			i--;
		}
	}
	return input;
}

