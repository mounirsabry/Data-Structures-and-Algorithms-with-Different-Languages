//Vector data structure, part of the datastructures_mounir namepsace.
/*
    I run into a problem with implementing iterator as nested class.
    This video helps me.
    https://www.youtube.com/watch?v=SZOabH-l51E

    These also helped.
    https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    https://stackoverflow.com/questions/52751066/use-the-typename-keyword-to-treat-nontype-as-a-type-in-dependent-context
    https://en.cppreference.com/w/cpp/language/operators
    https://stackoverflow.com/questions/18823618/overload-operator-for-nested-class-template

    The friend of a nested template class cannot be defined outside the class.
    I tried multiple times but did not work.
    Only way that I got it to work is to inline it in the header file.
    Otherwise the compiler is not able to deduce the type of the template.
*/
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace datastructures_mounir
{
    template <typename T> class Vector;

    template <typename T> 
    std::ostream& operator<< ( std::ostream&, const Vector<T> &vector);
    template <typename T> 
    bool operator== (const Vector<T> &vector1, const Vector<T> &vector2);

    template <typename T>
    class Vector
    {
    public:
        class Iterator;
        //The default constructor does not allocate any dynamic memory.
        Vector();
        //Allocates dynamic memory to accumlate the given capacity, the default
        //constructor must be defined for the datatype given.
        Vector(int initialCapacity);
        //Copy constructor, deep copy the parameter vector in vector.
        //Relies on the assignment operator for the given type.
        Vector(const Vector<T> &otherVector);
        ~Vector();
        //Assignment operator, deep copy the parameter vector in vector.
        //Relies on the assignment operator for the given type.
        Vector<T> &operator =(const Vector<T> &otherVector);
        //Expand the vector the new capacity, if the new capacity
        //is lower of equal to the current capacity, nothing happens.
        //Relies on the assignment operator and the destructor
        //for the given type.
        void reserve(int newCapacity);
        //Clears (destroyes) all the elements in the array.
        //Both the length and the capacity is reset to zero
        //after function end.
        //All iterators all invalidates after this call.
        //Relies on the destructor for the given type.
        void clear();
        int getCapacity() const;
        int getLength() const;
        bool isEmpty() const;
        //Does not check for out of boundary access, use
        //at your own risk.
        T &operator[] (int index) const;
        //Safer version of the operator function, throws
        //exception when attempting to access out of boundary element.
        T &at(int index) const;
        //Searches the vector for the given value.
        //Returns end() if the item was not found in the vector.
        //Sequential Search.
        //The search works on sorted and unsorted vector.
        //The algorithm does not cut early except when it find
        //the key item, otherwise it iterates through the whole vector.
        Vector<T>::Iterator findSequential(const T &item) const;
        //Searches the vector for the given value.
        //Returns end() if the item was not found in the vector.
        //Binary Search, require the vector to be sorted before operation.
        //Function does not sort the vector nor check if sorted.
        //If the function run on unsorted vector, the result will be unpredicatable.
        //Iterative Implementation.
        Vector<T>::Iterator findBinary(const T &item) const;
        //Returns an iterator pointing to the first element in the vector.
        Vector<T>::Iterator begin() const;
        //Returns an iterator pointing to the last element in the vector.
        Vector<T>::Iterator last() const;
        //Returns an iterator pointing to a location after the last element
        //in the vector.
        //The end iterator is a valid iterator, however the value/item pointed
        //to by the iterator is not valid.
        //Dereference the value will return a undefined value / garbage.
        Vector<T>::Iterator end() const;
        //Returns the first element in the vector.
        T &front() const;
        //Returns the last element in the vector.
        T &back() const;
        //Return an iterator pointing to the new inserted item.
        //The item is inserted before the given location.
        //Insert may invalidate the previous iterators' values
        //on the case of resize or shifting elements on insert.
        //The sent iterator is not updated by the function, hence invalid.
        //and should be reassigned by the value returned from the function.
        //The returned iterator is different object than the sent iterator.
        //Return end() if the insertion failed.
        //Insertion fails if there not enough memory or the location is invalid.
        Vector<T>::Iterator insert(const Vector<T>::Iterator &location, const T &item);
        //Inserts the element at the end of the vector, return an iterator
        //pointing to the newly inserted item, insertion may invalidates
        //the previous iterators' values.
        //Return end() if the insertion failed.
        //Insertion fails if their is not enough memory.
        Vector<T>::Iterator pushBack(const T &item);
        //Removes the last element in the vector.
        //Returns true if an erase happened, false otherwise.
        bool popBack();
        //Returns true in case of success, false otherwise.
        //The sent iterator is not updated by the function, however it is still valid
        //due to the mechanism of erasing.
        //The sent location will now point to the target that existed after the location.
        //If the location was the last element in the vector, then location will be end().
        bool erase(const Vector<T>::Iterator &location);
        //Swap the content of the elements pointed to by the iterators, the iterators
        //themselves are not affected and not swapped.
        void swap(const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2);
        //In-place sort.
        void sortSelectionSort();
        //In-place sort.
        void sortInsertionSort();
        //In-place sort.
        void sortBubbleSort();
        //In-place sort.
        //Recursive Implementation.
        void sortQuickSort();
        //Out of place sort, allocates aditional memory
        //during working, if the memory allocation failed
        //an exception will be thrown.
        //Recursive Implementation.
        void sortMergeSort();
        friend bool operator== <T>(const Vector<T> &vector1, const Vector<T> &vector2);
        friend std::ostream& operator<< <T>(std::ostream&, const Vector<T> &vector);
    private:
        T *array;
        int capacity;
        int length;
        const int DEFAULT_EMPTY_EXPAND_CAPACITY = 10;
        //Relies on the usage of the assignment operator for the datatype
        //given for the vector.
        void copyArray(T *oldArray, T *newArray, int length) const;
        void swap(T &element1, T &element2);
        void quickSortUtil(T *array, int minIndex, int maxIndex);
        T *mergeSortUtil(T *array, int minIndex, int maxIndex);
        T *merge(T *array1, T *array2, int length1, int length2);
    };
               
    template <typename T>
    class Vector<T>::Iterator
    {
    public:
        //Parameterized Constructor.
        Iterator(T *arrayStartPointer, int index);
        //Prefix increment operator.
        Vector<T>::Iterator &operator++ ();
        //Postfix increment operator.
        Vector<T>::Iterator operator++ (int);
        //Prefix increment operator.
        Vector<T>::Iterator &operator-- ();
        //Postfix increment operator.
        Vector<T>::Iterator operator-- (int);
        //Modify the calling object.
        Vector<T>::Iterator &operator+= (int offset);
        //Modify the calling object.
        Vector<T>::Iterator &operator-= (int offset);

        //Does not modify the calling object.
        friend Vector<T>::Iterator operator+ (const Vector<T>::Iterator &iter, int offset)
        {
            Vector<T>::Iterator temp = iter;
            temp += offset;
            return temp;
        }

        //Does not modify the calling object.
        friend Vector<T>::Iterator operator- (const Vector<T>::Iterator &iter, int offset)
        {
            Vector<T>::Iterator temp = iter;
            temp -= offset;
            return temp;
        }

        //Does not modify the calling object.
        friend bool operator== (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            if (iter1.startPointer != iter2.startPointer
            ||  iter1.currentIndex != iter2.currentIndex)
                return false;
            return true;
        }

        //Does not modify the calling object.
        friend bool operator!= (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            return !(iter1 == iter2);
        }

        //Does not modify the calling object.
        friend bool operator< (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            if (iter1.startPointer != iter2.startPointer)
                return false;
            else if (iter1.currentIndex < iter2.currentIndex)
                return true;
            else
                return false;
        }

        //Does not modify the calling object.
        friend bool operator<= (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            return (iter1 < iter2) || (iter1 == iter2);
        }

        //Does not modify the calling object.
        friend bool operator> (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            if (iter1.startPointer != iter2.startPointer)
                return false;
            else if (iter1.currentIndex > iter1.currentIndex)
                return true;
            else
                return false;
        }

        //Does not modify the calling object.
        friend bool operator>= (const Vector<T>::Iterator &iter1, const Vector<T>::Iterator &iter2)
        {
            return (iter1 > iter2) || (iter1 == iter2);
        }

        T &operator* () const;
        T &operator[] (int index) const;
        int getIndex() const;
    private:
        T *startPointer;
        int currentIndex;
    };
}

#endif