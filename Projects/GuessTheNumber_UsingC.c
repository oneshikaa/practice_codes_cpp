//We write a program that generates a random number and asks the player to guess it and ask the player to guess it .If the player's guess highre than the actual numbre , the program displays "lower number please".Similarly if the user's guess is too low , the program prints "Higher number please ".
//When the user guesses the correct number , the program displays the number of guesses the player used to arrive at the number .

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number,guess,nGuesses = 1;
    srand(time(0));
    number = rand()%100+1;

    do{
        printf("Please guess a numebr between 1 to 100\n");
        scanf("%d",&guess);
        if(guess>number){
            printf("Lower number please\n");

        }
        else if(guess<number){
            printf("Higher number please\n");

        }
        else{
            printf("Yay you got it\nYou took %d number of guesses",nGuesses);

        }
        nGuesses++;

    }while(guess != number);


    return 0;
    
     


}
