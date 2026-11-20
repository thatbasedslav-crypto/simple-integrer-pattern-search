#include <iostream>
#include <vector>
#include <string>

bool processVectors(std::vector<int> arrfs, std::vector<int> arrsc) //сравнение и возврат результата
{
    int num=0;
    int truthPoints=0;
    std::vector<int> truth_vec{};
    
    for(int i=0;i<std::size(arrsc);i++)
    {
        for(int k=0;k<std::size(arrsc);k++)
        {
            if(arrsc[k]==arrfs[k+num])
            {
                truthPoints++;
            }
        }
        if(truthPoints<std::size(arrsc))
        {
            truthPoints=0;
        }

        num++;
    }
    std::cout<<truthPoints<<" "<<std::size(arrsc)<<"\n";
    return (std::size(arrsc)<=truthPoints) ? true : false;
}

int main() {
    int n1;
    int n2;
    std::cout<<"Initialize size of array: ";
    std::cin>>n1;
    std::cout<<"Initialize size of a pattern: ";
    std::cin>>n2;
    std::vector<int> arr1;
    std::vector<int> arr2;
    std::cout<<"Initialize array: "<<"\n";
    for (int i = 0; i < n1; i++) 
    {
        int val;
        std::cin >> val;
        arr1.push_back(val);
    }
    std::cout<<"Initialize pattern: "<<"\n";
    for (int i = 0; i < n2; i++) 
    {
        int val2;
        std::cin >> val2;
        arr2.push_back(val2);
    }
    bool isConsecutive;
    if (std::size(arr1)>std::size(arr2))
    {
        isConsecutive = processVectors(arr1, arr2);
    } else 
    {
        isConsecutive = processVectors(arr2, arr1);
    }
    std::string result = (isConsecutive) ? "True, pattern found" : "False, pattern not found";
    std::cout<<result<<std::endl;
    return 0;
}