//
// Created by 阎懿 on 2019/11/2.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

using namespace std;

#include <iostream>
#include <string>
struct Student{
    string name;
    int score;
    //为了让结构体进行比较，所以要进行运算符的重载
    bool operator<(const Student& otherStudent){
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }
    friend ostream& operator<<(ostream& os, const Student& student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};
#endif //UNTITLED_STUDENT_H
