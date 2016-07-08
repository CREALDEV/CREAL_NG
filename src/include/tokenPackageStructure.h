/*
 * Created by Randy White
 */

#ifndef _TOKEN_PACKAGE_
#define _TOKEN_PACKAGE_

#include "queue.h" //I'm lazy, just plopping this in the directory
#include "tree.h" //I'm lazy, just plopping this in the directory

#define HELL_MAX 2048 /* This is temporary, it probably needs to be expanded */
#define TOKEN_ARRAY_MAX 2048 /* This is temporary, it probably needs to be expanded */

	union pload {
	/* These are the variables associated with the payloads
	At the moment there are only strings, float matrices, a long double and long long int	
	 */
	char stringP[TOKEN_ARRAY_MAX];
	//~ float floatP[HELL_MAX][HELL_MAX]; //this right here is too much for the message queues
	long long int intP;	
	long double doubleP;	
	
	};


struct tokenPackage 
{

	//these are actually the tokens now
	int index, typeId,fileDescriptor;
	/* Index of the package, the type of package processing needed and 
	file descriptor for various types of processing */
	  
	pid_t processId; 
	/* The process id for package, so we can track */ 
	FILE *filePointer; /* The main file pointer which is C standard */
	char filePathString[TOKEN_ARRAY_MAX];/* The main file path string */
	union pload payload;

	//~ struct tokenPackage *left, *right, *next; //these are used for linked lists //deprecated 

	SIMPLEQ_ENTRY(tokenPackage) links; //I guess set up the queue here //this is just using the system macros right here 

};



	struct tokenPackageQueue_t {

		SIMPLEQ_HEAD(tokenPackageQueue, tokenPackage) package;
		//this is the container right here for the queue 
	};


/* This was awesome
 * Using internal queue stuff now */
#endif _TOKEN_PACKAGE_



