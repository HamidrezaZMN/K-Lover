/* a number is k lover if it the divisions of
* each digit's repetition, equals to k
* for example: 2552515
* it has 4 fives and 2 twos
* so it's 2 lover (4/2==2)
*/

# include <iostream>
# include <set>          // a set is a array with no repeated element
# include <algorithm>    // it's used to find if an element is in a vector or not
# define N 10
using namespace std;

bool checker(set<int> s, int n);     // checks if n is in s or not

int main(){
    // getting number
    cout << "enter the number: " ;
    int number; cin >> number;
    
    // converting number's type to string
    string str = to_string(number);
    
    // adding one number to each digit that is used in the given number
    int arr[N];
    for(int i=0; i<N; i++) arr[i]=0;
    for(int i=0; i<str.length(); i++)
        arr[str[i]-48]++;
    
    // putting all none-zero numbers in one array
    // this array is the repetitions
    vector<int> nums;
    for(int i=0; i<N; i++)
        if(arr[i]!=0) nums.push_back(arr[i]);
    
    // adding K lover numbers to K_lover
    set<int> K_lover; int maxOmin;
    for(int i=0; i<nums.size()-1; i++)
        for(int j=i+1; j<nums.size(); j++){
        	if(max(nums[i], nums[j]) % min(nums[i], nums[j]) == 0){
	            maxOmin = max(nums[i], nums[j]) / min(nums[i], nums[j]);
	            if(maxOmin>1)
	            	K_lover.insert(maxOmin);
	        }
        }
    
    // if the given number is empty then return this
    if(K_lover.empty())                     
        cout << "\nthe number " << number << " is not k lover\n";
    else {
        // gets a k and checks if the given number is k lover or not
        cout << "\nenter k: " ;
        int k; cin >> k ;
        if(checker(K_lover, k)==1)
            cout << "\nthe number " << number << " is " << k << " lover" << endl ;
        else
            cout << "\nthe number " << number << " isn't " << k << " lover" << endl ;
            
        cout << "-------------------------" << endl ;
            
        // says all the k lover numbers
        cout << "\nthe number " << number << " is " ;
        int count=0;
        set<int> :: iterator itr;
        for(itr=K_lover.begin(); itr!=K_lover.end(); itr++){
            cout << *itr;
            if(count < K_lover.size()-1) cout << " and " ;
            else cout << " " ;
            count++;
        }
        cout << "lover\n" ;
    }
}

bool checker(set<int> s, int n){
    return (find(s.begin(), s.end(), n) != s.end());
}
