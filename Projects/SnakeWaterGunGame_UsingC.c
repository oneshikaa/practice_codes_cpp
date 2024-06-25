 #include<stdio.h>
 #include<time.h>
 #include<stdlib.h>

 int snakeWaterGun(char user,char computer){
     if(user==computer){
         return 0;
     }
     else if((user=='s' && computer=='w') || (user=='w' && computer=='g') ){
         return 1;
     }
     else{
         return -1;
     }
 }

 int main(){
     char user, computer;
     srand(time(0));
     int number = rand()%100+1;
     printf("Enter s for snake, w for water, g for gun\n");
     scanf("%c",&user);
     if(number<33){
         computer = 's';

     }
     else if(number>=33 || number<66){
         computer = 'w';

     }
     else{
         computer = 'g';

     }
     int result = snakeWaterGun(user,computer);
     if(result==0){
        printf("Game drawn\n");
     }
     if(result==1){
         printf("You win\n");
     }
    if (result== -1){
        printf("You lose\n");
     }
     printf("you chose %c and computer chose %c",user,computer);

     return 0;



 }