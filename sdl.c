#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include "SDL2/SDL.h" //I think this is sdl right here  
//~ #include "src/include/npth.h"  //these are for the threading stuff right here 



int main() 
{ 
	

	//~ pth_init(); //this is to initialize the npth threads 

	//Constants for the screen height and width 

	const int SCREEN_WIDTH = 640; 
	
	const int SCREEN_HEIGHT = 480;
	 //The window we'll be rendering to 
	 SDL_Window* window = NULL; //The surface contained by the window 
	 SDL_Surface* screenSurface = NULL; //Initialize SDL 
	 if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
	 { printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); }
		else
		{
			
			 //Create window 
			 window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			 if( window == NULL ) { printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); }
			
		}


	 while(1)
	 {
		 
			sleep(3); // make sure to give more stuff to the cpux
	};
	
	 //Destroy window 
	 SDL_DestroyWindow( window ); 
	 
 //just an infinite loop
	 //Quit SDL subsystems 
	 SDL_Quit();  

	//~ pth_kill(); //stop ntph threads 
	return 0; //this is good
} 


