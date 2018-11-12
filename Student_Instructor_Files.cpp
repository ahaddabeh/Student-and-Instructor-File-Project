#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

class StudentDetails{
	public:
		string PasswordGenerator(char x, int l);
		void MakeUserName();
		void Display(char g);
		void Insert(char s);
		void Update(char n);
		void PasswordChanger();
                
};


void StudentDetails::MakeUserName(){
	ofstream outFS;
        ifstream inFS;
        string name;
        char decision;
	
        int length;
        string pass;
        int off;
        string line;
        bool go = true;
         
        while(go == true)
        {
            
            inFS.open("User/passwords.txt");
        if (!inFS.is_open()) {
      cout << "Could not open file." << endl;
      return;
        }
			cout<<"Enter a username: ";
			cin>>name;
			cout<<endl;
	
              
                        while(!inFS.eof())
                        {
                            getline(inFS,line);
                            if ((off = line.find(name, 0)) != string::npos) 
                            {
                                cout << "Username is already exists, enter another username: "  <<endl;
                                inFS.close();
                                break;
                            }
                           
                        }
                        if(inFS.eof()){
                            inFS.close();
                            go=false;
                        }
        
        }
        
        
        outFS.open("User/passwords.txt", fstream::app);
	if (!outFS.is_open()) {
      cout << "Could not open file." << endl;
      return;
   }                   outFS<<endl;
                        outFS<<name;
                        outFS<<" ";
			cout<<"Enter a length for the password: ";
			cin>>length;
			cout<<endl;
			cout<<"For new password, enter 'z' for all digits, 'y' for all letters, or 'x' for anything: ";
			cin>>decision;
                        cout<<endl;
			if(decision=='z'){
                             pass = PasswordGenerator('D', length);
                             
			}
			else if(decision=='y'){
				 pass =PasswordGenerator('L', length);
			}
			else if(decision=='x'){
				 pass =PasswordGenerator('E', length);
			}
                        cout<<pass;
                        cout<<endl;
                        outFS<<pass;
                      
                        
	outFS.close();
	return;
};


void StudentDetails::PasswordChanger(){
    string userName;
    ofstream outFS;
    string findInfo,deletion;
    ifstream inFS;
    string findUser;
    string pass= " ";
    string information;
    char decision;
    string line;
    string newPass;
    int length;
    inFS.open("User/passwords.txt");
    if (!inFS.is_open()) {
      cout << "Could not open file." << endl;      
      return;
   }
    outFS.open("User/temp.txt");
    if (!outFS.is_open()) {
      cout << "Could not open file." << endl;      
      return;
    }
    cout<<"Enter username: ";
    cin>>userName;
    while(!inFS.eof()){
        inFS>>findUser;
        if(findUser==userName){
            inFS>>information;
            cout<<"Enter password: ";
            cin>>pass;
            while(pass != information){
                  cout<<"Wrong Password, try again, Enter password: ";
                  cin>>pass;
            }
                
                    deletion = userName + " " + pass;
                    cout<<"Enter length of password: ";
                    cin>>length;
                    cout<<endl;
                    cout<<"For new password, enter 'z' for all digits, 'y' for all letters, or 'x' for anything: ";
			cin>>decision;
                        cout<<endl;
			if(decision=='z'){
                             newPass = PasswordGenerator('D', length);
                             
			}
			else if(decision=='y'){
				 newPass =PasswordGenerator('L', length);
			}
			else if(decision=='x'){
				 newPass =PasswordGenerator('E', length);
			}
                        
                
            }
            
        }
        
    
    inFS.close();
            inFS.open("User/passwords.txt");
            while(getline(inFS,line)){
                if(line!=deletion){
                    outFS<<line<<endl;
                }
            }
            outFS<<userName<<" ";
            outFS<<newPass;
            outFS.close();
            inFS.close();
            remove("User/passwords.txt");
            rename("User/temp.txt", "User/passwords.txt");
};

string StudentDetails::PasswordGenerator(char x,int l){
	char password[l];
	int i;
	
	vector<char> numbers={'0','1','2','3','4','5','6','7','8','9'};
	vector<char> letters={'a','b','c','d','e','f','g','h'
    ,'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A', 'B','C','D',
    'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z'};
	vector<char> everything={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h'
    ,'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A', 'B','C','D',
    'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '='};
	
	
	
	/*ofstream outFS;
	outFS.open("/User/passwords.txt");
	if (!outFS.is_open()) {
      cout << "Could not open file." << endl;
      return; 
   }*/
        string pwd;
	if(x=='D'){
		srand(time(0));
		for(i=0;i<l; i++){
			password[i]=numbers.at(rand()%10);
			pwd +=password[i];
                }
                        return pwd;

	}
	else if(x=='L'){
            srand(time(0));
		for(i=0;i<l; i++){
			password[i]=letters.at(rand()%52);
			pwd+=password[i];
    }
                return pwd;
	}
	else if(x=='E'){
            srand(time(0));
		 for(i=0;i<l; i++){
			password[i]=everything.at(rand()%73);
			pwd+=password[i];
                 }
                        return pwd;
	}
	//outFS<<endl;
	//outFS.close();

};

void StudentDetails::Display(char g){
	ifstream inFS;
	string findID;
        string scores;
	inFS.open("Data/scores.txt");
	if (!inFS.is_open()) {
      cout << "Could not open file." << endl;      
      return;
   }

	
	
	if(g=='S'){ 						/*Display scores of a student*/
		string ID;
		cout<<"Enter ID: ";
		cin>>ID;
		cout<<endl;
		while(!inFS.eof()){
			inFS>>findID;
			if(findID==ID){
                            getline(inFS, scores);
                            cout<<scores<<" ";
                        }
                                    
                   }
		cout<<endl;
	}
		
	
	
		
	
	else if(g=='J'){	 			/*Display average score of a student*/
            int numScore;
            //vector<int> numScores;
                int sum=0;
		int counter=0;
		float avg;
		string ID;
		cout<<"Enter ID: ";
		cin>>ID;
		cout<<endl;
		string findID;
		while(!inFS.eof()){
			inFS>>findID;
			if(findID==ID){
                            while(inFS>>numScore){
                                if(numScore != ' '){
                                    cout<<numScore<< endl;
                                    sum+=numScore;
                                      counter++;
                                }
                                if(inFS.peek()=='\n'){
                                     break;
                               }
                            }
                        }
                }
                 avg = float(sum)/counter;
		cout<<fixed<<setprecision(2)<<avg;
                cout<<endl;
        }
		
		
	else if(g=='C'){                /*Display scores of an exam*/
            int numScore;
            int examNum;
            int counter=0;
            string ID;
            cout<<"Enter which exam scores you would like to see: ";
            cin>>examNum;
            while(!inFS.eof()){
                inFS>>ID;
                cout<<ID<<": ";
                for(int i=0;i<examNum;i++){
                    inFS>>numScore;
                    
                }
                cout<<numScore;
                cout<<endl;
                while(inFS.peek()!='\n'){
                    if(inFS.eof()){
                        break;
                    }
                    inFS>>numScore;
                }
            }
        }
        
        else if('V'){
            int numScore;
            int examNum;
            string ID;
            float average;
            int sum=0;
            int counter=0;
            cout<<"Enter which exam scores you would like to see the average of: ";
            cin>>examNum;
            while(!inFS.eof()){
                inFS>>ID;
                for(int i=0;i<examNum;i++){
                    inFS>>numScore;
                }
                sum+=numScore;
                counter++;
                while(inFS.peek()!='\n'){
                    if(inFS.eof()){
                        break;
                    }
                    inFS>>numScore;
                }
            }
            average=float(sum)/counter;
            cout<<fixed<<setprecision(2)<<average;
            cout<<endl;
            }
           
        
	
	
	
	
	
	inFS.close();
	
	
return;	
};


void StudentDetails::Insert(char s){
	ifstream inFS;
        inFS.open("Data/scores.txt");
	if (!inFS.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }
        
        
	int exam;
        if(s=='N'){
            istringstream SS;
            ofstream outFS;
            outFS.open("Data/temp.txt", fstream::app);
            if (!outFS.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }
            
            string newScore;
            string line;
            string ExamScores;
            cout<<"Enter new exam scores: ";
            cin.ignore();
            getline(cin,ExamScores);
            SS.str(ExamScores);
            string ID;
            string s;
            while(!inFS.eof()){
                  
             getline(inFS, line);
                    //outFS<<line;
                    //SS>>newScore;
                    //outFS<<' '<<newScore <<endl;
             if(line!=""){
             line.append(" ");
             SS>>ExamScores;
             line.append(ExamScores).append("\n");
             cout<<line;
             outFS<<line;
             }
            }
         
                
            
            outFS.close();
            inFS.close();
            remove("Data/scores.txt");
            rename("Data/temp.txt", "Data/scores.txt");
        }
	
	
	
	if(s=='B'){
           istringstream SS;
            ofstream outFS;
            outFS.open("Data/scores.txt", fstream::app);
            if (!outFS.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }
            int newScore;
            srand(time(0));
            string ExamScores;
            cout<<"Enter new exam scores: ";
            cin.ignore();
            getline(cin,ExamScores);
            SS.str(ExamScores);
            outFS<<"\n"<<"U"<<rand()%10<<rand()%10<<rand()%10<<" ";
            outFS<<ExamScores;
            outFS.close();
        }
        
        
                
                
	
		
	
	//outFS.close();
	return;
	
	
};

void StudentDetails::Update(char n){
    if(n=='Y'){
        ifstream inFS;
        inFS.open("Data/scores.txt");
	if (!inFS.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }
        ofstream outFS;
        outFS.open("Data/temp.txt", fstream::app);
        if(!outFS.is_open()){
             cout << "Could not open file." << endl;
            return; 
        }
        string ID;
        string findID;
        string scores;
        istringstream SS, BS;
        int change;
        char decide;
        int examNum;
        int counter;
        int fuckThis;
        
        cout<<"Enter user ID: ";
        cin>>ID;
        cout<<endl;
        cout<<"Enter 'Y' if you would like to add points "
                "or 'N' if you would like to deduct points: ";
        cin>>decide;
        cout<<endl;
        cout<<"Enter amount of points: ";
        cin>>change;
        cout<<endl;
        
    }
    
    
    else if(n=='Q'){
        
    }
};

int main(){
	int boolean=1;
	StudentDetails instructor;
	int option;
	char decision;
	char which;
	string name;
	while(boolean==1){
		cout<<"Menu"<<endl;
		cout<<"Enter '1' to create a new user"<<endl;
		cout<<"Enter '2' to change password"<<endl;
		cout<<"Enter '3' display scores of a student"<<endl;
		cout<<"Enter '4' to display scores of an exam"<<endl;
		cout<<"Enter '5' to display avg score of a student"<<endl;
		cout<<"Enter '6' to display avg score of an exam"<<endl; 
		cout<<"Enter '7' to insert scores of a new exam to all students"<<endl;
		cout<<"Enter '8' to insert scores of all exams of a student who is not in file"<<endl;
		cout<<"Enter '9' to update an exam score of a student"<<endl; 
		cout<<"Enter '10' to update an exam score of every student"<<endl; 
		cout<<"Enter '11' to exit"<<endl;
		cin>>option;
                
                
                switch(option){
                    case 1:  {
                        instructor.MakeUserName();
                        break;
                    }
                    case 2:
                        instructor.PasswordChanger();
                        break;
                    case 3:
                        instructor.Display('S');
                        break;
                    case 4:
                        instructor.Display('C');
                        break;
                    case 5:
                        instructor.Display('J');
                        break;
                    case 6:
                        instructor.Display('V');
                        break;
                    case 7:
                        instructor.Insert('N');
                        break;
                    case 8:
                        instructor.Insert('B');
                        break;
                    default:{
                        boolean = 0;
                    }
                    
                    
                }
        }
		/*if(option=='a'){
			
		}
		
		else if(option=='b'){
		}
		
		else if(option=='c'){
			instructor.Display('S');
		}
		
		/*else if(option=='d'){
		}
		
		else if(option=='e'){
			instructor.Display('J');
		}
		
		/*else if(option=='f'){
		}*
		
		else if(option=='g'){
			instructor.Insert('N');
		}
		
		else if(option=='h'){
			instructor.Insert('B');
		}
		
		/*else if(option=='i'){
		}*/
		
		/*else if(option=='j'){
		}*
		
		else if(option=='k'){
			boolean==0;
		}
	*/
	
	
	
	
	
	
	
	return 0;
}