/*
 * Question 1
 *
 * Given a nearly sorted vector of integers, I would prefer to use quick sort.
 *
 * Insertion sort means splitting the array into a sorted and unsorted part,
 * picking integers from unsorted part and placing it in the correct position in the sorted part.
 *
 * Quick sort means selecting a pivot, and putting smaller than pivot elements before pivot,
 * putting greater than pivot elements after x.
 *
 * Since we have a vector of integers that are nearly sorted, quick sort would be better.
 * We don't need to force sorted order every step like with insertion sort.
 *
 * Question 2
 *
 * In the worst case, quick sort has time complexity of O(n^2).
 *
 * This is due to the poor choice of the pivot. If the pivot is chosen as the first element,
 * which happens to be the smallest. The other elements would just all be placed after pivot, which is doing nothing.
 *
 * Question 3
 *
 * The drawback in space efficiency for merge sort is that it requires an extra array to store the merged array.
 * The advantage that merge sort has in terms of time efficiency over quicksort is that
 * its worst case is O(n*log(n))
 *
 * Question 4
 *
 * The primary assumption that a developer has to make before using a binary search algorithm is that
 * there are no duplicates.
 *
 * Question 5
 *
 * BASE
 * BASE
 * BASE
 *
 * BASE
 * DERIVED
 * BASE
 *
 * Question 6
 *
 * Making a class abstract means the class has virtual functions.
 * We cannot create an instance of an abstract class.
 *
 */

//class Person{
//public:
//    Person(){id = 0; grade = 0.0;}
//    Person(int nId, double nGrade){id = nId; grade = nGrade;}
//    virtual void move() = 0;
//private:
//    int id;
//    double grade;
//};

/*
 * Question 7
 *
 * Encapsulation means the private members of the class can only be accessed by its member functions or friend classes.
 *
 * If other classes want to access the private data, they have to go through the accessors & mutators.
 *
 * Question 8
 *
 * Constructor with two values
 * Copy Constructor
 *
 */