#include<stdio.h>
#include"symTab.h"

symRec symTab[SIZE];

void initSymTab(){
    for(int i=0 ; i<SIZE ; i+=1){
        symTab[i].def = 0;
    }
}

void updateSymTab(int index, int val){
    symTab[index].val = val;
} // updates the indexed loc

int isDefined(int index){
    if(symTab[index].def == 0){
        return 0;
    }
    else
    {
        return 1;
    }
}

int getVal(int index){
    return symTab[index].val;
}

void define(int index){
    symTab[index].def = 1;
}