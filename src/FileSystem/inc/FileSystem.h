/**
 * @file FileSystem.h
 * @author ZHANGHAO (zhangh527@mail2.sysu.edu.cn)
 * @brief 
 * @version 0.1
 * @date 2019-07-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <fstream>
#include <string>

class FileSystem
{
    private:
    char* buff;

    public:
    void read(std::string filename, char* buff, int length);
};