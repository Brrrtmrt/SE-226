#include <iostream>
#include <string>

void first(){
    std::string name;
    std::string studentID;
    std::cout<<"What is your name";
    std::cin>>name;
    std::cout<<"Hello: "<<name;
    std::cout<<"What is your student ID";
    std::cin>>studentID;
    std::cout<<"Your ID is: "<<studentID;

}
void second(){
    using namespace std;
    int var1;
    int var2;
    int sum;
    int prod;
    int diff;
    cout<<"Enter var1";
    cin>>var1;
    cout<<"Enter var2";
    cin>>var2;
    sum=var1+var2;
    diff=var1-var2;
    prod=var1*var2;

    cout<<"Var1"<<var1<<" "<<"Var2"<<" "<<var2<<"Prod"<<" "<<prod<<"Diff"<<" "<<diff<<"Sum"<<" "<<sum;
    

}
void third(){
    using namespace std;
    string name;
    float lab;
    float midterm;
    float final;
    float last;
    cout<<"Enter name";
    cin>>name;
     cout<<"Enter lab";
    cin>>lab;
     cout<<"Enter midterm";
    cin>>midterm;
     cout<<"Enter final";
    cin>>final;
    
    last=0.25*lab+0.35*midterm+0.4*final;

    cout<<"Name:"<<name<<" ";
    cout<<"Lab:"<<lab<<" ";
    cout<<"Midterm:"<<midterm<<" ";
    cout<<"Final:"<<final<<" ";
    cout<<"Last Score:"<<last<<" ";

}
void printstar(){
    std::cout<<"*"<<"\n"<<"**"<<"\n"<<"***"<<"\n"<<"**"<<"\n"<<"*";
}

int main(){
    first();
    second();
    third();
    printstar();
}