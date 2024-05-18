
//The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
//process print the result.
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>



//client
// p1 .... writer

int main(){

int fd ,res, fd1, cnt;
int n1;
int n2;
      
fd = open("/home/sunbeam/Desktop/eos_assignment/Day12_Assig/desd_fifo", O_WRONLY);
if(fd < 0){
    perror("open() failed");
	_exit(1);
}

printf("Enter two no.s : \n");
scanf("%d %d", &n1, &n2);

cnt = write(fd, &n1, sizeof(n1));
cnt = write(fd, &n2, sizeof(n2));

//printf("written in fifo: %d %d bytes\n",n1,n2);

fd1 = open("/home/sunbeam/Desktop/eos_assignment/Day12_Assig/desd_fifo1", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
cnt = read(fd1, &res, sizeof(res));
printf("Addition= %d\n",res);

close(fd);
close(fd1);

return 0;
}

