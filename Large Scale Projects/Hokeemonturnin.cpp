//Hokeemon.cpp
//cisp 400,Nader S. Opeyany
// 12/8/2019
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Specification C2 - Virtual Class Creature
class creature{
public:
string name;
int hunger = rand() %5;
int boredom =rand()% 5;
virtual string setName(){name ='a';
 return name;}//set to nothing

};

// Specification C3 - Child Class
class demonSpwan:public creature{
public:
// Specification A1 - Critter Name
string setName(){
  cout<<"First Enter your little monsters first name!No spaces or numbers please."<<endl;
  cin>>name;
  cout<<"Your creatures name is "<<name<<"."<<endl;
  cout<<"Your creatures hunger is "<<hunger<<"."<<"And its boredom is "<<boredom<<"."<<endl;
  
return name;
}
// Specification X1 - Overload Operator cout
friend ostream& operator<<(ostream& cout, demonSpwan &a);
void passTime();
};
//using money symbol output name of Hokeemon
ostream & operator << (ostream &cout, demonSpwan &a) 
{ 
    cout << a.name; 
    return cout; 
}

// Specification C1 - PassTime()
void demonSpwan::passTime(){
  hunger++;
  boredom++;
}

// Specification B3 - Second Child Class
class doubleDemonSpwan:public creature{
  public:
  string setName(){
    cout<<"If this has popped up something has gone terribly wrong hahah."<<endl;
    return name;
  }
  friend ostream& operator<<(ostream& cout, doubleDemonSpwan &b);
};
// Specification X2 - Overload Operator cout
ostream & operator << (ostream &cout, doubleDemonSpwan &b) 
{ 
    cout << b.name; 
    return cout; 
}

void greeting();
int main() {
bool game = true;
int choice;
int happiness=0;
greeting();
demonSpwan a;
a.setName();

cout<<"Once again, your little monsters name is "<<a.name<<endl;
 
cout<<"\nNow choose from the menue to interact with your Hokeemon."<<endl;

 do {
cin>>choice;

// Specification B1 - Validate Input
while(!cin)
{
    cin.clear();
    cin.ignore();
    cout << "Enter VALID choices only \n";
    cin>>choice;
}
cin.clear();
switch(choice){
  case 1:
   if(a.hunger>10){
    cout<<"Youve lost the game!"<<endl;
    game=false;
  }
   if(a.boredom>20){
    cout<<"Youve lost the game!"<<endl;
    game=false;
  }

    cout<<"You've decided to listen to your Hokeemon"<<endl;
    cout<<"Hunger is "<<a.hunger<<" while boredom is  "<<a.boredom;
      a.passTime( );
        break;
  case 2:
  cout<<"You've decided to feed your Hokeemon."<<endl;
  if(a.hunger>4){
    a.hunger=a.hunger-4;
  }else {
    a.hunger=0;
  }
  if(a.hunger>10){
    cout<<"Youve lost the game!"<<endl;
    game=false;
  }

    break;

  case 3:
   cout<<"You've decided to play with your Hokeemon."<<endl;
  if(a.boredom>4){
    a.boredom=a.boredom-4;
  }else {
    a.boredom=0;
  }
  if(a.boredom<4){
    cout<<"Your baby is happy "<<endl;
    //Specification B2 - Moods
    happiness++;
  }else if(a.boredom>9){
    cout<<"Your baby is ok"<<endl;
  }else if(a.boredom>14){
    cout<<"Your baby is Frustrated"<<endl;
  }else if(a.boredom>15){
    cout<<"Your baby is ANGRY "<<endl;
  }
  if(a.boredom==20){
    cout<<"Youve lost the game!"<<endl;
    game=false;
  }
    break;
  case 4:
    game =false;
    cout<<"You've decided to exit"<<endl;
    break;
}

 }while(game==true);

  cout<<"Youre Hokeemon was happy this many times "<< happiness;
}

void greeting(){
  cout<<"Welcome to Nader (the mad programmer) Hokeemon program.\nIf your Hokeemon hunger score goes over 10 or its boredom goes over 20 it dies.Play with it and feed it to keep that from happening.\nIts moods are as follows.Boredom moods: >15: Mad, 10-14: Frustrated, 5-9: OK, 0-4, Happy.\nYour choices are: 1.listen to how your Hokeemon is doing \n2.Feed Hokeemon \n3.Play with Hokeemon\n 4.Quit\nPress the number of the action you want."<<endl;
}
