#include <stdio.h>
#include <string.h>
#include <math.h>

#define cin(type, val) fscanf(input, type, &val)
#define cout(type, val) fprintf(output, type, val)
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)

#pragma region Search

int linearSearch(int A[], int a, int n)
{
    rep(i, n)
    {
        if (A[i] == n)
            return i;
    }
    return -1;
}
int binarySearch(int A[], int l, int u, int n)
{
    if (l > u)
        return -1;
    int mi = ((u - l) / 2) + l;
    int mid = A[mi];
    if (mid == n)
        return mi;
    else if (mid > n)
        return binarySearch(A, l, mi - 1, n);
    else
        return binarySearch(A, mi + 1, u, n);
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
int jumpSearch(int A[], int l, int u, int n)
{
    int root = sqrt(u - l);
    int step = l;
    while (A[step] <= n && step <= u)
    {
        if (A[step] == n)
            return step;
        if (A[step + root] > n)
            return step + linearSearch(A + step, root, n);
        step += root;
    }
    return -1;
}
int exponentialSearch(int A[], int n)
{
    if (A[0] == n)
        return 0;
    int i = 1;
    while (A[i] < n)
        i *= 2;
    return binarySearch(A, i / 2, i, n);
}

#pragma endregion

#pragma region Sort

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

void MagicSquares(int n)
{
    int A[10][10] = {0};
    int N = n * n;
    int r = 0;
    int c = n / 2;
    for (int i = 1; i <= N; i++)
    {
        if (A[r][c] != 0)
        {
            r += 2;
            c -= 1;
            if (r >= n)
                r = 1;
            if (c < 0)
                c = n - 1;
            A[r][c] = i;
        }
        else
            A[r][c] = i;

        r = r - 1 < 0 ? r + n - 1 : r - 1;
        c = c + 1 >= n ? 0 : c + 1;
    }
    rep(i, n)
    {
        rep(j, n)
        {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
}

void column(int A[][10], int n, int m, int r, int c, int d);
void Row(int A[][10], int n, int m, int r, int c, int d)
{
    int x = 0;
    for (int i = r; i <= n - 1; i += d)
    {
        if (A[i][c] == -1)
        {
            if (!x)
                return;
            r = i;
            break;
        }
        printf("%d ", A[i][c]);
        A[i][c] = -1;
        x++;
    }
    d *= -1;
    column(A, n, m, r, c, d);
}
void column(int A[][10], int n, int m, int r, int c, int d)
{
    int x = 0;
    for (int i = c; i <= m - 1; i += d)
    {
        if (A[r][i] == -1)
        {
            if (!x)
                return;
            break;
        }
        printf("%d ", A[r][i]);
        A[r][i] = -1;
        x++;
    }
    d *= -1;
    Row(A, n, m, r, c, d);
}
void SpiralMatrix(int A[][10], int n, int m)
{
    column(A, n, m, 0, 0, 1);
}

#pragma endregion


int AddressVerification1D()
{
    int n;
    scanf("%d", &n);
    int A[10] = {0};
    rep(i, n)
        scanf("%d", &A[i]);
    
    rep(a, n)
    {
        int * x = (A + (a - 1) * sizeof(A[1]));
        printf("%d   %d\n", &A[a], x);
        if (&A[a] != x)
        {
            //printf("%d %d", A[a], *(A + (a - 1) * sizeof(A[0])));
            //printf("No\n");
            return -1;
        }
    }
    printf("Yes\n");
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    AddressVerification1D();

    return 0;
}