#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<elf.h>

int func(int);

//using namespace std;

int main(int argc , char * argv[]){
    //cout << argc << "\n";
    if(argc == 2){
        Elf64_Ehdr *elfhP;
        int fd = open(argv[1] , O_RDONLY);
        int size = sysconf(_SC_PAGE_SIZE);
        void *a = NULL;
        elfhP = (Elf64_Ehdr *)mmap(a , size , PROT_EXEC , MAP_PRIVATE , fd , 0);
        //cout << "a = " << a << "\n";
        
        //Virtual Memory Mapped
    
        close(fd);

    }
    else{
        printf("Failure\n");
    }
}