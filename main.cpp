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
	// ��ģ ���� �־��� �ӽÿ� �迭�� �ʿ��ϴ� (int temp[])
	// �� �ӽÿ� �迭�� ������ ���� ������ �Լ��鿡�� temp�� �߰�����

	int i = start;								// ������ index
	int j = half + 1;							// �������� index
	int tempIndex{};

	while (i <= half && j <= end)				
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];		// ���� ���� �����ؾ��ϹǷ�
												// �ݵ�� Postfix ���
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	while (i <= half)							// ���� i�� ���ڰ� ���� ���
	{
		temp[tempIndex++] = input[i++];
	}

	while (j <= end)							// ���� j�� ���ڰ� ���� ���
	{
		temp[tempIndex++] = input[j++];
	}

	tempIndex = 0;								// ���� for���� ���� �ٽ� 0 ����
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];			// �ӽÿ� �迭��  
	}											// �� �迭�� Merge(����)
}												

void MergeSort(int input[], int start, int end, int temp[])
{
	// base case
	if (start >= end)			// start�� end���� Ŭ ��, �迭�� ũ�� ������
	{
		return;
	}

	//  recursive case
	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	Merge(input, start, half, end, temp);
}

// Ot = O (n * log n)  // MergeSort�� ������ ������ ���� * 2 = 2 * log n
					   // Merge = 28 ~ 49���� = n, for �� = n   = 2n
					   
// Os = O (n)		   // input[n], temp[n]
 
int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };
	int temp[SIZE]{};
	MergeSort(array, 0, SIZE - 1, temp);
	PrintArray(array, SIZE);
}