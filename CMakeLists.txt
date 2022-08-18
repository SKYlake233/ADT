#[[cmake最小版本]]
cmake_minimum_required(VERSION 3.23)
#[[项目名称]]
project(ADT)
#[[设置项目的版本号]]
set(ADT_VERSION_MAJOR 1)  #[[主版本号]]
set(ADT_VERSION_MINOR 0)   #[[次版本号]]
#[[设置C++版本]]
set(CMAKE_CXX_STANDARD 14)
#[[选择编译执行的文件]]

#[[多项目编译文件]]
# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./ ./tree)
#[[添加到build任务列表]]
add_subdirectory(tree)
#[[使用指定的源文件生成可执行文件]]
add_executable(ADT ${DIRSRCS})
#[[目标文件与库文件链接]]
target_link_libraries(ADT tree)