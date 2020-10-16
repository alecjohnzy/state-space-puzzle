#include<stdio.h>
#include<stdlib.h>
#include"A3_header_PES1201801074.h"

int number_of_solutions;


state* init(int *con,int *fs)
{
	state *temp=(state*)malloc(sizeof(state));
	for(int i=0;i<3;i++)
	{
		temp->jug[i]=con[i];
		temp->val[i]=fs[i];
	}
	return temp;
}


node* initialise(int *is,node *par)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->a=is[0];
	temp->b=is[1];
	temp->c=is[2];
	temp->parent=par;
	for(int i=0;i<6;i++)
	{
		temp->child[i]=NULL;
	}
	return temp;
}


int check(node *tree,state *fs)
{
	if((tree->a==fs->val[0]) && (tree->b==fs->val[1]) && (tree->c==fs->val[2]))
		return 1;
	return 0;
}


int duplicate(int *is,node *tree)
{
	node *temp=tree;
	while(temp)
	{
		if((is[0]==temp->a) && (is[1]==temp->b) && (is[2]==temp->c))
		{
			return 1;
		}
		temp=temp->parent;
	}
	return 0;
}

void fill(node *tree,state *fs)
{
	int s;
	int is[3];
	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;

	if(is[0]>0 && is[1]!=fs->jug[1])
	{
		s=fs->jug[1]-is[1];
		if(is[0]<s)
		{
			s=is[0];
		}
		is[0]-=s;
		is[1]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[0]=initialise(is,tree);
			if(!check(tree->child[0],fs))
				fill(tree->child[0],fs);
		}
	}

	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;
	if(is[0]>0 && is[2]!=fs->jug[2])
	{
		s=fs->jug[2]-is[2];
		if(is[0]<s)
		{
			s=is[0];
		}
		is[0]-=s;
		is[2]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[1]=initialise(is,tree);
			if(!check(tree->child[1],fs))
				fill(tree->child[1],fs);
		}
	}

	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;
	if(is[1]>0 && is[0]!=fs->jug[0])
	{
		s=fs->jug[0]-is[0];
		if(is[1]<s)
		{
			s=is[1];
		}
		is[1]-=s;
		is[0]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[2]=initialise(is,tree);
			if(!check(tree->child[2],fs))
				fill(tree->child[2],fs);
		}
	}

	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;
	if(is[1]>0 && is[2]!=fs->jug[2])
	{
		s=fs->jug[2]-is[2];
		if(is[1]<s)
		{
			s=is[1];
		}
		is[1]-=s;
		is[2]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[3]=initialise(is,tree);
			if(!check(tree->child[3],fs))
				fill(tree->child[3],fs);
		}
	}

	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;
	if(is[2]>0 && is[0]!=fs->jug[0])
	{
		s=fs->jug[0]-is[0];
		if(is[2]<s)
		{
			s=is[2];
		}
		is[2]-=s;
		is[0]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[4]=initialise(is,tree);
			if(!check(tree->child[4],fs))
				fill(tree->child[4],fs);
		}
	}

	is[0]=tree->a;
	is[1]=tree->b;
	is[2]=tree->c;
	if(is[2]>0 && is[1]!=fs->jug[1])
	{
		s=fs->jug[1]-is[1];
		if(is[2]<s)
		{
			s=is[2];
		}
		is[2]-=s;
		is[1]+=s;
		if(!duplicate(is,tree))
		{
			tree->child[5]=initialise(is,tree);
			if(!check(tree->child[5],fs))
				fill(tree->child[5],fs);
		}
	}

	return;
}


void print(node *tree,state *fs)
{
	number_of_solutions = 0;
	node solution[500];
	traverse(tree,solution,fs,0);
	printf("%d\n",number_of_solutions);
}


void traverse(node *tree,node soln[],state *fs, int i)
{
	if(tree == NULL)
		return;

	node *temp=tree;
	soln[i++] = *temp;
	if((temp->a == fs->val[0]) && (temp->b == fs->val[1]) && (temp->c == fs->val[2]))
	{
		number_of_solutions++;
		for(int j=0;j<i;j++)
			printf("%d %d %d\n",soln[j].a,soln[j].b,soln[j].c);

		printf("\n");
	}
	else
	{
		for(int j=0 ; j<6 ; j++)
			traverse(tree->child[j],soln,fs,i);
	}
}
