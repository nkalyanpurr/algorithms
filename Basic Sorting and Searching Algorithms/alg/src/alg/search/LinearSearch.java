
package alg.search;

import java.util.Arrays;

public class LinearSearch {
    public static int search(int[] array, int targetValue) {
        //System.out.println(Arrays.toString(array));
        for (int i = 0; i< array.length; i++)
            if (array[i] == targetValue)
                return i;

        return -1;
    }
}
