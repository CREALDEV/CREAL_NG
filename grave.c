
				strcpy(word, "hello there mr ed\0"); 
			  linenoiseSetCompletionCallback(completion);

			  while ((p = linenoise("CREAL_PROMPT > ")) != NULL) {
				linenoiseHistoryAdd(p);

				//~ output = runCommmand(p);

				//~ puts(output);
					
				//~ p[sizeof(p)]='\0';
				//~ token = "e";
				int i = 0;
				int count = 0; 
				for (i = 0; i < sizeof(p);  i++)
				{
						printf(" %c \n", p[i]);
					if (p[i] == '\t')
					{
						count++;
					}
				}
				
				printf(" %d  %d \n", count, sizeof(p));
				
				for ( i = 0; i < count; i++)
				{
					
					token = strsep(&p, "\t");
					puts (token); 
				}
				
				//~ while(token != '\0')
				//~ {
					//~ 
				//~ token = strsep(&p, " \t");
				//~ puts (token); 
//~ 
//~ 
				//~ }
				
				
				//~ free(p);
				//~ free(output); //now output buffwe in function allocates on stack memory
				
				free(p);
			  }


			
					  act.sa_sigaction = &catchinstance;
					  act.sa_flags = SA_SIGINFO;
					  sigfillset(&(act.sa_mask));

					  sigaction(SIGHUP, &act, NULL);//1
					  sigaction(SIGKILL, &act, NULL);//9
					  sigaction(SIGTERM, &act, NULL);//15
					  sigaction(SIGCHLD, &act, NULL);//17

					  act.sa_handler = SIG_IGN;
					  sigfillset(&act.sa_mask);
					  act.sa_flags = 0;
					  sigaction(SIGPIPE, &act, NULL);//13

					FILE *outputFP = NULL; //this is to actually write the file
					
					/* The stuff below is used for grabing the amount of processors on the system */
					

					
