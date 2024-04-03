#include<iostream>
using namespace std;
#define N 10

// user defined function to print 2 day array with correct format
void print_arr (int arr[N][N], int n, int m)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()

{
    int n, m;
    cin >> n >> m;
    int arr[N][N];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }
    }

    int transpose[N][N];

	for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // insert arr[row][col] to transpose[col][row]
            transpose[j][i] = arr[i][j];
        }

    }
	print_arr(transpose, n, m);

return 0;
}