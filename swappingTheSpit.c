#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h> 




#define MAX_PROCESSES 64
    

int pid;
pid_t mainPid;
bool mainGameLoopConditional;
//begin

enum PROCESSES {
	MAIN = 0,
	LAUNCHER, 
	JOY,
	KEY,
	MOUSE,
	SOUND
};


struct procIdentTableStructure
{
	
	int processNumber; 
	void (*processFunction)(void *);
	
};



struct procIdentTableStructure procIdentTable[MAX_PROCESSES]; //a table to identify the many processes that are going to be spawned 

//~ void *(something)(void); //I think this is a function pointer right here 
void joyStickDaemon(void *package);
void soundDaemon(void *package); 
void keyboardDaemon(void *package); 
void mouseDaemon(void *package); 
void launcherDaemon(void *package); 



int main()
{
	
	
	int i = 0; 
	
	for (i = 0; i < MAX_PROCESSES; i++)
	{
		procIdentTable[i].processFunction = &joyStickDaemon;
			mainPid = fork();
			
			if (mainPid != 0)
			{
				procIdentTable[i].processNumber = (int) mainPid; //make sure to cast this to make it safe 
				
			}
			else
			{
				procIdentTable[i].processFunction(NULL); 
				
			}
		
	}
	
			//ending the simulation is below right here 
			END_SIM: 
		return 0; 

} 




void joyStickDaemon(void *package)
{
	
	
	
	int i; 
	usleep(2);
}
