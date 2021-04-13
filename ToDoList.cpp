//TODOlist.cpp
//cisp 400,Nader S. Opeyany
// 11/17/2019
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include<fstream>
using namespace std;

class todo{
public:
string title;

//to have the object get the string input
void setTitle(){
string a;
cin>>a;
title =a;

}

string getTitle(){
  return title;
}

};

// Specification B1 - Overload «
ostream &operator <<(ostream&cout,todo vari){

  cout<<vari.getTitle()<<"\n";
  return cout;
} 


void greeting();
void printList();

int main(){
greeting();
char lmao;
bool flag=0;
vector <todo>bigBoy(9);
int count =0,element;//increments
do{{
cin>>lmao;
switch(lmao){
  case '+':{ // Specification C1 - + Symbol
  cout<<"Put in your item"<<endl;
    todo a;
    a.setTitle();
    bigBoy[count]=a;

    cout<<"This is what you put in\n"<<endl;
    cout<<bigBoy[count];
    count++;
    
    break;
  }
  // Specification C2 - ? Symbol
  case '?':{
   cout<<"\nThis is your list"<<endl;
  for(int i=0;i<count;i++){
    cout<<bigBoy[i]<<endl;
  }
    break;}

// Specification C3 - - symbol
  case '-':{
    cout<<"Put in the number of which item you wish to change."<<endl;
    cin>>element;
      todo a;
      cout<<"Put in new input, if you want it deleted simply put in space."<<endl;
      a.setTitle();
      bigBoy[element]= a;
    break;}

  // Specification B3 - Quit symbol
  case 'x':{

  flag = true;
  break;}
}
}}while(flag==false);


//after main
//Specification B2 - Save to disk
 ofstream outfile("Heres_your_List!.txt");
      
      for(int i=0;i<bigBoy.size();i++){
        outfile<<bigBoy[i]<<"\n";
      }

      //have to put this in to end the output
      outfile.close();

}//end of main



void greeting(){
  cout<<"Welcome to my to do list.\nEnter a + to add something and a - to delete that item.Enter in ?to see your list and enter in x to exit program."<<endl;
}

/*
void printList(vector<todo> &bigBoy){
  cout<<"\n THis is your list"<<endl;
  for(int i=0;i<bigBoy.size();i++){
    cout<<bigBoy[i]<<endl;

  }
}*/

