cmake_minimum_required(VERSION 3.17)
project(Heap C)

set(CMAKE_C_STANDARD 11)

add_executable(Heap main.c MaxHeap.h MaxHeap.c LeftistHeap.c LeftistHeap.h)