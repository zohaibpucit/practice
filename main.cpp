#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int id;
    int cgpa;
public:
//these are changes that i have made
    student(int id = 0, int cgpa = 0)
    {
        this->cgpa = cgpa;
        this->id = id;

    }

    void print()
    {
        cout << id << " " << cgpa << endl;
    }
};
int main()
{

    student obj(2, 3);

    student obj1;

    fstream file("test.dat", ios::binary);
    if(!file)
    {
        cout<<"not file";

        exit(0);
    }

    file.write(reinterpret_cast<char*>(&obj), sizeof(student));

    file.read(reinterpret_cast<char*>(&obj1), sizeof(student));

    obj1.print();
    // cin.read(reinterpret_cast<char*>(&obj),sizeof(student));

    file.close();


    return 0;
}