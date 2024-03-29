/**
 * @file HttpServer.cpp
 * @author ZHANGHAO (zhangh527@mail2.sysu.edu.com)
 * @brief 
 * @version 0.1
 * @date 2019-07-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "HttpServer.h"
#include "status.h"

#include <string.h> 
#include <errno.h>
#include <stdio.h>  
#include <stdlib.h> 
#include <thread>

#include <string>
#include <map>
#include <thread>
using namespace std;

HttpServer::HttpServer()
{
    log = Log::getPoint();
    socket_fd = 0;
    connect_fd = 0; 
    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    buff = new char[MAXLINE];
    n = 0;

    postHeader["version"] = "HTTP/1.1";
    postHeader["status_code"] = "200";
    postHeader["status"] = "OK";

    getHeader["version"] = "HTTP/1.1";
    getHeader["status_code"] = "200";
    getHeader["status"] = "OK";
}

HttpServer::~HttpServer()
{
    delete buff;
    close(socket_fd);
}

void HttpServer::serverListen()
{
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
    {  
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno); 
        exit(0);  
    }  
    log->print("Socket init successfully!"); 
    
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(DEFAULT_PORT);

    if(bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    {  
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
        exit(0);  
    }
    log->print("Bind socket successfully!");

    if( listen(socket_fd, 10) == -1)
    {  
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
        exit(0);  
    }    
    log->print("Listen process successfully!");
    log->print("waiting for client's request");
    while(1)
    {
        if((connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)) == -1)
        {  
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
            continue;
        }
        n = recv(connect_fd, buff, MAXLINE, 0);  
        buff[n] = '\0'; 
        text = buff;
        log->print("recv msg from client");

        praser.HttpHeaderPraser(text, body, header);

        if(header["method"] == "POST" && funcList[header["url"]] != nullptr)  
        {
            log->print("Receive post request successfully");
            thread t(*funcList[header["url"]], this, connect_fd, header, body);
            t.detach();
        } 
        else if(header["method"] == "GET")
        {
            log->print("Receive get request successfully");
            thread t(*response404, this, connect_fd, header);
            t.detach();
        }
        else
        {
            log->error("Receive post request successfully and url can't find");
            close(connect_fd);
        }
    }  
    close(socket_fd);
}

int HttpServer::get(std::string filepath, UserThread f)
{
    funcList.insert(pair<string, UserThread>(filepath, f));
}

void HttpServer::printRequest()
{
    string temp = buff;
    temp = "\n" + temp;
    log->print(temp.c_str(), n);
}

int HttpServer::sendto(int connect, std::string buff)
{
    int retval = send(connect, buff.c_str(), buff.length(), 0);
    return retval;
}
    
int HttpServer::sendto(int connect, char* buff)
{
    int length = 0;
    while(buff[length] != '0')
    {
        length++;
    }
    int retval = send(connect, buff, length, 0);
    return retval;
}
    
int HttpServer::sendto(int connect, const char* buff)
{
    int length = 0;
    while(buff[length] != '0')
    {
        length++;
    }
    int retval = send(connect, buff, length, 0);
    return retval;
}
    
int HttpServer::sendto(int connect, char*, int length)
{
    int retval = send(connect, buff, length, 0);
    return retval;
}
    
int HttpServer::sendto(int connect, const char* buff, int length)
{
    int retval = send(connect, buff, length, 0);
    return retval;
}

std::map<std::string, std::string> HttpServer::getPostTitle()
{
    return postHeader;
}
    
std::map<std::string, std::string> HttpServer::getGetTitle()
{
    return getHeader;
}

HttpPraser HttpServer::getHttpPraser()
{
    return praser;
}

