#include <iostream>
#include <vector>

template <typename T>
class Heap
{
  public:
    Heap(int maxSize) : _maxSize(maxSize), _size(0)
    {
        _array = new T[maxSize];
    }

    ~Heap()
    {
        if (_array)
        {
            delete[] _array;
        }
    }

  public:
    void SiftUp(int index);
    void SiftDown(int index);
    void Insert(T value);
    const T ExtractMax();
    void Remove(int index);

  private:
    int Parent(int index) { return (index / 2); }
    int LeftChild(int index) { return (2 * index); }
    int RightChild(int index) { return (2 * index + 1); }

  private:
    int _maxSize;
    int _size; // current size
    T *_array;
};

template <typename T>
void Heap<T>::SiftUp(int index)
{
    while (index > 1 && _array[Parent(index)] < _array[index])
    {
        std::swap(_array[Parent(index)], _array[index]);
        index = Parent(index);
    }
}

template <typename T>
void Heap<T>::SiftDown(int index)
{
    int maxIndex = index;
    int leftChildIndex = LeftChild(index);
    if ((leftChildIndex <= _size) && _array[leftChildIndex] > _array[maxIndex])
    {
        maxIndex = leftChildIndex;
    }
    int rightChildIndex = RightChild(index);
    if ((rightChildIndex <= _size) && (_array[rightChildIndex] > _array[maxIndex]))
    {
        maxIndex = rightChildIndex;
    }

    if (index != maxIndex)
    {
        std::swap(_array[index], _array[maxIndex]);
        SiftDown(maxIndex);
    }
}

template <typename T>
void Heap<T>::Insert(T value)
{
    if (_size == _maxSize)
    {
        std::cerr << "Overflow, dropping the value " << value;
        return;
    }

    _size++;
    _array[_size] = value;
    SiftUp(_size);
}

template <typename T>
const T Heap<T>::ExtractMax()
{
    T result = _array[1];
    _array[1] = _array[_size];
    _size--;
    SiftDown(1);
    return result;
}

template <typename T>
void Heap<T>::Remove(int index)
{
    _array[index] = std::numeric_limits<int>::max();
    SiftUp(index);
    ExtractMax();
}

int main()
{
    Heap<int> heap(4);
    heap.Insert(3);
    heap.Insert(4);
    heap.Insert(6);
    heap.Insert(2);

    std::cout << "Max " << heap.ExtractMax() << "\n";
    std::cout << "Max " << heap.ExtractMax() << "\n";

    heap.Insert(1);
    std::cout << "Max " << heap.ExtractMax() << "\n";

    heap.Remove(2);
    std::cout << "Max " << heap.ExtractMax() << "\n";
}