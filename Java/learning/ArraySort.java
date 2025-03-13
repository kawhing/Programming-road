//package ArraySort;

public class ArraySort{
    //int size;
    public void sort(int array[]){
        for(int i = 0; i < array.length-1; ++i){
            for(int j = i+1; j < array.length; ++j){
                if(array[i] < array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }        
    }
    public void printArray(int array[]){
        for(int i = 0; i < array.length; ++i){
            System.out.println(array[i]);
        }
    }

    public static void main(String[] args){
        int array[] = {10, 9, 7, 8, 6, 2, 3};
        ArraySort obj = new ArraySort();
        obj.sort(array);
        obj.printArray(array);
    }
    
}