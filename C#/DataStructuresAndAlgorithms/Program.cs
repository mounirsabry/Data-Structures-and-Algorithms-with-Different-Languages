using Mounir_DataStructures;

TestUserArrayList1();
TestUserList1();

void TestUserArrayList1()
{
    IUserList<int> list1 = new UserArrayList<int>();
    
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
}

void TestUserList1()
{

}