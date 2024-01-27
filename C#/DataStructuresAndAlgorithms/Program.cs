using Mounir_DataStructures;

TestUserArrayList1();
TestUserList1();

void TestUserArrayList1()
{
    IUserList<int> list1 = new UserArrayList<int>(2);
    Console.WriteLine("The list was created with 2 as the default capacity.");
    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);

    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);
    Console.WriteLine("list1 Front: " + list1.Front());
    Console.WriteLine("list1 Back: " + list1.Back());

    Console.WriteLine("list1 getindex of 1: " + list1.GetIndex(1));
    Console.WriteLine("list1 getindex of 10: " + list1.GetIndex(10));
    Console.WriteLine("list1 get 1: " + list1.Get(1));
    
    Console.WriteLine("Adding more data.");
    list1.Insert(0, 10); //At the start.
    list1.Insert(4, 101); //At the endNode.
    list1.Insert(4, 50); //At the tail.
    list1.Insert(2, 22); //At the middle.

    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);

    IUserList<int> list2 = new UserArrayList<int>(list1);
}

void TestUserList1()
{

}