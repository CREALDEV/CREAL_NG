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
#include <unistd.h>      /* pause() */
#include <xcb/xcb.h>

int main(int argc, char **argv)
{
	
	
	


  xcb_connection_t *c;
  xcb_screen_t     *screen;
  xcb_window_t      win;

  /* Open the connection to the X server */
  c = xcb_connect (NULL, NULL);

  /* Get the first screen */
  screen = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

  /* Ask for our window's Id */
  win = xcb_generate_id(c);

  /* Create the window */
  xcb_create_window (c,                             /* Connection          */
                     XCB_COPY_FROM_PARENT,          /* depth (same as root)*/
                     win,                           /* window Id           */
                     screen->root,                  /* parent window       */
                     0, 0,                          /* x, y                */
                     150, 150,                      /* width, height       */
                     10,                            /* border_width        */
                     XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
                     screen->root_visual,           /* visual              */
                     0, NULL);                      /* masks, not used yet */

  /* Map the window on the screen */
  xcb_map_window (c, win);


  /* Make sure commands are sent before we pause, so window is shown */
  xcb_flush (c);

  pause ();    /* hold client until Ctrl-C */

  return 0;

/*
	//this is supposed to be thread safe
	
	SDL_Surface* screen = NULL;
	SDL_Window *window;                    // Declare a pointer
	int x, y; 
	
	//~ x = atoi(argv[1]); 
	//~ y = atoi([argv[2]); //grab the x and y values.
	SDL_Init( SDL_INIT_EVERYTHING ); //just initialize everything here 
	
	 window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_SWSURFACE                  // flags - see below
    );
	
	
	
	//~ setenv("DISPLAY", "0", 0);
			//~ execve("/usr/bin/xeyes", NULL, NULL); 
	//~ SDL_SetWindowPosition(SDL_Window* window, x ,y)
	int child = fork();
	if(child==0) {
		printf("Child");
		execve("/usr/bin/xterm", NULL, NULL);
	}
*/
}


