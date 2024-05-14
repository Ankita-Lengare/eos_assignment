//Input signal number and a process id from user. Send given signal to the given process using kill() syscall.

#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

int main()
{
 int pid,signum,ret;

 printf("Enter The pid\n: ");
 scanf("%d",&pid);

 printf("Enter The signum\n: ");
 scanf("%d",&signum);

 ret = kill(pid,signum);
 if(ret == 0)
 {
   printf("successfully Kill\n");
 }
 else{
    printf("Process not kill\n");
 }


 return 0;
  
}
