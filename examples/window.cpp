#include <windows.h>

#include <bits/stdc++.h>
using namespace std;

int main() {    
    // 获取控制台窗口的句柄
    HWND hConsole = GetConsoleWindow();
	
    // 获取窗口的样式
    LONG style = GetWindowLong(hConsole, GWL_STYLE);
    if (style & WS_CAPTION)
        printf("窗口包含标题\n");
    if (style & WS_SYSMENU)
        printf("窗口包含系统菜单\n");
    if (style & WS_THICKFRAME)
        printf("窗口包含可调边框\n");
    if (style & WS_MINIMIZEBOX)
        printf("窗口包含最小化按钮\n");
    if (style & WS_MAXIMIZEBOX)
        printf("窗口包含最大化按钮\n");
    if (style & WS_SIZEBOX)
        printf("窗口包含可调大小的边框\n");
    if (style & WS_VSCROLL)
        printf("窗口包含垂直滚动条\n");
    if (style & WS_HSCROLL)
        printf("窗口包含水平滚动条\n");
    

    // 修改样式以禁止用户改变窗口的大小
    style ^= WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_VSCROLL | WS_HSCROLL;

    // 设置新的样式
    SetWindowLong(hConsole, GWL_STYLE, style);
	int x, y;
	while (cin >> x >> y)
	{
		// 获取控制台屏幕缓冲区的句柄
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	    COORD bufferSize = {x, y};
	    
	    // 设置控制台缓冲区的大小
	    SetConsoleScreenBufferSize(hConsole, bufferSize);
	    
	    // 设置窗口的大小
	    SMALL_RECT windowSize = {0, 0, bufferSize.X - 1, bufferSize.Y - 1};
	    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	}

//	HANDLE Hand;
//	CONSOLE_SCREEN_BUFFER_INFO Info;
//	Hand = GetStdHandle(STD_OUTPUT_HANDLE);
//	GetConsoleScreenBufferInfo(Hand, &Info);
//	SMALL_RECT rect = Info.srWindow;
//	COORD size = { rect.Right +1 ,rect.Bottom +1 };	//定义缓冲区大小，保持缓冲区大小和屏幕大小一致即可取消边框 
//	SetConsoleScreenBufferSize(Hand, size);
	
	char c;
	while (cin>>c) ;
	
    return 0;
}