#include "Project1.3.c"


int main()
{
	int i = 0;
//	GET();
//	space();
//	replacehttp();
//	replacehtmlsymbols();
//	replacequ();
	
	news *arr = (news *)calloc(100000 , sizeof(news));
	int newsnum = newsclassify(arr);
	capitals(arr, newsnum);
	puncremove( arr , newsnum);
	
//	printf("%s\n", arr[0].category[0]);
	writeNews(arr, newsnum);
	detectionImpWords(arr, newsnum);		
	bordarCat(newsnum, arr, cats);
//	printf("UUUUU = %lf KKKK = %lf", bord[0][2], bord[0][60]);
	
//	GETUNK();
//	spaceUNK();
//	replacehttpUNK();
//	replacehtmlsymbolsUNK();
//	replacequUNK();
	news *brr = (news *)malloc(100* sizeof(news));
	int Unewsnum = newsclassifyUNK(brr);
	capitals(brr, Unewsnum);
	puncremove(brr , Unewsnum);
	
	writeNewsUNK(brr, Unewsnum);
	detectCAT(Unewsnum, brr, cats, andazeha);
	
	for (i = 0; i < Unewsnum; i++)
	{
		printf("category : %s\n", spaceremove( (brr+i)->finalCategory) );
		printf("title : %s\n", spaceremove( (brr+i)->title ) );
		printf("description : %s\n", spaceremove( (brr+i)->description) );
		printf("link : %s\n", spaceremove( (brr+i)->link) );
		printf("pubdate : %s\n", spaceremove( (brr+i)->pubdate) );
		POST((brr+i)->title, (brr+i)->pubdate, (brr+i)->link, (brr+i)->description, (brr+i)->finalCategory);
	}
}
