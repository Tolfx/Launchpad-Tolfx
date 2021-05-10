#include <iostream>
#include <string>
#include <windows.h>

std::string GetClipboardText()
{
    if (!OpenClipboard(nullptr))
        return (std::string)"";

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
        return (std::string)""; // error

    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (pszText == nullptr)
        return (std::string)"";

    std::string text(pszText);

    GlobalUnlock(hData);

    CloseClipboard();

    return text;
};


int main()
{
    std::cout << GetClipboardText() << std::endl;
    return 0;
}