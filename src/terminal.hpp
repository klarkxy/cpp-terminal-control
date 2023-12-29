#include "util.hpp"

namespace ctc
{
    class terminal
    {
    public:
        // 设置终端标题
        void set_title(const std::string &title)
        {
            m_title = title;
            SetConsoleTitle(util::to_lpctstr(title));
        }
        // 获取终端标题
        const std::string &get_title() const
        {
            return m_title;
        }
        // 获取窗口大小
        int get_size_x() const
        {
            return m_size_x;
        }
        int get_size_y() const
        {
            return m_size_y;
        }
        // 设置窗口大小
        void set_size(int size_x, int size_y)
        {
            // 设置控制台缓冲区的大小
            COORD bufferSize = {size_x, size_y};
            SetConsoleScreenBufferSize(m_handle, bufferSize);

	        // 设置窗口的大小
            m_size_x = size_x;
            m_size_y = size_y;
            SMALL_RECT rect = {0, 0, size_x - 1, size_y - 1};
            SetConsoleWindowInfo(m_handle, TRUE, &rect);
        }

        // 设置光标是否可见
        void set_cursor_visible(bool visible)
        {
            CONSOLE_CURSOR_INFO cursor_info;
            GetConsoleCursorInfo(m_handle, &cursor_info);
            cursor_info.bVisible = visible;
            SetConsoleCursorInfo(m_handle, &cursor_info);
        }

        // 移动光标到指定位置
        void move_cursor(int x, int y)
        {
            COORD coord = {x, y};
            SetConsoleCursorPosition(m_handle, coord);
        }

        // 清屏
        void clear()
        {
            COORD coord = {0, 0};
            DWORD dwWritten;
            FillConsoleOutputCharacter(m_handle, ' ', m_size_x * m_size_y, coord, &dwWritten);
            move_cursor(0, 0);
        }

        // 睡眠
        void sleep(int ms)
        {
            Sleep(ms);
        }
    public:     // 窗口样式
        // 设置窗口样式
        void set_style(DWORD style, bool enable)
        {
            DWORD dwStyle = GetWindowLong(m_hwnd, GWL_STYLE);
            if (enable)
                dwStyle |= style;
            else
                dwStyle &= ~style;
            SetWindowLong(m_hwnd, GWL_STYLE, dwStyle);
        }
        // 设置窗口是否包含标题
        void set_titlebar(bool titlebar)
        {
            set_style(WS_CAPTION, titlebar);
        }
        // 设置窗口是否可调整大小
        void set_resizable(bool resizable)
        {
            set_style(WS_SIZEBOX, resizable);
        }
        // 设置窗口是否可最大化
        void set_maximizable(bool maximizable)
        {
            set_style(WS_MAXIMIZEBOX, maximizable);
        }
        // 设置窗口是否可最小化
        void set_minimizable(bool minimizable)
        {
            set_style(WS_MINIMIZEBOX, minimizable);
        }
        // 设置窗口是否可关闭
        void set_closable(bool closable)
        {
            set_style(WS_SYSMENU, closable);
        }
        // 设置窗口是否可置顶
        void set_topmost(bool topmost)
        {
            set_style(WS_EX_TOPMOST, topmost);
        }
        // 设置窗口是否可透明
        void set_transparent(bool transparent)
        {
            set_style(WS_EX_LAYERED, transparent);
        }
        // 设置窗口是否可拖动
        void set_draggable(bool draggable)
        {
            set_style(WS_EX_TRANSPARENT, draggable);
        }
        // 设置窗口是否可最前
        void set_foremost(bool foremost)
        {
            set_style(WS_EX_NOACTIVATE, foremost);
        }
        // 设置窗口是否包含边框
        void set_border(bool border)
        {
            set_style(WS_BORDER, border);
        }

    public:
        terminal()
        {
            m_handle = GetStdHandle(STD_OUTPUT_HANDLE);
            m_hwnd = GetConsoleWindow();
            // 获取控制台窗口大小
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(m_handle, &csbi);
            m_size_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            m_size_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }

    private:
        int m_size_x, m_size_y;
        std::string m_title;
        HANDLE m_handle;
        HWND m_hwnd;

    public: // 单例
        terminal(const terminal &) = delete;
        terminal &operator=(const terminal &) = delete;
        static terminal &instance()
        {
            static terminal instance;
            return instance;
        }
    };
}