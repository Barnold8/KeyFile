#include <windows.h>
#include <stdio.h>
#define WINVER 0x0500 // Tells windows we are win 2000 or later

FILE* openFile(char* path){

    FILE *fptr;
    fptr = fopen(path,"r");
    return fptr;

}

void sendKey(int key){

    INPUT ip;
    
    UINT mappedKey = MapVirtualKey(LOBYTE(key), 0);

    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = 0; // virtual-key code for the "a" key

    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wScan = mappedKey;
    ip.ki.dwFlags = 0 | KEYEVENTF_SCANCODE; // 0 for key press

    SendInput(1, &ip, sizeof(INPUT));
}

void simulateFile(char* path){

    FILE *file = openFile(path);
    char currChar;

    if(!(file)){
        return;
    }

    while((currChar = fgetc(file)) != EOF){

        if(currChar > 32){
            sendKey(currChar-32);
        }
        else{
            switch(currChar){

                case 10:
                    sendKey(0x0D);
                    break;
                case 32:
                    sendKey(0x20);
                    break;
                
                default:
                    break;

            }
        }
        

    }

}

// initialise fileStr - 
int main(int argc, char *argv[]){

    int time = 0;
    int charCount = 0;
    char currChar;
    FILE * f;
    INPUT ip;
 
    if(argc < 2 || argc > 3){
        printf("USAGE: main.exe [filePath] [sleepTimer : seconds]\n");
        return -1;
    }
    if (!( f = openFile(argv[1]))){
        printf("Error: cannot find file %s\n",argv[1]);
        return -1;
    }

    time = (argc == 3) ? atoi(argv[2])*1000 : 5000;

    // INPUT* fileStr = allocInputs(charCount); 

    // loadChars(fileStr,argv[1],charCount);

    Sleep(time);


    simulateFile(argv[1]);


    // SendInput(charCount,fileStr,sizeof(INPUT));

    // free(fileStr);

    return 0;
}



    // INPUT in[10] = {0}; // four inputs

    // // first input 0x53
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
    // in[2].ki.wVk=0x53;

    // in[3] = in[2];
    // in[3].ki.dwFlags |= KEYEVENTF_KEYUP;

    // in[4].type=INPUT_KEYBOARD;
    // in[4].ki.wScan=0;
    // in[4].ki.dwFlags=0;
    // in[4].ki.time=0;
    // in[4].ki.dwExtraInfo=0;
    // in[4].ki.wVk=0x53;

    // in[5] = in[0];
    // in[5].ki.dwFlags |= KEYEVENTF_KEYUP;

    // // second input 0x54
    // in[6].type=INPUT_KEYBOARD;
    // in[6].ki.wScan=0;
    // in[6].ki.dwFlags=0;
    // in[6].ki.time=0;
    // in[6].ki.dwExtraInfo=0;
    // in[6].ki.wVk=0x53;

    // in[7] = in[2];
    // in[7].ki.dwFlags |= KEYEVENTF_KEYUP;

    // in[8].type=INPUT_KEYBOARD;
    // in[8].ki.wScan=0;
    // in[8].ki.dwFlags=0;
    // in[8].ki.time=0;
    // in[8].ki.dwExtraInfo=0;
    // in[8].ki.wVk=0x53;

    // in[9] = in[0];
    // in[9].ki.dwFlags |= KEYEVENTF_KEYUP;



    // SendInput(10,in,sizeof(INPUT));