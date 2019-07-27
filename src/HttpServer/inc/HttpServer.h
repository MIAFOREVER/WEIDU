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
    std::map<std::string, void (*)(int, std::map<std::string, std::string>)>     funcList; 

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
     * @brief express like firmwork
     * 
     * @param filepath 
     * @param void(*)(int, std::map<std::string, std::string>))
     * @return int 
     */
    int get(std::string filepath, void (*)(int, std::map<std::string, std::string>));

    void printRequest();
};