
#include <iostream>
#include <string>
#include "StringClass.h"
#include "Interface.h"

using namespace std;

int main()
{
  system("chcp 65001 > nul");
  system("cls");

  int posX, posY, fieldLength;

  cout << "Enter PosX up to 25: ";
  cin >> posX;
  cout << "Enter PosY up to 25: ";
  cin >> posY;
  cout << "Enter Field Length: ";
  cin >> fieldLength;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string result = InputField(posX, posY, fieldLength);

  SetCursorPosition(0, posY + 2);
  cout << "Your string: " << result << endl;

  system("pause");
  return 0;
}