#include <windows.h>
#include <stdio.h>
#define WINVER 0x0500 // Tells windows we are win 2000 or later


// ip.ki.wVk = 0x41; 
// ip.ki.dwFlags = 0; 
// SendInput(1, &ip, sizeof(INPUT));



void sendKey(INPUT input, int key){

    input.ki.wVk = key; 
    input.ki.dwFlags = 0; 
    SendInput(1, &input, sizeof(INPUT));

}

FILE* openFile(char* path){

    FILE *fptr;
    fptr = fopen(path,"r");
    return fptr;

}

int main(int argc, char *argv[]){

    int time = 0;

    if(argc < 2 || argc > 3){
        printf("USAGE: main.exe [filePath] [sleepTimer : seconds]\n");
        return -1;
    }

    time = (argc == 3) ? atoi(argv[2])*1000 : 5000;

    Sleep(time);

    // initialise input

    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    


    return 0;
}