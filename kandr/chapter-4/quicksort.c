//Thu 03 Sep 2020 07:18:31 AM AWST
//qsort: sort v[left]...v[right] int increasing order
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) /*do nothing if array contains fewer than two elements*/
        return;
    swap(v, left, (left + right) / 2); //move partition element
    last = left;                       //to v[0]
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);               // restore partition element
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
