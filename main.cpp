#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include<ctime>

using namespace std;

int partition (float a[],int l,int r)
{
    int pivot;
    pivot = a[r]; int temp = r;
    r--;
    while (true)
    {
        while (l<=r&&pivot>a[l])   l++;
        while (l<=r&&pivot<a[r])   r--;
        if (l>=r) break;
        swap (a[r],a[l]);
        l++;
        r--;
    }
    swap (a[l],a[temp]);
    return l;
}

int partition_giam (float a[],int l,int r)
{
    int pivot;
    pivot = a[r]; int temp = r;
    r--;
    while (true)
    {
        while (l<=r&&pivot<a[l])   l++;
        while (l<=r&&pivot>a[r])   r--;
        if (l>=r) break;
        swap (a[r],a[l]);
        l++;
        r--;
    }
    swap (a[l],a[temp]);
    return l;
}

void quicksort (float a[],int l,int r)
{
    if (l<r)
    {
        int k = partition (a,l,r);
        quicksort (a,l,k-1);
        quicksort (a,k+1,r);
    }
}

void quicksort_giam (float a[],int l,int r)
{
    if (l<r)
    {
        int k = partition (a,l,r);
        quicksort (a,l,k-1);
        quicksort (a,k+1,r);
    }
}

void heapify(float arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapsort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int Random (int a,int b)
{
    return a + rand()%(b-a+1);
}

float Random_sothuc (float a,float b)
{
    return a + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(b-a)));
}

void xuatmang(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n=1000000;
    clock_t start,end;
    float *a =new float [n];
    //so sánh tg chạy quicksort và heapsort với mảng số nguyên
    //mảng 1 bình thường
    cout<<"Mang so nguyen"<<endl<<"Mang 1"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=Random(1,1000);
    }
     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     double time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     double time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     double time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     double time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;



     //mảng 2 bình thường
     cout<<"Mang 2"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random(1,1000);
    }
     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 3 tăng dần
     cout<<"mang 3 tang dan"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random(1,1000);
    }
    quicksort(a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 4 giảm dần
     cout<<"mang 4 giam dan"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random(1,1000);
    }
    quicksort_giam (a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 5 các phần tử bằng nhau
     cout<<"mang 5 cac phan tu bang nhau"<<endl;
     int k= Random(1,1000);
     for(int i=0;i<n;i++)
    {
        a[i]= k;
    }
    quicksort_giam (a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;


    //so sánh tg chạy quicksort và heapsort với mảng số thực
    //mảng 1 bình thường
    cout<<endl<<"Mang so thuc"<<endl<<"Mang 1"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=Random_sothuc(1,1000);
    }
     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;


     //mảng 2 bình thường
     cout<<"Mang 2"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random_sothuc(1,1000);
    }
     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 3 tăng dần
     cout<<"mang 3 tang dan"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random_sothuc(1,1000);
    }
    quicksort(a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 4 giảm dần
     cout<<"mang 4 giam dan"<<endl;
     for(int i=0;i<n;i++)
    {
        a[i]=Random_sothuc(1,1000);
    }
    quicksort_giam (a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

     //mảng 5 các phần tử bằng nhau
     cout<<"mang 5 cac phan tu bang nhau"<<endl;
     int p = Random_sothuc(1,1000);
     for(int i=0;i<n;i++)
    {
        a[i]= k;
    }
    quicksort_giam (a,0,n-1);

     start = clock();
     quicksort(a,0,n-1);
     end= clock();
     time1 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"QUICKSORT "<<time1<<endl;
     quicksort (a,0,n-1);

     cout<<"Heap sort ";
     start = clock();
     heapsort(a,n);
     end= clock();
     time2 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<time2<<endl;

     start = clock();
     sort (a,a+n);
     end= clock();
     time3 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"sort C++ "<<time3<<endl;

     start = clock();
     qsort (a, n, sizeof(int), compare);
     end= clock();
     time4 = (double) (end-start) / CLOCKS_PER_SEC ;
     cout<<"Qsort "<<time4<<endl;

    return 0;
}
