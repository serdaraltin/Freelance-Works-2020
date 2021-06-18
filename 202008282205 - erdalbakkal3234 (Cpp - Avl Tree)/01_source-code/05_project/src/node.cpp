/**
* @file node.cpp
* @description node.hpp içerisinde bulunan sınıfların methodlarının gövdeleri
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 2020.08.28
* @author Emre Uysal
*/
#include <iostream> 
#include <stack> 
#include "node.hpp"

using namespace std;

Node::Node(){
    hei = 0;
    l = NULL;
    r = NULL;
}