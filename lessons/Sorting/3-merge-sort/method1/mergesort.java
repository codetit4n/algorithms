import java.util.Arrays;

class MergeSort {
  public static void main(String[] args) {
    int[] arr = {5, 8, -1, 0, 4, 2, 6, 3, 1, 7};

    System.out.println("\nUnsorted array: ");
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }

    int[] sorted = mergesort(arr);

    System.out.println("\nSorted array: ");
    for (int i = 0; i < sorted.length; i++) {
      System.out.print(sorted[i] + " ");
    }
    System.out.println();
  }

  // Merge sort function
  static int[] mergesort(int[] arr) {
    // Base condition - if array has only one element
    if (arr.length <= 1) {
      return arr;
    }

    int mid = arr.length / 2;

    // Sort left half
    int[] left = mergesort(Arrays.copyOfRange(arr, 0, mid));

    // Sort right half
    int[] right = mergesort(Arrays.copyOfRange(arr, mid, arr.length));

    // Merge left and right halves and return
    return merge(left, right);
  }

  // Merge function
  private static int[] merge(int[] left, int[] right) {
    int[] result = new int[left.length + right.length];

    int i = 0; // pointer for left array
    int j = 0; // pointer for right array
    int k = 0; // pointer for result array

    while (i < left.length && j < right.length) {
      if (left[i] <= right[j]) {
        result[k] = left[i];
        i++;
      } else {
        result[k] = right[j];
        j++;
      }
      k++;
    }

    // Copy remaining elements of left array
    while (i < left.length) {
      result[k] = left[i];
      i++;
      k++;
    }

    // Copy remaining elements of right array
    while (j < right.length) {
      result[k] = right[j];
      j++;
      k++;
    }

    return result;
  }
}
