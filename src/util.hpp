#pragma once

#define NOMINMAX // 关闭windows.h自带的min和max
#include <windows.h>

#include <locale>
#include <codecvt>
#include <string>

namespace ctc
{
    class util
    {
    public:
        // 将一个string转成lpctstr
        static LPCTSTR to_lpctstr(const std::string &str)
        {
#ifdef UNICODE
            std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
            std::wstring wstr = conv.from_bytes(str);
            return wstr.c_str();
#else
            return str.c_str();
#endif
        }
    };
}