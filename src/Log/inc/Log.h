/**
 * @file Log.h
 * @author ZHANGHAO (zhangh527@mail2.sysu.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include <string>
/**
 * @brief Log class
 * 
 */
class Log
{
    public:
    /**
     * @brief single point
     * 
     */
    static Log*     pointer;

    public:
    ~Log();
    static Log* getPoint();
    
    public:
    void print(std::string log);
    void print(const char* log);
    void print(char* log);
    void print(const char* log, size_t length);
    void print(char* log, size_t length);

    public:
    void error(std::string log);
    void error(const char* log);
    void error(char* log);
    void error(const char* log, size_t length);
    void error(char* log, size_t length);

    public:
    std::string getTime();
};