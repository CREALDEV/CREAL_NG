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


#define AUDIO_FREQ 44100 //this is the default frequency
#define AUDIO_CHANNELS 2 //this is default audio channel, stereo
#define AUDIO_SAMPLES 4096 //this is default audio samples
#define MAX_WAV_CHANNELS 128
uint waveChannels[MAX_WAV_CHANNELS]; //these are the default wav channels

int main(int argc, char* argv[])
{


SDL_AudioSpec *desired;

desired = malloc(sizeof(SDL_AudioSpec)); //make sure to free this bullshit

desired->format = AUDIO_S16SYS; // audio system format
desired->freq = AUDIO_FREQ; //
desired->samples = AUDIO_SAMPLES; //

free(desired); //free
return 0; //ok


}



