package MounirDataStructures;

import java.util.Comparator;

public interface UserList<T> {
    //The clear function is not expected to de-allocate the allocated memory.
    //instead just setting the length to zero so that the list is empty.
    public void clear();
    String toString();
    boolean equals(Object object);
    public int getCapacity();
    public int getLength();
    public boolean isEmpty();
    public T front();
    public T back();
    public int getIndex(T Key);
    public T get(int index);
    public void set(int index, T newValue);
    void add(T item);
    void add(int index, T item);
    void remove(int index);
    void sort(Comparator<T> comp);

    //If you declare an interface inside interface, then the inner interface
    //is implicity public and static, since it is static I cannot create a method
    //that returns an argument of type generic like T (function getItem())
    //Therefore I had to move the inner interface out the UserList interface and define
    //it as separate interface.
    UserListIterator<T> getIterator(int index);
    UserListIterator<T> begin();
    UserListIterator<T> end();
}
