//main include for new message queues

#ifndef _CREAL_MQUEUE_
#define _CREAL_MQUEUE_

#define MAX_INTERNAL_MSG 2048; //this is the intenal message size for the application


struct messageForQueue 
{
	
	int mtype; //the messsage type 
	char mtext[MAX_INTERNAL_MSG]; //this is the actual string used for the msg type 
};

//~ #define 
key_t mainProcessKey; //in global
int queueIdent; //identifier fd in global
struct messageForQueue *mainMessageStructure; //this is the main structure in global


#endif //_CREAL_MQUEUE_
