cmake_minimum_required(VERSION 3.8)
project(practice_clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classfile.cpp classfile.h variable.cpp variable.h winmain1.cpp ManManager.cpp ManManager.h stdafx.cpp stdafx.h Sort.h Sort.cpp huffman.h huffman.cpp search.h search.cpp prepostin.cpp BF.cpp KMP.cpp note.cpp chong.cpp StrBlob.h Obeserver.cpp Obeserver.h ConcreteObeserver.cpp ConcreteObeserver.h Subject.cpp Subject.h ConcreteSubject.cpp ConcreteSubject.h Visitor/VisitorIm.cpp Visitor/VisitorIm.h allocTest.h allocTest.cpp)
add_executable(practice_clion ${SOURCE_FILES})