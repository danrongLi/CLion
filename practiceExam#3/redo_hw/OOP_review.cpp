/*
 * PROBLEM
 *
 * Write a program that that collects the age(yrs),
 * height (cm), and weight(kg) of a list of people.
 *
 * Store the information in a linked list,
 * write an output function to list all entries
 * Write an output function to display the average height, age, and weight
 *
 * Write a specific functions to calculate the average height, age, and weight
 *
 * No need to use template
 *
 */

#include<iostream>
#include<string>

using namespace std;

class LList; //will contain a list of pointers
class PersonNode;

class PersonNode
{
private:

    double height;
    double age;
    double weight;

    PersonNode* next;

// A -> B -> C -> null

//hero object
// hp = 100
// attack = 50;
// defense = 75;

public:
    PersonNode(double init_height = 0, double init_age = 0, double init_weight = 0, PersonNode* init_next = nullptr) : height(init_height), age(init_age), weight(init_weight), next(init_next) {
        if(init_weight<=0){
            this->weight = 0;
        }
    }

    //getters
    double get_height() { return height; }
    double get_age() { return age; }
    double get_weight() { return weight; }

    //setter
    void set_next(PersonNode* next_node) { next = next_node; }

    friend class LList;
    //we can also re-write to not require friend class

    //operator overloading

    void operator+(const double &num) { this->age += num; }

    PersonNode operator+(PersonNode& other_person) //what happens if we make this parameter constant?
    {
        double new_age = (*this).get_age() + other_person.get_age();
        double new_height = this->get_height() +  other_person.get_height();
        double new_weight = this->get_weight() +  other_person.get_weight();

        PersonNode temp(new_height, new_age, new_weight);

        return temp;
    }



};

class LList
{
private:
    PersonNode* head;

public:
    LList() { head = nullptr; }
    LList(double height, double age, double weight);
    // copy constructor
    LList(PersonNode* other_head);

    ~LList() { this->clear(); }

    void insert(double height, double age, double weight);
    void clear();
    void remove_first();
    void remove_last();

    void display_list();
    void display_averages();
    double get_average_height();
    double get_average_age();
    double get_average_weight();
};

int main()
{
    //LList people;
    LList people(25, 34, 39);
    // think about how we can create a constructor that's passed a list of people as a parameter


    people.insert(135, 23, 90);
    people.insert(175, 24, 46);
    people.insert(180, 42, 72);

    //people.display_list();



    people.remove_last();
    cout << "\n\n\n";
    //people.display_list();


    people.remove_first();
    cout << "\n\n\n";
    //people.display_list();


    //people.display_averages();

    people.clear();

    people.display_averages();

    /*
    PersonNode jim(180, 25, 72);
    jim + 10;
    cout << jim.get_age() << endl;
    PersonNode jennifer(190, 26, 64);
    PersonNode jimifer = jim + jennifer;
    cout << jimifer.get_age() << endl;
    */


    return 0;
}

LList::LList(double height, double age, double weight)
{
    this->head = new PersonNode(height, age, weight);

    return;
}

LList::LList(PersonNode* other_head){
//A->B->C
    PersonNode* here = nullptr;
    double height;
    double age;
    double weight;

    if(other_head!=nullptr){
        here = other_head;

        while(here!=nullptr){

            height = here->get_height();
            age = here->get_age();
            weight = here->get_weight();

            this->insert(height,age,weight);

            here = here->next;

        }

    }
    return;
}


void LList::insert(double height, double age, double weight)
{
    PersonNode* here = this->head;

    //check for empty list
    if (here == nullptr) {
        this->head = new PersonNode(height, age, weight);
    }
    else {
        //iterate through list
        while (here->next != nullptr)
        {
            here = here->next;
        }

        //set node value
        here->next = new PersonNode(height, age, weight);
    }
}

void LList::clear()
{
    PersonNode* here;
    PersonNode* next;

    here = this->head;
    while (here != nullptr) //There is another way to write this
    {
        if (here->next != nullptr) {
            next = here->next;
            delete here;
            here = next;

        }
        else {
            delete here;

            here = nullptr;
            next = nullptr;
        }
    }

    head = nullptr;

    return;
}

void LList::remove_first()
{
    if(head!=nullptr){
        if (head->next != nullptr) {
            PersonNode* new_head = head->next;
            delete head;
            head = new_head;
        }
        else
        {
            delete head;
            head = nullptr;
        }
    }
}

void LList::remove_last()
{
    if (head != nullptr) {
        PersonNode* here = head;
        PersonNode* prev = here;

        while (here->next != nullptr) //how else can we write this?
        {
            prev = here;

            here = here->next;


        }

        delete here;
        prev->next = nullptr;
    }
}

void LList::display_list()
{
    PersonNode* here = this->head;

    //iterate through list, notice how we end at here==nullptr instead of here->next==nullptr
    while (here != nullptr)
    {
        cout << "\nHeight: " << here->get_height() << " cm" << endl;
        cout << "Age: " << here->get_age() << " years" << endl;
        cout << "Weight: " << here->get_weight() << " kg" << endl;

        //go to next node
        here = here->next;
    }
}

void LList::display_averages()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Average Height: " << this->get_average_height() << endl;
    cout << "Average Age: " << this->get_average_age() << endl;
    cout << "Average Weight: " << this->get_average_weight() << endl;

    //We iterate across the linked list three times here, how can we do this more efficiently?
}

double LList::get_average_height()
{
    if (this->head == nullptr) //why do we do this?
    {
        return 0;
    }
    else
    {
        double total_height, average;
        double counter;

        PersonNode* here;

        here = this->head;
        total_height = 0;
        counter = 0;

        while (here != nullptr)
        {
            total_height += here->get_height();
            counter++;

            here = here->next;
        }

        average = static_cast<double>(total_height / counter);
        return average;
    }
}

double LList::get_average_age()
{
    if (this->head == nullptr) //why do we do this?
    {
        return 0;
    }
    else
    {
        double total_age, average;
        int counter;

        PersonNode* here;

        here = this->head;
        total_age = 0;
        counter = 0;

        while (here != nullptr)
        {
            total_age += here->get_age();
            counter++;

            here = here->next;
        }

        average = static_cast<double>(total_age / counter);
        return average;
    }
}

double LList::get_average_weight()
{
    if (this->head == nullptr) //why do we do this?
    {
        return 0;
    }
    else
    {
        double total_weight, average;
        int counter;

        PersonNode* here;

        here = this->head;
        total_weight = 0;
        counter = 0;

        while (here != nullptr)
        {
            total_weight += here->get_weight();
            counter++;

            here = here->next;
        }

        average = static_cast<double>(total_weight / counter);
        return average;
    }
}