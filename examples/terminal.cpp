#include <bits/stdc++.h>
#include "../src/terminal.hpp"
using namespace std;

int main()
{
       int x = ctc::terminal::instance().get_size_x();
       int y = ctc::terminal::instance().get_size_y();
       cout << x << " " << y << endl;
       ctc::terminal::instance().set_size(100, 100);

       // 获取控制台窗口的句柄
       HWND hConsole = GetConsoleWindow();

       // 获取窗口的大小和位置
       RECT rect;
       GetWindowRect(hConsole, &rect);

       // 输出窗口的大小和位置
       printf("The window is at (%ld, %ld), and its size is %ld x %ld.\n",
              rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

       // 获取字体大小
       CONSOLE_FONT_INFOEX cfi;
       cfi.cbSize = sizeof(cfi);
       cfi.nFont = 0;
       GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
       printf("The font size is %d x %d, and the font family is %s.\n",
              cfi.dwFontSize.X, cfi.dwFontSize.Y, cfi.FaceName);

		cin >> x;
}