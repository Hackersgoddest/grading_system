#include <iostream>
#include "ClassManagement.h"
using std::cin;
using std::cout;
using std::endl;
// Declaring function prototype
void WelcomeMessage();
int Menu();
void Option_1();
void Option_2();
void Option_3();
void isOptionDigit(string&);

// Declaring global object
ClassManagement student;
int main()
{

  int choice;
  WelcomeMessage();

  do
  {
    choice = Menu();
    if (choice == 1)
      Option_1();
    if (choice == 2)
      Option_2();
  } while (choice != 3);
  Option_3();

  system("PAUSE");

  return 0;
}

// Defining functions prototypes

void WelcomeMessage()
{ // Printing a welcoming message.

  string welcomeMessage = "WELCOME TO HACKERSGODDEST GRADING SYSTEM";
  string len, non, bef;
  len.assign(welcomeMessage.length() + 4, '*');
  non.assign(welcomeMessage.length() + 2, ' ');
  bef.assign(welcomeMessage.length() - 20, ' ');

  cout << bef << len << endl
       << bef << '*' << non << '*' << endl
       << bef << "* " << welcomeMessage << " *" << endl
       << bef << '*' << non << '*' << endl
       << bef << len << endl
       << "                     A PROGRAM TO RECORD CLASS INFORMATION\n"
       << "       THAT'S NAMES OF STUDENTS AND THEIR CORRESPONDING IDs, SCORES AND GRADES  \n";
  system("PAUSE");
  system("cls");
}
HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

int Menu()
{
  system("cls");
  int num;
  string choice;
  cout << "\n  ----------------------------------"
       << "\n  | HACKERSGODDEST GRADDING SYSTEM |\n"
       << "  ----------------------------------\n"
       << "1. RECORD CLASS INFORMATION TO A FILE" << endl
       << "2. RETRIEVE CLASS INFORMATION FROM A FILE" << endl
       << "3. EXIT THE PROGRAM" << endl
       << "Enter option....";
  do
  {
    cin >> choice;
    isOptionDigit(choice);
    num = stoi(choice);
    if (num != 1 && num != 2 && num != 3)
      cout << "You have entered invalid option\nEnter option again....";
  } while (num != 1 && num != 2 && num != 3);
  return num;
}

void isOptionDigit(string &score)
{
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < score.length(); i++)
        {
            if (!isdigit(score[i]) && score[i] != '.' && score[i] != '+' && score[i] != '-') // if score[i] is a number, this condition will evaluate to false else it will evaluate to true.
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout<< "ERROR : Invalid Option\nEnter option again... ";
            getline(cin >> std::ws, score);
        }
    }
}

void Option_1()
{
  student.setFileName();
  student.studentInfoForm(screen);
  student.getStudentNames();
  if (student.returnName() == "DONE")
    return;
  student.getStudentId();
  student.getStudentNumGrade();
  student.getStudentLetterGrade();
  student.clearInput();
  student.firstAssign();

  ++student;
  student.getStudentNames();
  while (student.returnName() != "DONE")
  {
    student.getStudentId();
    student.getStudentNumGrade();
    student.getStudentLetterGrade();
    student.clearInput();
    student.otherCalculations();
    ++student;
    student.getStudentNames();
  }
  student.returnClassAvg();
  student.Sorting();
  if (student.getIndex() != 0)
  {
    student.TableHeader();
    student.ClassInfo();
    student.ClassEvaluation();
  }
  system("PAUSE");
}

void Option_2()
{
  student.setFileName();
  student.readFromFile();
  system("PAUSE");
}

void Option_3()
{
  cout << "-------------------------------------------------------\n"
       << "|  THANK YOU FOR USING HACKERSGODDEST GRADING SYSTEM  |\n"
       << "-------------------------------------------------------\n";
  cin.get();
  cout<<"\nPress any key to EXIT...";
  cin.get();
  exit(0);
}
