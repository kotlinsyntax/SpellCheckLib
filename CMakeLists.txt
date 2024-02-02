cmake_minimum_required(VERSION 3.27)
project(SpellCheckLib)

set(CMAKE_CXX_STANDARD 17)

add_library(SpellCheckLib STATIC src/spellchk.cpp src/wordlist.h src/spellchk.h)