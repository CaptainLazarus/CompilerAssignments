// Name: Aditya Sujith Gudimetla
// Roll No: 17009
// Reg No: 207

int what(int * data ,  int no){
    int i=1;
    while(no > i){
        int temp = data[i];

        int j=i-1;
        while( j>=0 ){
            if(data[j] >= temp)
            {
                break;
            }
            else
            {
                data[j+1] = data[j];
                j--;
            }
        }
        data[j+1] = temp;
        i++;
    }
    return 0;
};  
