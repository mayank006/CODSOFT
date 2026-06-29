#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
 int main(){
    srand(time(0));

    int secretnumber = rand() % 100 + 1;
    int guess;
    int attempts=0;

    cout << "GUESS THE NUMBER(1-100) \n\n";
    
    do{
        cout << "Enter your number : ";
        cin >> guess;
        attempts++;

        if(guess > secretnumber){
            cout << "Your guess is Too High! Try Again \n\n";
        }
        else if(guess < secretnumber){
            cout << "Your guess is Too Low! Try Again\n\n";
        }
        else{
            cout << "\nCongratulations You Guess the number Correctly \n"<<endl;
            cout << "The Number is : "<< secretnumber<<endl;
            cout << "No. of Attempts : "<< attempts;
        }
    }while(guess != secretnumber);

    return 0;
}