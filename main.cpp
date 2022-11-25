#include <iostream>

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

void Merge(int input[], int start, int half, int end, int temp[])
{
	// 합친 것을 넣어줄 임시용 배열이 필요하다 (int temp[])
	// 이 임시용 배열의 생성을 위해 이전의 함수들에도 temp를 추가하자

	int i = start;								// 왼쪽의 index
	int j = half + 1;							// 오른쪽의 index
	int tempIndex{};

	while (i <= half && j <= end)				
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];		// 먼저 값을 저장해야하므로
												// 반드시 Postfix 사용
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	while (i <= half)							// 만일 i의 숫자가 남을 경우
	{
		temp[tempIndex++] = input[i++];
	}

	while (j <= end)							// 만일 j의 숫자가 남을 경우
	{
		temp[tempIndex++] = input[j++];
	}

	tempIndex = 0;								// 밑의 for문을 위해 다시 0 대입
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];			// 임시용 배열을  
	}											// 본 배열에 Merge(병합)
}												

void MergeSort(int input[], int start, int end, int temp[])
{
	// base case
	if (start >= end)			// start가 end보다 클 시, 배열의 크기 못구함
	{
		return;
	}

	//  recursive case
	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	Merge(input, start, half, end, temp);
}

// Ot = O (n * log n)  // MergeSort의 반으로 나누는 행위 * 2 = 2 * log n
					   // Merge = 28 ~ 49번줄 = n, for 문 = n   = 2n
					   
// Os = O (n)		   // input[n], temp[n]
 
int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };
	int temp[SIZE]{};
	MergeSort(array, 0, SIZE - 1, temp);
	PrintArray(array, SIZE);
}