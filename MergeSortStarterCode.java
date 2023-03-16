public class MergeSortStarterCode
{
    // temp is a temporary array that we will use as a copy 
    // of the original array so we won't overwrite values 
    // in the original; much the same way as we use a temp
    // variable when we swap two values in an array
    private static int[] temp;
    
    public static void sort(int[] arr)
    {
        temp = new int[arr.length];
        mergeSort(arr, 0, arr.length - 1);
    }
    
    private static void mergeSort(int[] arr, int low, int high)
    {
        if (low >= high)
            return; // base case
        int middle = (low + high)/2;  
        
        mergeSort (arr, low, middle); // sort the left half of the array (it's magic!)
        mergeSort (arr, middle+1, high); // sort the right half of the array
        
        merge (arr, low, middle, high); // merge the two sorted halves
    }
    
    private static void merge(int[] arr, int low, int middle, int high)
    {
/* DEBUGGING:
       System.out.println("low: " + low);
       System.out.println("middle: " + middle);
       System.out.println("high: " + high);
*/       
        // merges the two sorted halves:
        // arr[low] to arr[middle] is the left half.
        // arr[middle+1] to arr[high] is the right half.
        
       
        // store a copy of arr[low] to arr[high]
        // in temp[low] to temp[high]
        // thus, when merging, we can copy the values
        // from temp and store them in arr without worrying
        // about overwriting values in arr.
        for (int i = low; i <= high; i++)
            temp[i] = arr[i];
/* DEBUGGING:
         for (int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
*/
        int x = low, y = (middle + 1), z = low;
        while ((x <= middle) && (y <= high))
        {
            if (temp[x] <= temp[y])
            {
                arr[z] = temp[x];
                x++;
            }
            else
            {
                arr[z] = temp[y];
                y++;
            }
            z++;
        }
        while (x <= middle)
        {
            arr[z] = temp[x];
            x++;
            z++;
        }
        while (y <= high)
        {
            arr[z] = temp[y];
            y++;
            z++;
        }
         // your code here
        
       
    }
    
    private static void print(int[] arr)
    {
        // Print method fails for empty arrays, so I fixed it.
        System.out.print("[");
        if (arr.length > 0)
        {
            for (int i =0; i < arr.length-1; i++)
                System.out.print(arr[i] + ",");
            System.out.println(arr[arr.length-1] + "]");
        }
        else
        {
            System.out.print("]");
        }
    }    
    
    //tester code  
    public static void main (String[] args)
    {    
        int[] numbers = {3,1,4,5,9,2};
        int[] grades = {92,85,76,76,45,95,100,100,64,47,99};
        sort(numbers);
        sort(grades);
        print(numbers);
        print(grades);
                       
    }
             
}
