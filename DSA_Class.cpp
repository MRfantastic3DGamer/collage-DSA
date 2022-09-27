/* CODER       : Dhruv Bansal   */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep1(i, n) for (ll i = 1; i <= (n); i++)

// ##############################################################################

//        D A Y : 1

// ##############################################################################

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

// ##############################################################################

//        D A Y : 2

// ##############################################################################

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

// ##############################################################################

//        D A Y : 3

// ##############################################################################

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

// TODO : ____________________
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


// ##############################################################################

//        D A Y : 4

// ##############################################################################


int linearSearch(int A[], int l, int n){
    rep(i,l)
        if(A[i] == n) {
            cout << i;
            return i;
        }
    return -1;
}

int binarySearch(int A[], int s, int e, int n){
    
}

void anagram(string a, int l, string b, int m){
    if(l != m){
        cout << "No\n";
    }
    int chars[25] = {0};
    rep(i,l){
        chars[a[i]] += 1;
        chars[b[i]] -= 1;
    }
    rep(i,l){
        if(chars[i] != 0){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}


// ##############################################################################

//        M A I N ( )

// ##############################################################################


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int Arr[10];
    linearSearch(Arr,10,4);

}