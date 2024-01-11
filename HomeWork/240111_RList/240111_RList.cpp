
#include <iostream>
#include <ConsoleEngine/EngineDebug.h>
#include <list>

// 노드형태
typedef int DataType;
//template <typename DataType>
class MyList
{
private:
    class Node
    {
    public:
        DataType Data;
        Node* Next;
        Node* Prev;
    };

public:
    class iterator
    {
        friend MyList;
    public:
        iterator() {}
        iterator(Node* _CurNode)
            : CurNode(_CurNode)
        {}

        bool operator != (const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        DataType& operator*()
        {
            return CurNode->Data;
        }

        void operator++()
        {
            CurNode = CurNode->Next;
        }

    private:
        Node* CurNode = nullptr;
    };

    MyList()
    {
        Start->Next = End;
        End->Prev = Start;
    }

    ~MyList()
    {
        Node* DeleteNode = Start;
        while (DeleteNode != nullptr)
        {
            Node* Next = DeleteNode->Next;
            delete DeleteNode;
            DeleteNode = Next;
        }
    }

    iterator begin()
    {
        return iterator(Start->Next);
    }

    iterator end()
    {
        return iterator(End);
    }

    // End의 Prev에 새로운 데이터를 넣겠다.
    void push_back(const DataType& _Data)
    {
        Node* NewNode = new Node();
        NewNode->Data = _Data;

        NewNode->Next = End;
        NewNode->Prev = End->Prev;

        Node* PrevNode = NewNode->Prev;
        Node* NextNode = NewNode->Next;

        PrevNode->Next = NewNode;
        NextNode->Prev = NewNode;
    }

    // Start의 Next에 새로운 데이터를 넣겠다.
    void push_front(const DataType& _Data)
    {
        Node* NewNode = new Node();
        NewNode->Data = _Data;

        NewNode->Prev = Start;
        NewNode->Next = Start->Next;

        Node* PrevNode = NewNode->Prev;
        Node* NextNode = NewNode->Next;

        PrevNode->Next = NewNode;
        NextNode->Prev = NewNode;
    }

    iterator erase(iterator& _Iter)
    {
        if (_Iter.CurNode == Start || _Iter.CurNode == End)
        {
            MsgBoxAssert("Delete Range Error.");
        }

        iterator ReturnIter = iterator();
        if (_Iter.CurNode != nullptr)
        {
            ReturnIter = iterator(_Iter.CurNode->Next);

            Node* PrevNode = _Iter.CurNode->Prev;
            Node* NextNode = _Iter.CurNode->Next;

            PrevNode->Next = NextNode;
            NextNode->Prev = PrevNode;

            delete _Iter.CurNode;
            _Iter.CurNode = nullptr;
        }

        return ReturnIter;
    }

protected:

private:
    Node* Start = new Node();
    Node* End = new Node();
};

int main()
{
    LeakCheck;

    {
        std::cout << "std::list" << std::endl;
        std::list<int> NewList = std::list<int>();
        for (int i = 0; i < 5; i++)
        {
            NewList.push_back(i);
            //NewList.push_front(i);
        }

        std::list<int>::iterator iter = NewList.begin();
        for (iter; iter != NewList.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }

        std::list<int>::iterator Erase_iter = NewList.begin();

        // 지워진 노드의 다음 노드를 리턴함
        Erase_iter = NewList.erase(Erase_iter);
    }

    {
        std::cout << "\nMyList" << std::endl;
        MyList NewList = MyList();
        for (int i = 0; i < 5; i++)
        {
            NewList.push_back(i);
            //NewList.push_front(i);
        }

        MyList::iterator iter = NewList.begin();
        for (iter; iter != NewList.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }

        MyList::iterator Erase_iter = NewList.begin();
        Erase_iter = NewList.erase(Erase_iter);

        std::cout << std::endl;
        for (iter = NewList.begin(); iter != NewList.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }
}