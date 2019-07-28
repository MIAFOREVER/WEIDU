#include <gtest/gtest.h>
#include "HttpServer.h"
#include "Log.h"
#include <string>

using namespace std;

void calculate(HttpServer* hs, int connect, std::map<std::string, std::string>info, string body)
{
    Log* log = Log::getPoint();
    log->print("run successfully!"); 
    log->print("method:" + info["method"]);
    log->print("url:" + info["url"]);
    log->print("version:" + info["version"]);
    
    HttpPraser hp;
    string title;
    string header = "Content-Type: text/html\r\n\r\n";
    string sendBody = "<p>hello</p>";
    hp.mapToTitle(hs->getGetTitle(), title);
    hs->sendto(connect, title);
    hs->sendto(connect, header);
    hs->sendto(connect, sendBody);
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

