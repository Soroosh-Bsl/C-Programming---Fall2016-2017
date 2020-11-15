#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numberOFTowels = 0, numberOFTechs = 0 ,ID = 0, ID2 = 0, i = 0, temp = 0;
	char command[20], cm[5], garbage[10];
	int towel[1500];
	int tech[1500];
	
	for (i = 0; i < 1500; i++)
	{
		tech[i] = -1;
		towel[i] = 0;
	}
	
	gets(garbage);
	gets(command);
	ID = atoi(command);
	
	while (ID != 0)
	{
		for (i = 0; i < 20; i++)
		{			
			if (command[i] == ' ')
			{
				
				
				if (command[i + 1] == 't')
				{
					for (i += 1; i < 20; i++)
					{
						if (command[i] == ' ')
						{
							strcpy(cm, command + i + 1);
							ID2 = atoi(cm);
						}
					}
					tech[ID] = ID2;
				}
				
				
				
				else if (command[i + 1] == 'g')
				{
					if (tech[ID] == -1)
						printf("no towel has been assigned to me.\n");
					else
					{	
						temp = tech[ID];
						if (towel[temp] == 0)
						{
							printf("ok\n");
							towel[temp] = 10;
						}
						else
						{
							printf("impossible\n");
						}
					}	
				}
				
				
				
				else if (command[i + 1] == 'd')
				{
					for (i += 1; i < 20; i++)
					{
						if (command[i] == ' ')
						{
							strcpy(cm, command + i + 1);
							ID2 = atoi(cm);
						}
					}
										
					if (tech[ID] == -1)
						printf("no towel has been assigned to me.\n");
						
					else
					{
						temp = tech[ID];
						towel[temp] -= ID2;
						
						if (towel[temp] < 0)
							towel[temp] = 0;
					}
					
				}
				
				
				
				else if (command[i + 1] == 'o')
				{
					temp = tech[ID];
					if (tech[ID] == -1)
						printf("no towel has been assigned to me.\n");
					else
						printf("%d\n", towel[temp]);
				}
				
				break;
				
			}
		}
		gets(command);
		ID = atoi(command);	
	}
	
}

