/*
 * 
 *  This is the main part of the application that is used to display the video stuff 
 * 
 * 
 * */ 

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

//this stuff might not be needed 
//~ #include "SDL/SDL_opengl.h"
//~ #include "SDL/SDL_ttf.h"
//not needed

//~ #define MQNAME	"/CREAL_KEYBOARD"
//~ #define LOOPS	1000
//~ #define PRIO	10
//~ #define C_MAX_MSG 256 //this will be the max messages right here 
//~ #define C_DEF_MODE 777 //this is for default shit right here with fds 

int pid;
pid_t mainPid;


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_BPP 32

#define MQNAME	"/CREAL_VIDEO_0"
#define JOYQUEUE	"/CREAL_JOY_0"
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin


int renderQuad = 1;

int main()
{
	
	
	SDL_Surface *mainSurface = NULL;
    SDL_Surface *screen = NULL;
    
    
    mainGameLoopConditional = true; //this is for the main loop
	//message queue stuff
	mqd_t mq;
	int status;
	struct mq_attr attr,attrOld;
	int i; 
	fd_set set;//crap
	struct mq_attr mqa;
	mode_t defaultMode = C_DEF_MODE; 	//this is supposed to be the default mode right here for the queue
	
	//Analog joystick dead zone
	const int JOYSTICK_DEAD_ZONE = 8000; //taken from lazy foo's website : http://lazyfoo.net/tutorials/SDL/19_gamepads_and_joysticks/index.php
	
	mq_unlink(MQNAME); //remove the original message queue
	
	
	attr.mq_flags = 0;  
	attr.mq_curmsgs = 0;  
	attr.mq_maxmsg  = 1024;
	attr.mq_msgsize = 2; //just using an integer here
	
	
	
	mq = mq_open(MQNAME,  O_CREAT|O_RDWR , 0644, &attr); //openning the bullshit
	
	SDL_Init( SDL_INIT_EVERYTHING );
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	SDL_EnableUNICODE( SDL_TRUE ); //
	SDL_WM_SetCaption( "CREAL", NULL ); //sets the caption of the window
	mainSurface = SDL_LoadBMP( "70s.bmp" );
	//~ hello = SDL_LoadBMP( "english.bmp" );
	SDL_BlitSurface( mainSurface, NULL, screen, NULL );

    //Update Screen
    SDL_Flip( screen );

    //Pause
    SDL_Delay( 2000 );
    
	//~ hello = SDL_LoadBMP( "english.bmp" );
	SDL_BlitSurface( mainSurface, NULL, screen, NULL );

    //Update Screen
    SDL_Flip( screen );

    //Pause
    SDL_Delay( 2000 );
    
    
	//~ hello = SDL_LoadBMP( "70s.bmp" );
	//~ hello = SDL_LoadBMP( "english.bmp" );
	SDL_BlitSurface( mainSurface, NULL, screen, NULL );

    //Update Screen
    SDL_Flip( screen );

    //Pause
    SDL_Delay( 2000 );
    
	//~ hello = SDL_LoadBMP( "english.bmp" );
	SDL_BlitSurface( mainSurface, NULL, screen, NULL );

    //Update Screen
    SDL_Flip( screen );

    //Pause
    SDL_Delay( 2000 );
    
    
    SDL_FreeSurface( mainSurface );

    //Quit SDL
    SDL_Quit();

	return 0;
}
