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



//created by Trevor Chan, and modified by Randy White

//Ripped from man page
#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
               do { perror(msg); exit(EXIT_FAILURE); } while (0)


#define MQNAME	"/CREAL_JOY_0"
#define LOOPS	1000
#define PRIO	10
#define C_MAX_MSG 256 //this will be the max messages right here 
#define C_DEF_MODE 777 //this is for default shit right here with fds 

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin

int main(int argc, char* argv[])
{
    //sdl stuff 
    SDL_Joystick *joystick;
	SDL_Event event;
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
	perror("mq_open\n");
			if (mq == (mqd_t)-1)
		{ 
		//interesting to cast this type over -1
			perror("mq_open\n");
			return -1;
		}
			
		status = mq_getattr(mq, &attr);
		
		if (status)
		{
			perror("mq_getattr()");
			return -1; 
		}

		//~ mq_setattr(mq,&attr,NULL); //SETTING THE ATTRIBUTES OF THE MESSAGE QUEUE

		mq_send(mq, "L", 2, 1); //make sure to cast this thing here
		perror("set attr\n");	




    if (SDL_Init( SDL_INIT_JOYSTICK|SDL_INIT_VIDEO ) < 0) //SDL_INIT_VIDEO | //ONLY TRYING TO INITIALIZE THE JOY STICK SYSTEM
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
	
	else
	{
	    

while(mainGameLoopConditional)
{
	usleep(1); //sleep you bastard
 while(SDL_PollEvent(&event))
    {  
        switch(event.type)
        {
			
			//putting the mouse shit in here   
			 case SDL_MOUSEMOTION: {
				OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
				break;
			}
	 
			case SDL_MOUSEBUTTONDOWN: {
				switch(Event->button.button) {
					case SDL_BUTTON_LEFT: {
						OnLButtonDown(Event->button.x,Event->button.y);
						break;
					}
					case SDL_BUTTON_RIGHT: {
						OnRButtonDown(Event->button.x,Event->button.y);
						break;
					}
					case SDL_BUTTON_MIDDLE: {
						OnMButtonDown(Event->button.x,Event->button.y);
						break;
					}
				}
				break;
			}
			
			case SDL_MOUSEBUTTONUP:    {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }
        
            case SDL_KEYDOWN:
            {
            /* handle keyboard stuff here */                            
				break;
			}	
            case SDL_QUIT:
            {
				/* Set whatever flags are necessary to */
				/* end the main game loop here */
				mainGameLoopConditional = false; //exit out of the game loop
				break;
			}
        }
    }
    
	}//main game loop	
	    SDL_JoystickClose(joystick);

	}
	
	mq_close(mq); //close the file descriptor
	SDL_Quit();
	
	return 0;
}	


//GRAVE YARD BELOW

//~ case SDL_KEYDOWN:
				//~ /* keyboard stuff */				
				//~ while( SDL_PollEvent( &event ) )
				//~ {
				//~ /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
					//~ switch( event.type )
					//~ {
					  //~ case SDL_KEYDOWN:
						//~ printf( "Key press detected\n" );
						//~ break;
//~ 
					  //~ case SDL_KEYUP:
						//~ printf( "Key release detected\n" );
						//~ break;
//~ 
					  //~ default:
						//~ break;
					//~ }
				//~ }
				//~ break;
