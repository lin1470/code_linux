cmake_minimum_required(VERSION 3.0)
# 查找当前目录下的所有源文件
# 并宝成名称到DIR``````
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(apue ${DIR_LIB_SRCS})

