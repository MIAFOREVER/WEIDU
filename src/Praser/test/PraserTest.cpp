#include <gtest/gtest.h>
#include "Praser.h"
#include <string>
#include <map>
using namespace std;
TEST(PraserTest,convertHeader)
{
    HttpPraser p;
    string T = "POST /url.html HTTP/1.1\r\n";
    T += "context:t\r\n";
    T += "info:ppp\r\n\r\n";
    T += "ajkhd=kusdf&suidga=saduh&eiuruf=sadkgu&dsa=sdfk";
    map<string, string> header;
    map<string, string> info;
    p.HttpPostPraser(T, header, info);
    EXPECT_EQ(header["method"], "POST");
    EXPECT_EQ(header["url"], "/url.html");
    EXPECT_EQ(header["version"], "HTTP/1.1");
    EXPECT_EQ(header["context"], "t");
    EXPECT_EQ(header["info"], "ppp");

    EXPECT_EQ(info["ajkhd"], "kusdf");
    EXPECT_EQ(info["suidga"], "saduh");
    EXPECT_EQ(info["eiuruf"], "sadkgu");
    EXPECT_EQ(info["dsa"], "sdfk");

    string temp;
    p.HttpHeaderPraser(T, temp, header);
    EXPECT_EQ(header["method"], "POST");
    EXPECT_EQ(header["url"], "/url.html");
    EXPECT_EQ(header["version"], "HTTP/1.1");
    EXPECT_EQ(header["context"], "t");
    EXPECT_EQ(header["info"], "ppp");

    EXPECT_EQ(temp, "ajkhd=kusdf&suidga=saduh&eiuruf=sadkgu&dsa=sdfk");
}

TEST(PraserTest,convertJson)
{
    HttpPraser p;
    map<string, string> header;
    map<string, string> info;
    json j;

    string T = "POST /url.html HTTP/1.1\r\n";
    T += "context:t\r\n";
    T += "info:ppp\r\n\r\n";
    T += "{ \"happy\": true, \"pi\": 3.141 }";

    string temp;
    p.HttpHeaderPraser(T, temp, header);
    EXPECT_EQ(header["method"], "POST");
    EXPECT_EQ(header["url"], "/url.html");
    EXPECT_EQ(header["version"], "HTTP/1.1");
    EXPECT_EQ(header["context"], "t");
    EXPECT_EQ(header["info"], "ppp");
    
    p.HttpPostJson(temp, j);
    EXPECT_EQ(j["happy"], true);
    EXPECT_EQ(j["pi"], 3.141);
}