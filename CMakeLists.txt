cmake_minimum_required(VERSION 3.22)
project(KeenCPPTest_all)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
# 指定可执行文件的路径
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Volumes/KeenMacPlus/Projects/C++项目/KeenCPPTest-all/execu")

include_directories(/*)


add_executable(chainTest LinkedList/chainTest.cpp)
set_target_properties(chainTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "./execu")
add_executable(chainNodeTest LinkedList/chainNodeTest.cpp)
set_target_properties(chainNodeTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "./execu")