package MounirDataStructures;

public class UserQueue<T> {
    private UserList<T> internalStructure;

    public UserQueue() {
        internalStructure = new UserLinkedList<>();
    }

    public UserQueue(UserQueue<T> other) {
        internalStructure = ((UserLinkedList<T>)other.internalStructure).copy();
    }

    public UserQueue<T> copy() {
        UserQueue<T> copy = new UserQueue<>(this);
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
        UserQueue<T> castedQueue;
        if (object instanceof UserQueue<?>)
            castedQueue = (UserQueue<T>)object;
        else
            throw new ClassCastException("The object is not of type UserQueue.");

        return internalStructure.equals(castedQueue.internalStructure);
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

    public void popFront() {
        if (internalStructure.isEmpty())
            return;
        internalStructure.remove(0);
    }
}
