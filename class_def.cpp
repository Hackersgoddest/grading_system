#include "ClassManagement.h"
#include <windows.h>
#include <iostream>  // Help us to use some input output streams like cout, cin, getline, isdigit etc.
#include <iomanip>   // Help us to use various manipulators  like left, setw, setprecision, showpoint etc.
#include <algorithm> // Help us to use the "stod" function.
#include <direct.h>
//#include <bits/stdc++.h> // Help us to use the "stod" function.

using std::cerr;
using std::cin;
using std::cout; // Help us to use function from standard library like cout, cin, transform etc.
using std::endl;
using std::fixed;
using std::ios;
using std::left;
using std::setprecision;
using std::setw;
using std::showpoint;
using std::transform;
using std::ws;

// ClassManagement class member functions definitions

// Functions for console cursor controls

void ClassManagement::isEmpty(string &name, int x, int y)
{
  while(name.empty())
    {
      clearError();
      placeCursor(screen, 14, 25);
      cout<<left<<setw(100) << "ERROR : Can't be empty(if not move the cursor to the end of the input)\n";
      placeCursor(screen, x, y);
      getline(cin, name);
    }
    clearError();
}

void ClassManagement::clearError()
{
  placeCursor(screen, 14, 25);
  cout << left << setw(100) << ' ' << endl;
}

void ClassManagement::clearInput()
{
  placeCursor(screen, 5, 43);
  cout << left << setw(30) << " " << endl;
  placeCursor(screen, 7, 43);
  cout << left << setw(20) << " " << endl;
  placeCursor(screen, 9, 43);
  cout << left << setw(4) << " " << endl;
}

void ClassManagement::placeCursor(HANDLE screen, int row, int col)
{
  COORD position;
  position.Y = row;
  position.X = col;
  SetConsoleCursorPosition(screen, position);
}

void ClassManagement::studentInfoForm(HANDLE screen)
{
  system("cls");
  placeCursor(screen, 3, 25);
  cout << left << setw(60) << "***************** STUDENT INFORMATION ENTRY FORM *****************" << endl;
  placeCursor(screen, 4, 25);
  cout << left << setw(60) << "*                                                                *" << endl;
  placeCursor(screen, 5, 25);
  cout << left << setw(60) << "*  STUDENT NAME :                                                *" << endl;
  placeCursor(screen, 6, 25);
  cout << left << setw(60) << "*                                                                *" << endl;
  placeCursor(screen, 7, 25);
  cout << left << setw(60) << "*  STUDENT ID   :                                                *" << endl;
  placeCursor(screen, 8, 25);
  cout << left << setw(60) << "*                                                                *" << endl;
  placeCursor(screen, 9, 25);
  cout << left << setw(60) << "*  TOTAL SCORE  :                                                *" << endl;
  placeCursor(screen, 10, 25);
  cout << left << setw(60) << "*                                                                *" << endl;
  placeCursor(screen, 11, 25);
  cout << left << setw(60) << "*                                 NB: ENTER DONE AS NAME TO EXIT *" << endl;
  placeCursor(screen, 12, 25);
  cout << left << setw(60) << "******************************************************************" << endl;
}

void ClassManagement::getStudentNames()
{ // Getting student name from the user and storing it in the the student name array variable
  string name;
  placeCursor(screen, 5, 43);
  getline(cin, name);
  isEmpty(name, 5, 43);
  is_alpha(name);
  transform(name.begin(), name.end(), name.begin(), ::toupper);
  StudentName.push_back(name);
  clearError();
}

void ClassManagement::is_alpha(string &nm)
{
  bool isAlpha = 0;
  while (!isAlpha)
  {
    isAlpha = 1;
    for (int y = 0; y < nm.length(); y++)
    {
      if (!(isalpha(nm[y]) || nm[y] == ' '))
      {
        isAlpha = 0;
        break;
      }
    }
    if (!isAlpha)
    {
      clearError();
      placeCursor(screen, 14, 25);
      cout << left << setw(40) << "ERROR : Name can only contains alphabets\n";
      placeCursor(screen, 5, 43);
      getline(cin, nm);
    }
    isEmpty(nm, 5, 43);
  }
}

void ClassManagement::getStudentId()
{ // Getting student id numbers from the user and storing it in the student id array variable
  bool isTaken = 1;
  string id;
  do
  {
    placeCursor(screen, 7, 43);
    getline(cin, id);
    isEmpty(id, 7, 43);
    is_alphaNum(id);
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    isTaken = 0;
    if (index)
    {
      vector<string>::iterator it;
      it = std::find(StudentId.begin(), StudentId.end(), id);
      if (it != StudentId.end())
      { 
        clearError();
        placeCursor(screen, 14, 25);
        cout << left << setw(60) << "ERROR : ID already exist\n";
        placeCursor(screen, 7, 43);
        getline(cin, id);
        isEmpty(id, 7, 43);
        isTaken = 1;
      }
    }
  } while (isTaken);
  StudentId.push_back(id);

  clearError();
}

void ClassManagement::is_alphaNum(string &id)
{
  bool isAlphaNum = 0;
  while (!isAlphaNum || id.length() < 5)
  {
    if (id.length() < 5)
    {
      clearError();
      placeCursor(screen, 14, 25);
      cout << left << setw(60) << "ERROR : Length ID cannot be less than 5\n";
      placeCursor(screen, 7, 43);
      getline(cin, id);
      isEmpty(id, 7, 43);
    }
    else
    {
      isAlphaNum = 1;
      for (int t = 0; t < id.length(); t++)
      {
        if (!isalnum(id[t]))
        {
          isAlphaNum = 0;
          break;
        }
      }
      if (!isAlphaNum)
      {
        clearError();
        placeCursor(screen, 14, 25);
        cout << left << setw(60) << "ERROR : ID can only contains alphanumeric characters\n";
        placeCursor(screen, 7, 43);
        getline(cin, id);
        isEmpty(id, 7, 43);
      }
    }
  }
}

void ClassManagement::getStudentNumGrade()
{ // Getting student total score from the user and storing it in the student number grade array variable
  double num;
  do
  {
    placeCursor(screen, 9, 43);
    getline(cin, score);
    isEmpty(score, 9, 43);
    // Validating user input(thus checking whether the user has enter a number or not)
    is_digit(score);
    num = stod(score); // Converting string variable "score" to double with the help of the "stod" function and storing it in student num grade array
    clearError();   
    placeCursor(screen, 14, 25);
    if (num < 0.0)
      cout << left << setw(60) << "ERROR : Score cannot be less than 0\n";
    if (num > 100.000)
      cout << left << setw(60) << "ERROR : Score cannot be greater than 100\n";
  } while (num < 0.0 || num > 100.00);
  StudentNumGrade.push_back(num);
  clearError();
}

void ClassManagement::is_digit(string &score)
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
      clearError();
      placeCursor(screen, 14, 25);
      cout << left << setw(60) << "ERROR : Invalid score\n";
      placeCursor(screen, 9, 43);
      getline(cin, score);
      isEmpty(score, 9, 43);
    }
  }
}

void ClassManagement::getStudentLetterGrade()
{
  string grade;
  // Using tenary operator to assign the appropriate letter grade to a student based on the student total score
  grade = StudentNumGrade[index] >= 90 ? "A" : (StudentNumGrade[index] < 90 && StudentNumGrade[index] >= 85) ? "A"
                                           : (StudentNumGrade[index] < 85 && StudentNumGrade[index] >= 80)   ? "A-"
                                           : (StudentNumGrade[index] < 80 && StudentNumGrade[index] >= 75)   ? "B+"
                                           : (StudentNumGrade[index] < 75 && StudentNumGrade[index] >= 70)   ? "B"
                                           : (StudentNumGrade[index] < 70 && StudentNumGrade[index] >= 65)   ? "B-"
                                           : (StudentNumGrade[index] < 65 && StudentNumGrade[index] >= 60)   ? "C+"
                                           : (StudentNumGrade[index] < 60 && StudentNumGrade[index] >= 50)   ? "C"
                                           : (StudentNumGrade[index] < 50 && StudentNumGrade[index] >= 45)   ? "C-"
                                           : (StudentNumGrade[index] < 45 && StudentNumGrade[index] >= 40)   ? "D"
                                           : (StudentNumGrade[index] < 40 && StudentNumGrade[index] >= 30)   ? "E"
                                                                                                             : "F";
  StudentLetterGrade.push_back(grade);
}

void ClassManagement::firstAssign()
{
  ClassTotalScore += StudentNumGrade[index]; // Incrementing the total class score by the student total/final score
  LowestScore = StudentNumGrade[index];      // Assigning the class lowest score the value of the first student total score
  HighestScore = StudentNumGrade[index];     // Assigning the class highest score the value of the first student total score
}

int ClassManagement::operator++()
{ // This operator overloading function is just incrementing the value of i;
  return index += 1;
}

void ClassManagement::otherCalculations()
{
  ClassTotalScore += StudentNumGrade[index];
  if (StudentNumGrade[index] < LowestScore)
  {
    LowestScore = StudentNumGrade[index]; // Updating the class lowest score if the other student total score is less than the initial student total score
  }
  if (StudentNumGrade[index] > HighestScore)
  {
    HighestScore = StudentNumGrade[index]; // Updating the class highest score if the other student total score is higher than the initial student total score
  }
}

void ClassManagement::Sorting()
{ // Using bubble sort technique
  // bool flag = 1;    // Setting flag to 1 means swap between two students have occurred
  // while (flag == 1) // The statements inside this block will continue to executes whiles swap occurs between two student hence will terminate after the names of the students has been sorted in that order.
  // {
  //   flag = 0; // Intentionally initializing flag to zero to check whether the names of the students have been sorted
  bool flag = 1;
  while (flag == 1)
  {
    flag = 0;
    int x = 0;
    while (x <= index - 2)
    {
      string fTemp, lGrade;
      string iTemp;
      double nGrade;
      if (StudentName[x] > StudentName[x + 1])
      {
        // Exchanging various information between the two students that needs to be swapped.
        fTemp = StudentName[x],
        iTemp = StudentId[x],
        nGrade = StudentNumGrade[x],
        lGrade = StudentLetterGrade[x],
        StudentName[x] = StudentName[x + 1],
        StudentId[x] = StudentId[x + 1],
        StudentNumGrade[x] = StudentNumGrade[x + 1],
        StudentLetterGrade[x] = StudentLetterGrade[x + 1],
        StudentName[x + 1] = fTemp,
        StudentId[x + 1] = iTemp,
        StudentNumGrade[x + 1] = nGrade,
        StudentLetterGrade[x + 1] = lGrade,
        flag = 1;
      }
      x++;
    }
  }
}

void ClassManagement::setFileName()
{
  string folder_name, f_name;
  std::cout << "Enter the full path of the folder(please make sure the path exist).....";
  getline(cin >> ws, folder_name);
  folder_name = folder_name + "/";
  std::cout << "Enter file name....";
  getline(cin >> ws, f_name);
  f_name += ".txt";
  folder_name += f_name;
  file_name = folder_name;
}

// WriteToFile class member function definitions

string ClassManagement::line()
{
  string lines;
  return lines.assign(95, '-');
}

void ClassManagement::TableHeader()
{
  string nm;
  ofstream copyToFile(getFileName(), ios::app);
  if (copyToFile.fail())
  {
    cerr << strerror(errno) << endl;
    return;
  }
  else
  {
    copyToFile << line() << endl
               << "|    " << left << setw(88) << "                               HACKERSGODDEST GRADING SYSTEM"
               << " |" << endl
               << line() << endl
               // Updating the arrangement of the table header using the left and setw manipulator.
               << "|      " << left << setw(35) << "Student Names"
               << "| " << left << setw(20) << "Students IDs"
               << "| " << left << setw(20) << "Total Score"
               << "| " << left << setw(5) << "Grade"
               << " |" << endl
               << line() << endl;
    copyToFile.close();
  }
}

void ClassManagement::ClassInfo()
{
  ofstream copyToFile(getFileName(), ios::app);
  if (copyToFile.fail())
  {
    cerr << strerror(errno) << endl;
    return;
  }
  else
  {
    for (int x = 0, g = 1; x <= index - 1; x++, g++)
    {
      /// Formatting the table content using the left, setw, fixed, showpoint and setprecision manipulator.
      copyToFile << '|' << left << setw(6) << g << left << setw(35) << StudentName[x] << "| " << left << setw(20) << StudentId[x] << "| "
                 << "   " << left << setw(15) << fixed << showpoint << setprecision(2) << StudentNumGrade[x] << "  |   " << left << setw(3) << StudentLetterGrade[x] << " |" << endl
                 << line() << endl;
    }
    copyToFile.close();
  }
}

void ClassManagement::list(ofstream &copyToFile, vector<string> name, vector<string> id, int size)
{
  for (auto x = 0; x < size; x++)
  {
    copyToFile <<left<<setw(30)<< name[x] << '\t' <<left<<setw(20)<< id[x] << endl;
  }
}

void ClassManagement::ClassEvaluation()
{
  ofstream copyToFile(getFileName(), ios::app);
  if (copyToFile.fail())
  {
    cerr << strerror(errno) << endl;
    return;
  }
  else
  {
    int a = 0, b = 0, r = 0;             // Declaring and initializing a, b and r to 0 helps us find the number of students who above,below and exact as class average score respectively
    for (int x = 0; x <= index - 1; x++) // This for loop help us iterate through all the students total scores enterred by the user hence help us find the appropriate values for a, b and r;
    {
      if (StudentNumGrade[x] > ClassAvg)
      {
        Student_above_avg_names.push_back(StudentName[x]);
        Student_above_avg_ids.push_back(StudentId[x]);
        a++;
      }
      if (StudentNumGrade[x] < ClassAvg)
      {
        Student_below_avg_names.push_back(StudentName[x]);
        Student_below_avg_ids.push_back(StudentId[x]);
        b++;
      }

      if (StudentNumGrade[x] == ClassAvg)
      {
        Student_exact_avg_names.push_back(StudentName[x]);
        Student_exact_avg_ids.push_back(StudentId[x]);
        r++;
      }

      if (StudentNumGrade[x] >= 50)
      {
        Student_pass_names.push_back(StudentName[x]);
        Student_pass_ids.push_back(StudentId[x]);
      }

      if (StudentNumGrade[x] < 50)
      {
        Student_fail_names.push_back(StudentName[x]);
        Student_fail_ids.push_back(StudentId[x]);
      }
    }
    /// Displaying general information about the class based on previous calculations made.

    copyToFile << "\n\n\n CLASS SUMMARY \n"
               << "The highest score is:       " << HighestScore << endl
               << "The Class lowest score is:  " << LowestScore << endl
               << "The Class average score is: " << ClassAvg << endl
               << "The number of students who scored above class average:       " << a << endl
               << "The number of students who scored exactly as class average:  " << r << endl
               << "The number of students who scored below class average:       " << b << endl;

    if (!Student_above_avg_names.empty())
    {
      copyToFile << "\n\nNAMES AND IDs OF STUDENTS WHO SCORE ABOVE CLASS AVERAGE SCORE\n"
                 << "-------------------------------------------------------------\n";
      list(copyToFile, Student_above_avg_names, Student_above_avg_ids, Student_above_avg_names.size());
    }

    if (!Student_exact_avg_names.empty())
    {
      copyToFile << "\n\nNAMES AND IDs OF STUDENTS WHO SCORE EXACTLY AS CLASS AVERAGE SCORE\n"
                 << "------------------------------------------------------------------\n";
      list(copyToFile, Student_exact_avg_names, Student_exact_avg_ids, Student_exact_avg_names.size());
    }

    if (!Student_below_avg_names.empty())
    {
      copyToFile << "\n\nNAMES AND IDs OF STUDENTS WHO SCORE BELOW CLASS AVERAGE SCORE\n"
                 << "-------------------------------------------------------------\n";
      list(copyToFile, Student_below_avg_names, Student_below_avg_ids, Student_below_avg_names.size());
    }

    if (!Student_pass_names.empty())
    {
      copyToFile << "\n\nNAMES AND IDs OF STUDENTS WHO PASS THE EXAMS\n"
                 << "--------------------------------------------\n";
      list(copyToFile, Student_pass_names, Student_pass_ids, Student_pass_names.size());
    }
    if (!Student_fail_names.empty())
    {
      copyToFile << "\nNAMES AND IDs OF STUDENTS WHO FAIL THE EXAMS\n"
                 << "--------------------------------------------\n";
      list(copyToFile, Student_fail_names, Student_fail_ids, Student_fail_names.size());
    }
    copyToFile << "\n\n@HACKERSGODDEST" << endl;
    copyToFile.close();
    cout << "Class information has been written to \" " << getFileName() << "\" successfully" << endl;
  }
}

// ReadFile class member function definition

void ClassManagement::readFromFile()
{
  ifstream read_file(getFileName());
  if (read_file.fail())
  {
    // cout << "Error : unable to read from file or the file you have entered does not exist" << endl;
    cerr << strerror(errno) << endl;
    return;
  }
  else
  {
    string statement;
    while (getline(read_file, statement))
      cout << statement << endl;
    read_file.close();
  }
}
