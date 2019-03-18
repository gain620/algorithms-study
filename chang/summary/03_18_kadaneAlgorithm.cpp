// Maximum Sum SubArray (Kadane's algorithm) (Largest Sum Contigous SubArray)

#include <iostream>
#include <vector>
#include <random>

using namespace std;


int KadaneSubArray(const vector<int>& arr)
{
    int maxSubVal = arr[0];
    int maxEnding = 0;
    int start = 0, end = 0, s = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
        maxEnding += arr[i];
        
        if(maxSubVal < maxEnding)
        {
            maxSubVal = maxEnding;
            start = s;
            end = i;
        }
        
        if(maxEnding < 0)
        {
            maxEnding = 0;
            s = i + 1;
        }
        
    }
    
    cout << endl << "The sub array starts from " << start << " to " << end << endl; 
    
    
    return maxSubVal;
}

vector<int>& InitVector(vector<int>& arr)
{
    random_device rd;
    mt19937 mersenne(rd());
    uniform_int_distribution<> dice(-10,10);
    
    
    for(int i = 0; i < arr.capacity(); i++)
    {
        arr.push_back(dice(mersenne));
    }
    
    // prints out vector
    for(const auto& num : arr)
    {
        cout << num << ", ";
    }
}


int main()
{
    vector<int> inputArr;
    inputArr.reserve(16);
    
    InitVector(inputArr);

    cout << endl << "Max Sub Array value is " << KadaneSubArray(inputArr);

    
    return 0;
}
