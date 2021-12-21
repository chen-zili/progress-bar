#include "main.hpp"
#include "progress_bar.hpp"

using namespace std;

int main(int argc,char **argv)
{
    for(int i=0; i < 100; i++)
    {
        progressBar(i, 100);
    }

    return 0;
}