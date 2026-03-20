#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string name;
    int score;
    int id;
};
bool compare(Student stu1, Student stu2) {
    if (stu1.score != stu2.score) {
        return stu1.score > stu2.score;
    }
    if (stu1.name != stu2.name) {
        return stu1.name < stu2.name;
    }
    return stu1.id < stu2.id;
}
int main() {
    int n;
    cin >> n;
    vector<Student> stu(n);
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score >> stu[i].id;
    }
    sort(stu.begin(), stu.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].score << " " << stu[i].id << endl;
    }
    return 0;
}