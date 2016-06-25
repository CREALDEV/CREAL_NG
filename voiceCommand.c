//CREAL 2 - voice command 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
//~ #include "include/minclude.h" //this is in the internal build directory
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
#include <SDL/SDL.h>
#include <stdbool.h> 


//~ Paola 
#define MQNAME	"/PAOLA" //this is the name of the voice command right here 
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 


#define RECIEVE_CHAR_MAX 4096 //this should be 4095 in the calling application 

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin

char stringBuffer[RECIEVE_CHAR_MAX]; //this is the main string buffer for the application 

int main(int argc, char **argv)
{


//A lot of the beginning here is boiler plate code 
    mainGameLoopConditional = true; //this is for the main loop
	//message queue stuff
	mqd_t mq;
	int status;
	struct mq_attr attr,attrOld;
	int i; 
	fd_set set;//crap
	struct mq_attr mqa;
	mode_t defaultMode = C_DEF_MODE; 	//this is supposed to be the default mode right here for the queue
	mq = mq_open(MQNAME,  O_RDONLY , 0644, &attr); // openning the message queue right here 
		
		perror("mq_open\n");
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
	

	appPath = popen("espeak", "--stdin");

	if (appPath == NULL) {perror("could not connect to the standard output\n");} //hopefully we don't get here 

	while (mainGameLoopConditional)
	{
		//main loop right here
		usleep(1); //I'm just going to put this right here on top, I like it better than putting it on the bottom =P...
		mq_receive(mq, stringBuffer, RECIEVE_CHAR_MAX, NULL); 
		puts(stringBuffer); //this is for debugging, please comment this out Randy
	}
	
	pclose(appPath); //this will close the file descriptor


	return EXIT_SUCCESS; //gnu type 
} 


