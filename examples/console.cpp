#include <windows.h>

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 创建一个新的控制台窗口
	if (!AllocConsole()) {
	    DWORD error = GetLastError();
	    printf("Failed to allocate a new console. Error code: %lu\n", error);
	    return 1;
	}

    // 重定向标准输入、输出和错误流到新的控制台窗口
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    // 在新的控制台窗口中打印一些文本
    printf("Hello, world!\n");

    return 0;
}