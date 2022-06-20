#include "ClassManagement.h"
#include <windows.h>
#include <iostream>  // Help us to use some input output streams like cout, cin, getline, isdigit etc.
#include <iomanip>   // Help us to use various manipulators  like left, setw, setprecision, showpoint etc.
#include <algorithm> // Help us to use the "stod" function.
#include <direct.h>

// Including the functions below from the standard library.
using std::cerr;
using std::cin;
using std::cout;
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
ClassManagement::ClassManagement()
{ // Default constructor definition
    string welcomeMessage = "WELCOME TO HACKERSGODDEST GRADING SYSTEM";
    string symbol, space, mid_space;
    symbol.assign(welcomeMessage.length() + 4, '*');
    space.assign(welcomeMessage.length() + 2, ' ');
    mid_space.assign(welcomeMessage.length() - 20, ' ');

    cout << endl
         << mid_space << symbol << endl
         << mid_space << '*' << space << '*' << endl
         << mid_space << "* " << welcomeMessage << " *" << endl
         << mid_space << '*' << space << '*' << endl
         << mid_space << symbol << endl;
    placeCursor(screen, 8, 20);
    system("PAUSE");
    system("cls");
}
// Functions for console cursor controls

void ClassManagement::isEmpty(string &name, int x, int y)
{
    while (name.empty())
    {
        clearError();
        placeCursor(screen, 14, 25);
        cout << left << setw(100) << "ERROR : Can't be empty(if not move the cursor to the end of the input)\n";
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

void ClassManagement::setStudentName()
{ // Getting student name from the user and storing it in the the student name array variable
    string studentName;
    placeCursor(screen, 5, 43);
    getline(cin, studentName);
    isEmpty(studentName, 5, 43);
    is_alpha(studentName);
    transform(studentName.begin(), studentName.end(), studentName.begin(), ::toupper);
    StudentName.push_back(studentName);
    clearError();
}

void ClassManagement::is_alpha(string &student_name)
{
    bool isAlpha = 0;
    while (!isAlpha)
    {
        isAlpha = 1;
        for (int y = 0; y < student_name.length(); y++)
        {
            if (!(isalpha(student_name[y]) || student_name[y] == ' '))
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
            getline(cin, student_name);
        }
        isEmpty(student_name, 5, 43);
    }
}

void ClassManagement::setStudentId()
{ // Getting student id numbers from the user and storing it in the student id array variable
    bool is_id_already_exist = 1;
    string student_id;
    do
    {
        placeCursor(screen, 7, 43);
        getline(cin, student_id);
        isEmpty(student_id, 7, 43);
        is_alphaNum(student_id);
        transform(student_id.begin(), student_id.end(), student_id.begin(), ::toupper);
        is_id_already_exist = 0;
        if (student_index)
        {
            vector<string>::iterator it;
            it = std::find(StudentId.begin(), StudentId.end(), student_id);
            if (it != StudentId.end())
            {
                clearError();
                placeCursor(screen, 14, 25);
                cout << left << setw(60) << "ERROR : ID already exist\n";
                placeCursor(screen, 7, 43);
                getline(cin, student_id);
                isEmpty(student_id, 7, 43);
                is_id_already_exist = 1;
            }
        }
    } while (is_id_already_exist);
    StudentId.push_back(student_id);

    clearError();
}

void ClassManagement::is_alphaNum(string &student_id)
{
    bool isAlphaNum = 0;
    while (!isAlphaNum || student_id.length() < 5)
    {
        if (student_id.length() < 5)
        {
            clearError();
            placeCursor(screen, 14, 25);
            cout << left << setw(60) << "ERROR : Length ID cannot be less than 5\n";
            placeCursor(screen, 7, 43);
            getline(cin, student_id);
            isEmpty(student_id, 7, 43);
        }
        else
        {
            isAlphaNum = 1;
            for (int t = 0; t < student_id.length(); t++)
            {
                if (!isalnum(student_id[t]))
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
                getline(cin, student_id);
                isEmpty(student_id, 7, 43);
            }
        }
    }
}

void ClassManagement::setStudentTotalScore()
{ // Getting student total score from the user and storing it in the student number grade array variable
    float total_score = 0.0;
    do
    {
        placeCursor(screen, 9, 43);
        getline(cin, score);
        isEmpty(score, 9, 43);
        // Validating user input(thus checking whether the user has enter a number or not)
        is_digit(score);
        total_score = stof(score); // Converting string variable "score" to double with the help of the "stod" function and storing it in student num grade array
        clearError();
        placeCursor(screen, 14, 25);
        if (total_score < 0.0)
            cout << left << setw(60) << "ERROR : Score cannot be less than 0\n";
        if (total_score > 100.000)
            cout << left << setw(60) << "ERROR : Score cannot be greater than 100\n";
    } while (total_score < 0.0 || total_score > 100.00);
    StudentTotalScore.push_back(total_score);
    clearError();
    placeCursor(screen, 9, 43);
    cout << left << setw(40) << ' ';
}

void ClassManagement::is_digit(string &score)
{
    bool is_score_valid_number = 0;
    while (!is_score_valid_number)
    {
        is_score_valid_number = 1;
        int dot_count = 0;
        for (int i = 0; i < score.length(); i++)
        {
            if (!isdigit(score[i]) && score[i] != '.' && score[i] != '+' && score[i] != '-') // if score[i] is a number, this condition will evaluate to false else it will evaluate to true.
            {
                is_score_valid_number = 0;
                break;
            }
            if (score[i] == '.')
                dot_count += 1;

            if (i == 0)
                continue;
            else
            {
                if (score[i] == '+' || score[i] == '-' || dot_count > 1)
                {
                    is_score_valid_number = 0;
                    break;
                }
            }
        }
        if (score == "-" || score == "+")
            is_score_valid_number = 0;
        if (!is_score_valid_number)
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

void ClassManagement::setStudentGrade()
{
    string grade;
    // Using tenary operator to assign the appropriate letter grade to a student based on the student total score
    grade = StudentTotalScore[student_index] >= 90 ? "A" : (StudentTotalScore[student_index] < 90 && StudentTotalScore[student_index] >= 85) ? "A"
                                             : (StudentTotalScore[student_index] < 85 && StudentTotalScore[student_index] >= 80)   ? "A-"
                                             : (StudentTotalScore[student_index] < 80 && StudentTotalScore[student_index] >= 75)   ? "B+"
                                             : (StudentTotalScore[student_index] < 75 && StudentTotalScore[student_index] >= 70)   ? "B"
                                             : (StudentTotalScore[student_index] < 70 && StudentTotalScore[student_index] >= 65)   ? "B-"
                                             : (StudentTotalScore[student_index] < 65 && StudentTotalScore[student_index] >= 60)   ? "C+"
                                             : (StudentTotalScore[student_index] < 60 && StudentTotalScore[student_index] >= 50)   ? "C"
                                             : (StudentTotalScore[student_index] < 50 && StudentTotalScore[student_index] >= 45)   ? "C-"
                                             : (StudentTotalScore[student_index] < 45 && StudentTotalScore[student_index] >= 40)   ? "D"
                                             : (StudentTotalScore[student_index] < 40 && StudentTotalScore[student_index] >= 30)   ? "E"
                                                                                                               : "F";
    StudentGrade.push_back(grade);
}

void ClassManagement::firstAssign()
{
    ClassTotalScore += StudentTotalScore[student_index]; // Incrementing the total class score by the student total/final score
    LowestScore = StudentTotalScore[student_index];      // Assigning the class lowest score the value of the first student total score
    HighestScore = StudentTotalScore[student_index];     // Assigning the class highest score the value of the first student total score
}

int ClassManagement::operator++()
{ // This operator overloading function is just incrementing the value of i;
    return student_index += 1;
}

void ClassManagement::otherCalculations()
{
    ClassTotalScore += StudentTotalScore[student_index];
    if (StudentTotalScore[student_index] < LowestScore)
    {
        LowestScore = StudentTotalScore[student_index]; // Updating the class lowest score if the other student total score is less than the initial student total score
    }
    if (StudentTotalScore[student_index] > HighestScore)
    {
        HighestScore = StudentTotalScore[student_index]; // Updating the class highest score if the other student total score is higher than the initial student total score
    }
}

void ClassManagement::Sorting()
{
    bool is_student_names_sorted = 0;
    while (!is_student_names_sorted)
    {
        is_student_names_sorted = 1;
        int count = 0;
        while (count <= student_index - 2)
        {
            string name_temp, grade_temp;
            string id_temp;
            float score_temp;
            if (StudentName[count] > StudentName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1])
            {
                // Exchanging various information between the two students that needs to be swapped.
                name_temp = StudentName[count],
                id_temp = StudentId[count],
                score_temp = StudentTotalScore[count],
                grade_temp = StudentGrade[count],
                StudentName[count] = StudentName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1],
                StudentId[count] = StudentId[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1],
                StudentTotalScore[count] = StudentTotalScore[static_cast<std::vector<float, std::allocator<float>>::size_type>(count) + 1],
                StudentGrade[count] = StudentGrade[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1],
                StudentName[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1] = name_temp,
                StudentId[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1] = id_temp,
                StudentTotalScore[static_cast<std::vector<float, std::allocator<float>>::size_type>(count) + 1] = score_temp,
                StudentGrade[static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(count) + 1] = grade_temp,
                is_student_names_sorted = 0;
            }
            count++;
        }
    }
}

void ClassManagement::setFilePath()
{
    string folder_path, file_name;
    std::cout << "Enter the full path of the folder(please make sure the path exist).....";
    getline(cin >> ws, folder_path);
    folder_path = folder_path + "/";
    std::cout << "Enter file name....";
    getline(cin >> ws, file_name);
    file_name += ".txt";
    folder_path += file_name;
    file_path = folder_path;
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
    ofstream copyToFile(getFilePath(), ios::app);
    if (copyToFile.fail())
    {
        cerr << "Unable to open file" << endl;
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
    ofstream copyToFile(getFilePath(), ios::app);
    if (copyToFile.fail())
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    else
    {
        for (int index = 0, student_number = 1; index <= student_index - 1; index++, student_number++)
        {
            /// Formatting the table content using the left, setw, fixed, showpoint and setprecision manipulator.
            copyToFile << '|' << left << setw(6) << student_number << left << setw(35) << StudentName[index] << "| " << left << setw(20) << StudentId[index] << "| "
                       << "   " << left << setw(15) << fixed << showpoint << setprecision(2) << StudentTotalScore[index] << "  |   " << left << setw(3) << StudentGrade[index] << " |" << endl
                       << line() << endl;
        }
        copyToFile.close();
    }
}

void ClassManagement::list(ofstream &copyToFile, vector<string> name, vector<string> id, int size)
{
    for (auto count = 0; count < size; count++)
    {
        copyToFile << left << setw(30) << name[count] << '\t' << left << setw(20) << id[count] << endl;
    }
}

void ClassManagement::ClassEvaluation()
{
    ofstream copyToFile(getFilePath(), ios::app);
    if (copyToFile.fail())
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    else
    {
        int above_avg_count = 0, below_avg_count = 0, equal_avg_count = 0;  
        for (int count = 0; count <= student_index - 1; count++) // This for loop help us iterate through all the students total scores enterred by the user hence help us find the appropriate values for a, b and r;
        {
            if (StudentTotalScore[count] > ClassAvg)
            {
                Student_above_avg_names.push_back(StudentName[count]);
                Student_above_avg_ids.push_back(StudentId[count]);
                above_avg_count++;
            }
            if (StudentTotalScore[count] < ClassAvg)
            {
                Student_below_avg_names.push_back(StudentName[count]);
                Student_below_avg_ids.push_back(StudentId[count]);
                below_avg_count++;
            }

            if (StudentTotalScore[count] == ClassAvg)
            {
                Student_exact_avg_names.push_back(StudentName[count]);
                Student_exact_avg_ids.push_back(StudentId[count]);
                equal_avg_count++;
            }

            if (StudentTotalScore[count] >= 50)
            {
                Student_pass_names.push_back(StudentName[count]);
                Student_pass_ids.push_back(StudentId[count]);
            }

            if (StudentTotalScore[count] < 50)
            {
                Student_fail_names.push_back(StudentName[count]);
                Student_fail_ids.push_back(StudentId[count]);
            }
        }
        /// Displaying general information about the class based on previous calculations made.

        copyToFile << "\n\n\n CLASS SUMMARY \n"
                   << "The highest score is:       " << HighestScore << endl
                   << "The Class lowest score is:  " << LowestScore << endl
                   << "The Class average score is: " << fixed << setprecision(2) << ClassAvg << endl
                   << "The number of students who scored above class average:       " << above_avg_count << endl
                   << "The number of students who scored exactly as class average:  " << equal_avg_count << endl
                   << "The number of students who scored below class average:       " << below_avg_count << endl;

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
        cout << "Class information has been written to \" " << getFilePath() << "\" successfully" << endl;
    }
}

// ReadFile class member function definition

void ClassManagement::readFromFile()
{
    ifstream read_file(getFilePath());
    if (read_file.fail())
    {
        // cout << "Error : unable to read from file or the file you have entered does not exist" << endl;
        cerr << "Unable to open file" << endl;
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
