// MergeSort (���� ����)
// �� ���̸��� ���� ������ ����


// Divide�� �����ڵ�
/* 
MergeSort(array, start, end)	//�迭�� �����ؼ� �ɰ����ϹǷ�..
{	
	// base case				// ���� ������ ��� = ���Ұ� 1���϶�
	if (start == end)
	{
		return;
	}
	
	// recursive case			// Divide
	int half = (start + end) / 2;
	
	MergeSort(array, start, half);
	MergeSort(array, half + 1, end);


	// ������� �Դٴ� �� = ���� divide�� ����
	// �׷���, ���� ����(Merge)�� �ؾ��Ѵ�.
}
*/

// Merge�� �����ڵ�
/*
Merge()
{
	while(��ĥ�� ������)
	{
		����/������ �߿��� ���� �� ����
	}

	���� ���� �̾� ���̱�					// ���� 2, 7, 8�� 1, 3�� �� ��
}											// 1, 2, 3 ��ġ ��
*/											// ���� 7, 8�� �̾���̱�




