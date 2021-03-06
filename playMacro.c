//CREAL 2 - audio server command 
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
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <stdbool.h> 



//these are the standard for the message queues 
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 

//there has to be an MQNAME defined for this to work

#define GENERATE_MQ				\
	mqd_t mq;	\
	int status;	\
	struct mq_attr attr,attrOld;	\
	int i;	\
	fd_set set;	\
	struct mq_attr mqa;	\
	mode_t defaultMode = C_DEF_MODE;	\	

//this is for setting the message size, max, and unlinking the name
#define SET_MSG_SIZE_AND_MAX_MQ(size, max, name) do {					\
	mq_unlink(name);	\
	attr.mq_flags = 0;	\
	attr.mq_curmsgs = 0;	\ 
	attr.mq_maxmsg  = max;	\
	attr.mq_msgsize = size;	\
} while (0)


//this function is used to open a message queue
#define OPEN_RW_AND_SET(name) do {					\
		mq = mq_open(name,  O_CREAT|O_RDWR , 0644, &attr);	\
		mq_setattr(mq,&attr,NULL);	\
} while (0)


//~ #define LIST_REMOVE(elm, field) do {					\
	//~ if ((elm)->field.le_next != NULL)				\
		//~ (elm)->field.le_next->field.le_prev =			\
		    //~ (elm)->field.le_prev;				\
	//~ *(elm)->field.le_prev = (elm)->field.le_next;			\
	//~ _Q_INVALIDATE((elm)->field.le_prev);				\
	//~ _Q_INVALIDATE((elm)->field.le_next);				\
//~ } while (0)



int main()
{
	GENERATE_MQ; //use this macro right here 
	SET_MSG_SIZE_AND_MAX_MQ(2,2,"/joypad"); //set all the variables
	OPEN_RW_AND_SET("/joypad")
	return 0;	
}



