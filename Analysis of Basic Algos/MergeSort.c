#include<stdio.h> 
#include<malloc.h> 
#include <time.h> 
#define size 10000 

int a[size]; 
void merge(int left, int mid, int right)  
{ 
    int b[size]; 
    int i = left; 
    int j = mid + 1; 
    int k = left; 
    while(i <= mid && j <= right)  
	{ 
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
	} 
    while(i <= mid) 
	{ 
        b[k++] = a[i++]; 
	} 
    while(j <= right) 
	{ 
        b[k++] = a[j++]; 
	} 
    for(i = left; i <= right; i++) 
	{ 
        a[i] = b[i]; 
	} 
} 
void mergeSort(int left, int right)  
{ 
    int mid = (left + right) / 2; 
    if(left < right) { 
        mergeSort(left, mid); 
        mergeSort(mid + 1, right); 
        merge(left, mid, right); 
	} 
} 
 
void descbubblesort() 
{ 
    int temp; 
    for (int i = 0; i < size - 1; i++) 
	{
        for (int j = 0; j < size - i - 1; j++) 
    	{ 
            if (a[j] < a[j + 1]) 
        	{ 
            	temp = a[j]; 
                a[j] = a[j + 1]; 
                a[j + 1] = temp; 
        	} 
    	} 
	} 
} 
int main()  
{ 
    int i; 
    clock_t start,end; 
    double timetaken; 
    for(i = 0; i < size; i++) 
	{ 
        a[i]=rand(); 
	}
	start=clock(); 
    mergeSort(0, size - 1); 
	end=clock();
    timetaken=((double)(end-start))/CLOCKS_PER_SEC; 
    printf("\n%.7f ms for average case",timetaken); 
	
    start=clock(); 
    mergeSort(0, size - 1); 
    end=clock(); 
    timetaken=((double)(end-start))/CLOCKS_PER_SEC; 
    printf("\n%.7f ms for best case",timetaken); 
    
    descbubblesort(); 
	start=clock(); 
    mergeSort(0, size - 1); 
	end=clock(); 
    timetaken=((double)(end-start))/CLOCKS_PER_SEC; 
    printf("\n%.7f ms for worst case",timetaken); 
}
