// MergeSort (병합 정렬)
// 폰 노이만에 의해 정립된 정렬


// Divide의 수도코드
/* 
MergeSort(array, start, end)	//배열을 분할해서 쪼개야하므로..
{	
	// base case				// 가장 간단한 계산 = 원소가 1개일때
	if (start == end)
	{
		return;
	}
	
	// recursive case			// Divide
	int half = (start + end) / 2;
	
	MergeSort(array, start, half);
	MergeSort(array, half + 1, end);


	// 여기까지 왔다는 것 = 전부 divide된 상태
	// 그러니, 이제 병합(Merge)을 해야한다.
}
*/

// Merge의 수도코드
/*
Merge()
{
	while(합칠게 있으면)
	{
		왼쪽/오른쪽 중에서 작은 것 선택
	}

	남은 숫자 이어 붙이기					// 가령 2, 7, 8과 1, 3을 비교 시
}											// 1, 2, 3 배치 후
*/											// 남은 7, 8을 이어붙이기




