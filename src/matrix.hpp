#include "util.hpp"

#include <vector>

namespace ctc
{
    class matrix
    {
        // '\0'表示透明，其他字符表示对应的字符
        std::vector<std::vector<char>> m_data;

    public:
        matrix(int rows, int cols) : m_data(rows, std::vector<char>(cols, '\0')) {}
        std::vector<char> &operator[](int idx)
        {
            return m_data[idx];
        }
        // 重设矩阵大小，注意该函数会自动删除超出部分，并将不足部分填成'\0'
        void resize(int rows, int cols)
        {
            m_data.resize(rows);
            for (int i = 0; i < rows; i++)
                m_data[i].resize(cols);
        }
        // 将矩阵全部填充为指定字符
        void fill(char ch = '\0')
        {
            for (int i = 0; i < m_data.size(); i++)
                for (int j = 0; j < m_data[0].size(); j++)
                    m_data[i][j] = ch;
        }
        // 打印
        void print()
        {
            for (int i = 0; i < m_data.size(); i++)
            {
                for (int j = 0; j < m_data[0].size(); j++)
                    putchar(m_data[i][j]);
                putchar('\n');
            }
        }
        // 在(x,y)处插入一个矩阵
        void draw(int x, int y, const matrix &other)
        {
            for (int i = 0; i < other.m_data.size() && x + i < m_data.size(); ++i)
            {
                for (int j = 0; j < other.m_data[0].size() && y + j < m_data[0].size(); ++j)
                {
                    m_data[x + i][y + j] = other.m_data[i][j];
                }
            }
        }
        void draw(int x, int y, const matrix &other, int bx, int by)
        {
            for (int i = bx; i < other.m_data.size() && x + i < m_data.size(); ++i)
            {
                for (int j = bx; j < other.m_data[0].size() && y + j < m_data[0].size(); ++j)
                {
                    m_data[x + i][y + j] = other.m_data[i][j];
                }
            }
        }
        void draw(int x, int y, const matrix &other, int bx, int by, int ex, int ey)
        {
            for (int i = bx; i <= ex && i < other.m_data.size() && x + i - bx < m_data.size(); ++i)
            {
                for (int j = by; j <= ey && j < other.m_data[0].size() && y + j - by < m_data[0].size(); ++j)
                {
                    m_data[x + i - bx][y + j - by] = other.m_data[i][j];
                }
            }
        }
    };
}