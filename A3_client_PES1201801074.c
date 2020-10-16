#include<stdio.h>
#include<stdlib.h>
#include"A3_header_PES1201801074.h"

int main()
{
	int con[3];
	int is[3];
	int fs[3];

	for(int i=0;i<3;i++)
	{
		scanf("%d",&con[i]);
	}

	for(int i=0;i<3;i++)
	{
		scanf("%d",&is[i]);
	}

	for(int i=0;i<3;i++)
	{
		scanf("%d",&fs[i]);
	}

	printf("\n");
	node *tree=initialise(is,NULL);
	state *fsnode=init(con,fs);
	fill(tree,fsnode);
	print(tree,fsnode);
}
