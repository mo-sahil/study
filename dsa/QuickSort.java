public class QuickSort {
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low  - 1;
        
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                int temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[++i];
        arr[i] = arr[high];
        arr[high] = temp;

        return i;
    }

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pidx = partition(arr, low, high);
            quickSort(arr, low, pidx-1);
            quickSort(arr, pidx+1, high);
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 6, 3, 9, 5, 7, 8};

        quickSort(arr, 0, arr.length-1);

        for(int i : arr) System.out.print(i + " ");
        System.out.println();
    }
}
