package MounirDataStructures;

public interface UserListIterator<T> {
    public String toString();
    public boolean equals(Object object);
    public boolean hasNext();
    public boolean hasPrevious();
    public void increment();
    public void decrement();
    public T getCurrent();
    public void setCurrent(T newValue);
    //The function should add the item before the current item.
    //The current item should stay the same, which may requires updating
    //the iterator.
    public void addAtCurrent(T item);
    //The function should remove the current item and then
    //set the iterator to be pointing at the item after the deleted item (if any).
    public void removeCurrent();
}
