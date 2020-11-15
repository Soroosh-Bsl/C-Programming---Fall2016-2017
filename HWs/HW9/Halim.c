#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;

typedef struct TaStruct
{
	char Name[100];
	struct TaStruct * next;
}Ta;

Ta *head = NULL;

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

void del()
{
	head = head->next;
}

Ta* lastdel(Ta *heading)
{
	Ta *current = heading;
	if(i == 1)
	{
		printf("%s\n", head->Name);
		head = NULL;
		return;
	}
	while(current->next->next != NULL)
	{
		current = current->next;
	}
	printf("%s\n", current->next->Name);
	current->next = NULL;
	return current;
}


int main()
{
	Ta *current;
	int j = 0;
	char command[50], ID[50], LastName[50];
	int n = 0;
	
	scanf("%d", &n);
	

	for (j = 0; j < n; j++)
	{
		current = head;
		scanf(" %s", command);
		scanf(" %s", ID);
		if ( strcmp(command, "first") == 0 && strcmp(ID, "out") == 0)
		{
			printf("%s\n", head->Name);
	
			del();
			i--;
		}
		
		else if( strcmp(command, "last") == 0 && strcmp(ID, "out") == 0)
		{			
			current = lastdel(head);
			i--;
		}
		
		else
		{ 
			if(strcmp(ID, "in") == 0)
			{
				push(head, command);
				strcpy(LastName, command);
				i++;	
			}
		}
	}	
	printf("%d", i);
}


