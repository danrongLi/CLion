#include <iostream>
using namespace std;

class Employee{
public:
    Employee();
    Employee(string the_name, string the_ssn);
    string get_name() const;
    string get_ssn() const;
    double get_net_pay() const;
    void set_name(string new_name);
    void set_ssn(string new_ssn);
    void set_net_pay(double new_net_pay);
    void print_check() const;

private:
    string name;
    string ssn;
    double net_pay;
};

Employee::Employee() {
    name = "No Name Yet";
    ssn = "No Number Yet";
    net_pay = 0.0;
}

Employee::Employee(string the_name, string the_ssn) {
    name = the_name;
    ssn = the_ssn;
    net_pay = 0.0;
}

string Employee::get_name() const {
    return name;
}

string Employee::get_ssn() const {
    return ssn;
}
double Employee::get_net_pay() const {
    return net_pay;
}

void Employee::set_name(string new_name) {
    name = new_name;
}

void Employee::set_ssn(string new_ssn) {
    ssn = new_ssn;
}

void Employee::set_net_pay(double new_net_pay) {
    net_pay = new_net_pay;
}
void Employee::print_check() const {
    cout<<"Error"<<endl;
    exit(1);
}

class HourlyEmployee: public Employee{
public:
    HourlyEmployee();
    HourlyEmployee(string the_name, string the_ssn, double the_wage_rate, double the_hours);
    void set_rate(double new_wage_rate);
    double get_rate() const;
    void set_hours(double hours_worked);
    double get_hours() const;
    void print_check();
private:
    double wage_rate;
    double hours;
};

HourlyEmployee::HourlyEmployee(): Employee(), wage_rate(0.0), hours(0.0) {}

HourlyEmployee::HourlyEmployee(string the_name, string the_ssn, double the_wage_rate, double the_hours)
: Employee(the_name, the_ssn), wage_rate(the_wage_rate), hours(the_hours){}

void HourlyEmployee::set_rate(double new_wage_rate) {
    wage_rate = new_wage_rate;
}

double HourlyEmployee::get_rate() const {
    return wage_rate;
}

void HourlyEmployee::set_hours(double hours_worked) {
    hours = hours_worked;
}

double HourlyEmployee::get_hours() const {
    return hours;
}

void HourlyEmployee::print_check() {
    set_net_pay(hours * wage_rate);
    cout<<"\n________________\n";
    cout<<"Pay to the order of "<<get_name()<<endl;
    cout<<"The sum of "<<get_net_pay()<<" Dollars"<<endl;
    cout<<"Employee Number: "<<get_ssn()<<endl;
    cout<<"Hourly Employee. \nHours worked: "<<hours
        <<" Rate: "<<wage_rate<<" Pay: "<<get_net_pay()<<endl;
    cout<<"__________________\n";
}

class SalariedEmployee: public Employee{
public:
    SalariedEmployee();
    SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary);
    double get_salary() const;
    void set_salary(double new_salary);
    void print_check();
private:
    double salary;
};

SalariedEmployee::SalariedEmployee():Employee(), salary(0.0) {}

SalariedEmployee::SalariedEmployee(string the_name, string the_ssn, double the_weekly_salary)
:Employee(the_name, the_ssn), salary(the_weekly_salary) {}

double SalariedEmployee::get_salary() const {
    return salary;
}
void SalariedEmployee::set_salary(double new_salary) {
    salary = new_salary;
}

void SalariedEmployee::print_check() {
    set_net_pay(salary);
    cout<<"\n________________\n";
    cout<<"Pay to the order of "<<get_name()<<endl;
    cout<<"The sum of "<<get_net_pay()<<" Dollars"<<endl;
    cout<<"Employee Number: "<<get_ssn()<<endl;
    cout<<"Salaried Employee. Regular Pay: "<<salary<<endl;
    cout<<"__________________\n";
}

int main(){
    HourlyEmployee joe;
    joe.set_name("Mighty Joe");
    joe.set_ssn("123-45-6789");
    joe.set_rate(20.50);
    joe.set_hours(40);

    cout<<"Check for "<<joe.get_name()<<" for "<<joe.get_hours()<<" hours"<<endl;
    joe.print_check();
    cout<<endl;

    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
    cout<<"Check for "<<boss.get_name()<<endl;
    boss.print_check();
}

