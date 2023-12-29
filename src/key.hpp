#include "util.hpp"

#include <vector>

namespace ctc
{
    class key
    {
        std::vector<int> m_keys;

    public:
        key(int key)
        {
            m_keys.push_back(key);
        }

        key(std::initializer_list<int> keys)
        {
            for (auto key : keys)
            {
                m_keys.push_back(key);
            }
        }

        key operator+(const key &other) const
        {
            key result = *this;
            for (auto key : other.m_keys)
            {
                result.m_keys.push_back(key);
            }
            return result;
        }

        key &operator+=(const key &other)
        {
            for (auto key : other.m_keys)
            {
                m_keys.push_back(key);
            }
            return *this;
        }

        bool is_pressed() const
        {
            bool flag = true;
            for (auto key : m_keys)
            {
                if (!(GetAsyncKeyState(key) & 0x8000))
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
    };
    // 常用按键列表

    // 方向键
    const key KEY_UP = VK_UP;
    const key KEY_DOWN = VK_DOWN;
    const key KEY_LEFT = VK_LEFT;
    const key KEY_RIGHT = VK_RIGHT;
    // F1-F12
    const key KEY_F1 = VK_F1;
    const key KEY_F2 = VK_F2;
    const key KEY_F3 = VK_F3;
    const key KEY_F4 = VK_F4;
    const key KEY_F5 = VK_F5;
    const key KEY_F6 = VK_F6;
    const key KEY_F7 = VK_F7;
    const key KEY_F8 = VK_F8;
    const key KEY_F9 = VK_F9;
    const key KEY_F10 = VK_F10;
    const key KEY_F11 = VK_F11;
    const key KEY_F12 = VK_F12;
    // 数字键
    const key KEY_0 = '0';
    const key KEY_1 = '1';
    const key KEY_2 = '2';
    const key KEY_3 = '3';
    const key KEY_4 = '4';
    const key KEY_5 = '5';
    const key KEY_6 = '6';
    const key KEY_7 = '7';
    const key KEY_8 = '8';
    const key KEY_9 = '9';
    // 符号
    const key KEY_GRAVE_ACCENT = VK_OEM_3;  // `键
    const key KEY_MINUS = VK_OEM_MINUS;     // -键
    const key KEY_PLUS = VK_OEM_PLUS;       // +键
    const key KEY_LEFT_BRACKET = VK_OEM_4;  // [键
    const key KEY_RIGHT_BRACKET = VK_OEM_6; // ]键
    const key KEY_BACKSLASH = VK_OEM_5;     // \键
    const key KEY_SEMICOLON = VK_OEM_1;     // ;键
    const key KEY_QUOTE = VK_OEM_7;         // '键
    const key KEY_COMMA = VK_OEM_COMMA;     // ,键
    const key KEY_PERIOD = VK_OEM_PERIOD;   // .键
    const key KEY_SLASH = VK_OEM_2;         // /键
    // 字母const key KEY_A = 'A';
    const key KEY_B = 'B';
    const key KEY_C = 'C';
    const key KEY_D = 'D';
    const key KEY_E = 'E';
    const key KEY_F = 'F';
    const key KEY_G = 'G';
    const key KEY_H = 'H';
    const key KEY_I = 'I';
    const key KEY_J = 'J';
    const key KEY_K = 'K';
    const key KEY_L = 'L';
    const key KEY_M = 'M';
    const key KEY_N = 'N';
    const key KEY_O = 'O';
    const key KEY_P = 'P';
    const key KEY_Q = 'Q';
    const key KEY_R = 'R';
    const key KEY_S = 'S';
    const key KEY_T = 'T';
    const key KEY_U = 'U';
    const key KEY_V = 'V';
    const key KEY_W = 'W';
    const key KEY_X = 'X';
    const key KEY_Y = 'Y';
    const key KEY_Z = 'Z';
    // 小键盘
    const key KEY_NUMPAD0 = VK_NUMPAD0;     // 小键盘0
    const key KEY_NUMPAD1 = VK_NUMPAD1;     // 小键盘1
    const key KEY_NUMPAD2 = VK_NUMPAD2;     // 小键盘2
    const key KEY_NUMPAD3 = VK_NUMPAD3;     // 小键盘3
    const key KEY_NUMPAD4 = VK_NUMPAD4;     // 小键盘4
    const key KEY_NUMPAD5 = VK_NUMPAD5;     // 小键盘5
    const key KEY_NUMPAD6 = VK_NUMPAD6;     // 小键盘6
    const key KEY_NUMPAD7 = VK_NUMPAD7;     // 小键盘7
    const key KEY_NUMPAD8 = VK_NUMPAD8;     // 小键盘8
    const key KEY_NUMPAD9 = VK_NUMPAD9;     // 小键盘9
    const key KEY_NUMPADENTER = VK_SEPARATOR;   // 小键盘回车
    const key KEY_NUMPADPLUS = VK_ADD;          // 小键盘+
    const key KEY_NUMPADMINUS = VK_SUBTRACT;    // 小键盘-
    const key KEY_NUMPADMULTIPLY = VK_MULTIPLY; // 小键盘*
    const key KEY_NUMPADDIVIDE = VK_DIVIDE;     // 小键盘/
    const key KEY_NUMPADPERIOD = VK_DECIMAL;    // 小键盘.
    // 控制按键
    const key KEY_LWIN = VK_LWIN;       // 左win键
    const key KEY_RWIN = VK_RWIN;       // 右win键
    const key KEY_APPS = VK_APPS;       // 应用程序键
    const key KEY_LSHIFT = VK_LSHIFT;   // 左shift键
    const key KEY_RSHIFT = VK_RSHIFT;   // 右shift键
    const key KEY_LCTRL = VK_LCONTROL;  // 左ctrl键
    const key KEY_RCTRL = VK_RCONTROL;  // 右ctrl键
    const key KEY_LALT = VK_LMENU;      // 左alt键
    const key KEY_RALT = VK_RMENU;      // 右alt键
    const key KEY_CTRL = VK_CONTROL;    // ctrl键
    const key KEY_ALT = VK_MENU;        // alt键
    const key KEY_SHIFT = VK_SHIFT;     // shift键
    // 杂项
    const key KEY_ENTER = VK_RETURN;    // 回车键
    const key KEY_SPACE = VK_SPACE;     // 空格键
    const key KEY_ESC = VK_ESCAPE;      // ESC键
    const key KEY_BACKSPACE = VK_BACK;  // 退格键
    const key KEY_TAB = VK_TAB;         // TAB键
    const key KEY_CAPSLOCK = VK_CAPITAL;    // 大小写锁定键
    const key KEY_NUMLOCK = VK_NUMLOCK;     // 小键盘锁定键
    const key KEY_SCROLLLOCK = VK_SCROLL;   // 滚动锁定键
    const key KEY_INSERT = VK_INSERT;       // 插入键
    const key KEY_DELETE = VK_DELETE;       // 删除键
    const key KEY_HOME = VK_HOME;           // Home键
    const key KEY_END = VK_END;             // End键
    const key KEY_PAGEUP = VK_PRIOR;        // PageUp键
    const key KEY_PAGEDOWN = VK_NEXT;       // PageDown键
    const key KEY_PRINTSCREEN = VK_SNAPSHOT;// PrintScreen键
    const key KEY_PAUSE = VK_PAUSE;         // Pause键
    const key KEY_CLEAR = VK_CLEAR;         // Clear键
    const key KEY_MENU = VK_MENU;           // 菜单键
    const key KEY_HELP = VK_HELP;           // 帮助键
    const key KEY_SLEEP = VK_SLEEP;         // 休眠键
}