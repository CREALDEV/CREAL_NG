#include <stdio.h> //standard library
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <err.h>
#include <fcntl.h>
#include <mqueue.h>
#include <time.h>
#include <fcntl.h> //for file descriptor stuff
#include <stdbool.h> 
#include <math.h> //this is the standard math library for figureing out math functions	
#include <signal.h>


#define MAX_CMD_LEN 256
#define MAX_CMD_LEN_2 4096


#define MQNAME	"/CREAL_JOY_0"
#define JOY_MQNAME	"/CREAL_JOY_0"
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 


int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin


//~ #include <jansson.h> //this is jansson
//~ #include "libcudacreal.h"
//~ #include "struct_definitions.h" //struct definitions

static struct sigaction act; //main signal structure for the application, I think this is wrong -Randy 		
char tempString[256]; //this is here to just make a path for our function in order to run our parse daemon
pid_t crealPid; //this is used to grab the pid of the process
pid_t pid, sid, cpid; // this is the pid for our daemon process redundant

#include "src/include/linenoise.h"
#include "src/include/signals.h"


void completion(const char *buf, linenoiseCompletions *lc) {
  if (buf[0] == 'y') {
    
    linenoiseAddCompletion(lc, "yo");
    linenoiseAddCompletion(lc, "hello there");
    linenoiseAddCompletion(lc, "ADD");
    linenoiseAddCompletion(lc, "MOD");
    linenoiseAddCompletion(lc, "DEL");
    linenoiseAddCompletion(lc, "CPY");
    
  }
}

//using alloca was really stupid --Randy

char* runCommmand(const char *cmd) {
  
  char* outputBuffer = malloc(256); //I thought I changed this
  // not safe // now safe -Randy
  strlcpy(outputBuffer, "you entered: ",14); //out put
  strlcat(outputBuffer, cmd, MAX_CMD_LEN); //main cmd copy 
  return outputBuffer;
  
}



int main(int argc, char **argv)
{
	
	mqd_t mq, joyMq, mouseMq, vizMq;
	
	int status;
	struct mq_attr attr,attrOld;
	int i; 
	fd_set set;//crap
	struct mq_attr mqa;
	mode_t defaultMode = C_DEF_MODE; 	//this is supposed to be the default mode right here for the queue
	char tempBuffer[3];
	joyMq = mq_open(JOY_MQNAME,  O_RDONLY); //openning the bullshit
		perror("mq_open\n");
		while(1)
		{
			
				mq_receive(mq, tempBuffer, 3, NULL); 
				puts(tempBuffer); 
				usleep(1);
		}
	mq_close(mq);
	perror("mq_close\n");
		
	
	
					register int i, machineId, forkIndicator; 
					char *p;
					char* output;

					/* Right here we are initiating the application */
					
					  act.sa_sigaction = &catchinstance;
					  act.sa_flags = SA_SIGINFO;
					  sigfillset(&(act.sa_mask));

					  sigaction(SIGHUP, &act, NULL);//1
					  sigaction(SIGKILL, &act, NULL);//9
					  sigaction(SIGTERM, &act, NULL);//15
					  sigaction(SIGCHLD, &act, NULL);//17

					  act.sa_handler = SIG_IGN;
					  sigfillset(&act.sa_mask);
					  act.sa_flags = 0;
					  sigaction(SIGPIPE, &act, NULL);//13

					FILE *outputFP = NULL; //this is to actually write the file
					
					/* The stuff below is used for grabing the amount of processors on the system */
					

					



  
  
			  linenoiseSetCompletionCallback(completion);

			  while ((p = linenoise("CREAL_PROMPT > ")) != NULL) {
				linenoiseHistoryAdd(p);

				output = runCommmand(p);

				puts(output);

				//~ free(output); //now output buffwe in function allocates on stack memory
				free(p);
			  }




			return 0; 
		
		
}



