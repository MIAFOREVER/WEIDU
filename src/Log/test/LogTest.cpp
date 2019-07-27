#include <gtest/gtest.h>
#include "Log.h"
#include <string>
using namespace std;

TEST(LogTest, LogPrint)
{
    Log* p = Log::getPoint();
    p->print("i wannna eat sth");
    p->print("ppppp", 3);
}

TEST(LogTest, LogError)
{
    Log* p = Log::getPoint();
    string t = "test";
    p->error(t);
}

