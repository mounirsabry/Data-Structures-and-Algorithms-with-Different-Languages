package MounirDataStructures;

public class UserStack<T> {
    private UserList<T> internalStructure;

    public UserStack() {
        internalStructure = new UserLinkedList<>();
    }

    public UserStack(UserStack<T> other) {
        internalStructure = ((UserLinkedList<T>)other.internalStructure).copy();
    }

    public UserStack<T> copy() {
        UserStack<T> copy = new UserStack<>(this);
        return copy;
    }

    public void clear() {
        internalStructure.clear();
    }

    public String toString() {
        return internalStructure.toString();
    }

    @SuppressWarnings("unchecked")
    public boolean equals(Object object) {
        UserStack<T> castedStack;
        if (object instanceof UserStack<?>)
            castedStack = (UserStack<T>)object;
        else
            throw new ClassCastException("The object is not of type UserStack");

        return internalStructure.equals(castedStack.internalStructure);
    }

    public int getLength() {
        return internalStructure.getLength();
    }

    public boolean isEmpty() {
        return internalStructure.isEmpty();
    }

    public T peekFront() {
        return internalStructure.front();
    }

    public T peekBack() {
        return internalStructure.back();
    }
    
    public void pushBack(T item) {
        internalStructure.add(item);
    }

    public void popBack() {
        int length = internalStructure.getLength();
        if (length != 0)
            internalStructure.remove(length - 1);
    }
}
