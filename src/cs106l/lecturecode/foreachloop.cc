/**
 * foreachloop.cc
 * Purpose: This is to test the for each loop in cpp
 *  
 * @author Rahul W
 * @version 0.1 10/11/19
 */

#include <iostream>
#include <vector>

struct Course {
    std::string code;
    int startTime;
    int endTime;
};

void printVectorValues(const std::vector<Course>& courses) {
    for (auto& course : courses) {
        std::cout << course.code << std::endl;
    }
}

int main() {
    std::vector<Course> collegeCourses; 
    Course tempStruct;
    for (int i = 0; i < 5; i++) {
        tempStruct.code = "CS" + std::to_string(i);
        tempStruct.startTime = i * 3;
        tempStruct.endTime = i * 4;
        collegeCourses.push_back(tempStruct);
    }
    printVectorValues(collegeCourses);
    return 0;
}
