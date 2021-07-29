#include<stdlib.h>
#include <iostream> 
#include <Windows.h> 
#include <conio.h>   
#include <ctime>     
#include<fstream>   
#include<iomanip>   
 
using namespace std;    

int myarr=0;               
int point=0;   	           
void firstscreen();	
double duration;
double maxtime=60;
string comm;

enum color 
{           
	NONE,
	DARK_BLUE,
	GREEN,
	DARK_CYAN,
	DARK_RED,
	PURPLE,
	DARK_YELLOW,
	NORMAL,
	GRAY,
	BLUE,
	LIME,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};


struct question
{
  	string ques;
  	string ans1;
	string ans2;
	string ans3;
	string ans4;
	char ans;
};

int main()
{
	char name;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);
	firstscreen();
	getch();      
	system("cls"); 
	
	

return 0;
}

struct student
{
	int rollno;
	char name[50];
	int obt;
	double per;
	char grade;
	void calculate();
	void Result();


public:
	void getdata();
	void showdata() const;	 
	void show_tabular() const;  
};

//-------------------------------------------------------------------------------------------------------------------------//
void setcolor(color newColor) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(newColor) ); 
}



void gotoXY(int x, int y)
{
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);	//Handles of the active console screen buffer	 
	COORD CursorPosition; 
	CursorPosition.X = x;
	CursorPosition.Y = y; 


	SetConsoleCursorPosition(console,CursorPosition);
}


//-----------------------------------------------------3--------------------------------------------------------------------//
void student::show_tabular() const
{
	cout<<rollno<<setw(15)<<name<<setw(10)<<obt<<setw(10)<<per<<setw(6)<<grade<<endl;
	myarr++;
}

void class_result()
{
	student st;
	ifstream inFile;

	inFile.open("Q.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();

		cin.get();
		return;
	}

	cout<<"\n\n\t\tALL STUDENTS RESULT \n";
	cout<<"\n\t\tPress Enter to Go Back Home Screen\n";
	cout<<"==========================================================\n";
	cout<<"R.No          Name      Points     %      Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}


//------------------------------------------------------2--------------------------------------------------------------------//
void info()
{
	setcolor(RED);
	gotoXY(56,4);	
		cout<<"Instruction"<<endl;
	setcolor(GREEN);
	gotoXY(50,5);	
		cout<<"Press Enter to Home Menu"<<endl;
	
		setcolor(LIME);
		gotoXY(38,6);	
		cout<<"   ________________________________________"<<endl;
		gotoXY(38,7);
		cout<<" / \\                             	         \\."<<endl;
		gotoXY(38,8);
		cout<<"|   |                                      |."<<endl;
		gotoXY(38,9);
		cout<<" \\_ | Select==>                            |."<<endl;
		gotoXY(38,10);
		cout<<"    | Press only Valid Opton--> (a,b,c,d)  |."<<endl;
		gotoXY(38,11);
		cout<<"    | if u Press Other key consider wrong  |."<<endl;
		gotoXY(38,12);
		cout<<"    | answer.                              |."<<endl;
		gotoXY(38,13);
		cout<<"    |                            	   	 |."<<endl;
		gotoXY(38,14);
		cout<<"    | Skip==>                              |."<<endl;
		gotoXY(38,15);
		cout<<"    | Press Enter to Skip the Question     |."<<endl;
		gotoXY(38,16);
		cout<<"    |                            	         |."<<endl;
		gotoXY(38,17);
		cout<<"    | Points==>                            |."<<endl;
		gotoXY(38,18);
		cout<<"    | 10 Point will be awarded for each    |."<<endl;
		gotoXY(38,19);
		cout<<"    | correct answer.                      |."<<endl;
		gotoXY(38,20);
		cout<<"    |                                      |."<<endl;
		gotoXY(38,21);
		cout<<"    | Time==>                              |."<<endl;
		gotoXY(38,22);
		cout<<"    | Team will be given 60 seconds for    |."<<endl;
		gotoXY(38,23);
		cout<<"    | each question.                       |."<<endl;
		gotoXY(38,24);
		cout<<"    |                            	         |."<<endl;
		gotoXY(38,25);
		cout<<"    | Identification==>                    |."<<endl;
		gotoXY(38,26);
		cout<<"    | Enter Roll Number and Name for Recod |."<<endl;
		gotoXY(38,27);
		cout<<"    | save                          	 |."<<endl;
		gotoXY(38,28);
		cout<<"    |   ___________________________________|___"<<endl;
		gotoXY(38,29);
		cout<<"    |  /                                      /."<<endl;
		gotoXY(38,30);
		cout<<"    \\_/______________________________________/."<<endl;
	
}

//----------------------------------------------------------1-----------------------------------------------------------------//

void student::Result()
{
	int f=30;
	setcolor(RED);
	gotoXY(0,3);
	cout<<"  _____                 _ _   "<<endl;
	gotoXY(0,4);
	cout<<" |  __ \\               | | |  "<<endl;
	gotoXY(0,5);
	cout<<" | |__) |___  ___ _   _| | |_ "<<endl;
	gotoXY(0,6);
	cout<<" |  _  // _ \\/ __| | | | | __|"<<endl;
	gotoXY(0,7);
	cout<<" | | \\ \\  __/\\__ \\ |_| | | |_ "<<endl;
	gotoXY(0,8);
	cout<<" |_|  \\_\\___||___/\\__,_|_|\\__|"<<endl;
	
	setcolor(YELLOW);
gotoXY(30,1);
cout<<"                     ,---.           ,---.   "<<endl;
gotoXY(30,2);
cout<<"                    / /^`.\\.--''''-./,'^\\ \\	"<<endl;
gotoXY(30,3);
cout<<"                    \\ \\    _       _    / /	"<<endl;
gotoXY(30,4);
cout<<"                     `./  / __   __ \\  \\,'	"<<endl;
gotoXY(30,5);
cout<<"                      /    /_O)_(_O\\    \\	"<<endl;
gotoXY(30,6);
cout<<"                      |  .-'  ___  `-.  |	"<<endl;
gotoXY(30,7);
cout<<"                   .--|       \\_/       |--.	"<<endl;
gotoXY(30,8);
cout<<"                 ,'    \\   \\   |   /   /    `."<<endl;
gotoXY(30,9);
cout<<"                /       `.  `--^--'  ,'       \\"<<endl;
gotoXY(30,10);
cout<<"             .-^^^^^-.    `--.___.--'     .-^^^^^-."<<endl;
gotoXY(30,11);
cout<<".-----------/         \\------------------/         \\--------------."<<endl;
gotoXY(30,12);
cout<<"| .---------\\         /----------------- \\         /------------. |"<<endl;
gotoXY(30,13);
cout<<"| |          `-`--`--'                    `--'--'-'             | |"<<endl;
gotoXY(30,14);
cout<<"| |                                                             | |"<<endl;
gotoXY(30,15);
cout<<"| |                                                             | |"<<endl;
gotoXY(30,16);
cout<<"| |                                                             | |"<<endl;
gotoXY(30,17);
cout<<"| |                                                             | |"<<endl;
gotoXY(30,18);
cout<<"| |_____________________________________________________________| |"<<endl;
gotoXY(30,19);
cout<<"|_________________________________________________________________|"<<endl;
gotoXY(30,20);
cout<<"                   )__________|__|__________("<<endl;
gotoXY(30,21);
cout<<"                  |            ||            |"<<endl;
gotoXY(30,22);
cout<<"                  |____________||____________|"<<endl;
gotoXY(30,23);
cout<<"                    ),-----.(      ),-----.("<<endl;
gotoXY(30,24);
cout<<"                  ,'   ==.   \\    /  .==    `."<<endl;
gotoXY(30,25);
cout<<"                 /            )  (            \\"<<endl;
gotoXY(30,26);
cout<<"                 `==========='    `==========='  "<<endl;
	setcolor(CYAN);
	gotoXY(35,14);
	cout<<"Name ==>"<<name;
	setcolor(CYAN);
	gotoXY(70,14);
	cout<<"Roll No ==> "<<rollno;
	setcolor(CYAN);
	gotoXY(35,15);
	cout<<"Total Score ==> 50";
	gotoXY(70,15);
	cout<<"Your Score ==> "<<point;
	setcolor(CYAN);
	gotoXY(35,16);
	cout<<"Percentage ==> "<<per;
	gotoXY(70,16);
	cout<<"Grade ==> "<<grade;
	setcolor(CYAN);
	gotoXY(35,17);
	cout<<"Comments==> "<<comm;
    getch();
	
}

//---------------------------------------------------CALCULATE---------------------------------------------------------------//

void student::calculate()
{
	per=point/5*10;
	
	if(per>=80)
	{
		grade='A';
		comm="Excellent";
		}	
	else if(per>=60)
		{
			grade='B';
			comm="Good";
		}
		
	else if(per>=40)
		{
			grade='C';
			comm="Fair";
		}
	else
		{
			grade='F';
			comm="Fail Do hard work..";
		}
		
	
}

//------------------------------------------------------------------------------------------------------------------------------//
void ebod()                   
{
 			
			for(int x = 20; x < 103; x++){      
			setcolor(CYAN);
			gotoXY(x,4);	
			cout<<char(205);    //==== top-length
			}
			
			for(int x = 20; x < 103; x++){
			setcolor(PURPLE);
			gotoXY(x,12);	
			cout<<char(205);  //===== mid-length
			}
			

			for(int x = 5; x < 12; x++){
			setcolor(CYAN);
			gotoXY(20,x);	
			cout<<char(186);  // || left-top width
			}                     
			for(int x = 5; x < 12; x++){
			setcolor(CYAN);
			gotoXY(103,x);	
			cout<<char(186);   //   || right-top width
			}
			setcolor(CYAN);

			gotoXY(20,4);	
			cout<<char(201);         //Left-top edge
			gotoXY(103,4);	
			cout<<char(187);         //right-top edge
			gotoXY(103,12);	
			cout<<char(188);         //right-bottom edge
			gotoXY(20,12);	
			cout<<char(200);        //left-bottom edge

}


//--------------------------------------------------------GK-----------------------------------------------------------------------//
void GK()
{
	
	clock_t start;          
    start = clock();	         

	char a,b,e;
    int t=0;
	int i=0;
	int right=0;
	int wrong=0;
	char answer;
	struct question abc[6];
	int srno=0;
	

	abc[0] = {"Which one of the following river flows between Vindhyan and Satpura ranges?","Narmada","Mahanadi","Son","Netravati",'a'};
	abc[1] = {"The Central Rice Research Station is situated in?","Chennai","Cuttack","Bangalore","Quilon",'b'};
	abc[2] = {"Who among the following wrote Sanskrit grammar?","Kalidasa","Charak","Panini","Aryabhatt",'c'};
	abc[3] = {"The metal whose salts are sensitive to light is?","Zinc","Silver","Copper","Aluminum",'b'};
	abc[4] = {"Where was the electricity supply first introduced in India?","Mumbai","Dehradun","Darjeeling","Chennai",'c'};

	do {
		duration = (clock() - start ) / (double) CLOCKS_PER_SEC; 
			setcolor(RED);                        			
			gotoXY(69,3);
			cout << maxtime-duration << endl;
		if (duration>=maxtime) {
			t=0;
			break;
		}

		if (srno==i) {
			system("cls");

			srno++;
			b=' ';
			e=' ';
			answer=abc[i].ans;

			ebod();
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);  
			gotoXY(20,x);	
			cout<<char(186);                         //left-bottom width
			}
			for(int x = 20; x < 103; x++){
			setcolor(CYAN);                    
			gotoXY(x,16);	
			cout<<char(205);
			}
			                                             //bottom-length
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);                   
			gotoXY(103,x);	
			cout<<char(186);
			}                                  //right-bottom width
			


			setcolor(CYAN); 
			gotoXY(103,16);	
			cout<<char(188);                  //edges
			gotoXY(20,16);	
			cout<<char(200);

			int col=23;                       
			setcolor(BLUE);
			gotoXY(23,5);
			
			cout << "Question "<<srno<<") " <<endl;
			gotoXY(23,6);cout<< abc[i].ques<< endl;
	  		gotoXY(col,8);
			
			setcolor(DARK_YELLOW);
			cout <<" a - " << abc[i].ans1<< endl;
	  		gotoXY(col,9);
			cout <<" b - " << abc[i].ans2<< endl;
	  		gotoXY(col,10);
			cout << " c - " << abc[i].ans3<< endl;
	  		gotoXY(col,11);
			cout << " d - " << abc[i].ans4<< endl;
			gotoXY(45,13);		
			
			cout << " Press Enter to skip ";
			gotoXY(45,14);		
			cout << " Select your Option ==> ";
			
			setcolor(YELLOW);
			gotoXY(45,3);		
			cout << " Your Remaning Time ==> ";

		}

		if(_kbhit()){               
			setcolor(YELLOW);
			gotoXY(70,14);
			a=getch();
			cout<<a;

			if(int(a)==13)
			{       

					gotoXY(30,18);
					setcolor(RED);
				cout << "You skipped this Question";
			} 
			else {
				if(a==answer)
				{
					gotoXY(62,18);
					setcolor(LIME);
					point=point+10;
					cout << "Congratulation! You selected right option";
				} 
				else
				 {
					gotoXY(70,18);
					setcolor(GREEN);
					cout << "Correct Option is  ==> "<<answer;
					gotoXY(30,18);
					setcolor(RED);
					cout << "You selected wrong option.";

				}
			}
			getch();
			i++;
		} 
	} while (i<5);
	
	if (i<4) {
		cout<<"\n \t\t\t\t\t Time is up. You failed to attempt all questions"<<endl;
	} 
		        
	getch();
}



//----------------------------------------------------Programming---------------------------------------------------------------------

void P()
{
	clock_t start;          
    start = clock();	         

	char a,b,e;
    int t=0;
	int i=0;
	int right=0;
	int wrong=0;
	char answer;
	struct question abc[6];
	int srno=0;
	
	abc[0] = {"Which of the following is not the characteristic of a class?","Generic","Friend","Inline","Inline",'c'};
	abc[1] = {"Which of the following statements is most suitable for the language?","Statically typed language.","Dynamically typed language.","All","Type-less language.",'a'};
	abc[2] = {"Which of the following operators doesn’t allow overloading?","Comparison operator.","Assignment operator.","Scope resolution operator.","Dereference operator.",'c'};
	abc[3] = {"Which of the following isn’t supported in C++ language?","Namespaces.","Inheritance","Reflection.","Polymorphism.",'c'};
	abc[4] = {"Which of the following keywords can’t appear inside a class definition?","template","static","virtual","friend",'a'};

	do {
		duration = (clock() - start ) / (double) CLOCKS_PER_SEC; 
			setcolor(RED);                        			
			gotoXY(69,3);
			cout << maxtime-duration << endl;
		if (duration>=maxtime) {
			t=0;
			break;
		}

		if (srno==i) {
			system("cls");

			srno++;
			b=' ';
			e=' ';
			answer=abc[i].ans;

			ebod();
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);  
			gotoXY(20,x);	
			cout<<char(186);                         //left-bottom width
			}
			for(int x = 20; x < 103; x++){
			setcolor(CYAN);                    
			gotoXY(x,16);	
			cout<<char(205);
			}
			                                             //bottom-length
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);                   
			gotoXY(103,x);	
			cout<<char(186);
			}                                  //right-bottom width
			


			setcolor(CYAN); 
			gotoXY(103,16);	
			cout<<char(188);
			gotoXY(20,16);	
			cout<<char(200);

			int col=23;                       
			setcolor(BLUE);
			gotoXY(23,5);
			
			cout << "Question "<<srno<<") " <<endl;
			gotoXY(23,6);cout<< abc[i].ques<< endl;
	  		gotoXY(col,8);
			
			setcolor(DARK_YELLOW);
			cout <<" a - " << abc[i].ans1<< endl;
	  		gotoXY(col,9);
			cout <<" b - " << abc[i].ans2<< endl;
	  		gotoXY(col,10);
			cout << " c - " << abc[i].ans3<< endl;
	  		gotoXY(col,11);
			cout << " d - " << abc[i].ans4<< endl;
			gotoXY(45,13);		
			
			cout << " Press Enter to skip ";
			gotoXY(45,14);		
			cout << " Select your Option ==> ";
			
			setcolor(YELLOW);
			gotoXY(45,3);		
			cout << " Your Remaning Time ==> ";

		}

		if(_kbhit()){               
			setcolor(YELLOW);
			gotoXY(70,14);
			a=getch();
			cout<<a;

			if(int(a)==13)
			{       

					gotoXY(30,18);
					setcolor(RED);
				cout << "You skipped this Question";
			} 
			else {
				if(a==answer)
				{
					gotoXY(62,18);
					setcolor(LIME);
					point=point+10;
					cout << "Congratulation You selected right option";
				} 
				else
				 {
					gotoXY(70,18);
					setcolor(GREEN);
					cout << "Correct Option is  ==> "<<answer;
					gotoXY(30,18);
					setcolor(RED);
					cout << "You selected wrong option.";

				}
			}
			getch();
			i++;
		} 
	} while (i<5);
	
	if (i<4) {
		cout<<"\n \t\t\t\t\t Time is up. You failed to attempt all questions"<<endl;
		
	} 
		        
	getch();
}



//----------------------------------------------------lITERATURE---------------------------------------------------------------

void E()
{
	
	clock_t start;     //stores and return the processor time     
    start = clock();	         

	char a;
    int t=0;
	int i=0;
	int right=0;
	//double maxtime=60;
	int wrong=0;
	char answer;
	struct question abc[6];
	int srno=0;
	
    
	abc[0] = {"Which poem ends 'I shall but love thee better after death'?","How do I love thee","Ode to a Grecian urn","In faith I do not love thee with mine eyes","Let me not to the marriage of true minds",'a'};
	abc[1] = {"Which poet is considered a national hero in Greece?","John keats","Lord Byron","Solan","Sappho",'b'};
	abc[2] = {"Who wrote about the idyllic 'Isle of Innisfree'?","Dylan Thomas","Ezra Pound","W. B. Yeats","E.E. Cummings",' c'};
	abc[3] = {"A pattern of accented and unaccented syllables in lines of poetry?","Rhyme","Meter","Metaphor","Simile",'b'};
	abc[4] = {" Which of the following is not a poetic tradition?","The Epic","The Comic","The Occult","The Tragic",'c'};

	do {
		duration = (clock() - start ) / (double) CLOCKS_PER_SEC;  
			setcolor(RED);                        			
			gotoXY(69,3);
			cout << maxtime-duration << endl;
		if (duration>=maxtime) {
			t=0;
			break;
		}

		if (srno==i) {
			system("cls");

			srno++;

			answer=abc[i].ans;

			ebod();
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);  
			gotoXY(20,x);	
			cout<<char(186);                         //left-bottom width
			}
			for(int x = 20; x < 103; x++){
			setcolor(CYAN);                    
			gotoXY(x,16);	
			cout<<char(205);
			}
			                                             //bottom-length
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);                   
			gotoXY(103,x);	
			cout<<char(186);
			}                                  //right-bottom width
			


			setcolor(CYAN); 
			gotoXY(103,16);	
			cout<<char(188);
			gotoXY(20,16);	
			cout<<char(200);

			int col=23;                       
			setcolor(BLUE);
			gotoXY(23,5);
			
			cout << "Question "<<srno<<") " <<endl;
			gotoXY(23,6);cout<< abc[i].ques<< endl;
	  		gotoXY(col,8);
			
			setcolor(DARK_YELLOW);
			cout <<" a - " << abc[i].ans1<< endl;
	  		gotoXY(col,9);
			cout <<" b - " << abc[i].ans2<< endl;
	  		gotoXY(col,10);
			cout << " c - " << abc[i].ans3<< endl;
	  		gotoXY(col,11);
			cout << " d - " << abc[i].ans4<< endl;
			gotoXY(45,13);		
			
			cout << " Press Enter to skip ";
			gotoXY(45,14);		
			cout << " Select your Option ==> ";
			
			setcolor(YELLOW);
			gotoXY(45,3);		
			cout << " Your Remaning Time ==> ";

		}

		if(_kbhit()){               
			setcolor(YELLOW);
			gotoXY(70,14);
			a=getch();
			cout<<a;

			if(int(a)==13)
			{       

					gotoXY(30,18);
					setcolor(RED);
				cout << "You skipped this Question";
			} 
			else {
				if(a==answer)
				{
					gotoXY(62,18);
					setcolor(LIME);
					point=point+10;
					cout << "Congratulation You selected right option";
				} 
				else
				 {
					gotoXY(70,18);
					setcolor(GREEN);
					cout << "Correct Option is  ==> "<<answer;
					gotoXY(30,18);
					setcolor(RED);
					cout << "You selected wrong option.";

				}
			}
			getch();
			i++;
		} 
	} while (i<5);
	
	if (i<4) {
		cout<<"\n \t\t\t\t\t Time is up. You failed to attempt all questions"<<endl;
	} 
		        
	getch();
}


 //-----------------------------------------------------QUESTIONS-----------------------------------------------------------------

void q()	
{

	
	system("CLS");
	system("COlOR 0E");	
		
	
	
	setcolor(GREEN);
	gotoXY(50,20);
	cout<<" <<";
	gotoXY(74,20);
	cout<<" >>";
	gotoXY(54,20);
	setcolor(WHITE);
	cout<<"Press Enter Continue";
	Beep(500, 100);
	gotoXY(45,10);
	cout<<"===== Select Field to test your skills =====";
	gotoXY(50,12);
	cout<<"1-->  General Knowledge";
	gotoXY(50,13);
	cout<<"2-->  Programming Language ";
	gotoXY(50,14);
	cout<<"3-->  English Literature";  
	gotoXY(42,16);
	setcolor(CYAN);
	cout<<"Select : ";    
	Beep(500, 100);
	go:                                     
	int choice;
	gotoXY(51,16);
	cin>>choice;

switch(choice)
	{
		case 1:
			{
			system("CLS");
			            
			GK();	
			break;
			}
	case 2:
			{
			system("CLS");
	
			P();
			break;
			}
	case 3:
			{
			system("CLS");		
			E();
			break;
			}

	default:
			
			setcolor(RED);
			cout<<"  \tINVALID CHOICE! \n";
			cout<<"     Enter either 1,2 or 3";
			getch();
			goto go;
	}
		
}



void quiz()
{
	
    q();
    
}

//----------------------------------------------------------------------------------------------------------------------------

void student::getdata()
{	
	point=0;
	cout<<"\nEnter your R.No: ";
	cin>>rollno;
	cout<<"\n\nEnter your Name: ";
	cin.ignore();         
	cin.getline(name,50);
	system("cls");
	quiz();	                    
	obt=point;
	
	calculate();                
	system("cls");
	Result();                  
}



void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("Q.txt",ios::binary|ios::app);   
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student)); 
	cin.get();
}



//-------------------------------------------------------FIRSTSCREEN---------------------------------------------------------//
 
void firstscreen()	
{

	doo :
	system("CLS");		
						setcolor(DARK_YELLOW);
			cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
	
	
	setcolor(GREEN);
	gotoXY(50,20);
	cout<<" <<";
	gotoXY(74,20);
	cout<<" >>";
	gotoXY(54,20);
	setcolor(WHITE);
	cout<<"Press Enter Continue";
	Beep(500, 100);
	gotoXY(45,10);
	cout<<"======Select Following Option ======";
	gotoXY(50,12);
	cout<<"1-->  New Game";
	gotoXY(50,13);
	cout<<"2-->  Instructions";
	gotoXY(50,14);
	cout<<"3-->  Result Record";  
	gotoXY(42,16);
	setcolor(CYAN);
	cout<<"Select : ";    
	Beep(500, 100);
	go:                                     
	int type;
	gotoXY(51,16);
	cin>>type;

switch(type)
	{
		case 1:
			{
			system("CLS");
			
			system("COlOR 3F");            
			write_student();	
			break;
			}
	case 2:
			{
			system("CLS");
	
			info();
			getch();  
			goto doo;
			break;
			}
	case 3:
			{
			system("CLS");		
			setcolor(GREEN);
			class_result();
			
			system("CLS");
			goto doo;
			break;
			}

	default:
			
			setcolor(RED);
	
			cout<<"  \tINVALID CHOICE! \n";
			cout<<"     Enter either 1,2 or 3";
			getch();
			goto go;
	}
		
}
