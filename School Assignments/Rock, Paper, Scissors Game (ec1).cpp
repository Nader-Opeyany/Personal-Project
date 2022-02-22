// Rock, Paper, Scissors Game (ec1).cpp
// Nader S.Opeyany, cisp 400
// 9/1/19

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



int main() {
//variables
bool continueGame = true;// while flag that keeps game going unless the player presses 2 to exit
int menuChoice,compChoice;

int contgame;//meant to modify the continueGame bool.

int timesPlayed = -1;//count. of how many times timesPlayed

int tie = 0;

int compWin =0;//count of computer wins

int playerWin =0;//count of Human wins

//random number seed
srand (time(NULL));

//random number generator between 1-3 for computer choice
int num = rand()%3+1;


//begining of  do while loop that determins playthroughs
do{
//Into message r
cout << "This is a program designed by Nader S. Opeyany meant to simulate a game of Rock,Paper,Scissors!\n";

//describing program to user
cout<<"You have a menue of 4 options to choose from, they are (1)Rock,(2)Paper,(3)Scissors and (4)exit game.\n"<<"after you choose your option the computer will randomly choose its own and you will be notified if youve won,tied or loss.\n"<<"Pressing the number 4, the number of times youve played will be displayed,computer wins and player wins.\n\n";
cout<<"Enter in your desired option now \n"<<endl;
cin>>menuChoice;



switch(menuChoice){
  case 1: 
  cout<<"You choose rock, the computer choose "<<endl;
if(num == 1){
 
  cout<<"The computer also choose rock, its a tie!"<<endl;
  tie++;
}else if(num==2){
  cout<<"The computer choose paper you lose!"<<endl;
  compWin++;
}else if (num==3){
  cout<<"The computer choose scissors you win!"<<endl;
  playerWin++;
}
break;
case 2:
cout<<"You choose paper, the computer choose "<<endl;
if(num == 1){
  cout<<"The computer  choose rock you win!"<<endl;
   playerWin++;
}else if(num==2){
  cout<<"The computer choose paper its a tie!"<<endl;
  tie++;
}else if (num==3){
  cout<<"The computer choose scissors you lose!"<<endl;
  compWin++;
}
break;

case 3:
cout<<"you choose scissors, the computer choose"<<endl;
if(num == 1){
  cout<<"The computer  choose rock you lose!"<<endl;
  compWin++;
}else if(num==2){
  cout<<"The computer choose paper you win!"<<endl;
 playerWin++;
}else if (num==3){
  cout<<"The computer choose scissors you tie!"<<endl;
  tie++;
}
break;

case 4:
cout<<"\nYouve decided to exit the game your statistics will be displayed\n"<<endl;
continueGame = false;

cout<<"Computer wins: "<<compWin<<endl;

cout<<"Player wins:  "<<playerWin<<endl;

cout<<"The number of ties were:  "<<tie<<endl;


if(playerWin>compWin){
  cout<<"You bested the computer "<<endl;
}else if(compWin>playerWin){
  cout<<"The computer bested you "<<endl;
}else if(compWin==playerWin){
  cout<<"You and the comp tied, the eternal battle against skynet wages on!"<<endl;
}
break;
}






timesPlayed++;
cout<<"Youve played "<<timesPlayed<<" times.\n\n"<<endl;



}while(continueGame==true);

}
