#include "status.h"
#include <string>
using namespace std;

void response404(HttpServer* hs, int connect, std::map<std::string, std::string>info)
{
    HttpPraser hp;
    string title;
    string header = "Content-Type: text/html\r\n\r\n";
    string body = "<p>404</p>";
    hp.mapToTitle(hs->getGetTitle(), title);
    hs->sendto(connect, title);
    hs->sendto(connect, header);
    hs->sendto(connect, body);
    close(connect);
    close(connect);
}