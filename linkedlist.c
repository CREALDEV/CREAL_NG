#include <stdio.h>
#include <stdlib.h>



struct linkNode
{
			void *data; //this is a voided pointer to something
			struct linkNode *next, *previous, *left, *right; //this a pointer to the next element in the list
			
};



struct queueHead
{
	
int count; 

struct linkNode *head, *tail;

	
};



struct stackHead
{
	
int count; 

struct linkNode *top, *bottom;

	
};




struct treeHead
{
	
int count; 

struct linkNode *root, *bottom;

	
};



int linkNodeFindFromTop(void);
int linkNodeFindFromBottom(void);
int linkNodeInsertBefore(int count);
int linkNodeInsertAfterCount(int count);
int linkeNodeAddNodeForward(void); 
int linkeNodeAddNodeReverse(void); 
int linkNodeSetNull(void);
int linkNodeInit(void);

int queueEnqueueHead(struct queueHead *head, struct linkNode *node)
{
	
	
}



struct linkNode *linkNodeInit(void *element)
{
	//this function is used to insantiate and return a node
	struct linkNode *tmpNode = (void *) malloc(sizeof(struct linkNode) * 1); 
	
	if (!(tmpNode))
	{		
		return NULL; //return null just in case 	
	}
	
	
	tmpNode->next = tmpNode->previous = tmpNode->left = tmpNode->right = NULL; 
	
	tmpNode->data = element; 
	
	return tmpNode; 
	
}


int linkNodeAddNodeForward(struct linkNode *targetNode, struct linkNode *selectedNode)
{
	
	if (targetNode->next != NULL) 
	{
		selectedNode->next = targetNode->next; 
		targetNode->next = selectedNode; 
		
	}
	else
	{
		
		targetNode->next = selectedNode; 
	}
	
		selectedNode->previous = targetNode; 
	//if
	
	
}



int linkeNodeAddNodeReverse(struct linkNode *targetNode, struct linkNode *selectedNode)
{
	
	if (targetNode->next != NULL) 
	{
		selectedNode->previous = targetNode->previous; 
		targetNode->previous = selectedNode; 
		
	}
	else
	{
		
		targetNode->previous = selectedNode; 
	}
	
		selectedNode->next = targetNode; 
	//if
	
	
}

