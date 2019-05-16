#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Prototypes
void alarmHandler(int);
void quitHandler(int);


int main(){
   char string [100];
// set the signal handler
// so it sends a signal and pass it to a function
   signal(SIGALRM,alarmHandler);
   signal(SIGINT,quitHandler);

   while(1){
   printf("Type in your name:\n");
// a signal will be sent after five seconds
   alarm(5);
   gets(string);
   
   if(strcmp("exit",string)==0){
   printf("Bye bye!");
     exit(0); 
   }

// print out the notification when the time is up

   printf("Your name is:");
   puts(string);
 }

   return 0;

}

void alarmHandler(int theAlarm){ 
    printf("Time up!\n");
    printf("Type in your name:\n");
    alarm(5);
}

void quitHandler(int theInt){


    printf("\nPlease type 'exit' to quit\n");
    printf("Type in your name:\n");




}
