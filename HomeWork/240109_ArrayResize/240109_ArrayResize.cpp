#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

//#define SHALLOW

class IntArray
{
    // private: // 디폴트 접근제한 지정자
public:
    // 디폴트 생성자
    //IntArray()
    //{}

    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    // 디폴트 복사 생성자
    //IntArray(const IntArray& _Other)
    //{}

#ifdef SHALLOW
    IntArray(const IntArray& _Other)
    {
        ReSize(_Other.NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }
#else
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);
    }
#endif

    // 디폴트 소멸자
    //~IntArray()
    //{}

    ~IntArray()
    {
        Release();
    }

    // 디폴트 대입연산자
    //void operator= (const IntArray& _Other)
    //{}


#ifdef SHALLOW
    // 얕은 복사 (Shallow Copy)
    // 1. 참조만 복사하는 복사
    // 깊은 복사가 더 좋아 얕은 복사는 나빠 -> 이건 아니다. 상황에따라 써야한다.
    void operator= (const IntArray& _Other)
    {
        NumValue = _Other.NumValue;
        ArrPtr = _Other.ArrPtr;
    }
#else
    // 깊은 복사 (Deep Copy)
    // 1. 참조의 내부에 존재하는 값을 복사하는 복사
    // 2. 내부에 있는 값을 메모리를 동일하게 할당해 복사하는 복사
    void operator= (const IntArray& _Other)
    {
        Copy(_Other);
    }
#endif


    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    void ReSize(int _Size)
    {
        if (_Size <= 0)
        {
            MsgBoxAssert("Array Range Error!");
        }

        if (ArrPtr != nullptr)
        {
            Release();
        }

        ArrPtr = new int[_Size];
        NumValue = _Size;
    }

    void Copy(const IntArray& _Other)
    {
        ReSize(_Other.NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }

    void Release()
    {
        if (ArrPtr != nullptr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }

    int Num()
    {
        return NumValue;
    }

private:
    int NumValue = 0;
    int* ArrPtr = nullptr;

};


int main()
{
    IntArray NewArray = IntArray(10);

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }



    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }


}