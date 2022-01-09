#ifndef FINAL_H
#define FINAL_H

#include <iostream>
using namespace std;

#define throw(...)

typedef int Elem; // 기본 원소 타입
class ArrayVector {
public:
    ArrayVector(); // 생성자
    int size() const; // 원소의 수
    bool empty() const; // 벡터가 비었는가?
    Elem& operator[](int i); // 인덱스에 있는 원소
    Elem& at(int i) throw(IndexOutOfBounds); // 인덱스에 있는 원소
    void set(int i, const Elem& e) throw(IndexOutOfBounds);
    void erase(int i); // 인덱스에 있는 원소 삭제
    void insert(int i, const Elem& e); // 인덱스에 있는 원소 삽입
    void insertDoubling(); // N개의 자리 확보
    
private:
    int capacity; // 배열의 크기
    int n; // 벡터에 저장된 원소들의 수
    Elem* A; // 원소를 저장하는 배열
};

ArrayVector::ArrayVector() // 생성자
    : capacity(0), n(0), A(NULL) { }

int ArrayVector::size() const // 원소들의 개수
{ 
    return n; 
}

bool ArrayVector::empty() const // 벡터가 비었나?
{ 
    return size() == 0; 
}

Elem& ArrayVector::operator[](int i) // 인덱스의 원소
{ 
    return A[i]; 
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) { // 인덱스의 원소 (+예외처리)
    if (i < 0 || i >= n)
       throw out_of_range("illegal index in function at()");
    cout << A[i] << " ";
    return A[i];
}

void ArrayVector::set(int i,const Elem& e) throw(IndexOutOfBounds) { // 인덱스의 원소 (+예외처리)
    if (i < 0 || i >= n)
       throw out_of_range("illegal index in function at()");
    A[i] = e;
}

void ArrayVector::erase(int i) { // 인덱스의 원소 삭제
    for (int j = i+1; j < n; j++) // 원소들을 앞으로 이동
        A[j - 1] = A[j];
    n--; // 원소 개수 1 감소
}

void ArrayVector::insertDoubling() { // N개의 자리를 확보
    int N = max(1, 2 * capacity);
    if (capacity >= N) return; // 이미 충분히 크다
    Elem* B = new Elem[N]; // 더 큰 배열을 할당
    for (int j = 0; j < n; j++) // 내용을 새 배열로 복사
        B[j] = A[j];
    if (A != NULL) delete [] A; // 기존의 배열을 삭제
    A = B; // B를 새 배열로 만든다.
    capacity = N; // 새 용량을 설정
}

void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity) // 오버플로우?
        insertDoubling(); // 배열 크기를 두 배로
    for (int j = n - 1; j >= i; j--) // 원소들을 뒤로 이동
       A[j+1] = A[j];
    A[i] = e; // 빈자리에 삽입
    n++; // 원소 개수 1 증가
}

#endif