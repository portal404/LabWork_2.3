#include "Interface.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

void SetCursorPosition(int x, int y)
{
  COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string InputField(int x, int y, int maxLength)
{
  string input;
  input.reserve(maxLength);
  SetCursorPosition(x, y);
  cout << '[' << string(maxLength, ' ') << ']';

  int cursorPos = 0;
  SetCursorPosition(x + 1 + cursorPos, y);

  while(true)
  {
    int ch = _getch();

    if(ch == 13)
    {
      return input;
    }
    else if(ch == 8)
    {
      if(cursorPos > 0)
      {
        cursorPos--;
        input.pop_back();
        SetCursorPosition(x + 1 + cursorPos, y);
        cout << ' ';
        SetCursorPosition(x + 1 + cursorPos, y);
      }
    }
    else if(isprint(ch) && cursorPos < maxLength)
    {
      input += static_cast<char>(ch);
      cout << static_cast<char>(ch);
      cursorPos++;
    }
  }
}