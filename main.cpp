//
//  main.cpp
//  keyWord
//
//  Created by Ricardo on 2016/12/4.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

bool BruteForce(string text, string key){
    unsigned long  lenT = text.size();
    unsigned long lenK = key.size();
    if (lenT < lenK) {
        return false;
    }
    
    for (int s = 0; s <= lenT - lenK; s++) {
        bool bEqual = true;
        int i = 0;
        while (bEqual && (i < lenK)) {
            if (text[s+i] == key[i]) {
                i++;
            }
            else{
                bEqual = false;
            }
        }
        if (bEqual) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    string fileName = "/Users/Ricardo/c/keyWord/keyWord/src.txt";
//    cout << "请输入文件名：";
//    cin >> fileName;
    fstream outFile(fileName);
    cout << "请输入一段英文：";
    string word;
    while (cin >> word) {
        outFile << word << " ";
    }
    outFile.close();
    string keyWord;
    cout << "请输入要检索的关键字：";
    cin >> keyWord;
    int sum = 0;
    
    
    outFile.open(fileName);
    cout << "显示源文件“" <<  fileName << "”" << endl;
    string ch;
    if(!outFile){
        cerr << "open file wrong";
    }
    outFile.seekg(0);
    cout << endl;
    while (outFile >> word) {
        cout << word << " ";
        if(BruteForce(word, keyWord)){
            sum++;
        }
    }
    cout << endl;
    cout << "在源文件中共检索到：" << sum << "个关键字" << keyWord;
    
    return 0;
}
