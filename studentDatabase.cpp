 #include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>  
using namespace std;



string trim(const std::string &str) {
    // Find first non-space character
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return ""; // If all spaces, return empty string

    // Find last non-space character
    size_t last = str.find_last_not_of(" \t\n\r");

    // Extract substring between first and last non-space characters
    return str.substr(first, last - first + 1);
}




using namespace std;

class Instructor {
private:
    string name, password; // Variables to hold signup data

public:
    void signup() { // Sign up function to register user
        system("cls");
        cout << "Sign up" << endl;
        cout << "-------" << endl;

        cout << "Username: ";
        cin >> name;            // this stores the user name of the instructor
        cout << endl << "Password: ";
        cin >> password;         // the password of the instructor which will be used to login

        
        ofstream outputFile("signup.txt");
        if (!outputFile) {                // Ensure file opened successfully
            cerr << "Error: Unable to open file for writing." << endl;
            return;
        }

        outputFile << name << endl << password << endl;    //saving the name and password to the signup file
        outputFile.close();

        cout << "Wait to log in..." << endl;
        system("cls");
        login(); // Proceed to login after signup
    }

    void login() {
        system("cls");
        cout << "Sign in" << endl;
        cout << "-------" << endl;

        string userName, userPassword;
       
        ifstream inputFile("signup.txt");    //retrieving the signup file of the user
        if (!inputFile) {      // Check if file exists and if it doesn't, it prompts you
            cerr << "Error: No signup data found. Please sign up first." << endl;
            signup();
            return;
        }
               // Meaning the file exists then
        inputFile >> name >> password; // Read stored credentials of the instructor
        inputFile.close();

        cout << "Username: ";
        cin >> userName;
        cout << endl << "Password: ";
        cin >> userPassword;

        if (name == userName && password == userPassword) {   //when the name and password is correct
            cout << "Logged in successfully!" << endl;
        } else if ((name == userName && password != userPassword) || 
                   (name != userName && password == userPassword)) {   //this is when either one of them is correct
            cout << "Either username or password is incorrect." << endl;
            login();      // Retry login
        } else {             //Anything else like both been incorrect
            cout << "Details not found, please sign up." << endl;
            signup(); // Redirect to signup
        }
    }
};




class Electrical{
	
	private:
	//	int nStudents=0;
	    string name,indexNumber;        // Particulars of students
		vector<string> students;       //A student vector to house all the names
			vector<string> indexNumbers;  
		  int tony;
		  int* ptrtony;
		
	
	public:	
	     void addStudent(){
	     	   system("cls");
	     	clearStudents();
	     	
	     	cout<<"Name "<<"\t\t\t\t\t"<<"Index Number"<<endl;
	     	
	     	  // ofstream outputFile;   //Now i gotta store the details of all students using the file approach
	     	   ofstream outputFile("Sdetails.txt",ios::app);     //bringing the append mode over here instead of inputFile 
					if(!outputFile){
						cerr<<"Error: Unable to open the file for writing"<<endl;
						return;
					}  
					  
					     	for(int i; ;i++){
			 cout<<(i+1)<<". ";
	     	cin>>name;
			 
			 
			   if( name=="q"||name=="Q") //Using a loop to get students names if a name is q||Q it quits
	     	 break;     //To skip any remainging alteration but the whole program isn't exited entirely 
	     	//Get the name of each student at a time, with the help of the private declare virable 'namee
	     	students.push_back(name);   //It adds the name taken initially and adds it to the vector
	     	
	     	
	     	   
	     	  
	     	
	              
	              
	              	
	              	cout<<"\t\t\t\t\t";
	              	cin>>indexNumber;
	              	indexNumbers.push_back(indexNumber);
				  
	              outputFile<<(i+1)<<". "<<trim(name)<<"\t\t\t\t\t"<<trim(indexNumber)<<students.size()<<endl;
	              
	              cout<<endl;
	
	ptrtony= &i;	
	}
	  
	
	
	cout<<endl;
	
	 outputFile.close();           //The file should be closed outside the loop
	
	    	cout<<"The current class size is : "<<students.size();  //This allows you to get to know the size of the class after adding a name
		    cout<<endl;
		}
		
		
		
		
		
	void displayStudents(){     //The function to display all the students
		     system("cls");
		  cout<<"NAME"<<"\t\t\t\t\t"<<"INDEXNUMBER"<<endl;
		    ifstream inputFile;   
		    inputFile.open("Sdetails.txt");   //importing the file of the details of the students
		    
		    	if(!inputFile){
			cout<<endl<<"No student at the moment. Get started\? "<<endl;
			
		int option;
		   cout<<"1.Press '1' to Add students\n";
		   cin>>option;
		      switch(option){
		      	  case 1:
		      	  	addStudent();
		      	  	break;
		      	  
				  default:
				    cerr<<"Invalid input\n";		
			  }
			
		}
		    
		    
		if(inputFile.is_open()){     //Making sure the right file is opened
			
			
			string line;    //This variable is going to read the store data by line
			
			while(getline(inputFile,line)){
				
				cout<<line<<endl;              //reading the written files to the console
				                           
			}
			
			cout<<endl;
			
			
		}
	
		
		
			
		
			  
		
	}
	
	
	
	
	
	
 	void addToExisting() {
    system("cls");
   
    // Open the file to check if it exists
    ifstream inputFile("Sdetails.txt");
    if (!inputFile) { 
        cerr << "Error: Class not found. Please create a class first." << endl;
        return;
    }

    // Display existing records
    cout << "Current class records:" << endl;
    cout << "NAME" << "\t\t\t\t\t" << "INDEXNUMBER" << endl;
        
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
        students.size();
        
    }
    inputFile.close(); // Closing the file after reading

    // Opening the file in append mode to add new records
    ofstream outputFile("Sdetails.txt", ios::app);     //it helps to modify the file at hand without overwriting it
    if (!outputFile) {
        cerr << "Error: Unable to open the file for appending." << endl;
        return;
    }

    
        int currentSize=*ptrtony;   //ptrtony holdds the size of the location in line 135. so that it can loop from where it ended
    
    for(int j=0; ;j++){
	
         cout<<((students.size())+1)<<". ";
        cin>>name;
             
             outputFile <<trim( name) << "\t\t\t\t\t" <<trim( indexNumber) << endl;
        students.push_back(trim(name));
        
        if (name == "q" || name == "Q") { // Exit condition
            break;
            
            
             cout<< "\t\t\t\t\t";
        cin >> indexNumber;

        // Add the new student details to the file and vectors
        
        indexNumbers.push_back(trim(indexNumber));
        outputFile<<students.size();
       cout<<endl;
            
        }

         
    }
     cout << "Student added successfully!" << endl;
    outputFile.close(); // Close the file after writing
    cout << "All new students have been added!" << endl;
}	
		
		
		
		void clearStudents(){
		       ofstream outputFile;
			   outputFile.open("Sdetails.txt",ios::trunc);    //opens the file in truancated mode to be modified
			   if(outputFile.is_open()){
			   		students.clear();         //an inbuilt function clears the vector
			cout<<"All previous students have been cleared\n";
			     outputFile.close();
			   }	
		      else{
		      	
		      	cout<<"Failed to open the file\n";
			  }
		}
		
		
		void inputMarks(){
			        
			        
			        ifstream inputFile;
			        inputFile.open("Sdetails.txt");
			        if(!inputFile){
			        	cerr<<"File not found\n";
			        	return; 
					}
					
					vector<string> searchIndexVector;
					string line;
			        
			         while (getline(inputFile,line)) { // Reads index and name
                            searchIndexVector.push_back(line);
                            }
                            
                            
			        
				
					cout<<"Index number: ";
			       string searchIndex;
			       
			      
				   bool found= false;
				   
			        cin>>searchIndex;
			       
			        for(int i=0; i<indexNumbers.size() ;i++){
			        	cout<<"Hello";
			        	
			        	
			        	
			        	if(searchIndex==indexNumbers[i]){
			        	found = true;
			        	break;
						}
						
					
					            if(found==true){
					            	cout<<"Student found";
								}
			        	        else{
			        	        	cout<<"Student not found";
								}
			        	      
						    
					}
			        
			        
			                                
			     cout<<endl;
			
		      
		inputFile.close();
		}
				
				
				
				
		void numberOfStudents(){
			ifstream inputFile;
			inputFile.open("Sdetails.txt");
			
			if(inputFile.is_open()){
			
			for(int i=0; ;i++){
			inputFile>>students[i];
			
	
			
			inputFile.close();
		}
		cout<<"There are " <<students.size()<< " students in the class atm";		  
	}
}
};
				    
				    	   


				    
				    
		    	
		    	int main(){
		    		  
		    		Instructor teacher;     // An instance of the instructor class
		    		Electrical l100;   //This is an instance of the class electrical, in this case it's for l100's
		    		cout<<"1. Sign up"<<endl;
		    		cout<<"2. log in"<<endl;
		    		int option;cin>>option;
		    		
		    		switch(option){
		    			
		    			case 1:
		    				teacher.signup();
		    				break;
		    			case 2:
		    				teacher.login();
						    break;
							
						default:
						   cout<<"Invalid input";		
		    			
					}
		    		
		    		
		    		//Now, the user has been loggin so let's continue
		    
					
		    		system("cls");
		    		cout<<"1. Add to a 0 class size "<<endl;   //This is fully developed
		    		cout<<"2. Add to an existing class "<<endl;   //Hope to develop this too sooner
		    		cout<<"3. Display students "<<endl;  //displayig existing students
		    		cout<<"4. Input marks\n";
		    		cout<<"5. Class size\n";
		    		cin>>option;cout<<endl;
		    		system("cls");
		    		
		    		//using a switch statement for the display above
		    		switch(option){
		    			case 1:
		    				l100.addStudent();
		    				break;
		    			case 2:
		    				l100.addToExisting();
						    break;
							
						case 3:
							l100.displayStudents();
						    break;
						case 4:
						l100.inputMarks();
						    break;
						    
						case 5:
						  l100.numberOfStudents();
						    break;
													 
						default:
						cout<<"Invalid input";			
					}
		    		   
		         
		    		cout<<"Press Enter to exit";
		    		getchar();
		    		getchar();
		    	
		    		
		    		return 0;
				}
