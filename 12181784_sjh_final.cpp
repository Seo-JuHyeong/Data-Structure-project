#include <iostream>
#include "final.h"
using namespace std;

typedef int Elem;
class QuickSort{
    public:
        /* TODO: Write prototypes of some necessary accessor and update functions */ 
        QuickSort(ArrayVector myV) {
            myData = myV;
            nElem = myData.size(); // elements의 counting을 위한 변수 nElem을 vector의 size()함수를 통해 초기화
        }

        void qsort(int left, int right); // 정렬을 위한 qsort 함수
        int partition(int left, int right); // 분할을 위한 partition 함수
        void display(); // at()함수를 사용하여 value값 출력을 위한 함수
    
    private:
        int nElem; // counting the number of elements
        ArrayVector myData; // Your own class of your favorite data structure among lists, vectors, sequences
};

/* TODO: Define some necessary accessor and update functions */
void QuickSort::qsort(int left, int right){
    /* TODO: Complete the function definition */
    // Refer to the code fragment 11.6 (In-place quick-sort) in the textbook
    if (left < right) { // 원소가 1개 혹은 없는 경우를 거르기 위한 if문
        display(); // vector에 저장된 vlaue 값 출력 함수
        int p = partition(left, right); // partition 함수를 통해 분할을 하고 피벗의 index값을 구하여 p에 대입  
        qsort(left, p-1); // 피벗을 기준으로 왼쪽 값들에 대하여 QuickSort정렬 (재귀)
        qsort(p+1, right); // 피벗을 기준으로 오른쪽 값들에 대하여 QuickSort정렬 (재귀)
    }
}

int QuickSort::partition(int left, int right){
    /* TODO: Complete the function definition */    
    Elem pivot = myData.operator[](left); //피벗의 value 값을 left index의 value 값으로 설정
    int f = left; // 피벗의 index를 저장하기 위한 변수 f 선언
	Elem temp; // swap을 위한 변수 선언

	++left; // left 값을 피벗으로 설정하기 때문에 left+1번 째 index 부터 탐색을 시작하기 위함.

	while (left <= right) // right의 index값이 left보다 낮을때까지 즉, index가 교차될 때까지
	{
		while (myData.operator[](left) <= pivot && left < right) // left의 value값이 pivot의 value값 보다 커질 때까지 반복
		{
			++left; // left의 index값을 오른쪽으로 한칸 옮긴다.
		}

		while (myData.operator[](right) > pivot && left <= right) // right의 value값이 pivot의 value값 보다 작아질 때까지 반복
		{
			--right; // right의 index값을 왼쪽으로 한칸 옮긴다.
		}

		if (left < right)	// 앞선 while문을 통해 옮겨진 left와 right의 index값이 right가 더 클 경우 두 value 값을 swap
		{
			temp = myData.operator[](left);
			myData.set(left,myData.operator[](right)); 
			myData.set(right,temp);
		}
		else	// left >= right 즉, left와 right가 교차한 경우
			break; // while문 탈출
	}
    // 맨 왼쪽 index에 있는 피벗 vlaue 값과 right index에 있는 value 값을 swap 즉, right index에 피벗 value가 들어가므로 right index가 피벗 index가 된다.
	temp = myData.operator[](f);
	myData.set(f,myData.operator[](right));
	myData.set(right,temp);

	return right; // 피벗 index값을 return -> 이후 재귀 함수에 이용
}

void QuickSort::display(){
    /* TODO: Complete the function definition */
    // Print all elements in myData
    for (int i = 0; i < nElem; i++) { // vector에 저장된 원소의 수 만큼 반복 
        myData.at(i); // at을 사용하여 value 값 출력
    }
    cout << endl;
}

int main(){    
    ArrayVector myV;
    
    int n = 0;
    Elem a;
    
    cout << "How many elements do you want to sort?: ";
    cin >> n;

    cout << "Enter " << n << " elements to sort: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        myV.insert(i,a);
    }
    cout << "Start sorting" << endl;

    QuickSort myQsort(myV);
    myQsort.qsort(0, n-1);
    myQsort.display();
    
    cout << "Done sorting" << endl;

    return 0;
}