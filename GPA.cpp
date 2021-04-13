//Nader S.Opeyan
//Cisp 400, TTh
//9/22/19


#include <iostream>
#include <string>
#include <cmath>
#include <limits>
using namespace std;



//functions prototypes
int idVeri(int studentId);
void greeting();
int element(int);
void copyArray(int*&,int*&,int);
int responseTrap(int response);
void gpa(int*&,int);
void gpaTwo(int g);
void gpaThree(int z);

int main() {
//variables

int x;//for while loop
bool id =true;
int arraySize=0;//smallest arrray

// Specification A1 - OOP
class student{
public:

int studentId;


};


while(id==true){

//Program into
greeting();


student lol;
cin>>lol.studentId;

//function call for student id
x=idVeri(lol.studentId);
if(x==false){
  id =false;
}

//to make sure program dosent run if id ==false;
if(id == true){


//resizing,assign grade to temp after putting
//grade array values into temp arraySize
//finally assign pointer grade to pointer temp
int *grade; 
int * temp;

cout<<"\nInput your grades here.\nPress enter between each input.\n"<<endl;


//exit variable equals literal 'calc'
string calc = " ";

int response;
cin>>response;
while(cin.fail()){
  cin.clear();
  cin.ignore();
  cin>>response;
}

do{
//automatically runs
if(arraySize==0){
arraySize++;//will stop this block from ever running again

//error trapping
 
  // Specification B1 - Dynamic Array
    // Specification C1 - REPLACED
 response = responseTrap(response);

  grade = new int[arraySize];
    grade[0] = response;
    cout<<"Enter 'calc' to finalize.\nEnter any other character than press enter then input another grade \nto continue inputting grades. "<<endl;
      cout<<"\nThis is ignored string input, unless 'calc' is entered "<<endl;
      cin>>calc;
      //test 
      
      cin.ignore();
      
    
}else{

 
  arraySize++;

  temp = new int[arraySize];//temp pointer is intialized to one larger
  //than grade array

    
  copyArray(grade, temp,arraySize);//creat copy funtion for grade array to temp array

//response = responseIsInt(response);
//error trap this

cin>>response;
response = responseTrap(response);

temp[arraySize-1]=response;  


//when delete is used this deletes the memoery on the heap
//thats no longer used, pointer is still intact
delete [] grade;

grade =temp;

  cout<<"Enter 'calc' to finalize.\nEnter any other character than another grade\nto continue inputting grades. "<<endl;

cin>>calc;

cin.ignore();
 
  }//end of else statement
    
}while(calc!="calc");

// Specification C2 - Print Scores
for(int i=0;i<arraySize;i++){
  cout<<"This is input "<<i<<" and this is its assigned score "<<grade[i]<<" ";
  int z =grade[i];
  gpaThree(z);
  cout<<"\n";
}

//gpa average funtion
gpa(grade,arraySize);

}//main program statement

id =false;//ends id while loop in beginning of program

}//end of while bool for studentId


}//end of main




int idVeri(int studentId){

//Specification B2 - Validate Student ID
//error checking
while(studentId>10000000&&studentId<99999998){

//even checking
if(studentId%2 ==0){
//for 127
if(studentId>=12700000&&studentId<=12799998){

return studentId;
}
//for 379
else if(studentId>=37900000&&studentId<=37999998){

return studentId;
}
//833
else if(studentId>=83300000&&studentId<=83399998){
return studentId;
}

}//if statement end


}

cout<<"\nYouve inputted an invalid student id the program will now terminate.\n"<<endl;
return false;
}


// Specification C4 - Validate Test Scores
int responseTrap(int response){

while(response>100||response<0){
cout<<"Retry another grade"<<endl;
cin>>response;

}//end of while
  return response;
}

// Specification B3 - Letter Grades
void gpaThree(int z){
if(z<=100&&z>=90){
  cout<<"A";
}else if(z<=89&&z>=80){
  cout<<"B";
}else if(z<=79&&z>=70){
  cout<<"C";
}else if(z<=69&&z>=60){
  cout<<"D";
}else if(z<=59&&z>=0){
  cout<<"F";
}

}

void copyArray(int*&grade,int*&temp,int arraySize){

  for(int i=0;i<arraySize;i++){
    temp[i]=grade[i];//the final number is garbage as the array
    //for grade is nothing and temp has one more location
  }

}

//calculate total gpa
void gpa(int*&grade,int arraySize){
  int temp =0;
  int bigDawgStatus=0;
  

  for(int i=0;i<arraySize;i++){
  temp=grade[i];
  bigDawgStatus += temp;
  }

int g =bigDawgStatus/arraySize;

// Specification C3 - Compute GPA
cout<<"This is average GPA "<<g<<" ";
gpaTwo(g);
}



// Specification C5 - Print Letter Grade
void gpaTwo(int g){

if(g<=100&&g>=90){
  cout<<"A";
}else if(g<=89&&g>=80){
  cout<<"B";
}else if(g<=79&&g>=70){
  cout<<"C";
}else if(g<=69&&g>=60){
  cout<<"D";
}else if(g<=59&&g>=0){
  cout<<"F";
}

}

void greeting(){
  cout<<"\nWelcome!.\n"<<"This program is designed to take in your "<<" student id and numerical grade values from 0-100 "<<" then calculate your average gpa."<<endl;

cout<<"\nEnter in your student id with no whitespace\nor charcters in-between the digits\n"<<endl;
}


