#ifndef CLASSMANAGEMENT_H
#define CLASSMANAGEMENT_H
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;

class ClassManagement // Create a class called classManagement
{
private:
  // Declaring data members
  int student_index = 0;
  string score;
  vector<string> StudentName, // An array to contain the names of the students
      StudentId,              // An array to contain to students Identification numbers(IDs)
      StudentGrade,     // An array to contain the letter grade of the students(i.e from A to F)
      Student_pass_names,
      Student_pass_ids,
      Student_fail_names,
      Student_fail_ids,
      Student_above_avg_names,
      Student_above_avg_ids,
      Student_below_avg_names,
      Student_below_avg_ids,
      Student_exact_avg_names,
      Student_exact_avg_ids;
  string file_path; // A variable to hold the file name;

  vector<float> StudentTotalScore; // An array to contain the students final scores

  /*
   * ClassAvg is a variable to hold the class average score
   * HighestScore is a variable to hold the highest score in the class
   * LowestScore is a variable to hold the lowest score in the class
   * ClassTotalScore is a variable to hold the sum of the student scores in the class
   * StudentAboveAvg is a variable to hold the number of students who total score is above class average
   * StudentBelowAvg is a variable to hold the number of students who total score is below class average
   * StudentExactAvg is a variable to hold the number of students who total score is the same as the class average
   */
  float ClassAvg, HighestScore, LowestScore, ClassTotalScore = 0;
  int StudentsAboveAvg, StudentsBelowAvg, StudentsExactAvg;

public:
  ClassManagement(); // Default constructor
  // Creating member functions
  // For console cursor control
  HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
  void isEmpty(string&, int, int);
  void placeCursor(HANDLE, int, int);
  void clearError();
  void clearInput();
  void studentInfoForm(HANDLE screen);
  // For files operations functions
  void readFromFile();
  void setFilePath();
  string getFilePath() { return file_path; }


  void getStudentNames();       // A function to take student name from the user.
  void getStudentId();          // A function to take student id from the user.
  void getStudentNumGrade();    // A function to take student total score from the user
  void getStudentLetterGrade(); // A function to convert student total score to a letter grade
  void firstAssign();           // A function to initialize the class total score, highest score and the lowest score the first time the user inputs student informations
  int operator++();             // Is an operator overloading function
  void otherCalculations();     // A function to update the class total score, highest score and the lowest score as the user inputs student informations from the second time going
  void Sorting();               // A function to sort the students by the first letter of their names in alphabetical order
  void TableHeader();           // A function to display the statistical header of the classs information
  void ClassInfo();             // A function to  display the student informations(i.e their names,ids,total score and letter grade)
  void ClassEvaluation();       // A function to display the class summary(i.e average class score,highest score,lowest score, and student who score above,below and exact as class average)
  string line();
  string returnName(){ return StudentName[student_index];} // A function to access the name of the students in the main function
  string returnId(){ return StudentId[student_index];} // A function to access the ids of the students in the main function
  float returnNumGrade() { return StudentTotalScore[student_index];} // A function to access the student total score in the main function
  string returnLetterGrade(){ return StudentGrade[student_index];}// A function to access the student letter grade in the main function
  float returnClassAvg(){  ClassAvg = ClassTotalScore / student_index; return ClassAvg;}// A function to calculate and accesss the class average score in the main function
  float returnHighestScore(){ return HighestScore;}// A function to access the class highest score in the main function
  float returnLowestScore(){ return LowestScore;}// A function to access the classs lowest score in the main function
  int returnAboveAvg(){ return StudentsAboveAvg;}// A function to access the number of students who score above class average
  int returnBelowAvg(){ return StudentsBelowAvg;}// A function to access the number of students who score below class average
  int returnExactAvg()
  { return StudentsExactAvg;}// A function to access the number of students who score exact as the class average
  int getIndex(){return student_index;} // A function to access the value of i in the main function
  void is_alpha(string &);
  void is_alphaNum(string &);
  void is_digit(string &);
  void list(ofstream &, vector<string>, vector<string>, int);
};


#endif