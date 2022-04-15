#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 900;
	UI.height = 700;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 50;
	UI.TlBrWdth = 50;
	UI.MnItWdth = 80;

	UI.DrawClr = BLUE;
	UI.HiClr = RED;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3); ///////*****************
	CreateDesignToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i=0;	

	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.
	pWind->DrawImage("images\\DesignMenu.jpg", 0, 0);//here to input image in the tool bar
	pWind->DrawImage("images\\copy.jpg", 240, 0);
	pWind->DrawImage("images\\cut.jpg", 320, 0);
	pWind->DrawImage("images\\paste.jpg", 400, 0);
	pWind->DrawImage("images\\save.jpg", 480, 0);
	pWind->DrawImage("images\\edit.jpg", 560, 0);


	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);	
	//here to draw line in the tool bar around images
	pWind->DrawLine(320, UI.TlBrWdth, 320, 0);
	pWind->DrawLine(400, UI.TlBrWdth, 400, 0);
	pWind->DrawLine(480, UI.TlBrWdth, 480, 0);
	pWind->DrawLine(560, UI.TlBrWdth, 560, 0);
	pWind->DrawLine(640, UI.TlBrWdth, 640, 0);

}


void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar

	//Draw a line under the toolbar
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth, UI.width, UI.height - UI.StBrWdth);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Times New Romans");   //formatting font style from arial
	pWind->DrawString(10, UI.height - (int) (UI.StBrWdth/1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
