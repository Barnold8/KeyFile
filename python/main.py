# Python implementation, substitute of compiled program.
import sys
import os
import time

wait_timer = 0

try:
    import pyautogui
except ImportError:
    os.start("pip install -r requirements.txt")


if len(sys.argv) < 2:
    print("USAGE: main.py [filePath] [sleepTimer : seconds]\n")
    exit(1)

if len(sys.argv) >= 3:
    try:
        wait_timer = int(sys.argv[2])
    except TypeError: # coudlnt find a casting error
        wait_timer = 0 # ignore error and proceed as normal

time.sleep(wait_timer)

try:
    with open(sys.argv[1],"r") as file:
        for sentence in file.readlines():
            pyautogui.write(sentence)
except FileNotFoundError as fileError:
    print(fileError)
    exit(1)