/*
 * Question 1
 *
 * Given a nearly sorted vector of integers, I would prefer to use insertion sort.
 *
 * Insertion sort means splitting the array into a sorted and unsorted part,
 * picking integers from unsorted part and placing it in the correct position in the sorted part.
 *
 * Quick sort means selecting a pivot, and putting smaller than pivot elements before pivot,
 * putting greater than pivot elements after x.
 *
 * Insertion is faster in this case, it goes from O(n^2) to O(n) in this situation.
 *
 * (selection means finding the min, so still need O(n^2))
 * (insertion, selection, merge, quick sort)
 *
 * Question 2
 *
 * In the worst case, quick sort has time complexity of O(n^2).
 *
 * Suppose we have a list that is nearly sorted. If our pivot chosen is either the first or last element of the list,
 * we'd have n groups that each each need to be iterated through n times.
 *
 * Question 3
 *
 * The drawback in space efficiency for merge sort is that it requires an extra array to store the merged array.
 * (need auxiliary array for the merge step)
 * The advantage that merge sort has in terms of time efficiency over quicksort is that
 * it's always O(nlog(n))
 *
 * Question 4
 *
 * The primary assumption that a developer has to make before using a binary search algorithm is that
 * data has to sorted.
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
 * Making a class abstract means the class has pure virtual functions.
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
 * Encapsulation is the idea of hiding data and functions within a single unit.
 * In C++, we can do this via classes.
 *
 * Question 8
 *
 * Constructor with two values
 * Copy Constructor
 *
 */