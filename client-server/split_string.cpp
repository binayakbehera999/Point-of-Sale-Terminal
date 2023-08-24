#include<stdio.h>
#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

string getProductCode(char *buffer){
    istringstream ss(buffer);
    string code;

    for (int i = 0; i < 2; i++)
    {
        ss >> code;
    }
    
    
    return code;
}

int main(){
    char t[] = "hi hello";
    string temp;

    temp = getProductCode(t);
    cout << temp;
    return 0;
}