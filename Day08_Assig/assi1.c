#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
int ret , i, j, s;
int child_pid;

for (i=1;i<=5;i++)
  {
  ret = fork();
if (ret == 0)
{
// child task
for(j=1; j<=5; j++) {
printf("child %d is runnig %d\n",i, j);
sleep(1);
}
_exit(0);
}
  }
  // parent

  for (i=1;i<=5;i++)
  {
child_pid = wait(&s);
printf("parent is runnig for child %d for pid : %d\n",i,child_pid);
  }
  return 0;
}
















































