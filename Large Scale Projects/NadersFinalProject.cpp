//AI.cpp
//Cisp 400,Nader S. Opeyany
//December 19,2019
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;



/* THE PLAN IS TO MAKE THE MAJORITY OF THE FUNCTION WITHIN THE CLASS. SINCE THE CLASS FUNCTIONS AS A BLUEPRINT THIS IS AN EFFITENT DATA STRUCTURE for 200 similar objects */
class skynet{
  public:
  int xPoint,yPoint,energy,energyCount,geneActivation,turns,checkone;
  int map[10][10];//inherent map
  int genes[16][5];//genes per skynet
  int enviroment[4];//the 4 directions from the map
  
  //functions I created for the BLUEPRINT
  void mapCreate();
  void mapDisplay();
  void placeskynet(int xPoint,int yPoint);
  void makeGenes();
  void checkGenes();
  void setbats();
  void enviromentArr();
  void checkEnviroment();
  void geneMatch();
  void simulateLife();
  void resetValue();
 void madScientist();
   // Constructor  sets everyting for each object
   
    skynet() {

      energy = 5;//every skynet starts with 5 energy
      
      energyCount=0;//total batterys each collected is +5
      xPoint=(rand()%8)+1; yPoint=(rand()%8)+1;//starting point that dosent include the walls
      
        makeGenes();

        mapCreate();//every skynet generates a map

        setbats();//sets batterys for each map
        
        placeskynet(xPoint,yPoint);//map[xPoint][yPoint] is where skynet is!

        enviromentArr();//takes in surrounding

        geneMatch();//sets the action gene if enviromentArr works

        simulateLife(); //main code called up and done for every skynet
        
    }
};


void skynet::resetValue(){
  energyCount=0;energy=5;xPoint=(rand()%8)+1;yPoint=(rand()%8)+1;
}
void skynet::madScientist(){

}
//main event loop for each object
void skynet::simulateLife(){
  int turn=5;
  while(energy>1) //while energy is not 0
  {
    if (geneActivation==0 and enviroment[0]!=2 and enviroment[0]==0){
     // cout<<"\nskynet moved north into empty space "<<endl;//delete
        map[xPoint][yPoint]=0;//checkEnviroment();
        xPoint-=1;
    }
    else if(geneActivation==0 and enviroment[0]!=2 and enviroment[0]==1){
      //cout<<"\nskynet moved north "<<endl;//delete
        map[xPoint][yPoint]=0;
        xPoint=xPoint-1;//checkEnviroment();
        turn+=5;
        energy+=5;energyCount+=1; //if battery plus 5 turns and one battery
    } 
      else if(geneActivation==1 and enviroment[1]!=2 and enviroment[1]==0){
        //cout<<"\nskynet moved east into empty space "<<endl;
          map[xPoint][yPoint]=0;
          yPoint+=1;//checkEnviroment();
      }
      else if(geneActivation==1 and enviroment[1]!=2 and enviroment[1]==1){
        //cout<<"\nskynet moved east "<<endl;
          map[xPoint][yPoint]=0;
          yPoint+=1;//checkEnviroment();
          turn+=5;
          energy+=5;energyCount+=1;
      }
        else if(geneActivation==2 and enviroment[2]!=2 and enviroment[2]==0){
          //cout<<"\nskynet moved South into empty space "<<endl;
          map[xPoint][yPoint]=0;
          xPoint+=1;
        }
        else if(geneActivation==2 and enviroment[2]!=2 and enviroment[2]==1){
          //cout<<"\nskynet moved north "<<endl;//delete
          map[xPoint][yPoint]=0;
          xPoint=xPoint+1;//checkEnviroment();
          turn+=5;
          energy+=5;energyCount+=1;
        }
          else if(geneActivation==3 and enviroment[3]!=2 and enviroment[3]==0){
            //cout<<"\nskynet move west into empty space "<<endl;
            map[xPoint][yPoint]=0;
            yPoint-=1;//checkEnviroment();
          }
          else if(geneActivation==3 and enviroment[3]!=2 and enviroment[3]==1){
            //cout<<"\nskynet move west "<<endl;
            map[xPoint][yPoint]=0;
            yPoint-=1;//checkEnviroment();
            turn+=5;
            energy+=5;energyCount+=1;
          }
      placeskynet(xPoint, yPoint);
      enviromentArr();
      energy=-1;
      
  }
  //cout<<"\nThis is total battery collected: "<<energyCount<<endl;
  //cout<<"\nthis is total turn check for battery life "<<turn<<endl;
}

void skynet::geneMatch(){
 for(int i=0;i<16;i++){
  if(enviroment[0]==map[i][0] and enviroment[1]==map[i][1] and enviroment[2]==map[i][2] and enviroment[3]==map[i][4]){
    geneActivation=map[i][4];//sets it to geneActivation
    
  }
 }
 if(geneActivation==4){
   geneActivation=rand()%3;//4 is the set to random direction 
 }
}
void skynet::enviromentArr(){
  //n
enviroment[0]=map[xPoint-1][yPoint];//should take in the surroundings
  //east
enviroment[1]=map[xPoint][yPoint+1];//enviroment will be compared to 
  //s
enviroment[2]=map[xPoint+1][yPoint];//genes array
  // west
enviroment[3]=map[xPoint][yPoint-1];

}
void skynet::checkEnviroment(){//to check not important
  for(int i=0;i<4;i++){
    cout<<enviroment[i]<<"";;
  }cout<<endl;
}

void skynet::setbats(){
  int i=0,j=0;
  int bat=0;
  
  while(bat<40){//perfectly distributes 40 and dosent overlap them
    i= (rand()%8)+1;
    j= (rand()%8)+1; 
      while(map[i][j]==1){
        i= (rand()%8)+1;j=(rand()%8)+1;
      }
    map[i][j]=1;
    bat++;
  }
}

void skynet::makeGenes(){
//0=no object
//1=battery
//2=wall object
for(int i=0;i<16;i++){
  for(int j=0;j<4;j++){
genes[i][j]=rand()%3;
  }
 //action gene movement
  for(int z=0;z<16;z++){
    genes[z][4]=rand()%4;
  }
}
}

//placing skynet on map,skynet is 9
void skynet::placeskynet(int xPoint,int yPoint){
  map[xPoint][yPoint]=9;//xPoint and yPoint are initalized
  //in the Constructor

}

//check which genes were made,to match against the board
void skynet :: checkGenes(){
for(int i=0;i<16;i++){
  for(int j=0;j<5;j++){
  cout<<genes[i][j]<<" ";
  }
    cout<<endl;
}
}
//populate map
void skynet::mapCreate(){
int m=0,n=0,j=0,k=0,x=0,y=0,a=0,b=0;
  for (int i=0;i<10;i++){
    for(int j=0;j<10;j++){
    map[i][j]=0;
    }
}
  //this bulids top wall
  for(int n=0;m<10;m++){
    map[n][m]=2;
  }
  //bottom
  for(int j=9;k<10;k++){
    map[j][k]=2;
  }
  //right side
  for(int y=9;x<10;x++){
    map[x][y]=2;
  }
  //left side
  for(int b=0;a<10;a++){
    map[a][b]=2;
  }

}


//important superSecretSpecialSauce function
void superSecretSpecialSauce(skynet popArray[],skynet temp[]);

int main() {
int generations = 50;
srand(time(NULL));//needed so rand() dosent become stale because ewww

//saved outside so that the genes that are updated arent erased
skynet popArray[200];

do{

skynet temp[200];
skynet temperoary;


float tally;
  for(int i=0;i<200;i++){
    tally+=popArray[i].energyCount;
  }

  cout<<"\n\nThis is average intake of energon cubes(batteries) in generation "<<tally/200<<endl;//200 is constant pop
    
    
  //sorting popArray and getting top 100
  //100-200 is top preforming
  //each run through the top 100 from the previos
  //generation should be increasing prefomrance
  
  for(int i = 0; i<200; i++) {
   for(int j = i+1; j<200; j++)
   {
      if(popArray[j].energyCount< popArray[i].energyCount) {
        // temperoary = popArray[i].energyCount;
         temperoary=popArray[i];
         //popArray[i].energyCount = popArray[j].energyCount;
         popArray[i]=popArray[j];
        // popArray[j].energyCount = temperoary;
         popArray[j]=temperoary;
      }
   }
  }
    //top 100 in temp
    for(int i=100;i<200;i++){
     temp[i] =popArray[i];
    }
      //bred 100 in temp
      
        superSecretSpecialSauce(popArray,temp);
      
      // SET THE BRED skynetS WITH SUCCESSFUL PARENT skynetS 
      //INTO popArray Successfuly transfering both into popArray
      for(int l=0;l<200;l++){
        popArray[l]=temp[l];
      }

        
        generations-=1;
}while( generations>0);


}

void superSecretSpecialSauce(skynet popArray[],skynet temp[]){
for(int j=0;j<100;j++){
for(int i=0;i<8;i++){
 temp[i]= popArray[i];
}
for(int i=8;i<16;i++){
  temp[i]=popArray[i];
}
}
}
