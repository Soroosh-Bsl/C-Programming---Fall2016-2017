#include "Project1.1.c"
#include "Project1.2.c"
#include<math.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

char *cats[7];

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
	
	int n = 300; //evaluated number of keywords
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
					if(tetonewoco > 2 && tetonewoco < ( (double)newsnum * 1 / 20) && strlen(word) > 3){
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
			fprintf(file , "%s %.10lf\n" , finalwords[k][i].Word, finalwords[k][i].value);
			printf("%s : %s : %.10lf\n",cats[k] ,finalwords[k][i].Word , finalwords[k][i].value);
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

int main()
{
	GET();
	space();
	replacehttp();
	replacehtmlsymbols();
	replacequ();
	
	news *arr = (news *)calloc(100000 , sizeof(news));
	int newsnum = newsclassify(arr);
	capitals(arr, newsnum);
	puncremove( arr , newsnum);
	
	writeNews(arr, newsnum);
	detectionImpWords(arr, newsnum);		
}
