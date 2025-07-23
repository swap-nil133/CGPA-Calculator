#include<bits/stdc++.h>
using namespace std;

class Subject{
    public:
        string subject_name;
        int credit;
        float gradepoint;
    Subject(string name, int cr, float gp){
        subject_name=name;
        credit=cr;
        gradepoint=gp;
    }
};

class Student{
    public:
        string name;
        vector<Subject> subjects;
    Student(string stu_name){
        name=stu_name;
    }
    void addsub(string sub_name, int credit, float gradepoint){
        Subject newsub(sub_name,credit,gradepoint);
        subjects.push_back(newsub);
    }

    float calculate_cgpa(){
        int total_credit=0;
        float weight_grade_point=0;
        for(const Subject & Subject:subjects){
            total_credit+=Subject.credit;
            weight_grade_point+=Subject.credit*Subject.gradepoint;
        }
        float cgpa=0;
        if(total_credit>0)
            cgpa=weight_grade_point/total_credit;
        return cgpa;
    }

    void display(){
        cout << "Student Name :" << name << "\n";
        float cgpa=calculate_cgpa();
        cout << "CGPA :" << cgpa << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string student_name;
    int num_of_sub;
    cout << "Enter Student Name:";
    getline(cin,student_name);
    cout << "Enter total number of subjects:";
    cin >> num_of_sub;
    Student student(student_name);
    for(int i=1;i<=num_of_sub;i++){
        string sub_name;
        int credit;
        float gradepoint;
        cout << "Enter Subject Name :";
        cin.ignore();
        getline(cin,sub_name);
        cout << "Enter Sub Credit :";
        cin >> credit;
        cout << "Enter Your Grade :";
        cin >> gradepoint;
        student.addsub(sub_name,credit,gradepoint);
    }
    student.display();
    

    return 0;
}