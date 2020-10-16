#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int a;
	int b;
	int c;
	struct node *child[6];
	struct node *parent;
}node;

typedef struct state
{
	int jug[3];
	int val[3];
}state;

state* init(int *con,int *fs);//structure stores the value of the jugs and final states of the jug
node* initialise(int *is,node *par);//initialises the nodes of the tree
static int check(node *tree,state *fs);//checks if the node's states matches the final states
static int duplicate(int *is,node *tree);//checks the tree to see if the current state has existed in the particular path before
void fill(node *tree,state *fs);//generates the tree with the paths to the solution
void print(node *tree,state *fs);//prints the total number of solutions
static void traverse(node *tree,node *soln,state *fs,int i);//prints the various paths
