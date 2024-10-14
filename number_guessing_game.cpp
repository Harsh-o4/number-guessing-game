#include<stdio.h>
#include<iostream>
#include<chrono>
#include<random>
using namespace std;

void clearScreen() {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}

int main(){
    start:
    // Random number generation
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist(1, 100);
    int random = dist(gen);


    clearScreen();

    //starting screen
    cout<<"\t\t     WELCOME TO"<<endl;
    cout<<"\t\t NUMBER GUESSING GAME"<<endl;
    cout<<endl;
    cout<<endl;
    int initialisation;
    cout<<"\t     ->Enter any value to START"<<endl;
    cout<<"\t     ->Enter 99 to END"<<endl;
    cout<<endl;
    cout<<"\t\t\t";
    cin>>initialisation;
    switch (initialisation)
    {
        case 99: exit(0);break;    
        default:  break;
    }
    
    clearScreen();
    cout<<"A random number has been generated between 1 to 100."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\tTAKE A GUESS"<<endl;
    int guess;
    int counter=0;
    cout<<"\t\t\t  -->";
    cin>>guess;
    ++counter;
    
    clearScreen();

    //guess on 1st try case
    if(guess==random){
        cout<<"\t\t\t     BINGO!"<<endl;
        cout<<"\t\tYou guessed it on the 1st try!"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"The number was "<<random<<"."<<endl;
        cout<<endl;
        cout<<"Enter any value to Restart "<<endl;
        cout<<"Enter 99 to EXIT "<<endl;
        
        cout<<endl;
        cout<<" ";
        int menu;
        cin>>menu;
        switch(menu){
            case 99: exit(0);break;
            default: goto start; break;
        }
    }
    wrong_guess:
    cout<<"\t\t     WRONG GUESS"<<endl;
    cout<<endl;
    cout<<endl;
    if(guess>random){
        cout<<"The number is LOWER than "<<guess<<"."<<endl;
    }
    else{
        cout<<"The number is GREATER than "<<guess<<"."<<endl;
    }    
    cout<<endl;
    cout<<"\t\t TAKE ANOTHER GUESS"<<endl;
    cout<<"\t\t      -->";
    cin>>guess;
    ++counter;
    
    clearScreen();

    if(guess==random){
        cout<<"\t\t\t     BINGO!"<<endl;
        cout<<"\t\t\tYou guessed it!"<<endl;
        cout<<"\t\t     No. of guesses made = "<<counter<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"The number was "<<random<<"."<<endl;
        cout<<endl;
        cout<<"Enter any value to Restart "<<endl;
        cout<<"Enter 99 to EXIT "<<endl;
        cout<<endl;
        cout<<" ";
        int menu;
        cin>>menu;
        switch(menu){
            case 99: exit(0);break;
            default: goto start; break;
        }
    }
    else{
        goto wrong_guess;
    }

    return 0;
}