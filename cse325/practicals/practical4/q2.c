#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	struct dirent *dptr;
	
	int a = mkdir("dir1", 0777);
	int b = mkdir("dir2", 0777);
	
	if(a!=-1 && b!=-1){
		printf("Directories 'dir1' and 'dir2' has been created Successfully. \n");
	}
	else{
		printf("Either directories 'dir1' & 'dir2' already exist or could not be created due to any Error. \n");
	}
	
	int fd1 = open("dir1/f1.txt", O_CREAT|O_RDWR, 0777);
	
	printf("File 'f1.txt' has been created Successfully in 'dir1'. \n");
	printf("\n");
	
	char c[1000];
	
	printf("Write something in the file:\n");
	scanf("%[^\n]s", c);
	printf("\n");
	
	int size=0;
	
	for(int i=0;i<1000;i++)
	{
		if(c[i]=='\0'){
			break;
		} else {
			size++;
		}
	}
	
	write(fd1, c, size);
	printf("Given input text from user has been Successfully written in file 'f1.txt'. \n");
	printf("\n");
	
	DIR *dp = opendir("dir2");
	
	int no_of_files=0;
	
	while(NULL != (dptr=readdir(dp)))
	{
		no_of_files++;
	}
	
	printf("No. of files in directory which is named 'dir2' are: \n");
	printf("%d\n",no_of_files);
	printf("\n");
	
	int fd2 = open("dir2/f1_copy.txt", O_CREAT | O_RDWR, 0777);
	printf("File 'f1_Copy.txt' has been created Successfully in Directory 'dir2'. \n");
	
	write(fd2, c, size);
	printf("Content of File 'f1.txt' in Directory 'dir1' has been Successfully Copied to file named 'f1_copy.txt' which is in Directory 'dir2' \n");
	printf("\n");
	
	DIR *dp1 = opendir("dir2");
	
	int new_no_of_files=0;
	
	while(NULL != (dptr=readdir(dp1)))
	{
		new_no_of_files++;	
	}
	
	printf("Now no. of files in directory which is named 'dir' are: \n");
	printf("%d\n", new_no_of_files);
	printf("\n");
	
	return 0;
}
