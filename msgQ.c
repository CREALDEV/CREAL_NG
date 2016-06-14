//CREAL 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>



int main(int argc, char **argv)
{
	mainProcessKey = 0; 
	 
	 if (queueIdent = msgget(mainProcessKey, 0) <0 )
	 {
		 
		 puts("error establishing message queue"); 
		 
		 
	 }
	 else
	 {
		 //~ msgctl(mainProcessKey, int cmd, struct msqid_ds *buf);
			//~ mainMessageStructure->mtype = 1; //select the first message  
			
			msgsnd(mainProcessKey, const void *msgp, size_t msgsz, int msgflg);
	 
	 } 
		//IPC_NOWAIT -- use this flag for creating asynch queues
		return EXIT_SUCCESS;
}

