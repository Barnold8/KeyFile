#include <windows.h>
#include <stdio.h>


#define WINVER 0x0500 // Tells windows we are win 2000 or later


    // initialise input

    // ip.ki.wVk = 0x41; 
    // ip.ki.dwFlags = 0; 
    // SendInput(1, &ip, sizeof(INPUT));


int main(int argc, char *argv[]){

    if(argc < 2 || argc > 3){
        printf("USAGE: main.exe [filePath] [sleepTimer]\n");
        return -1;
    }

    // Sleep(5000);

    // initialise input

    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    



    return 0;
}