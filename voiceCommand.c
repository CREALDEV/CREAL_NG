//CREAL 2 - voice command 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "include/minclude.h" //this is in the internal build directory





int main(int argc, char **argv)
{

	mainProcessKey = 0; 

	if (chdir("~/creal_platform") < 0) //change the working directory of the application
	{
		puts("cannot enter the directory"); 
	}
	
	appPath = popen("espeak //", "w");
	close(appPath); //this will close the file descriptor
	return EXIT_SUCCESS; //gnu type 
} 

