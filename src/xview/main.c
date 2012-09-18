/*
** xview - program to display time series of 2 dimensional data
**		  This is compatible with data generated by the 
**		  GENESIS neural systems simulator
**		  
**		  X10 version written by Matt Wilson 12/10/87
**		  X11 version written by Matt Wilson 6/27/89
*/

#include	"xview.h"
#include 	<X11/cursorfont.h>
#include 	<X11/Xutil.h>

main(argc, argv,envp)
int32_t	argc;
char	*argv[];
char	*envp[];
{
int32_t	status;
int32_t	x,y;

    G = (GlobalContext *)calloc(1,sizeof(GlobalContext));
    V = (ViewContext *)calloc(1,sizeof(ViewContext));
    G->mapped = 1;
    G->wwidth = 200;
    G->wheight = 230;
    G->fontheight = 9;
    G->fontwidth = 6;
    ParseArgList(argc,argv);
    FileInit();
    if(report_autoscale){
	fprintf(stdout,"%g\t%g\n",minval,maxval);
	exit(0);
    }
    if(G->mapped){
	InitX(display);
	/* LoadNextFrame(); */
	EventLoop();
    } else {
	if(geometry){
	    status = XParseGeometry(geometry,&x,&y,&width,&height);
	    if(status & WidthValue){
		G->wwidth = width;
	    }
	    if(status & HeightValue){
		G->wheight = height;
	    }
	}
	color_min = 25;
	color_scale = 230;
	V->valid_frame = GetFrame(V->view_time);
	Rescale();
	if(commandfile){
	    ReadCommandFile(commandsource,commandfile);
	}
    }
    exit(0);
}
