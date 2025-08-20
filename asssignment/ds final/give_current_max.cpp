#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->marks = marks;
        this->name = name;
        this->roll = roll;
    }
};

class Cmp
{
public:
    bool operator()(Student a, Student b)
    {
        return a.marks == b.marks ? a.roll > b.roll : a.marks < b.marks;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, Cmp> pq; // max heap
    int N;
    cin >> N;
    while (N--)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student std(name, roll, marks);
        pq.push(std);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int val;
        cin >> val;
        if (val == 1)
        {
            if (!pq.empty())
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            else
                cout << "Empty" << endl;
        }
        else if (val == 2)
        {
            if (!pq.empty())
                pq.pop();
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else if (val == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student std(name, roll, marks);
            pq.push(std);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
    }
    return 0;
}