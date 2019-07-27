/**
 * @file HttpServer.h
 * @author ZHANGHAO (zhangh527@mail2.sysu.edu.com)
 * @brief 
 * @version 0.1
 * @date 2019-07-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h> 
#include <unistd.h>

#include <string>
#include <iostream>
#include <map>
#include <thread>

#include "Log.h"
#include "Praser.h"

#define MAXLINE 4096 
#define DEFAULT_PORT 80

class HttpServer
{
    public:
    typedef void (*UserThread)(HttpServer*, int, std::map<std::string, std::string>);

    private:
    int                                 socket_fd;
    int                                 connect_fd; 
    struct sockaddr_in                  servaddr; 
    char*                               buff;
    int                                 n;
    Log*                                log;
    HttpPraser                          praser;
    std::string                         text;
    std::string                         body;
    std::map<std::string, std::string>  header;
    std::map<std::string, std::string>  info;
    std::map<std::string, UserThread>   funcList; 

    private:
    std::map<std::string, std::string>  postHeader;
    std::map<std::string, std::string>  getHeader;

    public:
    /**
     * @brief Construct a new Http Server object
     * 
     */
    HttpServer();

    /**
     * @brief Deconstruct a new Http Server object
     * 
     */
    ~HttpServer();

    /**
     * @brief 
     * 
     */
    void serverListen();
    
    /**
     * @brief Express like firmwork
     * 
     * @param filepath 
     * @param void(*)(int, std::map<std::string, std::string>))
     * @return int 
     */
    int get(std::string filepath, UserThread);

    /**
     * @brief Print full buffer message
     * 
     */
    void printRequest();

    /**
     * @brief Send function
     * 
     * @param connect 
     * @param buff 
     * @return int 
     */
    int sendto(int connect, std::string buff);
    
    /**
     * @brief Send function
     * 
     * @param connect 
     * @param buff 
     * @return int 
     */
    int sendto(int connect, char* buff);
    
    /**
     * @brief Send function
     * 
     * @param connect 
     * @param buff 
     * @return int 
     */
    int sendto(int connect, const char* buff);
    
    /**
     * @brief Send function
     * 
     * @param connect 
     * @param buff 
     * @param length 
     * @return int 
     */
    int sendto(int connect, char* buff, int length);
    
    /**
     * @brief Send function
     * 
     * @param connect 
     * @param buff 
     * @param length 
     * @return int 
     */
    int sendto(int connect, const char* buff, int length);

    /**
     * @brief Get the Post Title object
     * 
     * @return std::map<std::string, std::string> 
     */
    std::map<std::string, std::string> getPostTitle();

    /**
     * @brief Get the Get Title object
     * 
     * @return std::map<std::string, std::string> 
     */
    std::map<std::string, std::string> getGetTitle();
};