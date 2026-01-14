#include <iostream>
using namespace std;

struct travelagency {  //structure for travel agency
    string name;    //package name
    string departure;  //departure city
	string destination;                //destination city                                      
    float fare;              //fare/rent...
    int seats;     //total number of seats
};

void menu(){
	cout<<"   1. Owner Menu"       <<endl;   //menu functions
	cout<<"   2. Traveller's Menu"  <<endl;}


void adminmenu(){
	cout<<"  1.Create a new Package " <<endl;
	cout<<"  2.Update and Delete Section" <<endl;          //menu function
	cout<<"  0.Main menu"   <<endl;
}


void adminmenu2(){
		cout<<"    1. List of  added  Packages"<<endl;
		cout<<"    2. Modify Package"<<endl;              //menu function
		cout<<"    0. Return to Main Menu"<<endl;
}

void submenuadmin3(){
	cout << "1. Return to main menu" << endl;
    cout << "2. Modify Train" << endl;
    cout << "3. Delete Train" << endl;                   //menu function
    cout << "Enter choice:" << endl;  
}
int main()
 {
    int n, choice, tickets, total;       //  n variable for total packages we want to add  //tickets and total to calcute bill for customer //choice to control if else
    travelagency kashmirtravels[100];          // object of structure with array of size 100   
    while(true){   //while loop to run program endlessly
    	

    	system ("cls");        //clear screen function
menu();
int option,suboption;
cin>>option;
if(option==1){
	int pin=1234;
cout<<"   Enter your Pin "<<endl;                //admin pin 1234
cin>>pin;
if(pin==1234){
         cout<<"  Kashmir Travels  "<<endl;
adminmenu();
cin>>suboption;
if(suboption==1){
	  //  admin creates or adds a new package
   	cout<<"  Total no of Packages"<<endl;
	cin>>n;
	 for (int i = 0; i < n; i++) {
        cout << "Enter Package " << i + 1 << " Name: "<<endl;
  cin>>kashmirtravels[i].name;
        cout << "Enter Departure City " << i+1 << endl;
   cin >>kashmirtravels[i].departure;                  //entry of a new item explained in video
        cout<<"Enter Destination City" << i+1 <<endl;
   cin >>kashmirtravels[i].destination;
        cout << "Enter Fare for Trip " << i+1  << endl;      
cin >>kashmirtravels[i].fare;
cout<<"Total no of seats in this Package" << i+1<<endl;
cin>>kashmirtravels[i].seats;
}
cout<<"press 0/enter to return to main menu"<<endl;
cin.ignore();
cin.get();
}
else if(suboption==2){
	adminmenu2();
	int select;
	cin>>select;
	switch(select){
		case 1:
			 // Display menu to user
    cout << "  Kashmir Travels" << endl;
    for (int i = 0; i < n; i++) {           //viewing list
      
           cout << i + 1 << ". " << kashmirtravels[i].name << " (" << kashmirtravels[i].departure<<" to "<< kashmirtravels[i].destination<< ") - Rs" 	<< kashmirtravels[i].fare	<< "Available seats : " << kashmirtravels[i].seats << endl;

    }
cin.ignore();
cin.get();
    break;
    case 2:
    	 for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << kashmirtravels[i].name << " (" << kashmirtravels[i].departure<<" to "<< kashmirtravels[i].destination<< ") - Rs" 	<< kashmirtravels[i].fare	<< "Available seats : " << kashmirtravels[i].seats << endl;
        

    }
    cout<<" Enter Package Number you  want to edit"<<endl;
    cin>>choice;
    
    cout << "0. Main Menu" << endl;
    cout << "1. Modify Package " << endl;
    cout << "2. Delete PacKage " << endl;
    cout << "Enter choice:" << endl;
   int subchoice;
    cin>>subchoice;

    if(subchoice==0){
	menu();
	}
	else if(subchoice==1){           //update function explained in video
		  cout << "Enter new name for Package: " <<endl; 
		       cin >>kashmirtravels[choice - 1].name;
        cout << "Enter New Departure City for Package: "<<endl;      
		  cin >> kashmirtravels[choice - 1].departure;
		  cout << "Enter New Destination City for Package: "<<endl;      
		  cin >> kashmirtravels[choice - 1].destination;
        cout << "Enter New fare for Package: " <<endl;
		 cin >>kashmirtravels[choice - 1].fare;
        cout << "Package information updated successfully"<<endl;
    }
	else if(subchoice==2){
		 for (int i = choice - 1; i < n - 1; i++) {        //delete function explained in video
            kashmirtravels[i] = kashmirtravels[i + 1];
        }
        n--;
        cout << "Package deleted successfully"<<endl;
	}
	break;
	default:
		cout<<"Invalid entry"<<endl;
	break;
	}
	
	
	}
}
else{
	cout<<" Wrong Pin Try Again "<<endl;
}
cin.ignore();
cin.get();
}
else if(option==2){
	cout<<"  1. kashmirtravels  Packages  informations"<<endl;
	cout<<"  2.  Book Package"<<endl;           //customer menu
	cout<<"  0. Main Menu"<<endl;
	
	  cin>>choice;
if(choice==0){
	
	menu();
}	  

else if(choice==1){          
	  for (int i = 0; i < n; i++) {          //showing list to customer
        cout << i + 1 << ". " << kashmirtravels[i].name << " (" << kashmirtravels[i].departure<<" to "<< kashmirtravels[i].destination<< ") - Rs" << kashmirtravels[i].fare << endl;
    }
    cin.ignore();
    cin.get();
      } 
else if(choice==2){
  cout << "Package Booking Menu" << endl;           //bookimg function
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << kashmirtravels[i].name << " (" << kashmirtravels[i].departure<<" to "<< kashmirtravels[i].destination<< ") - Rs" << kashmirtravels[i].fare << endl;}
	    // Ask user for number of tickets and calculate total fare
	    cin>>choice;
    cout  << "Enter number of tickets:"<<endl;
cin >> tickets;
    total = kashmirtravels[choice - 1].fare * tickets;
    
    // Check if enough seats are available
    if (tickets <= kashmirtravels[choice - 1].seats) {

        // Update available seats
        kashmirtravels[choice - 1].seats -= tickets;
    // Display bill
    cout << "Package: " << kashmirtravels[choice - 1].name << endl;
    cout << "Departure from : " <<  kashmirtravels[choice - 1].departure <<endl;
    cout << "Destination: " << kashmirtravels[choice - 1].destination << endl;
    cout << "Fare: Rs" << kashmirtravels[choice - 1].fare << endl;
    cout << "Number of tickets: " << tickets << endl;
    cout << "Total fare: Rs" << total << endl;
	 cin.ignore();
    cin.get();
	}
    else{
    	cout<<"not enough seats"<<endl;
	}
	cin.ignore();
	cin.get();
	
	}
}
      }}

    	
