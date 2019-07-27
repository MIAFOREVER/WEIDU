/**
 * @file Praser.h
 * @author ZHANGHAO (zhangh527@mail2.sysu.edu.com)
 * @brief 
 * @version 0.1
 * @date 2019-07-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include <string>
#include <map>
#include <json.hpp>

#include "Log.h"
using json = nlohmann::json;
/**
 * @brief HttpPraser module
 * 
 */
class HttpPraser
{
    private:

    Log* log;

    public:
    HttpPraser();
    /**
     * @brief POST Praser
     * 
     * @param text 
     * @param header 
     * @param info 
     */
    void HttpPostPraser(const std::string text, std::map<std::string, std::string>& header, std::map<std::string, std::string>& info);
    
    /**
     * @brief HEADER Praser
     * 
     * @param text 
     * @param header 
     */
    void HttpHeaderPraser(const std::string text, std::string& body, std::map<std::string, std::string>& header);
    
    /**
     * @brief Praser json
     * 
     * @param text 
     * @param info 
     */
    void HttpPostJson(const std::string text, json& info);

    /**
     * @brief 
     * 
     * @param info 
     * @param text 
     */
    void mapToHeader(std::map<std::string, std::string> info, std::string& text);

    /**
     * @brief 
     * 
     * @param info 
     * @param text 
     */
    void mapToTitle(std::map<std::string, std::string> info, std::string& text);
};