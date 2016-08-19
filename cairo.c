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
#include <time.h>


#include <cairo/cairo.h>
#include "src/include/cairosdl.h"
//~ #include <gtk/gtk.h>

#include "src/include/tree.h" //


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_BPP 32

#define NODE_SURFACE_WIDTH (SCREEN_WIDTH/10) //this is for the nodes and text
#define NODE_SURFACE_HEIGHT (SCREEN_HEIGHT/10) //this is for the nodes and text


int screenGrab[SCREEN_WIDTH][SCREEN_HEIGHT]; //just take the x values of the screen

//add a nice pi constant 
#define M_PI 3.14159265358979323846

//declarations for the voided function right here// we need this or else it will complain
static void draw (cairo_t *cr);
static void draw_screen (SDL_Surface *screen);
static void drawBg (SDL_Surface *screen); 
static void drawLs (SDL_Surface *screen);

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin

SDL_Surface *hello, *screen, *sdlsurf, *backGroundSurface, *nodeSurface;
cairo_surface_t *cairosurf, *surface;
cairo_t *cr, *tr;
		//~ SDL_Surface*  = NULL;
    
int deltaX, deltaY; 
 
//gcc example.c -o example `pkg-config --cflags --libs gtk+-3.0`

struct xContainerNode
{
		int x; //x offset
		SPLAY_ENTRY(xContainerNode) entry; //the entries into the binary tree
}; 
	

int returnRandIntInRange(int low, int high)
{
		volatile int randomVariable;
		do
		{
			randomVariable = (rand() %  (high - low + 1 ) + low); //return this right here 
		}
		
		while ( !(randomVariable < low && randomVariable > high ));
		
		return randomVariable; 
		
}



struct graphicNodeData 
{ 
		int x,y; //coordinates
		int innerX, innerY, outerX, outerY; //this is for screen space 
		int nodeId; 
		int numOfProperties; 
		char nodeName[256]; //I am only limiting this to 256 bytes
		char fileName[2048]; 
		int connections[16]; 

}; 


struct xAndY
{
	int x, y; //just simple
	
}; 


struct gNodeY { 
	RB_ENTRY(gNodeY) entry; 
	struct graphicNodeData *gnodePointer; //pointer of the gnode data
	int i,y; 
}; 
 


struct gNodeX { 
	RB_ENTRY(gNodeX) entry; 
	RB_HEAD(gNodeYHead, gNodeY) head; 
	int i,x; 
}; 
 

 
 
int 
intcmpX(struct gNodeX *e1, struct gNodeX *e2) 
{ 
	if(e1->x < e2->x)
	{
		return -1;
	}
	else if(e1->x > e2->x)
	{
		
		return 1;
	}
	else
	{
		
		return 0; 
	}
} 
 
 
int 
intcmpY(struct gNodeY *e1, struct gNodeY *e2) 
{ 
		if(e1->y < e2->y)
	{
		return -1;
	}
	else if(e1->y > e2->y)
	{
		
		return 1;
	}
	else
	{
		
		return 0; 
	}
	
} 
 


struct graphicNodeData *mainGrid[SCREEN_WIDTH][SCREEN_HEIGHT]; 

int main(int argc, char* argv[])
{
    //variables 
    SDL_Event event;
	SDL_Rect box, regionX, slaveGirl; //I don't know what i've been told.
	
	//zeroing
	sdlsurf = cr = tr = cairosurf = hello = screen = surface  = NULL; //nullify
	deltaX = deltaY = 0;
	
	
	//init
	 srand(time(0)); //set up a random number 
	SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER);
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,  SDL_HWSURFACE | SDL_RESIZABLE );
    SDL_WM_SetCaption ("Paola", "ICON"); // setting window tittle 
	
	//creating surfaces
	hello = SDL_CreateRGBSurface (0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0x00FF0000, 0x0000FF00,0x000000FF, 0); /* Amask */
	
	nodeSurface = SDL_CreateRGBSurface (0, NODE_SURFACE_WIDTH, NODE_SURFACE_HEIGHT, SCREEN_BPP, 0x00FF0000, 0x0000FF00,0x000000FF, 0); /* Amask */
	//~ SDL_SetColorKey( nodeSurface, SDL_SRCCOLORKEY, SDL_MapRGB(nodeSurface->format, 255, 0, 255) );
	
	backGroundSurface = SDL_CreateRGBSurface (0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0x00FF0000, 0x0000FF00,0x000000FF, 0); /* Amask */
	//~ surface = cairo_image_surface_create_for_data (sdlsurf->pixels, CAIRO_FORMAT_RGB24, sdlsurf->w, sdlsurf->h, sdlsurf->pitch);
	//~ cr = cairo_create (surface);
	
	//^ for use with cairo 


	//this right here is for the single quadrants
	box.w = NODE_SURFACE_WIDTH; 
	box.h = NODE_SURFACE_HEIGHT; 
	box.x = 0; 
	box.y = 0; 
	 
	drawBg(backGroundSurface); 	

   while (SDL_WaitEvent (&event)) 
	{

		
		switch (event.type) {
					
						case SDL_QUIT:
						{
							goto QUIT_PROGRAM;
							break; 
						}
							case SDL_MOUSEMOTION:
							{
								
								  deltaX = event.motion.x;
								  deltaY = event.motion.y;

								break;	
							}
						
							case SDL_MOUSEBUTTONDOWN:
							{
								puts("Mouse pressed down"); //the mouse was pressed down
								system("kst2 /home/romxero/Documents/code/c/cBuildNu/681_0.dat -y 2"); 
								break;	
							}
						
							default:
							{
								break; 
							}

				}
				printf("Mouse X location : %d -- Mouse Y location %d \n", deltaX, deltaY); //show the locations
				
				//clear the screen first
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)); //clear
				
				//~ drawLs(backGroundSurface); 
				draw_screen(screen); 
				//drawNode();//this is a test function right here
				//~ SDL_SetColorKey( nodeSurface, SDL_SRCCOLORKEY, SDL_MapRGB(nodeSurface->format, 255, 0, 255) );
				
				//~ SDL_BlitSurface( backGroundSurface, NULL, screen, NULL );
				//~ SDL_BlitSurface( hello, NULL, screen, NULL );
				//~ SDL_BlitSurface( nodeSurface, NULL, screen, &box );
				SDL_Flip (screen); //make sure you flip the buffers to right here 

	
		usleep(1); //using usleep

	//~ SDL_Delay( 2000 ); //this was way uneeded 
	
	}

	QUIT_PROGRAM: 
	//~ cairo_destroy (cr);
    //~ cairo_surface_destroy (surface);
	SDL_FreeSurface (screen);
    SDL_Quit ();
	return 0; //everything is fine right here
	
	
}



static void __drawNode(cairo_t *cr)
{
	//this function is used to draw the node only
	
	//this stuff below is for the background, and is deprecated
	//~ cairo_set_source_rgb (cr, 1, 1, 1);
	//~ cairo_paint (cr);

	cairo_set_source_rgba (cr, 0.001, 0.005, 1.0,.7);
	cairo_set_line_width (cr, 10.0);
	cairo_arc (cr, 128.0, 128.0, 12, 0, 2 * M_PI);

	cairo_fill (cr);
	
	cairo_set_source_rgba (cr, 1.0, 0.5, 0,.5);
	cairo_set_line_width (cr, 10.0);
	cairo_arc (cr, 128.0, 128.0, 12, 0, 2 * M_PI);

	cairo_stroke (cr);

}//this is a test function right here

static void drawNode(cairo_t *cr, double xOffset, double yOffset)
{
	//this function is used to draw the node only
	
	//this stuff below is for the background, and is deprecated
	//~ cairo_set_source_rgba (cr, 1, 1, 1, .1);
	//~ cairo_paint (cr);

	cairo_set_source_rgba (cr, 0.001, 0.005, 1.0,.7);
	cairo_set_line_width (cr, 10.0);
	cairo_arc (cr, xOffset, yOffset, 12, 0, 2 * M_PI);

	cairo_fill (cr);
	
	cairo_set_source_rgba (cr, 1.0, 0.5, 0,.5);
	cairo_set_line_width (cr, 10.0);
	cairo_arc (cr, xOffset, yOffset, 12, 0, 2 * M_PI);

	cairo_stroke (cr);

}//this is a test function right here


static void
drawNodes (cairo_t *cr)
{
	
	
	
	
}

static void
drawConnections (cairo_t *cr)
{
	
	
}


static void
drawText (cairo_t *cr, const char *string, double xOffset, double yOffset)
{
	
	cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size (cr, 12.0);
    cairo_set_source_rgba (cr, 0.001, 0.005, 1.0,.5);
    cairo_move_to (cr, xOffset, yOffset);
    cairo_show_text (cr, string);
	
}



static void
__drawBg (cairo_t *cr)
{
	
	//paint the background
cairo_set_source_rgb (cr, 1, 1, 1);
cairo_paint (cr);
}

static void
__drawBg2 (cairo_t *cr)
{
	
cairo_set_source_rgb (cr, 1, 0, 1);
	//paint the background
cairo_paint (cr);
}


static void
drawLines (cairo_t *cr)
{
	cairo_set_line_width (cr, 1.0);
	cairo_set_source_rgba (cr, 0, 0, 0,.5);
	//paint the background
	
	cairo_move_to(cr,513,302); 
	cairo_line_to(cr,750,321); 
	
	cairo_stroke (cr);
}


static void
draw (cairo_t *cr)
{
	
	//paint the background
cairo_set_source_rgb (cr, 1, 1, 1);
cairo_paint (cr);

cairo_set_source_rgba (cr, 1.0, 0.5, 0,.5);
cairo_set_line_width (cr, 10.0);
cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2 * M_PI);

cairo_stroke (cr);


 cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size (cr, 32.0);
    cairo_set_source_rgba (cr, 0.001, 0.005, 1.0,.5);
    cairo_move_to (cr, 200.0, 50.0);
    cairo_show_text (cr, "Pancrease_Test");


}

static void
draw_screen (SDL_Surface *screen)
{
    cairo_t *cr;
    cairo_status_t status;

    /* Create a cairo drawing context, normalize it and draw a clock. */
    SDL_LockSurface (screen); {
        cr = cairosdl_create (screen);

        //~ cairo_scale (cr, screen->w, screen->h);
      
		__drawBg(cr);
		//~ cairo_set_source_rgba (cr, 1, 1, 1, 1);
		
		drawLines(cr);		
        drawNode(cr,513,302);
		drawText(cr,"Node 1",533,282); 


        drawNode(cr,750,321);
		drawText(cr,"Node 2",770,301); 

		
        status = cairo_status (cr);
        cairosdl_destroy (cr);
    }
    SDL_UnlockSurface (screen);
    //~ SDL_SetColorKey( screen, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 255, 0, 255) );
    //~ SDL_Flip (screen);

    /* Nasty nasty error handling. */
    if (status != CAIRO_STATUS_SUCCESS) {
        fprintf (stderr, "Unable to create or draw with a cairo context "
                 "for the screen: %s\n",
                 cairo_status_to_string (status));
        exit (1);
    }
}




	//~ if( event.type == SDL_MOUSEMOTION )
		//~ {
			//~ //Get the mouse offsets
			//~ x = event.motion.x;
			//~ y = event.motion.y;
	//~ 
			//~ //If the mouse is over the button
			//~ if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
			//~ {
				//~ //Set the button sprite
				//~ clip = &clips[ CLIP_MOUSEOVER ];
			//~ }
			//~ //If not
			//~ else
			//~ {
				//~ //Set the button sprite
				//~ clip = &clips[ CLIP_MOUSEOUT ];
			//~ }
		//~ }




int 
intcmp(struct graphicNodeData *e1, struct graphicNodeData *e2) 
{ 
	if(e1->x < e2->x)
	{
		return -1;
	}
	else if(e1->x > e2->x)
	{
		
		return 1;
	}
	else
	{
		
		return 0; 
	}
	
}; 



static void
drawBg (SDL_Surface *screen)
{
    cairo_t *cr;
    cairo_status_t status;

    /* Create a cairo drawing context, normalize it and draw a clock. */
    SDL_LockSurface (screen); {
        cr = cairosdl_create (screen);

        cairo_scale (cr, screen->w, screen->h);
      
		__drawBg(cr);
        //~ drawNode(cr);
		//~ drawText(cr,"Pancrease"); 
        status = cairo_status (cr);
        cairosdl_destroy (cr);
    }
    SDL_UnlockSurface (screen);
  

    /* Nasty nasty error handling. */
    if (status != CAIRO_STATUS_SUCCESS) {
        fprintf (stderr, "Unable to create or draw with a cairo context "
                 "for the screen: %s\n",
                 cairo_status_to_string (status));
        exit (1);
    }
}






//~ cairo_select_font_face (cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
                               //~ CAIRO_FONT_WEIGHT_BOLD);
//~ cairo_set_font_size (cr, 90.0);
//~ 
//~ cairo_move_to (cr, 10.0, 135.0);
//~ cairo_show_text (cr, "Hello");
//~ 
//~ cairo_move_to (cr, 70.0, 165.0);
//~ cairo_text_path (cr, "void");
//~ cairo_set_source_rgb (cr, 0.5, 0.5, 1);
//~ cairo_fill_preserve (cr);
//~ cairo_set_source_rgb (cr, 0, 0, 0);
//~ cairo_set_line_width (cr, 2.56);
//~ cairo_stroke (cr);
//~ 
//~ /* draw helping lines */
//~ cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
//~ cairo_arc (cr, 10.0, 135.0, 5.12, 0, 2*M_PI);
//~ cairo_close_path (cr);
//~ cairo_arc (cr, 70.0, 165.0, 5.12, 0, 2*M_PI);
//~ cairo_fill (cr);
	
