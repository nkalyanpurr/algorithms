
package alg.sort;

/**
 *
 * @author nishi
 */
public class BubbleSort {
    public static void sort(int numbers[], int numbersSize){
        int i,j,temp;
        for(j = 0; j < numbersSize -1; j++) {
            
            for(i=0; i < numbersSize - j - 1; i++) 
                if(numbers[i] > numbers[i+1] ) {
                    temp=numbers[i];            
                    numbers[i]=numbers[i+1];   
                    numbers[i+1]=temp;         
                            
                }
            
        }
    }
        public static void main(String [] args) {
        int numbers [] = {10, 2, 78, 4, 45, 32, 7, 11};
        final int NUMBERS_SIZE = 8;
        int i,j;
        System.out.print("-----------BubbleSort---------\nUNSORTED: ");
        for (i = 0; i < NUMBERS_SIZE; i++) {
            System.out.print(numbers [i] + " ");
        }
        System.out.print("SORTED: ");
        sort(numbers,NUMBERS_SIZE);
        for (i = 0; i < NUMBERS_SIZE; i++) {
            System.out.print(numbers [i] + " ");
        }
    }
}

    

