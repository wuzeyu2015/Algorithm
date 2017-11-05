#ifndef INSERTION_H
#define INSERTION_H



void InsertionSort(int arr[], int n);
void __portionInsertionSort(int arr[], int l, int r);

/////////////////////////////////////////////////////////


void __portionInsertionSort(int arr[], int l, int r){

	for( int i = l + 1 ; i <= r ; i ++ ) {
		int e = arr[i];
		int j = 0;
		//��j����[j, i]�ڲ�ѭ����j����iӦ�ò����λ�ã��ڴ�֮ǰ����e����i��ֵ
		for (j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	return;
}
void InsertionSort(int arr[], int n){

	for( int i = 1 ; i < n ; i ++ ) {
		int e = arr[i];
		int j = 0;
		//��j����[0, i]�ڲ�ѭ����j����iӦ�ò����λ�ã��ڴ�֮ǰ����e����i��ֵ
		for (j = i; j > 0 && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	return;
}


#endif //INSERTION_H
