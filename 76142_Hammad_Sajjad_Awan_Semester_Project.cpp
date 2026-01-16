#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const int Total_marks=600;
const int Total_classes=30;
const int Maximum_Subjects=6;
struct Student
{
    string name;
    int roll,age,marks,attended_classes,semester,subject_count;
    string subjects[Maximum_Subjects];
    float CGPA;
};

string correct_username = "Hammad Sajjad Awan";
string correct_password = "Hammad@89372";
 
bool admin_login()
{
    string username,password;
    int attempts=0;
    while(attempts<3)
    {
    cout<<"========================================================="<<endl;
    cout<<"                      ADMIN LOGIN PORTAL                 "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"Admin Name: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Admin Password: ";
    cin>>password;
    if(username==correct_username && password==correct_password)
    {
        cout<<"Admin Login successfull! Welcome "<<username<<endl;
        return true;
    }
    else
    {
        attempts++;
        if(attempts<3)
        {
            cout<<"Login Faild! You have just "<<3-attempts<< " attempts left"<<endl;
        }
        else
        {
            cout << "You have used all 3 attempts: "<<endl;
        }
    }
}
    return false;
  
}
float attendence_percentage(Student s)
{
    if(Total_classes==0)
    {
        return 0;
    }
    else 
    {
        return (float)s.attended_classes/Total_classes*100;
    }
}
float marks_percentage(Student s)
{
    if(Total_marks==0)
    {
        return 0;
    }
    else
    {
        return (float)s.marks/Total_marks*100;
    }
}
float calculate_gpa(Student s)
{
    float percentage = marks_percentage(s);
    if (percentage >= 90) return 4.0;
    else if (percentage >= 80) return 3.5;
    else if (percentage >= 70) return 3.0;
    else if (percentage >= 60) return 2.5;
    else if (percentage >= 50) return 2.0;
    else return 0.0;
}
void print_students_table(Student s)
{
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"========================================Student Record====================================="<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"Name: "<<s.name<<endl;
    cout<<"Roll No: "<<s.roll<<endl;
    cout<<"Age: "<<s.age<<endl;
    cout<<"Semester: "<<s.semester<<endl;
    cout<<"Marks: "<<s.marks<<"/"<<Total_marks<<endl;
    cout<<"Marks Percentage: "<<fixed<<setprecision(2)<<marks_percentage(s)<<"%"<<endl;
    cout<<"Attend Classes: "<<s.attended_classes<<"/"<<Total_classes<<endl;
    cout<<"Attendence Percentage: "<<fixed<<setprecision(2)<<attendence_percentage(s)<<"%"<<endl;
    cout<<"GPA: "<<fixed<<setprecision(2)<<s.CGPA<<endl;
    cout<<"==============Enrolled Subjects==============="<<endl;
    for(int i=0;i<s.subject_count;i++)
    {
        cout<<i+1<<":"<<s.subjects[i]<<endl;
    }
}
int index( Student students[],int total,int roll_number)
{
    for(int i=0;i<total;i++)
    {
        if(students[i].roll==roll_number)
        {
            return i;
        }
    }
     return -1;
}

void add_students(Student students[],int &total)
{
    if(!admin_login()) 
    {
      return; 
    }
    else
    {
    cout<<"Enter the name of a student: ";
    cin.ignore();
    getline(cin,students[total].name);
    cout<<"Enter the roll number of a student: ";
    cin>>students[total].roll;
    cout<<"Enter the age of a student: ";
    cin>>students[total].age;
    cout<<"Enter the semester of a student: ";
    cin>>students[total].semester;
    do
    {
    cout<<"Enter the number of subjects in which the student is enrolled: (1-"<<Maximum_Subjects<<"): ";
    cin>>students[total].subject_count;
    if(students[total].subject_count <= 0 || students[total].subject_count > Maximum_Subjects)
    {
         cout << "Invalid input! Please enter a number between 1 and " << Maximum_Subjects << "." << endl;
    }
    } while(students[total].subject_count <= 0 || students[total].subject_count > Maximum_Subjects);
    }
    cin.ignore();
    for(int i=0;i<students[total].subject_count;i++)
    {
        cout<<"Enter Subject "<<i+1<<":";
        getline(cin,students[total].subjects[i]);
    }
    do
    {
    cout<<"Enter the total marks of a student:(0- "<<Total_marks<<"): ";
    cin>>students[total].marks;
    if(students[total].marks<0 || students[total].marks>Total_marks)
    {
        cout<<"Invalid marks! Please Enter the valid marks.";
    }
    }while(students[total].marks<0 || students[total].marks>Total_marks);
    do
    {
    cout<<"Enter the attended classes of a student:(0- "<<Total_classes<<"): ";
    cin>>students[total].attended_classes;
    if(students[total].attended_classes<0 || students[total].attended_classes>Total_classes)
    {
        cout<<"Invalid attendence! Please Enter the valid attendence.";
    }
    }while(students[total].attended_classes<0 || students[total].attended_classes>Total_classes);
    students[total].CGPA = calculate_gpa(students[total]);
    total++;
    cout<<"Student added successsfully: "<<endl;
}
void view_students(Student students[],int total)
{
    if(!admin_login()) 
    {
        return;
    }
    else
    {    
    int r;
    cout<<"Enter the roll number of a student: ";
    cin>>r;
    int d=index(students,total,r);
    if(d==-1)
    {
        cout<<"Record not found: "<<endl;
    }
    else
    {
        print_students_table(students[d]);
    }
}
}
void search_students(Student students[], int total)
{
     if(!admin_login())
     {
        return;
     }
     else
     {
        int a; 
        cout<<"Enter the roll number: ";
        cin>>a; 
        int c=index(students,total,a); 
        if(c==-1) 
        {
            cout<<"Record not found: "<<endl; 
        } 
        else
        {
            print_students_table(students[c]);
    }   
        }
}
void update_student(Student students[],int total)
{
     if(!admin_login())
     {
        return;
     }
     else
     {
    int r;
    cout<<"Enter the roll number: ";
    cin>>r;
    int ind=index(students,total,r);
    if(ind==-1)
    {
        cout<<"Record not found: "<<endl;
        return;
    }
    else
    {
        cout<<"Record found: "<<endl;
        cin.ignore();
        cout<<"Enter the new name of a student: ";
        getline(cin,students[ind].name);
        cout<<"Enter the new roll number of a student: ";
        cin>>students[ind].roll;
        cout<<"Enter the new age of a student: ";
        cin>>students[ind].age;
         cout<<"Enter the semester of a student: ";
    cin>>students[ind].semester;
    cout<<"Enter the number of subjects in which the student is enrolled: ";
    cin>>students[ind].subject_count;
    cin.ignore();
    for(int j=0;j<students[ind].subject_count;j++)
        {
            cout<<"Enter Subject "<<j+1<<":";
            getline(cin,students[ind].subjects[j]);
        }
    do
    {
       cout<<"Enter the total marks of a new student:(0- "<<Total_marks<<"): ";
       cin>>students[ind].marks;
       if(students[ind].marks<0 || students[ind].marks>Total_marks)
        {
          cout<<"Invalid marks! Please Enter the valid marks.";
        }
    }while(students[ind].marks<0 || students[ind].marks>Total_marks);
    do
    {
       cout<<"Enter the attended classes of a new student:(0- "<<Total_classes<<"): ";
       cin>>students[ind].attended_classes;
       if(students[ind].attended_classes<0 || students[ind].attended_classes>Total_classes)
        {
           cout<<"Invalid attendence! Please Enter the valid attendence.";
        }
    }while(students[ind].attended_classes<0 || students[ind].attended_classes>Total_classes);
    students[ind].CGPA = calculate_gpa(students[ind]);
    }
}
}
void delete_student(Student students[],int &total)
{
     if(!admin_login())
     {
        return;
     }
     else
     {
    int r;
    cout<<"Enter the roll number of student: ";
    cin>>r;
    int ind=index(students,total,r);
    if(ind==-1)
    {
        cout<<"Record not found: "<<endl;
    }
    else
    {
        cout<<"Record found: "<<endl;
        for(int i=ind;i<total-1;i++)
        {
            students[i]=students[i+1];
        }
           total--;
          cout<<"Record deleted successfully: "<<endl;
    } 
}
}
int main()
{
    Student students[1000];
    int total=0;

    int choice;
    do
    {
       cout<<"==========================================================================================="<<endl;
       cout<<"                               Students Record management System                           "<<endl;
       cout<<"==========================================================================================="<<endl;
       cout<<"1.Add Students: "<<endl;
       cout<<"2.View Students: "<<endl;
       cout<<"3.Search Students: "<<endl;
       cout<<"4.Update Students: "<<endl;
       cout<<"5.Delete Students: "<<endl;
       cout<<"6.Exit"<<endl;
       cout<<"Enter your choice: ";
       cin>>choice;
       switch(choice)
       {
        case 1:
           add_students(students,total);
           break;
        case 2:
           view_students(students,total);
          break;
        case 3:
           search_students(students,total);
           break;
        case 4:
           update_student(students,total);
           break;
        case 5:
           delete_student(students,total);
           break;
        case 6:
           cout<<"Exiting program: "<<endl;
           break;
        default:
           cout<<"Invalid choice! "<<endl;
        }
    } while (choice!=6);
    return 0;
}





