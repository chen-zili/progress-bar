#include "main.hpp"
#include "progress_bar.hpp"
#include <unistd.h> 

using namespace std;

int main(int argc,char **argv)
{
    for(int i=0; i < 39; i++)
    {
        progressBar(i, 39);
        // sleep(0);
    }

    return 0;
}