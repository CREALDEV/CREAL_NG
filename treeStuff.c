#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tree.h"



struct graphicNodeData 
{ 
		int innerX, innerY, outerX, outerY; //this is for screen space 
		int i, j, k,x,y; 
		int nodeId; 
		int numOfProperties; 
		SDL_Surface *nodeSurface; //the surface for the main node
		SDL_Rect box; 
		char nodeName[256]; //I am only limiting this to 256 bytes
		char fileName[2048]; 
		SPLAY_ENTRY(graphicNodeData) entry; //the entries into the binary tree
	
}; 


struct testStructure 
{
	SPLAY_ENTRY(testStructure) entry; //the entries into the binary tree
	int i, j, k,x,y; 
	char shitToType[256]; 
	void *something; 
}; 



int 
intcmp(struct testStructure *e1, struct testStructure *e2) 
{ 
	if(e1->x < e2->x)
	{
		return -1;
	}
	else if(e1->x > e2->x)
	{
		
		return 1;
	}
	else
	{
		
		return 0; 
	}
	
}; 



//this is confusing because it is a macro
SPLAY_HEAD(inittree, testStructure) head = SPLAY_INITIALIZER(&head);

SPLAY_GENERATE(inittree, testStructure, entry, intcmp);


void 
print_tree(struct testStructure *n) 
{ 
	struct testStructure *left, *right; 
 
	if (n == NULL) { 
		printf("nil"); 
		return; 
	} 
	left = SPLAY_LEFT(n, entry); 
	right = SPLAY_RIGHT(n, entry); 
	if (left == NULL && right == NULL) 
		printf("%d", n->x); 
	else { 
		printf("%d(", n->x); 
		print_tree(left); 
		printf(","); 
		print_tree(right); 
		printf(")"); 
	} 
}; 



int main(int argc, char* argv[])
{
	struct testStructure *n1, *n2, *n3, *n4; 
	//
	n1 = malloc(sizeof(struct testStructure) * 1); 
	n2 = malloc(sizeof(struct testStructure) * 1); 
	n3 = malloc(sizeof(struct testStructure) * 1); 
	n4 = malloc(sizeof(struct testStructure) * 1); 
	
	n1->x = 1;
	n2->x = 2;
	n3->x = 3;
	n4->x = 4;
	
	// // 
	SPLAY_INSERT(inittree, &head, n1); 
	SPLAY_INSERT(inittree, &head, n2); 
	SPLAY_INSERT(inittree, &head, n3); 
	SPLAY_INSERT(inittree, &head, n4); 

	print_tree(SPLAY_ROOT(&head));
	
	
	
	
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	
	return 0; 	
} 








/*
 * for (var = SPLAY_MIN(NAME, &head); var != NULL; var = nxt) { 
	nxt = SPLAY_NEXT(NAME, &head, var); 
	SPLAY_REMOVE(NAME, &head, var); 
	free(var); 
}
 * 
 * 
 * */ 
