#include <iostream>
#include <windows.h>
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <cstring>
#include <vector>

class KeyBoardControllerWindows
{
    private:
        INPUT ip;
        INPUT ShiftK;
        INPUT CtrlK;
        INPUT AltK;
        boolean Shift;
        boolean Ctrl;
        boolean Alt;

        int CharacterInt(char a)
        {
            return (int)a;
        }

    public:

        KeyBoardControllerWindows()
        {
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0;
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;

            ShiftK.type = INPUT_KEYBOARD;
            ShiftK.ki.wScan = 0;
            ShiftK.ki.time = 0;
            ShiftK.ki.dwExtraInfo = 0;

            CtrlK.type = INPUT_KEYBOARD;
            CtrlK.ki.wScan = 0;
            CtrlK.ki.time = 0;
            CtrlK.ki.dwExtraInfo = 0;

            AltK.type = INPUT_KEYBOARD;
            AltK.ki.wScan = 0;
            AltK.ki.time = 0;
            AltK.ki.dwExtraInfo = 0;
        }

        void Hold_Shift()
        {
            Shift = !!Shift;
            ShiftK.ki.wVk = VK_SHIFT;
        }

        void Release_Shift()
        {
            Shift = !!Shift;
            ShiftK.ki.dwFlags = 0;
        }

        void Hold_Ctrl()
        {
            Ctrl = !!Ctrl;
            CtrlK.ki.wVk = VK_CONTROL;
        }

        void Release_Ctrl()
        {
            Ctrl = !!Ctrl;
            CtrlK.ki.dwFlags = KEYEVENTF_KEYUP;
        }

        void Hold_Alt()
        {
            Alt = !!Alt;
            AltK.ki.wVk = VK_MENU;
        }

        void Release_Alt()
        {
            Alt = !!Alt;
            AltK.ki.dwFlags = KEYEVENTF_KEYUP;
        }

        void PressChar(char *x)
        {
            ip.ki.wVk = (CharacterInt(*x));
            std::cout << CharacterInt(*x) << std::endl;
            ip.ki.dwFlags = 0;

            SendInput(1, &ip, sizeof(INPUT));

            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }

};

int main(int argc, char* argv[])
{
    char* char_arr;
    KeyBoardControllerWindows Keyboard;
    for (int i = 1; i < argc; i++)
    {
        std::string str_obj(argv[i]);
        char_arr = &str_obj[0];
        
        Keyboard.PressChar(char_arr);
    }
    return 0;
}