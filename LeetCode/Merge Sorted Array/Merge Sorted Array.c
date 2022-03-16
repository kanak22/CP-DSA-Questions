void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    for (int i=0; i<n; ++i) //merging 2 arrays
      nums1[m+i] = nums2[i];
    int i,key,j;
    for (i=1; i<m+n; i++) // insertion sort
    {
        key= nums1[i];
        j= i-1;
        while (j>=0 && nums1[j]>key) //Move elements of the array, that are greater than key, to one position ahead of their current position
        {
            nums1[j+1]= nums1[j]; 
            j= j-1;
        }
        nums1[j+1]= key;
    }
}
