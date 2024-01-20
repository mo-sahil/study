#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	int a = mkdir("dir",0777);
	if(a!=-1)
	{
		printf("Your directory has been created: \n");
		printf("\n");
	}

	struct dirent *dptr;
		
	int fd1 = creat("dir/f1.txt",0777);
	int fd2 = creat("dir/f2.txt",0777);
	int fd3 = creat("dir/f3.txt",0777);
	
	if(fd1!=-1 && fd2!=-1 && fd3!=-1)
	{
		printf("file f1.txt is created.\n");
		printf("f2.txt is created.\n");
		printf("f3.txt is created.\n");
		printf("\n");
	}
	
	DIR *dp = opendir("dir");
	
	printf("List of files in created directory: \n");
	
	while(NULL!=(dptr = readdir(dp)))
	{
		printf("%s\n", dptr->d_name);
	}
	return 0;
}
