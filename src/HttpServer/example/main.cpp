#include "HttpServer.h"

void calculate(int connect, std::map<std::string, std::string>& info)
{
    Log* log = Log::getPoint();
    log->print("run successfully!"); 
    log->print(info["method"]);
    log->print(info["url"]);
    log->print(info["version"]);
}

int main()
{
    HttpServer hs;
    //hs.serverListen();
    //hs.get("/text", calculate);
}