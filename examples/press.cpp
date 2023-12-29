#include <windows.h>
#include <iostream>

int main()
{
    while (true)
    {
        if (GetAsyncKeyState('A') & 0x8000)
        {
            std::cout << "A key is pressed" << std::endl;
//            break;
        }
        Sleep(1000/30);
    }
    return 0;
}