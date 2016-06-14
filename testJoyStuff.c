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



//created by Trevor Chan, and modified by Randy White

//Ripped from man page
#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
               do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define MQNAME	"/CREAL_JOY_0"
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 


int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin


int main()
{
		mqd_t mq;
	int status;
	struct mq_attr attr,attrOld;
	int i; 
	fd_set set;//crap
	struct mq_attr mqa;
	mode_t defaultMode = C_DEF_MODE; 	//this is supposed to be the default mode right here for the queue
	char tempBuffer[3];
	mq = mq_open(MQNAME,  O_RDONLY); //openning the bullshit
		perror("mq_open\n");
		while(1)
		{
			
				mq_receive(mq, tempBuffer, 3, NULL); 
				puts(tempBuffer); 
				usleep(1);
		}
	mq_close(mq);
	perror("mq_close\n");
		
}


