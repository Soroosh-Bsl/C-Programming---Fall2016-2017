#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

int whiled = 0;
// trie node
struct TrieNode
{
    struct TrieNode *children[26];
    int repeats;
    int isLeaf;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isLeaf = 0;
 		pNode->repeats = 0;
        for (i = 0; i < 26; i++)
        {
        	pNode->children[i] = NULL;	
        }
            
    }
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
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
 		pCrawl->children[index]->repeats += 1;
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isLeaf += 1;
}
 
// Returns true if key presents in trie, else false
int search(struct TrieNode *root, const char *key)
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

int searchREP(struct TrieNode *root, const char *key)
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
 
    return (pCrawl->isLeaf);
}

//int repeats(struct TrieNode *root, const char *key)
//{
//    int level;
//    int length = strlen(key);
//    int index;
//    int number = 0;
// 
//	while (1)
//	{ 
//		whiled += 1;
//    	struct TrieNode *pCrawl = root;
//    	for (level = 0; level < length; level++)
//    	{
//        	index = CHAR_TO_INDEX(key[level]);        
//			if (pCrawl->children[index]->repeats > 0)
//			{
//				pCrawl->children[index]->repeats -= 1;
//				pCrawl = pCrawl->children[index];
//			}
//				
//			else
//			{
//				whiled -= 1;
//				return number;
//			}
//		}
//		number += 1;
//    }
//}
//
//void recover(struct TrieNode *root, const char *key)
//{
//	int level;
//    int length = strlen(key);
//    int index, i;
//	for (i = 0; i < whiled; i++)
//	{
//		struct TrieNode *pCrawl = root;
//		for (level = 0; level < length; level++)
//    	{
//        	index = CHAR_TO_INDEX(key[level]);        
//			pCrawl->children[index]->repeats += 1;
//			pCrawl = pCrawl->children[index];
//		}		
//	}
//}
 
// Driver
int main()
{
	int n = 0;
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[1000]; 
 
    struct TrieNode *root = getNode();
 
 	scanf("%d", &n);
 	
    // Construct trie
    int i;
    
    for (i = 0; i < n; i++)
    {
    	scanf("%s", keys);
    	insert(root, keys);
    }
        
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
    {
    	scanf("%s", keys);
    	if (search(root, keys))
    	{
    		printf("%d\n", searchREP(root, keys));
    	}
    	else
    	{
    		printf("0\n");
    	}
    }
 
    return 0;
}

