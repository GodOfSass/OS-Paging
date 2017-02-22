#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
char logical[16];
char physical[32];
int main()
{   
    for(int i=0;i<32;i++)//Initializing Address Data
    {
      if(i<16){logical[i]=' ';}
      physical[i]=' ';
    }  
    int page_move=0; int ft[4]; int frame=0;
    int r1,r2;
    time_t t;
    srand((unsigned) time(&t));
    r1=((rand()%8)*4);
    r2=((rand()%8)*4);
    cout<<"Frames Occupied Are->"<<(r1/4)<<" & "<<(r2/4);
    for(int i=0;i<4;i++)// Fill in 2 random frames
    {         
         physical[r1++]='F';
         physical[r2++]='F';
    }
    cout<<"\nPhysical Memory is now->\n";
    for(int i=0;i<32;i++)
    { 
     if(i%4==0){cout<<"\n";}
     cout<<"\n"<<i<<"\t"<<physical[i];
    }
    cout<<"\nEnter Logical Data->\n";
    for(int i=0;i<16;i++)//Get Logical Data
    { if(i%4==0){ cout<<"\n-Page "<<page_move++<<"-\n";}
       cin>>logical[i];       
    }
    int w=0; page_move=0; int temp=0;
    cout<<"\n:::FRAME TABLE:::\n";
    while(w<=28)  // Construct Frame Table
    {        
        if(physical[w]==' ' && page_move!=4)
        {             
           ft[page_move]=frame;
           temp=(4*frame);
           for(int z=0;z<4;z++)
           {
             physical[temp++]=logical[(4*page_move)+z];
           }
           ++page_move;
        }
        ++frame;
        w=w+4;
    }
    cout<<"\nPage\tFrame\n";
    for(int i=0;i<4;i++)//Print the Frame Table
    {
      cout<<"\n "<<i<<"\t"<<ft[i];
    }
    cout<<"\nPhysical Memory Contains->\n";
    for(int i=0;i<32;i++) // Display Physical Memory
    { if(i%4==0){cout<<"\n";}
      cout<<"\n"<<i<<"\t"<<physical[i];
    }   
    int add1;
    cout<<"\nEnter Logical Address to Map(0-15)->";
    cin>>add1;
    int flag=0;
    for(int i=0;i<32;i++)//Check for address mappings
    {
      if(physical[i]==logical[add1])
       { 
         cout<<"\nLogical Address "<<add1<<" was mapped with Physical Address "<<i; flag=1;
         break;
       }       
    }
    if(!flag){cout<<"\nAddress Was Not Mapped!";}
  getch();  
}
