#include "HttpServer.h"
#include "Log.h"
#include "Praser.h"

#include <thread>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    HttpServer hs;
    HttpPraser hp;
    Log* log = Log::getPoint();
    thread t(std::bind(&HttpServer::serverListen, &hs));
    return 0;
}
