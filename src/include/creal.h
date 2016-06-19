//This file is located from within the parser directory

/* NON is used to tell the computer that no action should be taken.. 
also to fill the action array with good data */

typedef double creal_t; //the main creal datatype
typedef double creal_d; //this is the upcomming datatype right here, alwayse use a double data type for now

void quitWithError(char const *string); //this is used to quit with an error
void quitWithSuccess(char const *string); //this is used to quit with success







//This lookup table is for conditional data
creal_d (*conditionLookUpTables[7])(creal_d , creal_d ) =
{
	&wasteCpuNullAction,
	&equalTo,
	&greaterThan,
	&lesserThan,
	&greaterThanEqualTo,
	&lesserThanEqualTo,
	&notEqualTo
	
};

char const NONACTION = 0x00; //nothing a type of NULL action

char const INCREASE = 0x01; //used for addition

char const DECREASE = 0x02; //used for deletion

char const CHANGE = 0x03; //used for changing

char const MAINTAIN = 0x04; //used for maintaining

char const TRANSPORT = 0x05; //used for transporting



/*Constants for relations */

char const NONRELATION = 0x00; //nothing a type of NULL action

char const EQUAL = 0x01; //used for addition

char const GREATERTHAN = 0x02; //used for deletion

char const LESSERTHAN = 0x03; //used for changing

char const GREATERTHANEQUALTO = 0x04; //used for maintaining

char const LESSERTHANEQUALTO = 0x05; //used for transporting

char const NOTEQUAL = 0x06; //used for transporting



//These are garbage collection directives

char const HOST = 0x00; //These are used to change some garbage collection function

char const DEVICE = 0x01; //These are used to change some garbage collection function




	


//other libraries are below

//~ #include "simplePrintf/cuPrintf.cu" //including the cuda simple printf stuff

//the data structures
//~ #include "libs/data_structures.h"
//~ 
//~ //creal node structures
//~ #include "libs/creal_node_structures.h"

//the json stuff
//~ #include "libs/json_parse.h"

//cuda functions
//~ #include "libs/cuda_functions.h"






/*
void setupTest(char charArray[])
{
	
			charArray[0] = ADD;
			charArray[1] = ADD;
			charArray[2] = ADD;
			charArray[3] = ADD;
			charArray[4] = ADD;
			charArray[5] = ADD;
			
}
*/

//~ void crealTimeFunction(struct timeStructure *time)
//~ {
		//~ 
		//~ time->milliseconds = time->milliseconds + .001;
	//~ 
//~ }
//~ 
//~ 
//~ void displayCrealTime(struct timeStructure *time)
//~ {
		//~ 
		//~ printf("%f\n",time->milliseconds);
//~ 
//~ 
//~ }
//~ 


//this string is just used to brand the application...



void quitWithError(char const *string)
{
		//this is a wrapper function for quiting
		perror(string); //print the string
		puts("\n"); // add a new line
		exit(EXIT_FAILURE); //exit with failure 

}




mode_t read_umask (void) {
    mode_t mask = umask (0);
    umask (mask);
    return mask;
}


