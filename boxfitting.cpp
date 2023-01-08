#include<iostream>
using namespace std;

char task1(int pack_height , int pack_width , int pack_length , int box_height , int box_width , int box_length)
{
    // Your Code for task 1 starts here
        char ans;

    if(pack_height <= 0 || pack_width <= 0 || pack_length <= 0 || box_height <= 0 || box_height <= 0 || box_height <= 0)

        ans = 'n';

    else if(box_height % pack_height == 0 && box_length % pack_length == 0 && box_width % pack_width == 0)

        ans = 'y';

    else if(box_height % pack_height == 0 && box_length % pack_width == 0 && box_width % pack_length == 0)

        ans = 'y';

    else if(box_height % pack_width == 0 && box_length % pack_length == 0 && box_width % pack_height == 0)

        ans = 'y';

    else if(box_height % pack_width == 0 && box_length % pack_height == 0 && box_width % pack_length == 0)

        ans = 'y';

    else if(box_height % pack_length == 0 && box_length % pack_height == 0 && box_width % pack_width == 0)

        ans = 'y';

    else if(box_height % pack_length == 0 && box_length % pack_width == 0 && box_width % pack_height == 0)

        ans = 'y';

    else

        ans = 'n';

    return ans;
        
      

    
    // Your Code for task 1 ends here
}

int task2(int pack_height , int pack_width , int pack_length , int box_height , int box_width , int box_length)
{
    // Your Code for task 2 starts here
    int boxSize,packSize,V;
    int result;
    boxSize=box_height*box_width*box_length;
   packSize=pack_height*pack_width*pack_length;
      if (boxSize>0 && packSize>0 && boxSize % packSize==0)
      {V=boxSize / packSize;
       
       result= V; } 
       else { result=0;}
    
    

    return result;

    
    // Your Code for task 2 ends here
}

void test1(int arr[][7] , int size)
{
    cout << "\n\nTask 1 Results\n\n";
    int passed = 0;
    int failed = 0;
    char val;
    for(int i = 0 ; i < size ; i++)
    {
        val = task1(arr[i][0] ,arr[i][1] , arr[i][2] , arr[i][3] , arr[i][4] , arr[i][5]);
        if((val == 'y' && arr[i][6] == 1) || (val == 'n' && arr[i][6] == 0))
            passed++;
        else
        {
            failed++;
            cout << "Test Failed" << endl;
            cout << "Pack Height =" << arr[i][0] << "\tPack Width =" << arr[i][1] << "\tPack Length =" << arr[i][2] << endl;
            cout << "Box Height = " << arr[i][3] << "\tBox Width = " << arr[i][4] << "\tBox Length = " << arr[i][5] << endl;
            if(arr[i][6])
            {
                cout << "Expected = " << 'y' << endl;
                cout << "Result = " << 'n';
            }
            else
            {
                    cout << "Expected = " << 'n' << endl;
                    cout << "Result = " << 'y';
            }
            cout << "\n\n";
        }
    }
    cout << "\n\n";
    cout << "Total Passed: " << passed << endl;
    cout << "Total Failed: " << failed;
    cout << "\n\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
}

void test2(int arr[][7] , int size)
{
    cout << "\n\nTask 2 Results\n\n";
    int passed = 0;
    int failed = 0;
    int val;
    for(int i = 0 ; i < size ; i++)
    {
        val = task2(arr[i][0] ,arr[i][1] , arr[i][2] , arr[i][3] , arr[i][4] , arr[i][5]);
        if(val == arr[i][6])
            passed++;
        else
        {
            failed++;
            cout << "Test Failed" << endl;
            cout << "Pack Height =" << arr[i][0] << "\tPack Width =" << arr[i][1] << "\tPack Length =" << arr[i][2] << endl;
            cout << "Box Height = " << arr[i][3] << "\tBox Width = " << arr[i][4] << "\tBox Length = " << arr[i][5] << endl;
            cout << "Expected = " << arr[i][6] << endl;
            cout << "Result = " << val;
            cout << "\n\n";
        }
    }
    cout << "\n\n";
    cout << "Total Passed: " << passed << endl;
    cout << "Total Failed: " << failed;
    cout << "\n\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
}

int main()
{
    int arr1[][7] ={{0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {-1,1,1,1,1,1,0},
                    {1,1,1,-1,1,1,0},
                    {2,2,2,8,8,8,1},
                    {4,3,4,16,12,20,1},
                    {6,5,8,20,24,16,1},
                    {7,5,11,500,110,1400,1},
                    {3,5,20,16,16,600,0},
                    {3,5,7,21,30,75,1}};
    int arr2[][7] ={{0,0,0,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {-1,-1,-1,-1,-1,-1,0},
                    {2,2,2,8,8,8,64},
                    {4,3,4,16,12,20,80},
                    {12,10,16,40,24,32,16},
                    {7,5,11,500,111,1400,0},
                    {3,10,10,40,30,40,160},
                    {3,5,7,21,30,75,450}};
    test1(arr1,10);
    test2(arr2,10);
    return 0;
}
