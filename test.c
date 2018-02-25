#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	long int val=syscall(314,1,"/usr/src/linux-3.13/sh_task_info/file");
	//long int val=syscall(314,1,"/usr/src/linux-3.13/sh_task_info/files");
	//long int val=syscall(314,-1,"/usr/src/linux-3.13/sh_task_info/file");
	//long int val=syscall(314,2000,"/usr/src/linux-3.13/sh_task_info/file");
	//long int val=syscall(314,1,".");
	

	//printf("System Call sh_task_info returned %ld\n",val);
	if(val==0)
		printf("System Call sh_task_info returned %ld\n",val);
	else
	{
		printf("System Call sh_task_info returned %d\n",1);
		printf("Error generated: %s\n",strerror((int)val));
		//return 1;
	}
	return 0;
}
