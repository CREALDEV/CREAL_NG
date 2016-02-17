/*
 *
 */

#ifndef _TOKEN_PACKAGE_
#define _TOKEN_PACKAGE_

#define TMP_MAX 2048 /* This is temporary, it probably needs to be expanded */

struct tokenPackage 
{

	 
	int index, typeId,fileDescriptor;
	/* Index of the package, the type of package processing needed and 
	file descriptor for various types of processing */
	  
	pid_t processId; 
	/* The process id for package, so we can track */ 
	FILE *filePointer; /* The main file pointer which is C standard */
	char filePathString[TMP_MAX];/* The main file path string */

	union payload {
	/* These are the variables associated with the payloads
	At the moment there are only strings, float matrices, a long double and long long int	
	 */
	char stringP[TMP_MAX];
	float floatP[TMP_MAX][TMP_MAX];
	long long int intP;	
	long double doubleP;	
	
	};

struct tokenPackage *left, *right, *next; //these are used for linked lists
};

/* This was awesome */
#endif _TOKEN_PACKAGE_
