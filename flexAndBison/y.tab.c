/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141006

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "bison.y"

#define YYSTYPE char * /* Use this for string data */

#define NAME "CREAL Language to C Parser DAEMON\n Created by Randy White for C.R.E.A.\n" /* Just putting a label on this thing */
#define USAGE "Usage : ctcpd [input file] [output file] \n \
This application takes one arguments, an input and output pipe (fifo) file for IPC communication\n \
It is preferable to use named pipes with this program, or files used in an location for shared memory (i.e. tmpfs)\n" /* Usage of this application */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "flex.h"


#define MAXSIZE 2048
#define MAX_PIPE_SIZE 2048
#define TEMP "crealProperties" /*REPLACE EVENTUALLY*/
static char buffer0[MAXSIZE], buffer1[MAXSIZE], buffer2[MAXSIZE], buffer3[MAXSIZE], 
outputPipePath[256], inputPipePath[256], errorPipePath[256]; /* These are the buffers */

int loopConditionVar, errorBit;
uint parenCount, bracketCount, bufferCounter; /* Used to count parenthesis */
extern int yydebug;
extern void yyrestart( FILE *new_file );
FILE *inputPipeFile, *outputPipeFile, *errorPipeFile; /* Now we are getting things cooking */
extern FILE *yyin; /*getting the input filehandle*/
extern FILE *yyout; /*getting the output filehandle */
void abortParser(void);
pid_t pid, sid, cpid; /* this is the pid for our daemon process*/
void startDaemonMode(void); /*starts the daemon*/
int writeToPipe(const char *path, const char *string);
int readFromPipe(const char *path, char buffer[]);
char **stringCubby; /*huge!*/

#line 63 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUMBER 257
#define SPACE 258
#define MOD 259
#define SIN 260
#define EOLN 261
#define PID 262
#define LBRACKET 263
#define RBRACKET 264
#define CREAL_END 265
#define LPAREN 266
#define RPAREN 267
#define CREAL_BEGIN 268
#define UNKNOWN 269
#define CREAL_PRINT 270
#define COPY 271
#define POWERFUNC 272
#define COMMA 273
#define COS 274
#define TAN 275
#define ASIN 276
#define ACOS 277
#define ATAN 278
#define TANH 279
#define SINH 280
#define RANDFUNC 281
#define EXP 282
#define COSH 283
#define POW 284
#define PLUS 285
#define MINUS 286
#define MUL 287
#define DIV 288
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,    2,
    2,    3,    3,    3,    3,    3,    3,    4,    4,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
};
static const YYINT yylen[] = {                            2,
    2,    1,    2,    1,    3,    3,    3,    3,    3,    1,
    3,    1,    3,    2,    2,    1,    1,    3,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    6,    6,    6,
};
static const YYINT yydefred[] = {                         0,
    2,   12,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,
   16,   17,    0,    0,    0,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,   14,    0,    1,    0,
    0,    0,    0,    0,    0,   18,    0,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,   20,   19,    0,   22,   24,   25,   21,   27,
    0,   26,    0,   23,    0,    0,    0,   30,   29,   28,
};
static const YYINT yydgoto[] = {                         17,
   18,   19,   20,   21,   22,
};
static const YYINT yysindex[] = {                      -225,
    0,    0, -265, -255, -268, -194, -254, -253, -252, -251,
 -248, -247, -246, -245, -194, -194,    0, -188, -250,    0,
    0,    0, -194, -228, -220,    0,  -89, -194, -194, -194,
 -194, -194, -194, -194, -194,    0,    0, -194,    0, -194,
 -194, -194, -194, -194,  -78,    0, -218,    0, -243,  -67,
  -56,  -45,  -34, -111, -100,  -23, -250, -250, -250, -250,
 -250,    0,    0,    0, -194,    0,    0,    0,    0,    0,
 -194,    0, -194,    0,  -12,   -1,   10,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -177,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -166, -155, -144, -133,
 -122,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -6,  -32,  -11,    0,    0,
};
#define YYTABLESIZE 298
static const YYINT yytable[] = {                         27,
   23,   24,   26,   36,   37,   57,   25,   58,   59,   60,
   61,   28,   29,   30,   31,   38,   45,   32,   33,   34,
   35,   49,   50,   51,   52,   53,   54,   55,   56,   65,
    1,    2,   62,   44,    3,   46,   47,    4,    0,    5,
    6,   40,   41,   42,   43,   64,    7,    0,    8,    9,
    0,    0,    0,   10,   11,   12,   13,   14,   75,   15,
   16,    0,    2,    0,   76,    3,   77,    0,    4,    0,
   38,    6,    0,    0,    0,    0,    0,    7,    0,    8,
    9,    4,   39,    0,   10,   11,   12,   13,   14,    4,
   15,   16,    9,    4,    0,    4,   40,   41,   42,   43,
    9,    0,    0,    5,    9,    0,    9,    4,    4,    4,
    4,    5,    0,    0,    6,    5,    0,    5,    9,    9,
    9,    9,    6,    0,    0,    7,    6,    0,    6,    5,
    5,    5,    5,    7,    0,    0,    8,    7,    0,    7,
    6,    6,    6,    6,    8,    0,    0,   38,    8,    0,
    8,    7,    7,    7,    7,   70,    0,    0,   38,    0,
    0,   71,    8,    8,    8,    8,   72,    0,    0,   38,
    0,    0,   73,   40,   41,   42,   43,   48,    0,    0,
   38,    0,    0,    0,   40,   41,   42,   43,   63,    0,
    0,   38,    0,    0,    0,   40,   41,   42,   43,   66,
    0,    0,   38,    0,    0,    0,   40,   41,   42,   43,
   67,    0,    0,   38,    0,    0,    0,   40,   41,   42,
   43,   68,    0,    0,   38,    0,    0,    0,   40,   41,
   42,   43,   69,    0,    0,   38,    0,    0,    0,   40,
   41,   42,   43,   74,    0,    0,   38,    0,    0,    0,
   40,   41,   42,   43,   78,    0,    0,   38,    0,    0,
    0,   40,   41,   42,   43,   79,    0,    0,   38,    0,
    0,    0,   40,   41,   42,   43,   80,    0,    0,    0,
    0,    0,    0,   40,   41,   42,   43,    0,    0,    0,
    0,    0,    0,    0,   40,   41,   42,   43,
};
static const YYINT yycheck[] = {                          6,
  266,  257,  271,   15,   16,   38,  262,   40,   41,   42,
   43,  266,  266,  266,  266,  259,   23,  266,  266,  266,
  266,   28,   29,   30,   31,   32,   33,   34,   35,  273,
  256,  257,   44,  284,  260,  264,  257,  263,   -1,  265,
  266,  285,  286,  287,  288,  264,  272,   -1,  274,  275,
   -1,   -1,   -1,  279,  280,  281,  282,  283,   65,  285,
  286,   -1,  257,   -1,   71,  260,   73,   -1,  263,   -1,
  259,  266,   -1,   -1,   -1,   -1,   -1,  272,   -1,  274,
  275,  259,  271,   -1,  279,  280,  281,  282,  283,  267,
  285,  286,  259,  271,   -1,  273,  285,  286,  287,  288,
  267,   -1,   -1,  259,  271,   -1,  273,  285,  286,  287,
  288,  267,   -1,   -1,  259,  271,   -1,  273,  285,  286,
  287,  288,  267,   -1,   -1,  259,  271,   -1,  273,  285,
  286,  287,  288,  267,   -1,   -1,  259,  271,   -1,  273,
  285,  286,  287,  288,  267,   -1,   -1,  259,  271,   -1,
  273,  285,  286,  287,  288,  267,   -1,   -1,  259,   -1,
   -1,  273,  285,  286,  287,  288,  267,   -1,   -1,  259,
   -1,   -1,  273,  285,  286,  287,  288,  267,   -1,   -1,
  259,   -1,   -1,   -1,  285,  286,  287,  288,  267,   -1,
   -1,  259,   -1,   -1,   -1,  285,  286,  287,  288,  267,
   -1,   -1,  259,   -1,   -1,   -1,  285,  286,  287,  288,
  267,   -1,   -1,  259,   -1,   -1,   -1,  285,  286,  287,
  288,  267,   -1,   -1,  259,   -1,   -1,   -1,  285,  286,
  287,  288,  267,   -1,   -1,  259,   -1,   -1,   -1,  285,
  286,  287,  288,  267,   -1,   -1,  259,   -1,   -1,   -1,
  285,  286,  287,  288,  267,   -1,   -1,  259,   -1,   -1,
   -1,  285,  286,  287,  288,  267,   -1,   -1,  259,   -1,
   -1,   -1,  285,  286,  287,  288,  267,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  285,  286,  287,  288,
};
#define YYFINAL 17
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#define YYUNDFTOKEN 296
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","SPACE","MOD","SIN",
"EOLN","PID","LBRACKET","RBRACKET","CREAL_END","LPAREN","RPAREN","CREAL_BEGIN",
"UNKNOWN","CREAL_PRINT","COPY","POWERFUNC","COMMA","COS","TAN","ASIN","ACOS",
"ATAN","TANH","SINH","RANDFUNC","EXP","COSH","POW","PLUS","MINUS","MUL","DIV",0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : cpy",
"cpy : expr COPY",
"cpy : error",
"cpy : CREAL_END COPY",
"expr : power",
"expr : expr PLUS power",
"expr : expr MINUS power",
"expr : expr MUL power",
"expr : expr DIV power",
"expr : expr MOD power",
"power : num",
"power : power POW num",
"num : NUMBER",
"num : LPAREN expr RPAREN",
"num : MINUS num",
"num : PLUS num",
"num : crealproperty",
"num : functions",
"crealproperty : LBRACKET NUMBER RBRACKET",
"crealproperty : LBRACKET PID NUMBER RBRACKET",
"functions : SIN LPAREN expr RPAREN",
"functions : SINH LPAREN expr RPAREN",
"functions : COS LPAREN expr RPAREN",
"functions : COSH LPAREN expr RPAREN",
"functions : TAN LPAREN expr RPAREN",
"functions : TANH LPAREN expr RPAREN",
"functions : EXP LPAREN expr RPAREN",
"functions : RANDFUNC LPAREN expr RPAREN",
"functions : EXP LPAREN expr COMMA expr RPAREN",
"functions : RANDFUNC LPAREN expr COMMA expr RPAREN",
"functions : POWERFUNC LPAREN expr COMMA expr RPAREN",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 371 "bison.y"



int main(int argc, char *argv[]) {
		
		static  struct sockaddr_un mainSocketDataStructure; // this is used as the main data structure for the sockets 
			puts(NAME); /* Show the usage!! */
			
					if (argc <= 1 || argv[1] <= 0 || argv[2] <=0)
					{
						

						fprintf(stderr,"%s : \n\n %s",argv[0],USAGE);
						exit(EXIT_FAILURE);
						
						
					}
		/*  Assigning memory for the data structure */			
		/*  Do a memory pool for this application */			
		
		stringCubby = malloc(MAXSIZE * sizeof(char *));
		
		if ( stringCubby == NULL) {perror("We ran out of memory!"); exit(EXIT_FAILURE);}
		memset(stringCubby,0,sizeof(char*) * MAXSIZE); //set everything to zero!!
		int i = 0;
		
		for(i = 0; i < MAXSIZE; i++)
		{
			
			stringCubby[i] = (char *) malloc(MAXSIZE * sizeof(char));
			if ( stringCubby[i] == NULL) {perror("We ran out of memory!"); exit(EXIT_FAILURE);}
			memset(stringCubby[i],0,sizeof(char) * MAXSIZE); //set everything to zero!!
			
		}
		
		
				
		
		
		

		//~ startDaemonMode(); //starts the daemon
		daemon(1, 0); //this right here is used instead of my shitty function


		loopConditionVar = 1;		
		inputPipeFile = outputPipeFile = NULL; //set everything to NULL
		bufferCounter = bracketCount = parenCount = 0; //setting this shit to zero
		

		

		
		strcpy(outputPipePath,argv[2]);
				
		strcpy(inputPipePath,argv[1]);
		
		YY_BUFFER_STATE stringState, bState;
		

		/* All is good, start this program as a daemon */
			
		while(loopConditionVar == 1) //while this is true, always run the daemon
		{
		
		readFromPipe(inputPipePath,buffer3); 
		stringState = yy_scan_string(buffer3); //trying out parsing a string
		yy_switch_to_buffer(stringState);
		yyparse();
		yylex_destroy();
					
				if (errorBit >= 1)
				{

						writeToPipe(outputPipePath,buffer0);
						errorBit = 0;
				}
				

				bufferCounter = bracketCount = parenCount = 0; //setting this shit to zero
						
		}	
	
	
	
		/* Freeing the memory right here*/ 
		
		for(i = 0; i < MAXSIZE; i++)
		{
			free(stringCubby[i]);
			
		}
		
		free(stringCubby);

		exit(EXIT_SUCCESS);



}


/*
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

*/


int yyerror(char *s)
    {
			/*  This right here is used to tell if there is an error with the parser */			
		          
          	printf("ERROR : %s", s); //prints out a syntax error to the filehandle
			
    }




int writeToPipe(const char *path, const char *string)
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

int readFromPipe(const char *path, char buffer[])
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

#line 548 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 64 "bison.y"
	{
		
			if (parenCount % 2 != 0)
			{
				puts("Parenthesis are not equal!");
				/* Lets make sure there are the correct amount of parenthesis */
			}
	
	
			else if (bracketCount % 2 != 0)
			{
				puts("Brackets are not equal!");
				/* Lets make sure there are the correct amount of brackets */
			}
		else
		{
			strcpy(buffer0,yystack.l_mark[-1]);
			writeToPipe(outputPipePath,buffer0);
			YYACCEPT; /*This probably needs to be taken out of here */
			
		}
}
break;
case 2:
#line 87 "bison.y"
	{ 
	
	
	printf("%d\n",YYRECOVERING());
	errorBit = 1;
	yyrestart(yyin);
	YYABORT;

	
	}
break;
case 3:
#line 99 "bison.y"
	{ 
	
	loopConditionVar = 0;
	 }
break;
case 5:
#line 116 "bison.y"
	{
	 memset(buffer1,0,sizeof(char) * MAXSIZE);
	 memset(buffer2,0,sizeof(char) * MAXSIZE);
	 strcpy(buffer1,yystack.l_mark[-2]);
	 strcpy(buffer2,yystack.l_mark[0]);
	 puts(buffer1);
	 puts(buffer2);
	 sprintf(yyval,"%s + %s", buffer1, buffer2); 

	 }
break;
case 6:
#line 126 "bison.y"
	{
	 memset(buffer1,0,sizeof(char) * MAXSIZE);
	 memset(buffer2,0,sizeof(char) * MAXSIZE);
	 strcpy(buffer1,yystack.l_mark[-2]);
	 strcpy(buffer2,yystack.l_mark[0]);
	 puts(buffer1);
	 puts(buffer2);
	 sprintf(yyval,"%s - %s", buffer1, buffer2);
	 
	  }
break;
case 7:
#line 136 "bison.y"
	{
	 memset(buffer1,0,sizeof(char) * MAXSIZE);
	 memset(buffer2,0,sizeof(char) * MAXSIZE);
	 strcpy(buffer1,yystack.l_mark[-2]);
	 strcpy(buffer2,yystack.l_mark[0]);
	 puts(buffer1);
	 puts(buffer2);
	 sprintf(yyval,"%s * %s", buffer1, buffer2);
	 
	  }
break;
case 8:
#line 146 "bison.y"
	{
	 memset(buffer1,0,sizeof(char) * MAXSIZE);
	 memset(buffer2,0,sizeof(char) * MAXSIZE);
	 strcpy(buffer1,yystack.l_mark[-2]);
	 strcpy(buffer2,yystack.l_mark[0]);
	 puts(buffer1);
	 puts(buffer2);
	 sprintf(yyval,"%s / %s", buffer1, buffer2);
	 
	  }
break;
case 9:
#line 156 "bison.y"
	{
	 memset(buffer1,0,MAXSIZE);
	 memset(buffer2,0,MAXSIZE);
	 strcpy(buffer1,yystack.l_mark[-2]);
	 strcpy(buffer2,yystack.l_mark[0]);
	 puts(buffer1);
	 puts(buffer2);
	 sprintf(yyval,"fmod(%s,%s)", buffer1, buffer2);
	 /*sprintf($$,"%s %c %s", buffer1,'%', buffer2);*/
	 /*added correct mod rules for creal 2 */
	  }
break;
case 11:
#line 173 "bison.y"
	{memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);
					strcpy(buffer1,yystack.l_mark[-2]);
					strcpy(buffer2,yystack.l_mark[0]);
	 sprintf(yyval,"pow(%s,%s)", buffer1, buffer2);
/*also add the new modulous rules to this parser*/
	 }
break;
case 12:
#line 186 "bison.y"
	{ 
	memset(buffer1,0,sizeof(char) * MAXSIZE);
	strcpy(buffer1,yystack.l_mark[0]);
	puts(buffer1);
	sprintf(yyval,"%s", buffer1);
	 
	 }
break;
case 13:
#line 194 "bison.y"
	{
	memset(buffer1,0,sizeof(char) * MAXSIZE);
	strcpy(buffer1,yystack.l_mark[-1]);
	puts(buffer1);
	sprintf(yyval,"(%s)", buffer1);
	 }
break;
case 14:
#line 201 "bison.y"
	{
	memset(buffer1,0,sizeof(char) * MAXSIZE);
	strcpy(buffer1,yystack.l_mark[0]);
	puts(buffer1);
	sprintf(yyval,"-%s", buffer1);
	 }
break;
case 15:
#line 208 "bison.y"
	{
	memset(buffer1,0,sizeof(char) * MAXSIZE);
	strcpy(buffer1,yystack.l_mark[0]);
	puts(buffer1);
	sprintf(yyval,"+%s", buffer1);
	 }
break;
case 18:
#line 220 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"%s[%s]", TEMP,  buffer1);
	
}
break;
case 19:
#line 230 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"%s[%s]", TEMP,  buffer1);
	
}
break;
case 20:
#line 243 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"sin(%s)", buffer1);


}
break;
case 21:
#line 254 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"sinh(%s)", buffer1);


}
break;
case 22:
#line 265 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"cos(%s)", buffer1);


}
break;
case 23:
#line 276 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"cosh(%s)", buffer1);


}
break;
case 24:
#line 287 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"tan(%s)", buffer1);


}
break;
case 25:
#line 298 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
	
					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);
	
					sprintf(yyval,"tanh(%s)", buffer1);


}
break;
case 26:
#line 309 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);

					strcpy(buffer1,yystack.l_mark[-1]);
					puts(buffer1);

					sprintf(yyval,"exp(%s)", buffer1);


}
break;
case 27:
#line 320 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);



					puts(buffer1);
					sprintf(yyval,"rand()");


}
break;
case 28:
#line 331 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);
					strcpy(buffer1,yystack.l_mark[-3]);
					strcpy(buffer2,yystack.l_mark[-1]);
					puts(buffer1);
					puts(buffer2);
					sprintf(yyval,"exp((%s + %s))", buffer1, buffer2);


}
break;
case 29:
#line 343 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);

					
					puts(buffer1);
					sprintf(yyval,"rand()");


}
break;
case 30:
#line 354 "bison.y"
	{
					memset(buffer1,0,sizeof(char) * MAXSIZE);
					memset(buffer2,0,sizeof(char) * MAXSIZE);
					strcpy(buffer1,yystack.l_mark[-3]);
					strcpy(buffer2,yystack.l_mark[-1]);
					puts(buffer1);
					puts(buffer2);
					
					sprintf(yyval,"pow(%s,%s)", buffer1, buffer2);


}
break;
#line 1078 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
