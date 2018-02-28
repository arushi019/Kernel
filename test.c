#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	/*The following function calls are used to test the functioning of our system call
	1. Arguments are correct and system call should function normally(Printing details about task )
	2. Creates a file with the name files and system call should function normally
	3. Negative PID is not possible hence appropriate error is generated
	4. No task with such PID is found and hence approriate error is generated
	5. Invalid file format hence appropriate error is generated
	*/
	//1
	long int val=syscall(314,1,"/usr/src/linux-3.13/sh_task_info/file"); 
	//2
	//long int val=syscall(314,1,"/usr/src/linux-3.13/sh_task_info/files");
	//3
	//long int val=syscall(314,-1,"/usr/src/linux-3.13/sh_task_info/file");
	//4
	//long int val=syscall(314,2000,"/usr/src/linux-3.13/sh_task_info/file");
	//5
	//long int val=syscall(314,1,".");
	
	if(val==0)
		printf("System Call sh_task_info returned %ld\n",val); // System Call returns 0 if no error is generated
	else
	{
		printf("System Call sh_task_info returned %d\n",1); // System Call returns the appropriate error number if error is generated
		printf("Error generated: %s\n",strerror((int)val)); // Prints the error
		//return 1;
	}
	return 0;
}
