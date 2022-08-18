#[[查找所有源文件]]
aux_source_directory(. DIR_TREE_SRCS)
#[[将源文件转化为动态库库文件]]
add_library(tree ${DIR_TREE_SRCS})