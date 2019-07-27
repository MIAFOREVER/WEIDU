#include <gtest/gtest.h>
#include "Log.h"
#include <string>
using namespace std;

TEST(LogTest, LogT)
{
    Log* p = Log::getPoint();
    p->print("i wannna eat sth");
    p->print("ppppp", 3);
}

