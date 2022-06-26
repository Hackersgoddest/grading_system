#include <iostream>
#include "ClassManagement.h"
using std::cin;
using std::cout;
using std::endl;

int Menu();
void Option_1();
void Option_2();
void Option_3();
void isOptionDigit(string &);

// Declaring global object
ClassManagement stud;
// Declaring a pointer that points to an object of ClassManagement
ClassManagement *student = &stud; 
int main()
{

  int choice;
  // WelcomeMessage();

  do
  {
    choice = Menu();
    if (choice == 1)
      Option_1();
    if (choice == 2)
      Option_2();
  } while (choice != 3);
  Option_3();
  delete student;
  student = nullptr;
  return 0;
}

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

int Menu()
{
  system("cls");
  int num;
  string choice;
  student->placeCursor(screen, 3, 20);
  cout << "----------------------------------\n";
  student->placeCursor(screen, 4, 20);
  cout << "| HACKERSGODDEST GRADDING SYSTEM |\n";
  student->placeCursor(screen, 5, 20);
  cout << "----------------------------------\n";
  student->placeCursor(screen, 6, 20);
  cout << "1. RECORD CLASS INFORMATION TO A FILE" << endl;
  student->placeCursor(screen, 7, 20);
  cout << "2. RETRIEVE CLASS INFORMATION FROM A FILE" << endl;
  student->placeCursor(screen, 8, 20);
  cout << "3. EXIT THE PROGRAM" << endl;
  student->placeCursor(screen, 9, 20);
  cout << "Enter option...";
  do
  {
    student->placeCursor(screen, 9, 35);
    getline(cin, choice);
    while (choice.empty())
    {
      student->placeCursor(screen, 9, 35);
      getline(cin, choice);
    }
    isOptionDigit(choice);
    num = stoi(choice);
    if (num != 1 && num != 2 && num != 3)
      student->placeCursor(screen, 10, 20);
    cout << "You have entered invalid option\n";
    student->placeCursor(screen, 9, 20);
    cout << "Enter option...";
  } while (num != 1 && num != 2 && num != 3);
  system("cls");
  return num;
}

void isOptionDigit(string &score)
{
  bool isInteger = 0;
  while (isInteger)
  {
    isInteger = 1;
    for (int i = 0; i < score.length(); i++)
    {
      if (!isdigit(score[i]) && score[i] != '.' && score[i] != '+' && score[i] != '-') // if score[i] is a number, this condition will evaluate to false else it will evaluate to true.
      {
        isInteger = 0;
        break;
      }
    }
    if(score == "+" || score == "-")
       isInteger = 0;
    if (!isInteger)
    {
      student->placeCursor(screen, 10, 20);
      cout << "You have entered invalid option\n";
      student->placeCursor(screen, 9, 20);
      cout << "Enter option...";
      student->placeCursor(screen, 9, 35);
      getline(cin, score);
      while (score.empty())
      {
        student->placeCursor(screen, 9, 35);
        getline(cin, score);
      }
    }
  }
}

void Option_1()
{
  student->setFilePath();
  student->studentInfoForm(screen);
  student->setStudentName();
  if (student->getStudentName() == "DONE")
    return;
  student->setStudentId();
  student->setStudentTotalScore();
  student->setStudentGrade();
  student->clearInput();
  student->firstAssign();

  ++(*student);
  student->setStudentName();
  while (student->getStudentName() != "DONE")
  {
    student->setStudentId();
    student->setStudentTotalScore();
    student->setStudentGrade();
    student->clearInput();
    student->otherCalculations();
    ++(*student);
    student->setStudentName();
  }
  student->getClassAvg();
  student->Sorting();
  if (student->getIndex() != 0)
  {
    student->TableHeader();
    student->ClassInfo();
    student->ClassEvaluation();
  }
  system("PAUSE");
}

void Option_2()
{
  student->setFilePath();
  student->readFromFile();
  system("PAUSE");
}

void Option_3()
{
  cout << "-------------------------------------------------------\n"
       << "|  THANK YOU FOR USING HACKERSGODDEST GRADING SYSTEM  |\n"
       << "-------------------------------------------------------\n";
  cout << "\nPress any key to EXIT...";
  cin.get();
  exit(0);
}
