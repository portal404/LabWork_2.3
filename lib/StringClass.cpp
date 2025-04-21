#include <iostream>
#include "StringClass.h"
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

TString::TString()
{
  len = 1;
  str = new char[1] {'\0'};
}

TString::TString(const TString& p): len(p.len), str(new char[p.len + 1])
{
  copy(p.str, p.str + len + 1, str);
}

TString::TString(TString&& p): len(p.len), str(p.str)
{
  p.str = nullptr;
  p.len = 0;
}

TString::TString(char* str_, int len_): len(len_)
{
  if (len_ <= 0) throw invalid_argument("Length cannot be less than 1");
  str = new char[len + 1];
  copy(str_, str_+len, str);
  str[len] = '\0';
}

TString::TString(const char* str_)
{
  if (!str_) throw invalid_argument("Pointer Null=");
  len = strlen(str_);
  str = new char[len + 1];
  copy(str_, str_ + len + 1, str);
}

TString::~TString()
{
  if (str != nullptr)
    delete[] str;
  str = nullptr;
}

const char* TString::GetStr() const
{
  return str;
}

int TString::GetLen() const
{
  return len;
}

void TString::SetStr(const char* str_)
{
  int len_ = strlen(str_);
  char* new_str = new char[len_+1];
  strcpy(new_str, str_);
  delete[] str;
  str = new_str;
  len = len_;
}

void TString::SetLen(int len_) {
  if (len_ < 0) len_ = 0;
  if (len_ == len) return;
  char* new_str = new char[len_ + 1];
  int copy_len = (len_ > len) ? len : len_;

  if (str != nullptr)
  {
    strncpy(new_str, str, copy_len); // Копирование  содержимого нуль-терминированной строки в буфер ограниченного размера.
    new_str[copy_len] = '\0';
  }
  else
  {
    new_str[0] = '\0';
  }

  delete[] str;
  str = new_str;
  len = len_;
}

int TString::Find(const TString& substring) const
{
  const char* main_str = GetStr();
  const char* sub_str = substring.GetStr();
  int main_len = GetLen();
  int sub_len = substring.GetLen();

  if (sub_len == 0) return 0;
  if (main_len < sub_len) return -1;

  for (int i = 0; i <= main_len - sub_len; ++i) {
    bool found = true;
    for (int j = 0; j < sub_len; ++j) {
      if (main_str[i + j] != sub_str[j]) {
        found = false;
        break;
      }
    }
    if (found) return i;
  }
  return -1;
}


TString TString::Substring(size_t start, size_t count) const
{
  if (start >= len) throw out_of_range("Start >= len");

  size_t actual_count = min(count, len - start);
  TString res;
  res.len = actual_count;
  res.str = new char[actual_count + 1];

  copy(str + start, str + start + actual_count, res.str);
  res.str[actual_count] = '\0';

  return res;
}

TString TString::operator+ (const TString& p) const
{
  TString res;
  res.len = this->len + p.len;
  res.str = new char[res.len+1];

  if (this->str) copy(this->str, this->str + this->len, res.str);
  if (p.str) copy(p.str, p.str + p.len + 1, res.str + this->len);

  return res;
}


TString TString::operator* (int n) const
{
  if (n <= 0)
  {
    return TString();
  }

  TString res;
  res.len = len * n;
  res.str = new char[res.len + 1];

  for (int i = 0; i < n; ++i) {
    copy(str, str + len, res.str + i * len);
  }

  res.str[res.len] = '\0';
  return res;
}


TString& TString::operator=(const TString& p)
{
  if (this != &p)
  {
    delete[] str;
    len = p.len;
    str = new char[len + 1];
    copy(p.str, p.str + len + 1, str);
  }
  return *this;
}

bool TString::operator==(const TString& p) const
{
  if (len != p.len) return false;
  return equal(str, str + len, p.str);
}

char& TString::operator[](size_t i)
{
  if (i >= len) throw out_of_range("Index out of range");
  return str[i];
}

const char& TString::operator[](size_t i) const
{
  if (i >= len) throw out_of_range("Index out of range");
  return str[i];
}

ostream& operator<<(std::ostream& os, const TString& str)
{
  os << str.GetStr();
  return os;
}

istream& operator>>(std::istream& is, TString& str)
{
  char buffer[1024];
  if (is >> buffer)
  {
    str.SetStr(buffer);
  }
  return is;
}

