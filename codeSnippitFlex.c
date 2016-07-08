void startDaemonMode(void) //starts the daemon
{
					//* Daemon stuff below
					pid = fork(); //fork the proceess to a child process
					
					if(pid < 0)
					{
						printf("ERROR!\n");
						perror("Could not get a PID for child process"); //new way to handle errors
						exit(EXIT_FAILURE); // exit, things have failed
					}
					
					if(pid > 0)
					{
						//Things have succeeded
						exit(EXIT_SUCCESS); // exit, things have failed
					}
					
					umask(0); //change the file mask
					
					sid = setsid(); //get a set id for child process
						
						
					if(sid < 0)
					{
						puts("ERROR!\n");
						perror("Could not get a SID for child process"); //new way to handle errors
						exit(EXIT_FAILURE); // exit, things have failed
					}
					
					//* Change the current working directory 
					if ((chdir(".")) < 0) {
					//* Log any failure here 
					

				
					}
				
				
					//closes the standard display stuff
					//* Close out the standard file descriptors 
					close(STDIN_FILENO);
					close(STDOUT_FILENO); //standard output
					close(STDERR_FILENO);
				
				
				
}



int yyerror(char *s)
    {
			/*  This right here is used to tell if there is an error with the parser */			
		          
          	printf("ERROR : %s", s); //prints out a syntax error to the filehandle
			
    }




int shrdMemFileIo(const char *path, const char *string)
{
	/* this function writes to a pipe */
		FILE *fp = NULL;
		
	 fp = fopen(path,"w");
	 
	 if (fp == NULL) 
	 {
		 
			return -1;
			
	 }
	 
	 fputs(string,fp);
	 fclose(fp);
	 return 1;
}


int shrdMemFile(const char *path, char buffer[])
{
	/*  this function reads from the pipe */			
		
		FILE *fp = NULL;
		
	 fp = fopen(path,"r");
	 
	 if (fp == NULL) 
	 {
		 
			return -1;
			
	 }
	 
	 while(fgets(buffer,MAX_PIPE_SIZE,fp) != NULL) {

		}
	 
	 fclose(fp);
	 return 1;
	 
}



/*

enum CREAL_JOY_STATES {
	//these are just enumerated states in order to process joystick events.
	JOY_UP,
	JOY_DOWN,
	JOY_LEFT,
	JOY_RIGHT,
	JOY_UP_LEFT,
	JOY_UP_RIGHT,
	JOY_DOWN_LEFT,
	JOY_DOWN_RIGHT,
	JOY_BUTTON_0,
	JOY_BUTTON_1,
	JOY_BUTTON_2,
	JOY_BUTTON_3,
	JOY_BUTTON_4,
	JOY_BUTTON_5,
	JOY_BUTTON_6,
	JOY_BUTTON_7,
	JOY_BUTTON_8,
	JOY_BUTTON_9 ,
	JOY_BUTTON_10,
	JOY_BUTTON_11,
	JOY_BUTTON_12
		
};

*/
