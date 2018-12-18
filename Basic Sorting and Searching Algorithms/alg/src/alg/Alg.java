/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package alg;
/**
 *
 * @author nishi
 */
import alg.testset.util.TestSort;
import alg.testset.util.testsortwithbubble;
public class Alg {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        testsortwithbubble.testExtremeCase(100, 10000, 100, "Comparison [base case]", true);
        testsortwithbubble.testExtremeCase(100, 10000, 100, "Comparison [worse case]", false);
        testsortwithbubble.testAverageCase(100, 10000, 100, "Comparison [average case]");
        
        
        
        
    }
    
}
