#include "progress_bar.hpp"

std::string startChar = "|";
std::string endChar = ">";
std::string fullChar = "-";
std::string blankChar = " ";

// min{progressBarLength, N}
int progressBarLength = 40;

fmt::v8::text_style style = fg(fmt::color::green);

/*-----------------------------------------------------------------------------
Function progressBar
Provides a simple command line progress bar display

Parameter: 
    i       Count value, from 0 to N-1
            i =  0      start
            i >= N-1    end
    
    N       Number of cycles

-----------------------------------------------------------------------------*/
void progressBar(const int &i, const int &N)
{
    static clock_t startTime; // time control
    static bool isStart;
    static bool isEnd;
    static int index;

    int barlength = progressBarLength;
    if (N < barlength)
        barlength = N;

    if (0 == i) // start
    {
        startTime = clock();
        fmt::print("\033[?25l"); // hide cursor
        fmt::print("\n");
        isStart = true;
        isEnd = false;
        index = 1;
    }

    if (isStart && !isEnd) // loop
    {
        double len = N * 1.0 / barlength;
        if (abs(i - index * len) < 1e-15)
        {
            index++;

            fmt::print("\r");

            fmt::print(style, startChar);

            int j = 0;
            for (; j < index; j++)
                fmt::print(style, fullChar);

            for (; j < barlength; j++)
                fmt::print(style, blankChar);

            fmt::print(style, endChar);

            clock_t endTime = clock();
            double consumTime = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000;
            fmt::print(style, "| {}/{} | {:.2f} ms |", index, barlength, consumTime);
        }
    }

    if (isStart && !isEnd && N - 1 <= i) // loop end
    {
        isStart = false;
        isEnd = true;
        fmt::print("\n\n");
        fmt::print("\33[?25h"); // display cursor
    }
}

/*-----------------------------------------------------------------------------
Function wait
Simple delay function

Parameter: 
    time_us        delay microseconds

-----------------------------------------------------------------------------*/
void wait(double time_us)
{
    clock_t time1, time2;
    time1 = clock();
    while (1)
    {
        time2 = clock();
        double consumTime = (double)(time2 - time1) / CLOCKS_PER_SEC * 1000; // ms
        if (consumTime > time_us / 1000)
            break;
    }
}