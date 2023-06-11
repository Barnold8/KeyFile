# NOTICE
Use the python version of this software to achieve the end result for now. The compiled version is still in works


# What does KeyFile do?

Key file works by reading the contents of a file and then it proceeds to write the contents of the file out as if it was you writing it yourself. 

# What is the actual usage for this?

The usage sprung to mind when I was playing [Minecraft](https://www.minecraft.net/) of all things. I was playing in a [Minecraft modded server](https://en.wikipedia.org/wiki/Minecraft_modding) and we were on an older version of [computer craft](https://www.computercraft.info/) so copying and pasting code from somewhere into the lua computer was difficult, so I had an idea to make some software that was essentially a middle man step to copy and pasting. Due to the nature of gaming, this software is only meant for windows, but the python version **should** provide usability to mac/linux due to its interpreted nature. 

# How do I use this software?

All you need to do is go to the location of the program and write the name of the program with 1 or more of the following parameters

KeyFile.exe filePath timer

## filePath

This is the path to the file you wish to be read

## timer

This is the countdown timer you set for yourself before the program starts writing the contents of a file. Alternative to this, you can leave this section blank. Doing this will leave the timer set to 0


# Bugs

Currently, the compiled version does not work **(mostly)**. It can read from a file and simulate key presses that are english letters, this means characters like the "space" and "enter" are left out of this. A workaround to this is the [python version](python/main.py) of this software, which does require installation of python and the pyautogui library. The compiled version is meant to leave out all instances of external requirements. A consistent bug between versions of the software, compiled/interpreted is a weird one. It will only write text after a certain point if you move the mouse, my suspicion is that writing in windows is weirldly tied to some specific event. 

