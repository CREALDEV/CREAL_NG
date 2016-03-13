
#include <stdio.h> //standard library
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h> //for file descriptor stuff
#include <stdbool.h> 
#include <math.h> //this is the standard math library for figureing out math functions	
#include <signal.h>
#define MAX_CMD_LEN 256
#define MAX_CMD_LEN_2 4096



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
  }
}

// THIS IS GREAT SHIT!! - RANDY, LOOK UP ALLOCA!! bwahahaha!
// this function will return a char which will be printed to stdout
// this is not the best solution but having a function that interperts and runs
// all user input will be a simple solution

char* runCommmand(const char *cmd) {
  
  char* outputBuffer = alloca(256);
  // not safe // now safe -Randy
  strlcpy(outputBuffer, "you entered: ",14); //out put
  strlcat(outputBuffer, cmd, MAX_CMD_LEN); //main cmd copy 
  return outputBuffer;
  
}



int main(int argc, char **argv)
{
	
	
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

