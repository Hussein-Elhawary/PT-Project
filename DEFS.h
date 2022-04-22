#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)

	ADD_CONNECTOR, //Add a connector between two statements

	EDIT_STAT,	//Edit a statement

	SELECT,		//Select a statement, a connector

	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
	RESIZE,		//Resize a figure(s)
	START,      //Add start
	READ,		//Add read
	WRITE,		//Add write
	END,		//Add end
	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	EXIT,		//Exit the application
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to simulatiom mode
	COPY,		//Copy
	CUT,		//Cut
	PASTE,		//Paste
	ZOOM_OUT,	//Zoom out
	ZOOM_IN,	//Zoom in
	RUN,		//Run
	BCTODSG,	//return back to design mode
	FLTOCODE,	//flow chart to code
	DEBUG,		//step by step run

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{

	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	//TODO: Add more items names here
	ITM_EXIT,		  //Exit
	ITM_START,        //Start
	ITM_READ,         //Read
	ITM_WRITE,        //Write
	ITM_SMPL_ASSIGN,  //simple assignment statement
	ITM_COND,		  //conditional statement
	ITM_CONNECTOR,    //Connector
	ITM_END,		  //End
	ITM_COPY,		  //Copy
	ITM_CUT,		  //Cut
	ITM_PASTE,		  //Paste
	ITM_SAVE,		  //Save
	ITM_EDIT_STAT,	  //Edit statment
	ITM_ZOOM_OUT,	  //Zoom out
	ITM_ZOOM_IN,	  //Zoom in
	ITM_DSN_CNT		  //no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_RUN,	//Run
	ITM_STP,	//Step by step
	
	//TODO:Add more items names here

	ITM_SIM_BCTODSG,//back to design mode
	ITM_SIM_FLTOCODE,//flow chart to C++ code
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
};




#ifndef NULL
#define NULL 0
#endif

#endif