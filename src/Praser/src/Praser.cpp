#include "Praser.h"
#include <iostream>
using namespace std;
void HttpPraser::HttpPostPraser(const string t, map<string, string>& header, map<string, string>& info)
{
    string text = t; 
    string method;
    string url;
    string version;
    string key, value;
    /**
     * @brief First line praser
     * 
     */
    method  = text.substr(0, text.find(' '));
    text = text.substr(text.find(' ') + 1);
    url = text.substr(0, text.find(' '));
    text = text.substr(text.find(' ') + 1);
    version = text.substr(0, text.find("\r\n"));
    text = text.substr(text.find("\r\n") + 2);
    header.insert(pair<string, string>("method", method));
    header.insert(pair<string, string>("url", url));
    header.insert(pair<string, string>("version", version));

    /**
     * @brief Header Read praser
     * 
     */
    int space;
    int linefeed;
    space = text.find(':');
    linefeed = text.find("\r\n");
    while(text.substr(linefeed, 4) != "\r\n\r\n")
    {
        key = text.substr(0, space);
        value = text.substr(space + 1, linefeed - space - 1);
        header.insert(pair<string, string>(key, value));
        text = text.substr(linefeed + 2);
        space = text.find(':');
        linefeed = text.find("\r\n");
    }
    key = text.substr(0, space);
    value = text.substr(space + 1, linefeed - space - 1);
    header.insert(pair<string, string>(key, value));
    text = text.substr(linefeed + 4);
    
    /**
     * @brief context praser
     * 
     */
    space = text.find('=');
    linefeed = text.find('&');
    while(!(space != 0 && linefeed == std::string::npos))
    {
        key = text.substr(0, space);
        value = text.substr(space + 1, linefeed - space - 1);
        info.insert(pair<string, string>(key, value));
        text = text.substr(linefeed + 1);
        space = text.find('=');
        linefeed = text.find('&');
    }
    key = text.substr(0, space);
    value = text.substr(space + 1);
    info.insert(pair<string, string>(key, value));
    text = "";
}

void HttpPraser::HttpHeaderPraser(const string t, string& body, map<string, string>& header)
{
    string text = t; 
    string method;
    string url;
    string version;
    string key, value;
    /**
     * @brief First line praser
     * 
     */
    method  = text.substr(0, text.find(' '));
    text = text.substr(text.find(' ') + 1);
    url = text.substr(0, text.find(' '));
    text = text.substr(text.find(' ') + 1);
    version = text.substr(0, text.find("\r\n"));
    text = text.substr(text.find("\r\n") + 2);
    header.insert(pair<string, string>("method", method));
    header.insert(pair<string, string>("url", url));
    header.insert(pair<string, string>("version", version));

    /**
     * @brief Header Read praser
     * 
     */
    int space;
    int linefeed;
    space = text.find(':');
    linefeed = text.find("\r\n");
    while(text.substr(linefeed, 4) != "\r\n\r\n")
    {
        key = text.substr(0, space);
        value = text.substr(space + 1, linefeed - space - 1);
        header.insert(pair<string, string>(key, value));
        text = text.substr(linefeed + 2);
        space = text.find(':');
        linefeed = text.find("\r\n");
    }
    key = text.substr(0, space);
    value = text.substr(space + 1, linefeed - space - 1);
    header.insert(pair<string, string>(key, value));
    text = text.substr(linefeed + 4);
    body = text;
}

void HttpPraser::HttpPostJson(const std::string text, json& info)
{
    json temp = json::parse(text.c_str());
    info = temp;
}