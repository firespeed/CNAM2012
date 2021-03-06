import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;
 
/**
 * TreeMap example code.
 */
public class TreeMapExemple {
    public TreeMapExemple() {
        super();
    }
 
    public static void main(String[] args) {
        //Cr�ation d'un treeMap pour stocker des N� de telephone
        TreeMap<String, Integer> testTreeMap = new TreeMap<String, Integer>();
 
        testTreeMap.put("Sam", 258963147);
        testTreeMap.put("John", 5874569);
        testTreeMap.put("Sunny", 58963147);
        testTreeMap.put("Linda", 523658);
        testTreeMap.put("Amit", 5333658);
        testTreeMap.put("Sheila", 4566878);
        testTreeMap.put("Lili", 852369);
 
        System.out.println("Cl�s et valeurs : "); 
        for (Map.Entry<String, Integer> entry : testTreeMap.entrySet()) {
            System.out.println("Key = " + entry.getKey() + ", Value = " +
                               entry.getValue());
        }
        System.out.println("-------------------------------"); 
 
        SortedMap<String, Integer> headMapElements = testTreeMap.headMap("Linda") ;
        System.out.println("Sortie de la m�thode headMap : "); 
        for (Map.Entry<String, Integer> entry : headMapElements.entrySet()) {
            System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
        }
        System.out.println("-------------------------------"); 
 
        SortedMap<String, Integer> tailMapElements = testTreeMap.tailMap("Sheila") ;
        System.out.println("Sortie de la m�thode tailMap : "); 
        for (Map.Entry<String, Integer> entry : tailMapElements.entrySet()) {
            System.out.println("Key = " + entry.getKey() + ", Value = " +
                               entry.getValue());
        }
        System.out.println("-------------------------------"); 
 
        SortedMap<String, Integer> subMapElements = testTreeMap.subMap("Amit","Sheila") ;
        System.out.println("Sortie de la m�thode subMap : "); 
        for (Map.Entry<String, Integer> entry : subMapElements.entrySet()) {
            System.out.println("Key = " + entry.getKey() + ", Value = " + entry.getValue());
        }
 
    }
}