#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


// server..... reader

int main(){

int fd, fd1, res, cnt, n1, n2;

fd = open("/home/sunbeam/Desktop/eos_assignment/Day12_Assig/desd_fifo",O_RDONLY);
if(fd < 0){
    perror("open() failed");
	_exit(2);
}

printf("waiting for data....\n");

cnt = read(fd, &n1, sizeof(n1));
cnt = read(fd, &n2, sizeof(n2));

printf(".......numbers received....\n");

res = n1 + n2;

fd1 = open("/home/sunbeam/Desktop/eos_assignment/Day12_Assig/desd_fifo1",O_WRONLY);
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}

cnt = write(fd1, &res, sizeof(res));

//printf("read from fifo: %d bytes -- %d %d\n", cnt,n1 , n2);

close(fd);
close(fd1);

return 0;
}

