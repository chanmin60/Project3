#include <iostream>
using namespace std;

template <typename T>     //템플릿을 사용해서 데이터 타입에 구애받지 않는 클래스나 함수들을 작성
class SimpleVector {      //클래스 이름은 Simple Vector
private:
	T* data;
	int currentSize;      //현재 원소의 개수
	int currentCapacity;  //배열의 크기      동적 배열일 때 원소의 개수와 배열의 크기는 달라질 수 있음

public:
	SimpleVector() :currentSize(0), currentCapacity(10) { //멤버 변수 초기화
		data = new T[currentCapacity]; //T 타입의 크기가 10인 배열을 동적 할당
	}
	//숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
	SimpleVector(int Capacity) : currentSize(0), currentCapacity(Capacity) {
		data = new T[currentCapacity];
	}

	~SimpleVector() {
		delete[] data;   // 동적 할당된 메모리 해제
	}

	// 배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다
	void push_back(const T& value) { //push_back  인자로 받은 원소를  맨 뒤에 추가 합니다. 반환값 없이. 
		if (currentSize < currentCapacity) { //현재 원소 개수가 배열의 크기보다 작으면
			data[currentSize++] = value;
			//현재 배열의 크기에 1을 더해서 새로운 원소 하나를 추가하고 
			//새로 추가된 원소를 value에 저장
		}
	}

	void pop_back() {
		if (currentSize > 0) { //원소가 존재하기만 한다면 = 사라질 원소가 1개라도 있다면
			currentSize--; //벡터의 마지막 원소 제거
			//그냥 삭제만 하면 되기 때문에 push_back처럼 원소가 저장될 value 작성도 필요 없음
		}
	}

	//size는 인자가 없고 현재 원소의 개수를 반환합니다.
	int size() const {
		return currentSize;
	}

	//capacity는 현재 내부 배열의 크기를 반환합니다.
	int capacity() const {
		return currentCapacity;
	}

};