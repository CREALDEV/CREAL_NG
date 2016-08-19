#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "src/include/tree.h"
#include <err.h> 

struct graphicNodeData 
{ 
		int x,y; //coordinates
		int innerX, innerY, outerX, outerY; //this is for screen space 
		int nodeId; 
		int numOfProperties; 
		char nodeName[256]; //I am only limiting this to 256 bytes
		char fileName[2048]; 
		int connections[16]; 

}; 


struct xAndY
{
	int x, y; //just simple
	
}; 


struct gNodeY { 
	RB_ENTRY(gNodeY) entry; 
	struct graphicNodeData *gnodePointer; //pointer of the gnode data
	int i,y; 
}; 
 


struct gNodeX { 
	RB_ENTRY(gNodeX) entry; 
	RB_HEAD(gNodeYHead, gNodeY) head; 
	int i,x; 
}; 
 

 
 
int 
intcmpX(struct gNodeX *e1, struct gNodeX *e2) 
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
} 
 
 
int 
intcmpY(struct gNodeY *e1, struct gNodeY *e2) 
{ 
		if(e1->y < e2->y)
	{
		return -1;
	}
	else if(e1->y > e2->y)
	{
		
		return 1;
	}
	else
	{
		
		return 0; 
	}
	
} 
 
RB_HEAD(gNodeXHead, gNodeX) head; 
RB_GENERATE(gNodeXHead, gNodeX, entry, intcmpX) 
RB_GENERATE(gNodeYHead, gNodeY, entry, intcmpY) 
 




int addGNode();

int generateNodes(int j); 

int returnRandIntInRange(int low, int high)
{
		volatile int randomVariable;
		do
		{
			randomVariable = (rand() %  (high - low + 1 ) + low); //return this right here 
		}
		
		while ( !(randomVariable < low && randomVariable > high ));
		
		return randomVariable; 
		
}


struct graphicNodeData *findGNode(int x, int y)
{
//this is to actually find the graphical node
	
	struct gNodeX tmpXGNode;
	struct gNodeY tmpYGNode;
	
	struct gNodeX *returnXGNode;
	struct gNodeY *returnYGNode;
	
	struct graphicNodeData *returnedGraphicNodeData; //this is the actual data from the y node
	tmpXGNode.x = x; 
	tmpYGNode.y = y;
	 
	returnXGNode = RB_FIND(gNodeXHead, &head, &tmpXGNode); //this works 
	if (returnXGNode == NULL) {return NULL;} 
	
	
	//~ RB_INSERT(gNodeYHead,,); 
	returnYGNode  = RB_FIND(gNodeYHead, &(returnXGNode)->head, &tmpYGNode); //this works 

	if (returnYGNode == NULL) {return NULL;} 
	
	return returnYGNode->gnodePointer; 	//return this right here
};  

//~ int findGNodeY(struct gNodeY *e1);
 
int findGNodeX(); 
int removeGNode(); 
int moveGNode(); 

void insertGNodeInTree(int x, int y, struct graphicNodeData *GNode )
{
	
	
	volatile int internalX, internalY;
	
	struct gNodeX tmpXGNode;
	struct gNodeY tmpYGNode;
	
	struct gNodeX *returnXGNode;
	struct gNodeY *returnYGNode;
	 
	struct gNodeX *tmpXGNode = malloc(sizeof(struct gNodeX) *1 );
	struct gNodeY *tmpYGNode = malloc(sizeof(struct gNodeY) *1 );
	tmpYGNode->gnodePointer = GNode; 
	//~ GNode->x; 
	//~ GNode->y; 
	
	//~ tmpXGNode
	RB_INSERT(gNodeXHead, &head, n);
	
	

	
}
//~ findGNodeX 

//~ RB_HEAD(gNodeXHead, gNodeX) xHead;


struct graphicNodeData mainNodes[100];

int main(int argc, char* argv[])
{
	
	struct gNodeX *omg = malloc(sizeof(struct gNodeX) *1 );
	struct gNodeY *yee = malloc(sizeof(struct gNodeY) *1 );
	


//~ void 
//~ print_tree(struct node *n) 
//~ { 
	//~ 
//~ };

	//~ RB_HEAD(gNodeXHead, gNodeX) nuhead  = RB_INITIALIZER(&nuhead);
	//~ RB_INSERT(gNodeXHead, &nuhead, omg); 
	//~ SPLAY_INIT(&(omg)->yHead);
	//~ SPLAY_INSERT(xLocationHead, &xHead, omg); 
	//~ SPLAY_INSERT(xLocationHead, &xHead, omg); 
	//~ SPLAY_INSERT(xLocationHead, &xHead, omg); 
	//~ SPLAY_INSERT(xLocationHead, &xHead, omg); 
	//~ 
	//~ 
	//~ SPLAY_INSERT(yLocationHead, &(omg)->yHead, yee); 
	//~ 
	//~ print_treeX(omg);
	//~ print_treeY(yee); 
	//~ struct xLocation findKey; 
	//~ findKey.x = 3;
	//~ SPLAY_MAX(xLocationHead, &xHead); 
	//~ 
	//~ SPLAY_FIND(yLocationHead, &xHead, &findKey);
	//~ 
	//~ 
	//~ free(omg);
	//~ free(yee); 

	//~ RB_INSERT(inttree, &head, n);


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
