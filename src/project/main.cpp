#include "HttpServer.h"
#include "Log.h"
#include "Praser.h"

#include <thread>
using namespace std;
int main()
{
    HttpServer hs;
    HttpPraser hp;
    Log* log = Log::getPoint();
    thread t(std::bind(&HttpServer::serverListen, &hs));
    
}
