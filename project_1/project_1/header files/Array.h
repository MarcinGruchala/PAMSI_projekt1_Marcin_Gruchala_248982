#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>

template<typename T,int S>
class Array
{
private:
	T* m_elements = new T[S];
	int divide(int beginingIndex, int endIndex);
	void sortAndMerge(int beginingIndex, int endIndex, int centreIndex);
	void heapTree(int count, int i);
	int findPivot(int firstNumber, int middleNumber, int lastNumber);

public:
	Array();
	void random(float sortedPart = 0);
	void swap(T* a, T* b);
	void insertsort(int beginingIndex = 0, int endIndex = S - 1);
	void heapsort(int count = S);
	void quicksort(int beginingIndex = 0, int endIndex = S - 1);
	void mergesort(int beginingIndex = 0, int endIndex = S - 1);
	void introsort(int beginingIndex = 0, int endIndex = S - 1, int breakpoint = floor(2 * log(S)));
	bool check()const;
	void freeMemory();
	void print()const;
	~Array();
};

template<typename T, int S>
int Array<T, S>::divide(int beginingIndex, int endIndex)
{
	T pivotNumber = m_elements[endIndex];
	int index = (beginingIndex - 1);

	for (int i = beginingIndex; i <= (endIndex - 1); i++)
	{
		if (m_elements[i] <= pivotNumber)
		{
			index++;
			swap(&m_elements[index], &m_elements[i]);
		}
	}
	swap(&m_elements[index + 1], &m_elements[endIndex]);
	return (index + 1);
}

template<typename T, int S>
void Array<T, S>::sortAndMerge(int beginingIndex, int endIndex, int centreIndex)
{
	int lcount = centreIndex - beginingIndex + 1;
	int rcount = endIndex - centreIndex;

	T* rarray = new int[rcount];
	T* larray = new int[lcount];

	for (int i = 0; i < lcount; i++)
	{
		larray[i] = m_elements[beginingIndex + i];
	}
	for (int i = 0; i < rcount; i++)
	{
		rarray[i] = m_elements[centreIndex + i + 1];
	}

	int larrayindex = 0;
	int rarrayindex = 0;
	int marrayindex = beginingIndex;

	while (larrayindex < lcount && rarrayindex < rcount)
	{
		if (larray[larrayindex] <= rarray[rarrayindex])
		{
			m_elements[marrayindex] = larray[larrayindex];
			larrayindex++;
		}
		else
		{
			m_elements[marrayindex] = rarray[rarrayindex];
			rarrayindex++;
		}
		marrayindex++;
	}

	while (larrayindex < lcount)
	{
		m_elements[marrayindex] = larray[larrayindex];
		larrayindex++;
		marrayindex++;
	}

	while (rarrayindex < rcount)
	{
		m_elements[marrayindex] = rarray[rarrayindex];
		rarrayindex++;
		marrayindex++;
	}

	delete[] larray;
	delete[] rarray;

}

template<typename T, int S>
void Array<T, S>::heapTree(int count, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left<count && m_elements[left]> m_elements[largest])
	{
		largest = left;
	}

	if (right < count && m_elements[right] > m_elements[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(i, largest);
		heapTree(count, largest);
	}
}

template<typename T, int S>
int Array<T, S>::findPivot(int firstNumber, int middleNumber, int lastNumber)
{
	if (firstNumber < middleNumber && middleNumber < lastNumber)
		return middleNumber;

	if (firstNumber < lastNumber && lastNumber <= middleNumber)
		return lastNumber;

	if (middleNumber <= firstNumber && firstNumber < lastNumber)
		return firstNumber;

	if (middleNumber < lastNumber && lastNumber <= firstNumber)
		return lastNumber;

	if (lastNumber <= firstNumber && firstNumber < middleNumber)
		return firstNumber;

	if (lastNumber <= middleNumber && middleNumber <= firstNumber)
		return middleNumber;
}

template<typename T, int S>
Array<T, S>::Array()
{

}

template<typename T, int S>
void Array<T, S>::random(float sortedPart)
{
	srand(time(NULL));
	for (int i = 0; i < S; i++)
		m_elements[i] = rand() % S + 1;

	if (sortedPart > 0)
		quicksort(0,(sortedPart/100.0) * S - 1);
	else if (sortedPart < 0)
	{
		quicksort();
		T* tmp= new T[S];
		for (int i = 0; i < S; i++)
			tmp[i] = m_elements[i];
		for (int i = 0; i < S; i++)
			m_elements[i] = tmp[S - 1 - i];
		delete[] tmp;
	}
}

template<typename T, int S>
void Array<T, S>::swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename T, int S>
void Array<T, S>::insertsort(int beginingIndex, int endIndex)
{
	for (int i = beginingIndex + 1; i <= endIndex; i++)
	{
		int currentNumber = m_elements[i];
		int previousNumberIndex = i - 1;

		while (previousNumberIndex >= beginingIndex && m_elements[previousNumberIndex] > currentNumber)
		{
			m_elements[previousNumberIndex + 1] = m_elements[previousNumberIndex];
			previousNumberIndex--;
		}
		m_elements[previousNumberIndex + 1] = currentNumber;
	}
}

template<typename T, int S>
void Array<T, S>::heapsort(int count)
{
	for (int i = count / 2 - 1; i >= 0; i--)
	{
		heapTree(count, i);
	}

	for (int i = count - 1; i >= 0; i--)
	{
		swap(0, i);
		heapTree(i, 0);
	}
}

template<typename T, int S>
void Array<T, S>::quicksort(int beginingIndex, int endIndex)
{
	if (beginingIndex < endIndex)
	{
		int pivot = divide(beginingIndex, endIndex);
		quicksort(beginingIndex, pivot-1);
		quicksort(pivot + 1, endIndex);
	}
}

template<typename T, int S>
void Array<T, S>::mergesort(int beginingIndex, int endIndex)
{
	if (beginingIndex < endIndex)
	{
		int centreIndex = beginingIndex + (endIndex - beginingIndex) / 2;
		mergesort(beginingIndex, centreIndex);
		mergesort(centreIndex + 1, endIndex);
		sortAndMerge(beginingIndex, endIndex, centreIndex);
	}
}

template<typename T, int S>
void Array<T, S>::introsort(int beginingIndex, int endIndex, int breakpoint)
{
	int currentCount = endIndex - beginingIndex + 1;

	if (currentCount < 16)
	{
		insertsort(beginingIndex, endIndex);
		return;
	}

	if (breakpoint == 0)
	{
		std::make_heap(&m_elements[beginingIndex], &m_elements[endIndex]);
		std::sort_heap(&m_elements[beginingIndex], &m_elements[endIndex]);
		return;
	}

	int pivot = findPivot(beginingIndex, beginingIndex + currentCount / 2, endIndex);
	swap(&m_elements[pivot], &m_elements[endIndex]);

	int divideIndex = divide(beginingIndex, endIndex);
	introsort(beginingIndex, divideIndex-1, breakpoint - 1);
	introsort(divideIndex + 1, endIndex, breakpoint - 1);

	return;
}

template<typename T, int S>
bool Array<T, S>::check()const
{
	for (int i = 0; i < S - 1; i++)
	{
		if (m_elements[i] > m_elements[i+1] )
		{
			return false;
		}
	}
	return true;
}

template<typename T, int S>
void Array<T, S>::freeMemory()
{
	delete[] m_elements;
}


template<typename T, int S>
void Array<T, S>::print()const
{
	for (int i = 0; i < S; i++)
	{
		std::cout << m_elements[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T, int S>
Array<T, S>::~Array()
{
	delete[] m_elements;
}