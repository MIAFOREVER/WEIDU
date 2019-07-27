#include <iostream>
#include <time.h>
#include "Log.h"

using namespace std;
Log* Log::pointer;

Log::~Log()
{
    delete pointer;
}

Log* Log::getPoint()
{
    if(pointer == nullptr)
    {
        pointer = new Log;
        return pointer;
    }
    else
    {
        return pointer;
    }
}

string Log::getTime()
{
    time_t tt = time(NULL);
	tm* t = localtime(&tt);
    string TTime;
    TTime += to_string(t->tm_year + 1900);
    TTime += '-';
    if((t->tm_mon + 1) / 10 == 0)
    {
        TTime += '0';
    }
    TTime += to_string(t->tm_mon + 1);
    TTime += '-';
    if((t->tm_mday) / 10 == 0)
    {
        TTime += '0';
    }
    TTime += to_string(t->tm_mday);
    TTime += ' ';
    if((t->tm_hour) / 10 == 0)
    {
        TTime += '0';
    }
    TTime += to_string(t->tm_hour);
    TTime += ':';
    if((t->tm_min) / 10 == 0)
    {
        TTime += '0';
    }
    TTime += to_string(t->tm_min);
    TTime += ':';
    if((t->tm_sec) / 10 == 0)
    {
        TTime += '0';
    }
    TTime += to_string(t->tm_sec);
    return TTime;
}

void Log::print(std::string log)
{
    string TTime = getTime();
    cout << "[" << TTime << "][info]:\t" << " " << log << endl;
}
void Log::print(const char* log)
{
    string TTime = getTime();
    cout << "[" << TTime << "][info]:\t" << " " << log << endl;
}
void Log::print(char* log)
{
    string TTime = getTime();
    cout << "[" << TTime << "][info]:\t" << " " << log << endl;
}
void Log::print(const char* log, size_t length)
{
    string TTime = getTime();
    cout << "[" << TTime << "][info]:\t" << " " ;
    for(int i = 0; i < length; i++)
    {
        cout << log[i];
    }
    cout << endl;
}
void Log::print(char* log, size_t length)
{
    string TTime = getTime();
    cout << "[" << TTime << "][info]:\t" << " " ;
    for(int i = 0; i < length; i++)
    {
        cout << log[i];
    }
    cout << endl;
}