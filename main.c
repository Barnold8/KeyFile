#include <windows.h>
#include <stdio.h>


#define WINVER 0x0500 // Tells windows we are win 2000 or later



int main(int argc, char *argv[]){

    if(argc != 2){
        printf("%d\n",argc);
        return -1;
    }

    printf("%s\n", argv[1]);

    return 0;
}