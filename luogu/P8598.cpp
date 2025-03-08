#include <iostream>
#include <vector>
#include <algorithm>
//created by Claude 3.7 Sonnet, because my code not perfectfully correct, so I use the AI to help me.
int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> nums;
    
    // 读取所有数据
    for (int i = 0; i < n; ++i) {
        int num;
        while (std::cin >> num) {
            nums.push_back(num);
            // 检查是否到行尾
            if (std::cin.peek() == '\n') {
                std::cin.ignore();
                break;
            }
        }
    }
    
    // 排序
    std::sort(nums.begin(), nums.end());
    
    // 寻找断号和重号
    int missing = -1;
    int duplicate = -1;
    
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        int diff = nums[i + 1] - nums[i];
        
        if (diff == 0) {  // 重号
            duplicate = nums[i];
        } else if (diff == 2) {  // 断号
            missing = nums[i] + 1;
        }
    }
    
    // 输出结果
    std::cout << missing << " " << duplicate << std::endl;
    
    return 0;
}