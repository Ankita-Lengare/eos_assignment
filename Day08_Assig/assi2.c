/*From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination*/



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

 int b,c,d,s1,s2,s3,i;
 b = fork();
 if (b==0){
for ( i =1;i<=5;i++){
  c= fork();
if(c==0){
d=fork();
if (d==0){
 printf("child 3(D) is running %d\n",i);
 sleep(1);
_exit(0);
}
printf("child 2 (C)is running%d\n",i);
sleep(1);
waitpid(d,&s3,0);
_exit(0);
}
printf("child 1(B) is running%d\n",i);
sleep(1);
waitpid(c,&s2,0);
}
_exit(0);// exiting 1st child

 }
 //parent
 waitpid(b,&s1,0);
 printf("parent process A ");
 return 0;
}
























































