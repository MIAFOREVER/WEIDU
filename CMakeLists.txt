cmake_minimum_required (VERSION 2.8)

project (WEIDU)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 添加头文件路径

# 添加 math 子目录
add_subdirectory(src/HttpServer)
add_subdirectory(src/Log)
add_subdirectory(src/Praser)
add_subdirectory(src/project)