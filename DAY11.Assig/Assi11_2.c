//The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process
//print the result and exit. The parent process wait for completion of the child and then exit.

#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
   {
   int arr1[2],arr2[2],res,ret,num1,num2,n1,n2,s;

   ret = pipe(arr1);
   if(ret < 0)
   {
     perror("pipe() failed");
	 _exit(1);
   
   }

   ret = pipe(arr2);
   if(ret < 0)
   {

     perror("pipe() failed\n");
	 _exit(1);
   }
     ret = fork();
	 if(ret == 0)
	 {
        //child
		close(arr1[0]);
		close(arr2[1]);
		printf("enter num1 and num2 : \n");
		scanf("%d\t%d",&num1,&num2);
		ret= write(arr1[1],&num1,sizeof(num1));
		ret= write(arr1[1],&num2,sizeof(num2));

		ret = read(arr2[0],&res,sizeof(res));
        printf("result:%d\n",res);

		close(arr2[0]);	
		close(arr1[1]);

	 }


    else
	{
 
       //parent
	   close(arr1[1]);
       close(arr2[0]); 
	   ret = read(arr1[0],&num1,sizeof(num1));
	   ret = read(arr1[0],&num2,sizeof(num2));
	   res = num1 + num2;
	   ret = write(arr2[1],&res,sizeof(res));

	   close(arr2[1]);
	   close(arr1[0]);
	   waitpid(-1,&s,0);

	}

	return 0;
}
