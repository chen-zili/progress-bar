#ifndef _PROGRESS_BAR_
#define _PROGRESS_BAR_

#include <string>
#include <ctime>

#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/chrono.h>

extern void progressBar(const int &i, const int &N);
extern void wait(double time_us = 1000);

#endif