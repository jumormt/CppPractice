//
// Created by 76947 on 2018/3/6.
//
#include "huffman.h"
//
//void Huffman::CreateHTree(vector<float> *a, int n) {
//    vector<float> *queue = new vector<float>(*a);
//
//    vector<float> newqueue;
//
////    while(queue->size() > 1){
////        sort(queue->begin(), queue->end());
////        HNode* leftNode = queue[0];
////    }
//
//}


//# -*- coding: utf-8 -*-
//'''
//Created on 2017-03-23
//
//@author: naiive
//'''
//
//
//'''
//This is the Huffman  coding that write by naiive.
//'''
//
//import copy
//import numpy as np
//import math
//
//# This class is the process of the haffman
//class createHuffmanTree():
//def __init__(self, source):
//self.queue = source
//
//
//def haf(self):
//queue = self.queue[:]#复制原来的队列
//
//        newqueue = [] #构造一个存放新队列的列表
//
//#构建哈夫曼树
//while len(queue)>1:
//queue.sort(key=lambda item :item.probability)
//node_left = queue.pop(0)
//node_right = queue.pop(0)
//if node_left.symbol is not None:
//        newqueue.append(node_left)
//if node_right.symbol is not None:
//        newqueue.append(node_right)
//if node_left.probability>node_right.probability:
//        node_left.codeWord = '0'
//node_right.codeWord = '1'
//else:
//node_left.codeWord = '1'
//node_right.codeWord = '0'
//node_fagher = HuffmanObjext( probability = node_left\
//                                              .probability+node_right.probability )
//node_fagher.lChild = node_left
//node_fagher.rChild = node_right
//node_left.father = node_fagher
//node_right.father = node_fagher
//queue.append(node_fagher)
//
//queue[0].father = None
//
//return  newqueue, queue[0]
//# 哈夫曼编码
//def huffmanEncoding(self):
//queue, root = result.haf()
//probability = []
//codes = ['']*len(queue)
//symbol = []
//
//for i in range(len(queue)):
//tmp_node = queue[i]
//while tmp_node.father != None:
//        codes[i] = tmp_node.codeWord + codes[i]
//tmp_node =  tmp_node.father
//
//
//queue[i].codeWord = codes[i]
//symbol.append(queue[i].symbol)
//probability.append(queue[i].probability)
//
//return symbol, codes, probability
//
//
//
//# This is the Objext the Huffman
//
//class HuffmanObjext():
//
//# get the Object of huffman
//def __init__(self, symbol = None, probability = None,\
//                codeWord = '', procode = None ):
//
//self.symbol = symbol
//self.probability = probability
//self.codeWord = codeWord
//self.procode = procode
//self.father = None
//self.lChild = None
//self.rChild = None
//
//if __name__ == '__main__':
//x1 = HuffmanObjext(symbol = "X1", probability = 0.375,\
//                    codeWord = '' )
//x2 = HuffmanObjext(symbol = "X2", probability = 0.125,\
//                    codeWord = '' )
//
//x3 = HuffmanObjext(symbol = "X3", probability = 0.25,\
//                    codeWord = '')
//x4 = HuffmanObjext(symbol = "X4", probability = 0.25,\
//                    codeWord = '')
//x5 = HuffmanObjext(symbol = "X5", probability = 0.125,\
//                    codeWord = '')
//#     x6 = HuffmanObjext(symbol = "X6", probability = 0.1,\
//#                     codeWord = '')
//
//result = createHuffmanTree([ x1,x2, x3, x4, x5])
//# a, b = result.haf()
//symbol, code, probability = result.huffmanEncoding()
//H = []
//K = []
//for item in zip(code, probability):
//print (item[1])
//H_X = item[1] * math.log(item[1],2)
//K_X = item[1] *len(item[0])
//H.append(H_X)
//K.append(K_X)
//
//
//H_X = -np.sum(H)
//K_X = np.sum(K)
//n = H_X /K_X
//
//
//print ("Encoding")
//print (symbol, "\n")
//print (code)
//#     print (info)
//print (H_X)
//print ("average of procode", K_X)
//print ("aberage of n", n)
