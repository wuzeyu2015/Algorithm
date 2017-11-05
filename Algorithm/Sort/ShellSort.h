#ifndef SHELLSORT_H
#define SHELLSORT_H


void ShellSort(int arr[], int n);

/////////////////////////////////////////////////////////

void ShellSort(int arr[], int n){
	int h = 1;
	while(h < n/3) h = 3*h + 1;
	while(h >= 1)
	{
		//��i����[h, n)ÿһ��Ԫ�أ�����Ҳ�ͽ���ر��������еķ���
		for( int i = h ; i < n ; i ++ ) {
			//��[0, i]��Χ�ڣ���j����i���Ԫ�����ڵķ��飬���ʼ��Ϊh����arr[i]����arr[i - h]��arr[i - 2*h]��arr[i - 3*h]���ʵ�λ��
			for (int j = i; j >= h && arr[j - h] > arr[j]; j -= h)
			{
				swap(arr[j], arr[j-h]);	
			}
		}
		h = h / 3;
	}

	return;
}
#endif //SHELLSORT_H
