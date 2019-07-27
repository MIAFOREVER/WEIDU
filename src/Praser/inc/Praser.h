/**
 * @file Praser.h
 * @author your name (you@domain.com)
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
using json = nlohmann::json;
/**
 * @brief HttpPraser module
 * 
 */
class HttpPraser
{
    public:
    
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
};