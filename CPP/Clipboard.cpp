#include <iostream>
#include <string>
#include <windows.h>

std::string GetClipboardText()
{
    // Try opening the clipboard
    if (!OpenClipboard(nullptr))
        return (std::string)"";

    // Get handle of clipboard object for ANSI text
    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
        return (std::string)""; // error

      // Lock the handle to get the actual text pointer
    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (pszText == nullptr)
        return (std::string)""; // error

      // Save text in a string class instance
    std::string text(pszText);

    // Release the lock
    GlobalUnlock(hData);

    // Release the clipboard
    CloseClipboard();

    return text;
};


int main()
{
    std::string text = GetClipboardText();

    std::cout << text << std::endl;

    return 0;
}