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

INPUT* allocInputs(int size){

    INPUT* inputs = (INPUT*)malloc(sizeof(INPUT)*size); 
    return inputs;
}

FILE* openFile(char* path){

    FILE *fptr;
    fptr = fopen(path,"r");
    return fptr;

}

void loadChars(INPUT* chars, char* path, int size){

    char currChar;
    FILE* openedFile = fopen(path,"r");
    int index = 0;
    int charMin = 32;

    while((currChar = fgetc(openedFile)) != EOF){

        printf("Curr char is %c : %d\n",currChar,currChar);

        if(currChar > charMin){

            chars[index].type=INPUT_KEYBOARD;
            chars[index].ki.wScan=0;
            chars[index].ki.dwFlags=0;
            chars[index].ki.time=0;
            chars[index].ki.dwExtraInfo=0;
            chars[index].ki.wVk=currChar - 32;

            chars[index+1] = chars[index];
            chars[index+1].ki.dwFlags |= KEYEVENTF_KEYUP;

            index += 2;

        }else{

            switch(currChar){
                case 10:
                        printf("asdeasdw %d\n",currChar);
                        chars[index].type=INPUT_KEYBOARD;
                        chars[index].ki.wScan=0;
                        chars[index].ki.dwFlags=0;
                        chars[index].ki.time=0;
                        chars[index].ki.dwExtraInfo=0;
                        chars[index].ki.wVk=32;

                        chars[index+1] = chars[index];
                        chars[index+1].ki.dwFlags |= KEYEVENTF_KEYUP;

                        

                    break;
                case 32:


                default:
                    break;
                
            }
            index += 2;
        }
    }   
 
}

 // initialise fileStr
int main(int argc, char *argv[]){

    int time = 0;
    int charCount = 0;
    FILE * f;
    char currChar;
 
    if(argc < 2 || argc > 3){
        printf("USAGE: main.exe [filePath] [sleepTimer : seconds]\n");
        return -1;
    }
    if (!( f = openFile(argv[1]))){
        printf("Error: cannot find file %s\n",argv[1]);
        return -1;
    }

    time = (argc == 3) ? atoi(argv[2])*1000 : 5000;

    charCount = getCharCount("test.txt")*2; // times by two to allow for keyUp events

    INPUT* fileStr = allocInputs(charCount); 

    loadChars(fileStr,argv[1],charCount);

    Sleep(time);

    SendInput(charCount,fileStr,sizeof(INPUT));

    free(fileStr);

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