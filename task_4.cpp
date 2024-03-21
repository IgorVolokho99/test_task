#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


std::list<int> mergeAndUnique(std::vector<int>& vec, std::list<int>& lst) {

    std::list<int> vecAsList(vec.begin(), vec.end());

    vecAsList.merge(lst);


    vecAsList.unique();

    return vecAsList;
}

int main() {
    std::vector<int> vec = {1, 2, 4, 5, 6};
    std::list<int> lst = {2, 3, 5, 7};

    std::list<int> result = mergeAndUnique(vec, lst);

    std::cout << "Union list without repeating: " << std::endl;
    for(int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
