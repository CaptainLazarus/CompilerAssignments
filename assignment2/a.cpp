#include<iostream>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<elf.h>
#include<string.h>
#include<math.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<cstring>
#include<stdlib.h>

using namespace std;

int (*func)(int);   //Function Prototype

void printSectionNames(char *sP, int size){
    for(int i=1; i<size; ++i)
    {
        if(sP[i] == '\0') 
            cout << "\n";
        cout << sP[i];
    }
}

int getText(char *sP, int size){
    int j=0;
    char temp[30];
    for(int i=1; i<size; ++i)
    {
        if(sP[i] == '\0') {
            string s = temp;
            if(s == ".text"){
                return i-5; 
            }
            memset(temp, 0, sizeof(temp));
            j=0;
        }
        else{
            temp[j] = sP[i];
            j++;
        }
    }
}

int getSym(char *sP, int size){
    int j=0;
    char temp[30];
    for(int i=1; i<size; ++i)
    {
        if(sP[i] == '\0') {
            string s = temp;
            if(s == ".symtab"){
                return i-7; 
            }
            memset(temp, 0, sizeof(temp));
            j=0;
        }
        else{
            temp[j] = sP[i];
            j++;
        }
    }
}

int getSymbol(char *sP , int size , string s , int stringSize){
    int j=0;
    char temp[30];
    for(int i=1; i<size; ++i)
    {
        if(sP[i] == '\0') {
            string s1 = temp;
            if(s1 == s){
                // cout << s1 << "\n";
                return i-stringSize; 
            }
            memset(temp, 0, sizeof(temp));
            j=0;
        }
        else{
            temp[j] = sP[i];
            j++;
        }
    }
}


int main(int argc , char *argv[]){
    
    if(argc > 1 && argc<4){
        //Declarations
        int fd = open(argv[1] , O_RDONLY);
        int size = sysconf(_SC_PAGE_SIZE);

        //Elf Types declaration
        Elf64_Ehdr *elf;
        Elf64_Shdr *header , *stsh , *ts;

        //Getting String Table
        elf = (Elf64_Ehdr *)mmap(0 , size , PROT_EXEC , MAP_PRIVATE , fd , 0);
        header = (Elf64_Shdr *)((char *)elf + elf->e_shoff );
        stsh = &header[elf->e_shstrndx];
        int sizeTable = stsh->sh_size;
        char * stringTable = (char *)elf + stsh->sh_offset;
        
        if (argc == 2){
            //Getting .text index
            int textIndex = getText(stringTable , sizeTable);
            
            //Finding text section
            int i;
            for(i=0 ; i < elf->e_shnum ; i++){
                if(header[i].sh_name == textIndex){
                    break;
                }
            }
            int textSection = i;
            ts = &header[textSection];
            
            //Executing the function
            int n;
            char *zz = (char *)elf + header[textSection].sh_offset;
            func = (int (*)(int))zz;
            cout << "Enter a number: ";
            cin >> n;
            cout << func(n) << "\n";
        }
        else if(argc == 3){
            //Getting .symtab index
            int symtabIndex = getSym(stringTable , sizeTable);
            
            //Finding Section Header of Symbol Table
            int i;
            for(i=0 ; i < elf->e_shnum ; i++){
                if(header[i].sh_name == symtabIndex){
                    break;
                }
            }
            int symSection = i;
            Elf64_Shdr *symTable = &header[symSection];
            
            //Finding Section Header of the string table of the symbol
            Elf64_Shdr *symStringTable =  &header[symTable->sh_link];
            
            //Finding string table 
            char * stringTableII = (char *)elf + symStringTable->sh_offset;
            int stringSize = strlen(argv[2]) ;
            int functionOffset = getSymbol(stringTableII , symStringTable->sh_size , argv[2] , stringSize); 

            Elf64_Sym *symTableEntries = (Elf64_Sym *)((char *)elf + symTable->sh_offset);
            for(i=0 ; i < (symTable->sh_size/symTable->sh_entsize) ; i++){
                if(symTableEntries[i].st_name == functionOffset){
                    break;
                }
            }
            char *sectionOffset = (char *)elf + header[symTableEntries[i].st_shndx].sh_offset + symTableEntries[i].st_value;
            func = (int (*)(int))sectionOffset;
            int n;
            cout << "Enter a number: ";
            cin >> n;
            cout << "Function Output is: " << func(n) << "\n";
        }
        
    }
    else{
        cout << "Format: <output file> <file with functions (*.o file)> <function name (optional)> \n";
    }
    //Property of CaptainLazarus
    return 0;
}
