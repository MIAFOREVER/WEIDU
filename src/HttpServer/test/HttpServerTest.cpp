#include <gtest/gtest.h>
#include "HttpServer.h"
#include "Log.h"
#include <string>

using namespace std;

void calculate(int connect, std::map<std::string, std::string>info)
{
    Log* log = Log::getPoint();
    log->print("run successfully!"); 
    log->print(info["method"]);
    log->print(info["url"]);
    log->print(info["version"]);
    close(connect);
}

TEST(HttpServerTest, ServerTest)
{
    HttpServer hs;
    Log* log = Log::getPoint();
    log->print("begin test");
    thread t(std::bind(&HttpServer::serverListen, &hs));
    log->print("begin get");
    hs.get("/index", calculate);
    t.join();
}

