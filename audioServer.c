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


#define AUDIO_FREQ 44100 //this is the default frequency
#define AUDIO_CHANNELS 2 //this is default audio channel, stereo
#define AUDIO_SAMPLES 4096 //this is default audio samples
#define MAX_WAV_CHANNELS 128
uint waveChannels[MAX_WAV_CHANNELS]; //these are the default wav channels



#define MQNAME_VOICE	"/PAOLA" //this is the name of the voice command right here 
#define MQNAME	"/AUDIO" //this is the name of the voice command right here 
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 


#define RECIEVE_CHAR_MAX 4098 //This has to be 1 less than 4096 in order to make sure it sends properly 

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin


int main(int argc, char* argv[])
{


//for this application we have to start the initializing SDL2 for its audio.
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0) //
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

SDL_AudioSpec *desired;

desired = malloc(sizeof(SDL_AudioSpec)); //make sure to free this bullshit

desired->format = AUDIO_S16SYS; // audio system format
desired->freq = AUDIO_FREQ; //
desired->samples = AUDIO_SAMPLES; //
//this is where the loop goes right here 



free(desired); //free
return 0; //ok


}



