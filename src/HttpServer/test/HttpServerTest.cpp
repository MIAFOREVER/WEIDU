#include <gtest/gtest.h>
#include "HttpServer.h"
#include "Log.h"
#include <string>
using namespace std;

void calculate()
{
    Log* log = Log::getPoint();
    log->print("run successfully!"); 
}

TEST(HttpServerTest, ServerTest)
{
    HttpServer hs;
    hs.serverListen();
    //hs.get("/search", calculate);
}

