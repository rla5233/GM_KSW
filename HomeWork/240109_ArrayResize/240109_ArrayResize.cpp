#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{

public:

    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    IntArray(const IntArray& _Other)
    {
        Copy(_Other);
    }

    ~IntArray()
    {
        Release();
    }

    void operator= (const IntArray& _Other)
    {
        Copy(_Other);
    }

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

        //////////////////////////
        int* Temp = nullptr;
        Temp = new int[_Size];

        if (Temp == nullptr)
        {
            MsgBoxAssert("Memory Allocation Error!");
        }

        if (NumValue < _Size)
        {
            for (int i = 0; i < NumValue; i++)
            {
                Temp[i] = ArrPtr[i];
            }
        }
        else
        {
            for (int i = 0; i < _Size; i++)
            {
                Temp[i] = ArrPtr[i];
            }
        }
        ///////////////////////////


        if (ArrPtr != nullptr)
        {
            Release();
        }

        ArrPtr = Temp;
        NumValue = _Size;
        Temp = nullptr;
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
    LeakCheck;
    IntArray NewArray = IntArray(5);

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }
    // [0][1][2][3][4]


    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << " ";
    }

    NewArray.ReSize(10);
    // ? 는 무슨값이 들어 있어도 괜찮다.
    // [0][1][2][3][4][?][?][?][?][?] -> 원하는 결과

    // 1. 왜 결과가 다른가? 분석하기
    // -> 새로운 영역을 공간만 할당하고 원본값을 복사하진 않았기 때문
    // 
    // 2. 원하는 결과로 나오도록 출력
    // 
    // 3. 기존에 존재하는 값을 보존하면서 확장할수 있게 만들어라
    // 
    // 4. ReSize 인수값은 작아질수도 커질수도 있다.


    std::cout << std::endl;
    for (int i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << " ";
    }
}