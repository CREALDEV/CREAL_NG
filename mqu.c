#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <err.h>
#include <fcntl.h>
#include <mqueue.h>
#include <signal.h>
#include <string.h>


//Ripped from man page
#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
               do { perror(msg); exit(EXIT_FAILURE); } while (0)


#define MQNAME	"/mytstqueue3"
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 

int pid;
pid_t mainPid;



/*
 * Created by Randy White
 */

#ifndef _TOKEN_PACKAGE_
#define _TOKEN_PACKAGE_

#include "queue.h" //I'm lazy, just plopping this in the directory
#include "tree.h" //I'm lazy, just plopping this in the directory

#define HELL_MAX 2048 /* This is temporary, it probably needs to be expanded */

	union pload {
	/* These are the variables associated with the payloads
	At the moment there are only strings, float matrices, a long double and long long int	
	 */
	char stringP[HELL_MAX];
	//~ float floatP[HELL_MAX][HELL_MAX];
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
	char filePathString[HELL_MAX];/* The main file path string */
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



	
enum CREAL_JOY_STATES {
	//these are just enumerated states in order to process joystick events.
	JOY_UP,
	JOY_DOWN,
	JOY_LEFT,
	JOY_RIGHT,
	JOY_UP_LEFT,
	JOY_UP_RIGHT,
	JOY_DOWN_LEFT,
	JOY_DOWN_RIGHT,
	JOY_BUTTON_0,
	JOY_BUTTON_1,
	JOY_BUTTON_2,
	JOY_BUTTON_3,
	JOY_BUTTON_4,
	JOY_BUTTON_5,
	JOY_BUTTON_6,
	JOY_BUTTON_7,
	JOY_BUTTON_8,
	JOY_BUTTON_9 ,
	JOY_BUTTON_10,
	JOY_BUTTON_11,
	JOY_BUTTON_12
		
};

	
	
enum MESSAGE_PRIORITY {
	//this will probably need to be redone right here
	LOWEST = 0,
	BELOW_NORMAL,
	NORMAL,
	ABOVE_NORMAL,
	HIGHEST
};

int main(int argc, char **argv)
{
	//add something here to help out with the queues
	
	mq_unlink(MQNAME); //remove the original message queue

	char tempBuffer[HELL_MAX]; //this is just a temporary buffer right here

	mqd_t mq;
	int status;
	struct mq_attr attr,attrOld;

	fd_set set;

	struct mq_attr mqa;
	mode_t defaultMode = C_DEF_MODE; 	//this is supposed to be the default mode right here for the queue


	attr.mq_maxmsg  = 10;
	attr.mq_msgsize = sizeof(struct tokenPackage); //I'm just going to put 128 characters right here for this test //this is just a hack right here 
	mq_setattr(mq,&attr,NULL); //I think this is fine right here
	perror("set attr\n");
	attr.mq_flags = 0;  
	attr.mq_curmsgs = 0;  
	printf("Size of structure entirely : %d \n", sizeof(struct tokenPackage));
	printf("Size of structure entirely : %d \n", sizeof(int));
	
	mq = mq_open(MQNAME, O_CREAT|O_RDWR, 0644, &attr);
			
		if (mq == (mqd_t)-1)
		{ 
		//interesting to cast this type over -1
			perror("mq_open\n");
			return -1;
		}
			
		status = mq_getattr(mq, &attr);
		
		if (status)
		{
			perror("mq_getattr()");
			return -1; 
		}

		puts(tempBuffer);
	//sending shit right here 
	
	
	
	mq_send(mq, "some message", strlen("some message")+1, 1); 
	perror("sending\n");
	mq_receive(mq, tempBuffer, 4144, NULL); 
	perror("receiving\n");
	puts(tempBuffer);
	mq_close(mq); //close the file descriptor
		return 0;
}





//O_CREAT

//~ mq = mq_open(MQNAME, O_CREAT | O_RDWR | O_EXCL, 0666, &attr);
//~ mqd_t mainQ = 	mq_open("pit",O_RDWR | O_CREAT, defaultMode, NULL);
//~ mqd_t mainQ = 	mq_open(MQNAME, O_RDWR, NULL);
 //~ mq_send(mqd_t mqdes, const char *msg_ptr,
                     //~ size_t msg_len, unsigned int msg_prio);
