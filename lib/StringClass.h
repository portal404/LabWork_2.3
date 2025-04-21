#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class TString
{
protected:
    char* str;
    int len;
public:
    TString();
    TString(const TString& p);
    TString(TString&& p);
    TString(char* str_, int len_);
    TString(const char* str_);
    ~TString();

    const char* GetStr() const;
    int GetLen() const;

    void SetStr(const char* str_);
    void SetLen(int len_);

    int Find(const TString& substring) const;

    TString Substring(size_t start, size_t count = -1) const;

    TString operator+ (const TString& other) const;
    TString operator* (int count) const;
    TString& operator= (const TString& p);

    bool operator== (const TString& p) const;

    char& operator[] (size_t i);
    const char& operator[] (size_t i) const;


    friend ostream& operator<<(std::ostream& os, const TString& str);
    friend istream& operator>>(std::istream& is, TString& str);
};