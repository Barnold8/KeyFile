#include <windows.h>
#include <stdio.h>
#define WINVER 0x0500 // Tells windows we are win 2000 or later


int getCharCount(char* path){

    int chars = 0;
    char currChar;
    FILE* openedFile = fopen(path,"r");

    while((currChar = fgetc(openedFile)) != EOF){
        chars++;
    }
    return chars;
}

 // initialise fileStr
int main(int argc, char *argv[]){

    int time = 0;
    FILE * f;
    char currChar;
    INPUT fileStr[4];

    if(argc < 2 || argc > 3){
        printf("USAGE: main.exe [filePath] [sleepTimer : seconds]\n");
        return -1;
    }
    if (!( f = openFile(argv[1]))){
        printf("Error: cannot find file %s\n",argv[1]);
        return -1;
    }

    time = (argc == 3) ? atoi(argv[2])*1000 : 5000;

    Sleep(time);

    INPUT in[4] = {0}; // four inputs

    // first input 0x53
    // in[0].type=INPUT_KEYBOARD;
    // in[0].ki.wScan=0;
    // in[0].ki.dwFlags=0;
    // in[0].ki.time=0;
    // in[0].ki.dwExtraInfo=0;
    // in[0].ki.wVk=0x53;

    // in[1] = in[0];
    // in[1].ki.dwFlags |= KEYEVENTF_KEYUP;

    // // second input 0x54
    // in[2].type=INPUT_KEYBOARD;
    // in[2].ki.wScan=0;
    // in[2].ki.dwFlags=0;
    // in[2].ki.time=0;
    // in[2].ki.dwExtraInfo=0;
    // in[2].ki.wVk=0x54;

    // in[3] = in[2];
    // in[3].ki.dwFlags |= KEYEVENTF_KEYUP;

    // SendInput(4,in,sizeof(INPUT));

    
   

    return 0;
}