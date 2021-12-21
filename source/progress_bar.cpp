#include "progress_bar.hpp"

// 全局控制变量
std::string startChar = "|";
std::string endChar = ">";
std::string fullChar = "-";
std::string blankChar = " ";

int progressBarLength = 40;

fmt::v8::text_style style = fg(fmt::color::black);

/*-----------------------------------------------------------------------------
Function progressBar
提供简易的命令行进度条显示

参数: 
    i       计数值, 值从0至N-1
            i =  0   进度条开始
            i >= N-1 进度条结束
    
    N       循环次数

-----------------------------------------------------------------------------*/
void progressBar(const int & i, const int & N)
{
    static clock_t startTime;
    static bool isStart;
    static bool isEnd;
    static int index;

    if (0 == i)
    {
        startTime = clock();
        fmt::print(style, "\n{}", startChar);
        isStart = true;
        isEnd = false;
        index = 1;
    }
    else if (isStart && !isEnd && N-1 <= i)
    {
        fmt::print(style, "{}\n", endChar);
        isStart = false;
        isEnd = true;

        clock_t endTime = clock();
        double consumTime = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
        fmt::print("\nTime consuming: {:.2f} ms\n", consumTime);
    }
    else if (isStart && !isEnd)
    {
        double len = N * 1.0 / progressBarLength;
        if (i > index*len)
        {
            index++;
            fmt::print(style, fullChar);
        }
    }
}
