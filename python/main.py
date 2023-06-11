# Python implementation, substitute of compiled program.
import sys
import os
import time

try:
    import pyautogui
except ImportError:
    os.start("pip install -r requirements.txt")


if len(sys.argv) < 2:
    print("USAGE: main.py [filePath] [sleepTimer : seconds]\n")
    exit(1)

