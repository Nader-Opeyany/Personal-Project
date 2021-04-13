//Nader S. Opeyany
//cisp 400
// 10/20/2019
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*make an dynamic array  from
a custom type item*/


// Specification B1 - OOP
class item{
public:
char itemDescription[22];
int quantityStore;
int retailCost;
void timeNow();

void inputVariable()
{
  cout<<"Input item Description"<<endl;
 cin.getline(itemDescription,256,'\n'); //22 char of newline
  string d=itemDescription;//overloaded


  while(d.length()>=22 or d.length()<1){
    cout<<"Item Desctription must be less than or"<<" equal to 22 characters."<<endl;
    cin>>d;
  }
  
  cin.clear();

  cout<<"Input quantity of item"<<endl;
  cin>>quantityStore;
  cin.clear();

  cout<<"Input retail Cost(automatically markep up)"<<endl;
  cin>>retailCost;
  retailCost=retailCost*2;
  cin.clear();

  //time is done automatically
  
}

void displayInvetory(){
  time_t tt; 
    struct tm * exactTime; 
    time (&tt); 
    exactTime = localtime(&tt); 
  
cout<<itemDescription<<"\n"<<quantityStore<<"\n"<<retailCost<<"\n"<<asctime(exactTime);//these time functions could use a little tinkering, and by that i mean alot

}


};


//functions
void programGreeting();
void switchCaseTrap(int &);
void insideArray(item*& second,int arraySize);


int main() {

  int input;
  int arraySize =1;
  bool exitProgram = true,more=true;//when false main event loop don
  
  

  programGreeting();
    item* first=new item[arraySize];

do{
cout<<"Choose from the menu, input single digit for your choice"<<endl;

  switchCaseTrap(input);

// Specification C4 - Main Menu
switch(input){
  case 1:
  cin.ignore();
  
        // Specification C2 - Add Option
    first[arraySize-1].inputVariable();
      cout<<"\n This is what you put in"<< endl;
      first[arraySize-1].displayInvetory();
      
        more = true;//needed for dynamic resizing
      break;
  
  case 2:
    //This is the area of code that manageds the changes that happen

    //The inventory falls apart when an inaccessable memory location is reached, specifically inputing bad values
    int change;
    cout<<"Enter in the inventory you want gone"<<endl;
    cin>>change;

      while(change<1){
        cout<<"\nInaccesable storage try again\n"<<endl;
        cin>>change;
      }//this at least fights against negative data entered


    change = change-1;//the element will be modified by one so the
                    //array properly gets the right element

      
      //Specification B2 - Delete Inventory Item
      // Specification B3 - Shrink Dynamic Array
    for(int i=change;i<arraySize;i++){
      first[i] = first[i+1];//literally loop over the one you want gone

    }
      arraySize--;
      more=false;//stops increment of array
      break;
 
  case 3:
    cout<<"\nYou have these items currently:\n";
      // Specification C3 - Display Option


    for(int i =0;i<arraySize-1;i++){
       first[i].displayInvetory();//the minus one is for bounds 
    }
  

        more =false;
    break;

  case 4:
  cout<<"\nYouve decided to exit the program\n"<<endl;
  exitProgram =false;
   
    break;

}
//had to be within the while but not the switch case!
// Specification C1 - Dynamic Array
if(more ==true and exitProgram ==true){
  item* second =new item[arraySize+1];
    for(int i =0;i<arraySize;i++){
    second[i]=first[i];
    
      }
    delete []first;//deletes the first on heap

      first=second;//first pointer equal to seconds improved array

      delete []second;//delets seconds pointer on heap

      second = nullptr;//seconds pointer is closed up but not deleted

      arraySize++;//arraySize expanded by one
      
}

}while(exitProgram == true);

}

void programGreeting(){
  cout<<"\n Salutations! This is an invetory program that will allow you to "<<
  "\n1. Add Inventory"<<
  "\n2. Delete Inventory"<<
  "\n3. Display Inventory"<<
  "\n4. Quit Program\n"<<endl;
}

// Specification C5 - Validate Menu
void switchCaseTrap(int &input){
   
do
{
  cin >> input;
  if(input >= 1 and input <= 4)//needs to be tweaked
                              //so string is caught too,going to try catch block it when i become more profitient with its syntax
  {
    break;
  }
  else
  {
    cout << "Error on Input";
  }
}while(input < 1 or input > 4);
  
}

