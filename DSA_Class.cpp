/* CODER       : Dhruv Bansal   */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep1(i, n) for (ll i = 1; i <= (n); i++)

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

#pragma region Day 1

void traversing(int A[], int n)
{
    rep(i, n)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}

void insert(int A[], int l, int i, int n)
{
    for (int x = l; x != i; x--)
    {
        A[x] = A[x - 1];
    }
    A[i] = n;
}

void insertInSortedArray(int A[], int l, int n)
{
    int x;
    for (x = l; x >= 0 && A[x] > n; x--)
    {
        A[x] = A[x - 1];
    }
    A[x + 1] = n;
}

void deletion(int A[], int l, int n)
{
    int f = 0;
    int x;
    rep(i, l)
    {
        if (A[i] == n)
            f = 1;
        if (f)
        {
            A[i] = A[i + 1];
        }
    }
}

int MissingNo(int A[], int l)
{
    int m, t1 = 0, t2 = 0;
    rep(i, l)
    {
        t1 += A[i];
        t2 += i + 1;
    }
    m = t1 - t2;
    cout << m << "\n";
}

void reversal(int A[], int B[], int n)
{
    rep(i, n)
    {
        B[i] = A[n - i - 1];
    }
}

void RepeatedAndNonRepeated(int A[], int l, int Rep[], int NRep[])
{
    map<int, int> m;
    int x, y;
    x = y = 0;
    rep(i, l)
    {
        auto x = m.find(A[i]);
        if (x == m.end())
            m[A[i]] = 0;
        else
            m[A[i]] += 1;
    }
    for (auto i : m)
    {
        if (i.second)
        {
            Rep[x] = i.first;
            x++;
        }
        else
        {
            NRep[y] = i.first;
            y++;
        }
    }
}

#pragma endregion

#pragma region Day 2

void mergeSortedArrays(int *a, int m, int *b, int n)
{
    int i = 0, j = 0, k = 0;
    int c[m + n];
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else if (b[j] < a[i])
            c[k++] = b[j++];
        else
        {
            c[k++] = a[i++];
            c[k++] = b[j++];
        }
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
    rep(j, m + n)
            cout
        << c[i] << " ";
}

void mergeSet(int *a, int m, int *b, int n)
{
    int i = 0, j = 0, k = 0;
    int c[m + n];
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else if (b[j] < a[i])
            c[k++] = b[j++];
        else
        {
            c[k++] = a[i++];
            j++;
        }
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
}

void intersect(int *a, int m, int *b, int n)
{
    int i = 0, j = 0, k = 0;
    int c[m + n];
    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            c[k++] = a[i++];
            j++;
        }
        else if (b[j] < a[i])
            j++;
        else
            i++;
    }
}
void SetDiff(int arr[], int brr[], int n, int m)
{
    vector<int> diff;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (arr[i] == brr[j])
            i++;
        else if (arr[i] < brr[j])
            diff.push_back(arr[i++]);

        else
            diff.push_back(brr[j++]);
    }
    while (i < n)
        diff.push_back(arr[i++]);
    while (j < m)
        diff.push_back(brr[j++]);

    cout << "the symmetric diffference of entered arrays is:\n";
    cout << "{";
    for (auto it : diff)
        cout << " " << it << " ";
    cout << " }";
}

vector<int> findUnion(int arr1[], int arr2[], int n1, int n2)
{

    int i = 0, j = 0;
    vector<int> ans;
    while (i < n1 and j < n2)

    {
        if (i > 0 and arr1[i] <= arr2[j] and arr1[i] == arr1[i - 1])
            i++;
        else if (j > 0 and arr2[j] < arr1[i] and arr2[j] == arr2[j - 1])
            j++;
        else if (arr1[i] > arr2[j])
            ans.push_back(arr2[j]), j++;
        else if (arr1[i] < arr2[j])
            ans.push_back(arr1[i]), i++;
        else if (arr1[i] == arr2[j])
            ans.push_back(arr1[i]), i++, j++;
    }
    while (i < n1)
    {
        if (i > 0 and arr1[i] == arr1[i - 1])
            i++;
        else
            ans.push_back(arr1[i]), i++;
    }
    while (j < n2)
    {
        if (j > 0 and arr2[j] == arr2[j - 1])
            j++;
        else
            ans.push_back(arr2[j]), j++;
    }
    return ans;
}

#pragma endregion

#pragma region Day 3

void LargestInMatrix()
{
    int n, m, t;
    cin >> n >> m;
    int largest = -1000;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> t;
            if (largest < t)
                largest = t;
        }
    }
    cout << largest << "\n";
}

void MatrixAddition()
{
    int n, m, t;
    cin >> n >> m;
    int M1[n][m];
    rep(i, n)
            rep(j, m)
                cin >>
        M1[i][j];
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> t;
            cout << M1[i][j] + t << " ";
        }
        cout << "\n";
    }
}

void MatrixSubtraction()
{
    int n, m;
    cin >> n >> m;
    int M1[n][m];
    int M2[n][m];
    rep(i, n)
            rep(j, m)
                cin >>
        M1[i][j];
    rep(i, n)
            rep(j, m)
                cin >>
        M2[i][j];
    rep(i, n)
    {
        rep(j, m)
        {
            cout << M1[i][j] - M2[i][j] << " ";
        }
        cout << "\n";
    }
}

void MatrixMultiply()
{
    int n;
    cin >> n;
    int M1[n][n];
    int M2[n][n];
    rep(i, n)
            rep(j, n)
                cin >>
        M1[i][j];
    rep(i, n)
            rep(j, n)
                cin >>
        M2[i][j];
    rep(i, n)
    {
        int x = 0;
        rep(j, n)
        {
            rep(k, n)
                x += M1[i][k] * M2[k][j];
            cout << x << " ";
        }
        cout << "\n";
    }
}

void Transpose()
{
    int n, m;
    cin >> n >> m;
    int M1[n][m];
    rep(i, n)
            rep(j, m)
                cin >>
        M1[i][j];

    rep(i, n)
    {
        rep(j, n)
        {
            cout << M1[j][i] << " ";
        }
        cout << "\n";
    }
}

void Determinant()
{
    int n;
    cin >> n;
    float M1[n][n];
    rep(i, n)
            rep(j, n)
                cin >>
        M1[i][j];

    rep1(i, n)
    {
        float x = M1[i][i];
        float y = M1[i - 1][i - 1];
        for (int j = 0; j < n; j++)
        {
            M1[i][j] -= M1[i][j] * y / x;
        }
    }
    cout << "\n";
    rep(i, n)
    {
        rep(j, n)
        {
            cout << M1[j][i] << " ";
        }
        cout << "\n";
    }

    int ans = 0;
    rep(i, n) ans *= M1[i][i];
    cout << ans << "\n";
}

#pragma endregion

#pragma region Day 4

int linearSearch(int arr[], int lo, int hi, int x)
{
    for (int i = lo; i < hi; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int BinarySearchIterative(int arr[], int l, int h, int ele)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == ele)
            return mid;
        if (arr[mid] < ele)
            l = mid + 1;
        else if (arr[mid] > ele)
            h = mid - 1;
    }
    return -1;
}

int BinarySearchRecursive(int arr[], int l, int h, int ele)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == ele)
        return mid;
    else if (arr[mid] > ele)
        return BinarySearchIterative(arr, l, mid - 1, ele);
    else if (arr[mid] < ele)
        return BinarySearchIterative(arr, mid + 1, h, ele);
    return -1;
}

int interpolate(int arr[], int lo, int hi, int x)
{
    int pos;

    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {

        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        // found the x
        if (arr[pos] == x)
            return pos;

        // binary search
        if (arr[pos] < x)
            return interpolate(arr, pos + 1, hi, x);
        if (arr[pos] > x)
            return interpolate(arr, lo, pos - 1, x);
    }
    return -1;
}

int jumpSearch(int arr[], int n, int x)
{
    int fact = sqrt(n);
    int jump = sqrt(n);
    int lo = 0;
    while (jump <= n)
    {
        if (arr[lo] <= x && arr[jump] >= x)
            return linearSearch(arr, lo, jump, x);
        else
        {
            lo = jump;
            jump += fact;
        }
    }
    return -1;
}

int ternarySearch(int A[], int l, int u, int n)
{
    if (l > u)
        return -1;
    int m1 = l + (u - l) / 3;
    int m2 = u - (u - l) / 3;
    if (A[m1] == n)
        return m1;
    if (A[m2] == n)
        return m2;
    if (n < A[m1])
        return ternarySearch(A, l, m1 - 1, n);
    else if (n > A[m2])
        return ternarySearch(A, m2 + 1, u, n);
    else
        return ternarySearch(A, m1, m2, n);
}

#pragma endregion

#pragma region Day 5

int serBin(int arr[], int lo, int hi, int x)
{
    if (lo > hi)
        return -1;
    int mid = (lo + hi) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
        return serBin(arr, lo, hi - 1, x);
    return serBin(arr, mid + 1, hi, x);
}

int fact(int n, int ans = 1)
{
    if (n == 1)
        return ans;
    return fact(n - 1, ans * n);
}

long long int dat[101];

long long int fib(int n)
{
    if (n == 1 || n == 2)
        return dat[n] = n - 1;
    else
    {
        if (dat[n] == 0)
            dat[n] = fib(n - 1) + fib(n - 2);
    }
    return dat[n];
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

bool is_palindrome(string s, int lo, int hi)
{
    if (s[lo] != s[hi])
        return false;
    if (lo < hi)
    {
        is_palindrome(s, lo + 1, hi - 1);
    }
    return true;
}

long long power(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n >= 1;
    }
    return res;
}

int rev(int n, int ans = 0)
{
    return n == 0 ? ans : rev(n / 10, ans * 10 + n % 10);
}

int sumOfdg(int n, int ans = 0)
{
    return n == 0 ? ans : sumOfdg(n / 10, ans + n % 10);
}

int tower(int n, string beg = " Rod 1 ", string aux = " Rod 2 ", string dest = " Rod 3 ")
{
    static int cnt = 0;
    if (n > 0)
    {
        tower(n - 1, beg, dest, aux);
        cout << "Move disk " << n << " from" << beg << "to" << dest << "\n";
        cnt++;
        tower(n - 1, aux, beg, dest);
    }

    return cnt;
}

#pragma endregion

#pragma region Day 6

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

void CountingSort(int A[], int a)
{
    int B[10];
    int max = A[0];
    rep(i, a) if (A[i] > max) max = A[i];

    int C[10] = {0};
    rep(i, a) C[A[i]]++;
    rep1(i, 10) C[i] += C[i - 1];
    for (int i = a - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    A = B;
    rep1(i, a) printf("%d  ", B[i]);
}

void sort_insert(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void RadixSort(int A[][2], int a, int r)
{
    int B[10];
    int max = A[0][1];
    rep(i, a) if (A[i][1] > max) max = A[i][1];

    int C[10] = {0};
    rep(i, a) C[A[i][1]]++;
    rep1(i, 10) C[i] += C[i - 1];
    for (int i = a - 1; i >= 0; i--)
    {
        B[C[A[i][1]] - 1] = A[i][0];
        C[A[i][1]]--;
    }
    rep(i, a) printf("%d ", B[i]);
}

void mergeArr(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
        a[i] = arr[i + l];
    for (int i = 0; i < n2; i++)
        b[i] = arr[m + 1 + i];

    int p = 0, q = 0, r = l;
    while (p < n1 && q < n2)
    {
        if (a[p] < b[q])
            arr[r++] = a[p++];
        else
            arr[r++] = b[q++];
    }
    while (p < n1)
        arr[r++] = a[p++];
    while (q < n2)
        arr[r++] = b[q++];
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    { // if(l==h) return
        int m = (l + h) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);
        mergeArr(arr, l, m, h);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minInd] > arr[j])
                minInd = j;
        }
        swap(arr[i], arr[minInd]);
    }
}

#pragma endregion

void anagram(string a, int l, string b, int m)
{
    if (l != m)
    {
        cout << "No\n";
    }
    int chars[25] = {0};
    rep(i, l)
    {
        chars[a[i]] += 1;
        chars[b[i]] -= 1;
    }
    rep(i, l)
    {
        if (chars[i] != 0)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

void LinearProbing()
{
    ll l, a, b;
    cin >> l;
    ll ans[l * 2] = {0};
    rep(n, l)
    {
        cin >> a >> b;
        while (ans[a])
            a++;
        ans[a] = b;
    }
    rep(n, l * 2)
    {
        if (ans[n])
            cout << n << " => " << ans[n] << endl;
    }
}

void QuadraticProbing()
{
    ll l, a, b;
    cin >> l;
    ll ans[l] = {0};
    rep(n, l)
    {
        cin >> a >> b;
        while (ans[a])
        {
            a = (a + 1 >= l) ? 1 : a + 1;
        }
        ans[a] = b;
    }
    rep(n, l * 2)
    {
        if (ans[n])
            cout << n << " => " << ans[n] << endl;
    }
}

void Hashing()
{
    int l, m;
    cin >> l >> m;
    ll ans[l][10] = {0};
    ll t;
    rep(i, l)
    {
        cin >> t;
        int x = t % m;
        int y = 0;
        while (ans[x][y])
        {
            y++;
        }
        ans[x][y] = t;
    }
    rep(i, m)
    {
        cout << i << " => ";
        int y = 0;
        while (ans[i][y])
        {
            cout << ans[i][y] << " , ";
            y++;
        }
        cout << "\n";
    }
}

#pragma endregion

// ##############################################################################

//        M A I N ( )

// ##############################################################################

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int A[10];
}
