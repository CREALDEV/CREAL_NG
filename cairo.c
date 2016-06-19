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

#include <cairo.h>
#include <gtk/gtk.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_BPP 32


int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin



//gcc example.c -o example `pkg-config --cflags --libs gtk+-3.0`

int main(int argc, char* argv[])
{

	//~ SDL_Surface *sdlsurf = SDL_CreateRGBSurface()	//this is the cairo surface right here 
	SDL_Surface *sdlsurf = SDL_CreateRGBSurface (0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0x00FF0000, 0x0000FF00,0x000000FF, 0); /* Amask */
	//^ for use with cairo 

cairo_surface_t *cairosurf = cairo_image_surface_create_for_data (
    sdlsurf->pixels,
    CAIRO_FORMAT_RGB24,
    sdlsurf->w,
    sdlsurf->h,
    sdlsurf->pitch);	
	
	return 0; //everything is fine right here
	
	
}


