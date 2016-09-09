#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


//~ #define M_PI 3.14159265358979323846
//~ int deltaX, deltaY; 





struct linkNode
{ 
	//this is the main node structure 
	void *payload; //this is the payload of the structure 
	struct linkNode *next, *previous, *left, *right; 
};


struct queueHead
{ 
	//this is the main head structure 
	unsigned int count; //counter variable 
	struct struct linkNode *first, *last; 
};



//~ int screenGrab[SCREEN_WIDTH][SCREEN_HEIGHT]; //just take the x values of the screen
//~ 
//~ bool compareFunction(void *a, void *b); //prototype
//~ //these are the functions for the queue right here
//~ 
//~ struct queueNode *__returnQueueFirst(struct queueHead **head);
//~ struct queueNode *__returnQueueLast(struct queueHead **head);
//~ struct queueNode *__returnQueueEnd(struct queueHead **head);
//~ struct queueNode *__returnQueueNext(struct queueHead **head);
//~ struct queueNode *__returnQueuePrev(struct queueHead **head);
//~ 


int main(int argc, char* argv[])s
{



	return 0;
}


