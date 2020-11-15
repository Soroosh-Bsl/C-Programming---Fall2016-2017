#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Clients
{
	int debt;
	char Name[50];
	char Family[50];
	int numOfComings;
	int Paid;
}Clients;

int compare (const void * a, const void * b)
{
	struct Clients *e1 = (struct Clients *)a;
	struct Clients *e2 = (struct Clients *)b;
//	printf("%d %d\n", e1->debt, e2->debt);
	if (e1->debt < e2->debt)
	{
//		printf("!");
		return -1000;
	}
	else if (e1->debt == e2->debt && e1->numOfComings >= e2->numOfComings)
		return -1000;
	else
		return 1000;
   
}

int main()
{
	Clients *clients;
	char command[100], name[100], family[100];
	int whoID = 0, receipt = 0, payment = 0, n = 0, i = 0, id = 0;
	int rank = 1;
	scanf("%d", &n);
	
	clients = malloc(100000 * sizeof(Clients));
	for (i = 0; i < n; i++)
	{
		scanf(" %s", command);		
		
		if ( strcmp(command, "register") == 0)
		{
			scanf(" %s", name);
			scanf(" %s", family);
			
			strcpy(clients[id].Name, name); 
			strcpy(clients[id].Family, family); 
			clients[id].debt = 0;
			clients[id].numOfComings = 0;
			clients[id].Paid = 0;
			id++;
		}
		
		else
		{
			scanf(" %d", &whoID);
			scanf(" %d", &receipt);
			scanf(" %d", &payment);
			
			clients[whoID].numOfComings += 1;
			clients[whoID].debt += receipt - payment;
			clients[whoID].Paid += payment;
		}
	}

	qsort (clients, id, sizeof(Clients), compare);
	
	for (i = 0; i < id; i++)
	{
		printf("%s %s %d\n", clients[i].Name, clients[i].Family, (int) (clients[i].Paid/pow(2., rank)));
		rank++;	
	}
}


