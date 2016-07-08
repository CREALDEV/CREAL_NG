//changed for CREAL2 
#ifndef _CREAL_DEFINES_
#define _CREAL_DEFINES_


/* These macros were copied verbatim from an earlier version of the creal parser */
#define SHARED_MEM_DIR_PATH "/dev/shm/creal/" //this is used to create a folder in order to facilitate multiprocessing.
#define SHARED_MEM_FILE "/dev/shm/creal/phpSHMcore0" //this is used to create a folder in order to facilitate multiprocessing.
#define PATH "/dev/shm/core" //this is used for the named pipe..
#define DEFAULT_THREAD_COUNT 4 //this is used to determine the default thread count of the application- unless there is a over ride
#define MAX_THREADS 16 //this is just put in for measure
#define ERROR_FILE "/dev/shm/php_pipe_errors" //this is used to look at the errors of the php stuff

/* These were added to facilitate pipe IPC, for expression parsing */
#define PIPE_IN_FILE "/dev/shm/crealPipeInput"
#define PIPE_OUT_FILE "/dev/shm/crealPipeOutput"
#define MAX_PIPE_SIZE 2048

//~ #include "libs/json_parse.h"

#define USAGE "Cerebro, the maker of Creal version .07\n first argument json file, second argument output c file" //this is the usage of the program

#define CREAL_FILE_NAME "creal_ng.bin" //the name of the binary

#define CREAL_INCLUDE_FILE_NAME "creal_ng.h" //the name of the include file

#define CREAL_MAIN_CSOURCE_FILE_NAME "creal_ng.c" //this is the name of the main source file

/* This right here are the headers for the Creal_NG binary*/
#define CREAL_HEADERS "#include <stdio.h> \n#include <stdlib.h> \n#include <errno.h> \n#include <unistd.h> \n#include <string.h> \n#include <sys/types.h> \n#include <sys/stat.h> \n#include <time.h> \n#include <fcntl.h> \n#include <math.h> \n#include <pthread.h> \n#include <omp.h>" 

#define MAIN_PART "int main(int argc, char **argv) \n {" //this is actually the beginning of the main function of the application

#define END_PART "\n \n \n \
		\
exit(EXIT_SUCCESS);	\n}" //this is the end of the application

/* names of the structures*/
#define NAME_CREAL_NODE_STRUCTURE "crealNodes" //this is the name of the main creal node array of structures

#define NAME_CREAL_PROP_STRUCTURE "crealProperties" //this is the name of the main creal properties array of structures

#define NAME_CREAL_ACT_STRUCTURE "crealActions" //this is the name of the main creal node array of structures


/* These are used to pad the structures */

#define ACTION_AND_CONDITION_PAD 80 //these are used to add an extra amount of action, and conditions to the nodes

#define ACTIONLIST_PAD 15 //pad the action lists

#define PROPERTY_PAD 205 //pad the properties

#define CREAL_NODE_PAD 105 //pad the nodes

#define INDEX_PAD 201 //this is a pad for the index of the nodes 

//these are defined functions for handling errors

#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
               do { perror(msg); exit(EXIT_FAILURE); } while (0)


#endif
