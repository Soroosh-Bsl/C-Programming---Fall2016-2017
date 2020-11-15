#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0, flag = 0, p = 0,flag2 = 0;
char call[100];


typedef struct TaStruct
{
	char Name[100];
	struct TaStruct * next;
}Ta;

Ta *head = NULL;

void printList(Ta *head) 
{
	int j =0;
    Ta * current = head;
    for (j = 0; j <= i; j++)
	{
        printf("%s\n", current->Name);
        current = current->next;
    }
}

void push(Ta * heading, char name[])
 {
    Ta * current = heading;
    if (current == NULL)
    {
    	head = (Ta *)malloc(sizeof(Ta));
    	head->next = NULL;
    	strcpy(head->Name, name);
    	return;
    }
    while (current->next != NULL)
	{
        current = current->next;
    }
    current->next = (Ta *)malloc(sizeof(Ta));
    strcpy(current->next->Name, name);
    current->next->next = NULL;
}

void del(Ta * heading, char name[])
{
	Ta * current = heading;
	if (strcmp(head->Name, name) == 0)
	{
		head = head->next;
	}
	else
	{
		while(strcmp(current->next->Name, name) != 0)
		{
			current = current->next;
		}
		if (current->next->next != NULL)
			current->next = current->next->next;
		else
			current->next = NULL;	
	}
}

void printAfter(Ta * head, char name[])
{
	Ta * current = head;
	while(strcmp(current->Name, name) != 0)
	{
		current = current->next;
	}	
	if (current->next != NULL)
		printf("%s\n", current->next->Name);
	else
		printf("%s is the last TA.\n", name);
}

void printBefore(Ta * head, char name[])
{
	Ta * current = head;
	if (strcmp(head->Name , name) == 0)
		printf("%s is the first TA.\n", name);
	else
	{
		while(strcmp(current->next->Name, name) != 0)
		{
			current = current->next;
		}	
		printf("%s\n", current->Name);
	}
}

void reverse(char name1[], char name2[])
{
	Ta *nextCurrent = NULL, *currCurrent = NULL, *find = head, *current = head , *copy = NULL, *findP = NULL, *curr = NULL;
	int counter = 0;
	int i = 0; 
	if (strcmp(name1, name2) == 0)
		return;
	if (strcmp(head->Name, name1) == 0)
	{
		char naming[100];
		strcpy(naming,head->next->Name);
		if (strcmp(naming, name2) != 0)
			reverse(naming, name2);
		curr = head->next;		
		while (strcmp(current->Name, naming) != 0)
		{
		current = current->next;
		}
		head->next = current->next;
		current->next = head;
		head = curr;
		return;
	}
	while (strcmp(current->next->Name, name1) != 0)
	{
		current = current->next;
	}
	if (flag2 == 0)
	{
		flag2 = 1;
		findP = current->next;
		while (strcmp(findP->Name, name2) != 0)
		{
			p++;
			findP = findP->next;
		}
		p--;
	}
	copy = current->next;
	strcpy(call, copy->next->Name);
	while (strcmp(find->Name, name2) != 0)
	{
		find = find->next;
	}

	while (current->next!= find->next)
	{
		nextCurrent = current->next->next->next;
		currCurrent = current->next->next;
		current->next->next->next = current->next;
 	    current->next->next = nextCurrent;
 	    current->next = currCurrent;
 	    current = current->next;
	}	
	if (flag == 0)
	{
		flag = 1;
		for(counter = 0; counter < p; counter++)
		{
			reverse(call, find->Name);
		}
	}

}



int main()
{
	Ta *current;
	head = (Ta *)malloc(sizeof(Ta));
		
	char command[100], ID[100], ID2[100];
	int n = 0;
	
	scanf("%d", &n);
		
	if (n != 0)
	{
	
	current = head;
	for (i = 0; i < n; i++)
	{
		scanf("%s", current->Name);
		if (i != n -1)
		{
			current->next = malloc(sizeof(Ta));
			current->next->next = NULL;
			current = current->next;
		}
		else
		{
			current->next = NULL;
		}
	}	
	i--;
	}

	
	else
	{
		head = NULL;
		i--;
	}
	
	scanf("%s", command);
	
	while (strcmp(command, "end") != 0)
	{
		if (strcmp (command, "woe") == 0)
		{
			scanf("%s", ID);
			scanf(" %s", ID2);
			printList(head);
		}
		
		
		else
		{
			if (strcmp(command, "add") == 0)
			{
				scanf(" %s", ID);
				push(head, ID);
				i++;
			}
			
			else if(strcmp(command, "dabbe") == 0)
			{
				scanf(" %s", ID);
				del(head, ID);	
				i--;

			}
			
			else if(strcmp(command, "after") == 0)
			{
				scanf(" %s", ID);
				printAfter(head, ID);
			}
			
			else if(strcmp(command, "before") == 0)
			{
				scanf(" %s", ID);
				printBefore(head, ID);
			}
			
			else if(strcmp(command, "reverse") == 0)
			{
				scanf(" %s", ID);
				scanf(" %s", ID2);
				reverse(ID, ID2);
				flag = 0;
				flag2 = 0;
				p = 0;
			}
		}
		scanf(" %s", command);
	}
}

