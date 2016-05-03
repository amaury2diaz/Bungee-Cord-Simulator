/****************************************************************************************************
Filename:				ass3.cpp
Version: 				1.0                                         
Author:					Amaury Diaz Diaz                                              
Student No:  			040 738 985                                             
Course Name/Number:		CST8233 Numerical Computing                                 
Lab Sect: 				302                                                      
Assignment #:			3
Assignment name:		Bungee
Due Date:				December 6 2015                                           
Submission Date:		December 6 2015
Professor:				Andrew Tyler                                           
Purpose: 				Simulate how a Bungee cord behaves.
****************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

#define G 9.8
#define M 68
#define A 8
#define VMAX 46
#define K 0.04
#define H 400
#define SECOND 1000

/****************************************************************************************************
Function name:			main
Purpose:				main function
						It runs the menu that allows the user to select if run the simulation.
						Once the simulation is selected its is ended when the user arrives
						succesfully to the floor or crashes. The user can also select to end the
						simulation at any time.
In parameters:			none
Out parameters:			0 for successful execution
Version:				1.0
Author:					Amaury Diaz Diaz
****************************************************************************************************/

int main( int argc, const char* argv[] )
{
	bool run=true;

	while(run){
		bool KeepRunning;
		char play;
		char buttonPressed='n';
		double cHeight = H;
		double cC = 10.0;
		double v_i = 0.0f,v_ii,accn;
		int mSeconds=0;
		double firstSec;
		/*Print the menu of the application*/
		cout<<"Welcome to the bungee jump simulator"<<endl;
		cout<<"Select what you want to do:"<<endl;
		cout<<"1. Run the simulator"<<endl;
		cout<<"2. Quit"<<endl;
		cin>>play;
		switch(play){
		/*For this case run the simulation*/
		case '1':
			KeepRunning=true;
			/*Get the initial time in milliseconds*/
			firstSec = GetTickCount();
			while(KeepRunning)
			{
				/*Get the following time in milliseconds*/
				double nextSec = GetTickCount();
				/*Find the difference to find the interval of time*/
				double dT = nextSec - firstSec;
				/*In case the interval of time is 0 do nothing*/
				if(dT!=0){
					cout<<"Press q to quit; w to increase drag; e to decrease drag"<<endl;
					/*Find if a key on the keyboard was hit*/
					if (_kbhit()){

						switch(_getch()){
						case 'e': (cC > 1)?--cC:cC;buttonPressed='e';break;
						case 'w': (cC < 10)?++cC:cC;buttonPressed='w'; break;
						case 'q': KeepRunning=false; break;
						}
					}
					cout<<setiosflags(ios::fixed);
					switch(buttonPressed){
					case 'n':
						cout<<"starting bungee jump: wind drag = "<<setprecision(3)<<cC<<endl;break;
					case 'e':
						cout <<"e was pressed - reduce wind drag: wind drag = "<< setprecision(3)<<cC<< endl;break;
					case 'w':
						cout <<"w was pressed - increase wind drag: wind drag = "<<setprecision(3)<<cC<< endl;break;
					}

					/*Calculate the amount of milliseconds elapsed*/
					mSeconds+=dT;
					/*Convert the interval of time to seconds*/
					dT/=1000;
					/*Find the acceleration*/
					accn=G-(cC/M)*(v_i+A*(pow((v_i/VMAX),2)))-(K*(H-cHeight));
					/*Find the current velocity*/
					v_ii=v_i + accn*dT;
					/*Finde the current height*/
					cHeight = cHeight-((v_i+v_ii)/2)*dT;
					/*Next iteration current velocity becomes the past velocity*/
					v_i=v_ii;


					cout << "minute = " <<(mSeconds/60000)<<"; second = "<<(mSeconds/1000)%60<<"; millisec = "<<mSeconds%1000<< " to run.\n";
					cout<<"speed of descent = "<<v_i<<"m/s"<<endl;	
					cout<<"height above the ground = "<<cHeight<<"metres"<<endl;
					/*The user crashed if the went below 0 height*/
					if(cHeight < 0.0f && v_i>1.0){
						cout<< "You crashed!" <<endl;
						cout<< "Time Taken(min:sec:millisec) = "<< (mSeconds/60000) << ":"<<(mSeconds/1000)%60 << ":" << mSeconds%1000 << endl;
						system("pause");
						system("cls");
						break;
					}
					/*The user succeeds if they are at a height of less than 1 and bigger than 0 and a velocity less than 1*/
					if((cHeight < 1.0 && cHeight >0.0)&& v_i<1.0){
						cout<< "You rock !!!!!"<<endl;
						cout<< "Time Taken(min:sec:millisec) = "<< (mSeconds/60000) << ":"<<(mSeconds/1000)%60 << ":" << mSeconds%1000 << endl;
						system("pause");
						system("cls");
						break;
					}

					system("cls");

				}
				firstSec = nextSec;
			}
			break;
		/*In this case quit the application*/
		case '2':
			run=false;
			break;
		}
	}
}