//Nader S. Opeyany
//Cisp 400, TTh
//9/9/2019
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;



//functions prototype
//used for error trapping the menu choice
 char menu();

int player(int );//die variable most likely
int comp(int );//"   "
int dieA();

void game();
int main() {
 

 //variables
 string playerName;
 int score = 0;//scoreboard
int resign = 0;
int victory =0;
int defeat =0;
int playerScore = 0;
int tempPlayerScore = 1;
int compScore =0;
//using pointer to save data within a scope
int * p;//used for player
int* pp;//used for computer
char yesOrNo;
 int die = dieA();//randomized die
 bool flag =true ;
 bool secondflag = true;
 bool start=true;
 bool start1 = true;
int compTemp = 0;

// variable that controlls switch alphabet
char choice;

do{
// Specification A3 - Current Date
//theres no method that dosent require a c library as far as i know
//program intro
cout<<"This is a program meant to allow you to play pig with a ai."
<<"The rules are as follows: Each turn, the active player faces a decision (roll or hold): "<<"Roll the die. If it’s is a:1: You lose your turn, and your grand total is tallied. "<< " 2-6: The number you rolled is added to your turn total."<<endl<<endl;

// Specification C2 - Student Name
cout<<"Player enter your name here : ";
cin >> playerName;
cout<<"\n Hello "<< playerName<<endl;




do{
 
 //Specification B2 - Randomize Start
 if (secondflag ==true){
 int z = rand()%2 + 1;
 
 if (z == 1){
   cout<<"Player starts first: "<<endl;
 }
 else if(z==2){ cout<<"Skynet reins supreme and starts first "<<endl;
 //automatically give skynet its turn
  die = dieA();//recalling die function for new value


compTemp += comp(die);// comp(die)? there goes my overlord
compScore = compTemp;

if(compTemp == 1 || compTemp== 2||compTemp==3){
  cout<<"\nYour turn again"<<endl;
  flag = false;
  
}else{
  
 
 comp(die);
 //make it so that when its 3-6, the computer rerolls.
 //idea: make nother function for answers 3-6
}
//didnt have problem here wasnt random selectin turn
cout<<"Current computer Score: "<<compScore<<endl;
// Specification B1 - Track each turn
pp =&compScore;}
 }
//this is only for the first random start




//input for letter choice
cout<<"\n Choose from the following menue, the letters within these"
<<" <> are your single character choices to control the menu\n"<<endl;

cout<<" 1. <R>oll 2. <H>old 3. Re<S>ign 4. <Q>uit"<<endl;




die = dieA();//rerandomizing
choice = menu();//calling menu()


// Specification C3 - REPLACED.
// Specification B3 - Alpha Menu
switch(choice){
  case 'R':


if (die == 1){
  cout<<"You rolled a 1 Skynets turn \n"<<endl;
  die = dieA();//recalling die function for new value


compTemp += comp(die);// comp(die)? there goes my overlord
compScore = compTemp;
if(compTemp == 1 || compTemp== 2||compTemp==3){
  cout<<"\nYour turn again"<<endl;
  flag = false;
  
}else{
  
 
 comp(die);
 //make it so that when its 3-6, the computer rerolls.
 //idea: make nother function for answers 3-6

}

cout<<"Current computer Score: "<<compScore<<endl;

pp =&compScore;


}else if ( die != 1) {//never more than 6
player(die);

playerScore += die;// I wish rolf

cout<<"\n This is your current score : "<<playerScore<<endl;
p =&playerScore;

cout<<" It's your turn again: "<<endl;
}

  break;
//problem here
  case 'H':
  cout<<"\n\nYouve decided to hold your turn "<<"Its the computer turn now"<<endl;
  

compTemp += comp(die);// comp(die)? there goes my overlord
compScore = compTemp;
cout<<"Current computer Score: "<<compScore<<endl;

pp =&compScore;
p =&tempPlayerScore;//for the end while condition


  break;

  case 'S':
  
cout<<"You decide to give up like a failure *whomp whomp whompppp* "<<endl;
resign++;
// Specification B4 – Resign Option
main();     //calling main restarts the game 

  break;

  case 'Q':
  //have to exit the game loop
/*cout<<"Youve decided to exit the game.\n"<<endl;
cout<<" Youve won: "<<victory<<" many games"<<endl;
cout<<"Computer has won "<<defeat<<" many games"<<endl;
*/
start = false;
cout<<"Youve decided to quit."<<endl;
  break;

}
secondflag = false;

if(*p >=  100 ){
  start = false;
}else if(*pp >= 100){
  start = false;
}


// p for player pp for comp
if(*p >=  100 ){
  cout<<"\n\nPlayer wins!"<<endl; 
  victory++;
}else if(*pp >= 100){
  cout<<"\n\nComputer wins!"<<endl;
  defeat++;
}




//game flag is set to true until its not
}while( start==true);



// Specification A2 - Group Stats
cout<<" Youve won: "<<victory<<" many games"<<endl;
cout<<"Computer has won "<<defeat<<" many games"<<endl;

cout<<"\n\n\n Do you want to play again? y/n "<<endl;
cin>>yesOrNo;
// Specification A1 - Main Event Loop
if(yesOrNo == 'y'){
  cout<<"youre playing again\n"<<endl;
  start1 =true;
  playerScore=0;
  compScore =0;

}else if(yesOrNo == 'n'){
cout<<"Goodbye"<<endl;
start1 =false;
}
}while(start1==true);


//end of main
}



//the function used to error trap
char menu(){
char choiceB;

cin>>choiceB;
cin.ignore();//clear keyboard buffer

//variable

//Specification A4 - Upper and Lower Case
choiceB = toupper(choiceB);

//cout<<choiceB<<endl;

if(choiceB == 'R'){
return choiceB;
}else if(choiceB == 'Q'){
return choiceB;

}else if(choiceB == 'S'){
return choiceB;

}else if(choiceB == 'H'){
return choiceB;

}else{
  
 // Specification C4 - Bulletproof Menu
  cout<<"incorrect input retry "<<endl; 
menu();

}



return 0;
}

//Player function
int player(int die){
int playerScoreb;

if(die == 1){
  cout<<"Rolled 1, no points added and lost your turn scrub.\n "<<endl;
return 0;
}
else{//die >1
cout<<"you rolled : "<<die<<". That many points are added to your total"<<endl;

}

  return playerScoreb;
}

int comp(int die){//die is randomized each roll

if(die <4){
  cout<<" \nComputer rolled: "<< die<<" and decided to hold\n"<<endl;
  
  
}else{
  cout<<" \nComputer rolled: "<< die<<" and decided to reroll\n"<<endl;
 

}

 
  
  
  return die;
  }






//for the randomized die
int dieA(){
 // Specification C1 - Time Seed
 srand((unsigned)time(NULL));

int die = rand()%6+1;//the die 
  
  
  return die;

}

// lets see if this works
void game(){



}