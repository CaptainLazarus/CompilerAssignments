#include<string.h>
#define ID_LEN 50
#define ST_SIZE 100

typedef struct {
    char id[ID_LEN];
    char type;
    int size;
    int displacement;
} symTabEntry;

class symTab {
    symTabEntry ste[ST_SIZE];
    int nextIndex;
    int displacement;

    public:
    symTab();
};