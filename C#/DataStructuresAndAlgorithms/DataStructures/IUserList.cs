
namespace Mounir_DataStructures
{
    public interface IUserList<T> : ICloneable
    {
        public int Capacity { get; }
        public int Count { get; }
        string? ToString();
        bool Equals(object? obj);
        int GetHashCode();
        public void Clear();
        public bool IsEmpty();
        public T? Front();
        public T? Back();
        public int GetIndex(T? key);
        public T? Get(int index);
        public void Set(int index, T? newValue);
        void Add(T? item);
        bool Insert(int index, T? item);
        bool Remove(T? item);
        bool RemoveAt(int index);
        void Sort(IComparer<T> comparer);
    }
}