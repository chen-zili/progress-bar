#include "main.hpp"
#include "progress_bar.hpp"
#include <unistd.h> 

using namespace std;

int main(int argc,char **argv)
{
    for(int i=0; i < 10000000; i++)
    {
        progressBar(i, 10000000);
        // sleep(0);
    }

    return 0;
}