bool validMountainArray(int* arr, int arrSize){
    if(arrSize < 3){
        return false;
    }else{
        int test = 0;
        if(arr[0] < arr[1]){
            for(int i = 1; i < arrSize-1; ++i){
                if(arr[i] == arr[i+1]){
                    return false;
                }else if(arr[i] > arr[i+1]){
                    test = i+1;
                    break;
                }
            }
        }else{
            return false;
        }

        if(test != 0){
            for(int i = test; i < arrSize-1; ++i){
                if(arr[i] <= arr[i+1]){
                    test = 0;
                    
                }
            }
        }
        if(test != 0){
            return true;
        }else{
            return false;
        }
    }
}