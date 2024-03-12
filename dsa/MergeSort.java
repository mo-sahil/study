class MergeSort{
    public static void conquer(int arr[], int si, int mid, int ei) {
        int merged[] = new int[ei - si + 1];
        int idx1 = si, idx2 = mid+1, x = 0;

        while(idx1 <= mid && idx2 <= ei) {
            if(arr[idx1] <= arr[idx2]) {
                merged[x++] = arr[idx1++];
            } else {
                merged[x++] = arr[idx2++];
            }
        }

        while(idx1 <= mid) {
            merged[x++] = arr[idx1++];
        }

        while(idx2 <= ei) {
            merged[x++] = arr[idx2++];
        }

        for(int i = si, j = 0; j < merged.length; i++, j++) arr[i] = merged[j]; 
    }

    public static void divide(int arr[], int si, int ei) {
        if(si >= ei) return;
        
        int mid  = si + (ei - si)/2;
        divide(arr, si, mid);
        divide(arr, mid+1, ei);

        conquer(arr, si, mid, ei);
    }


    public static void main(String args[]){
        int arr[] = {1,3, 4, 2, 6, 3, 9};
        divide(arr, 0,arr.length-1);
        for(int i : arr) System.out.print(i + " ");
        System.out.println();
    }
}