#include "Praser.h"
#include "Log.h"
#include <iostream>
using namespace std;

HttpPraser::HttpPraser()
{
    log = Log::getPoint();
}

void HttpPraser::HttpPostPraser(const string t, map<string, string>& header, map<string, string>& info)
{
    Log* log = Log::getPoint();
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

    log->print("Post infomation prase successfully");
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

void HttpPraser::mapToHeader(map<string, string> info, string& text)
{
    text = "";
    map<string, string>::iterator it = info.begin();
    for(it; it != info.end(); it++)
    {
        text += it->first;
        text += ':';
        text += it->second;
        text += "\r\n";
    }
    text += "\r\n";
}

void HttpPraser::mapToTitle(map<string, string> info, string& text)
{
    text = "";
    text += info["version"];
    text += ' ';
    text += info["status_code"];
    text += ' ';
    text += info["status"];
    text += "\r\n";
    log->print("Convert map to string successfully!");
}