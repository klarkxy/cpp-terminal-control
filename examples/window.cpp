#include <windows.h>

#include <bits/stdc++.h>
using namespace std;

int main() {    
    // ��ȡ����̨���ڵľ��
    HWND hConsole = GetConsoleWindow();
	
    // ��ȡ���ڵ���ʽ
    LONG style = GetWindowLong(hConsole, GWL_STYLE);
    if (style & WS_CAPTION)
        printf("���ڰ�������\n");
    if (style & WS_SYSMENU)
        printf("���ڰ���ϵͳ�˵�\n");
    if (style & WS_THICKFRAME)
        printf("���ڰ����ɵ��߿�\n");
    if (style & WS_MINIMIZEBOX)
        printf("���ڰ�����С����ť\n");
    if (style & WS_MAXIMIZEBOX)
        printf("���ڰ�����󻯰�ť\n");
    if (style & WS_SIZEBOX)
        printf("���ڰ����ɵ���С�ı߿�\n");
    if (style & WS_VSCROLL)
        printf("���ڰ�����ֱ������\n");
    if (style & WS_HSCROLL)
        printf("���ڰ���ˮƽ������\n");
    

    // �޸���ʽ�Խ�ֹ�û��ı䴰�ڵĴ�С
    style ^= WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_VSCROLL | WS_HSCROLL;

    // �����µ���ʽ
    SetWindowLong(hConsole, GWL_STYLE, style);
	int x, y;
	while (cin >> x >> y)
	{
		// ��ȡ����̨��Ļ�������ľ��
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	    COORD bufferSize = {x, y};
	    
	    // ���ÿ���̨�������Ĵ�С
	    SetConsoleScreenBufferSize(hConsole, bufferSize);
	    
	    // ���ô��ڵĴ�С
	    SMALL_RECT windowSize = {0, 0, bufferSize.X - 1, bufferSize.Y - 1};
	    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	}

//	HANDLE Hand;
//	CONSOLE_SCREEN_BUFFER_INFO Info;
//	Hand = GetStdHandle(STD_OUTPUT_HANDLE);
//	GetConsoleScreenBufferInfo(Hand, &Info);
//	SMALL_RECT rect = Info.srWindow;
//	COORD size = { rect.Right +1 ,rect.Bottom +1 };	//���建������С�����ֻ�������С����Ļ��Сһ�¼���ȡ���߿� 
//	SetConsoleScreenBufferSize(Hand, size);
	
	char c;
	while (cin>>c) ;
	
    return 0;
}