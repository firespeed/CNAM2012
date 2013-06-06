import java.io.IOException;
import java.util.*;

public class LesPiles {
	public static void main (String args[]) throws IOException
	{
	
		Stack<String> s = new Stack<String>();
		
		s.push("Un");		// Ajout des valeurs
		s.push("Deux");
		s.push("Trois");
		s.push("Quatre");
		s.push("Cinq");
		s.push("Six");

		// valeur de la pile
		// On ne peut pas la lire avec une boucle classique
		// On utilise donc un iterateur
		Iterator<String> it = s.iterator();
		System.out.println("Valeurs de la pile : ");
		while(it.hasNext())
		{
			System.out.println("occurence : "+it.next());
		}
		
		String s1 = s.pop();// s1 vaut "Six"
		String s2 = s.pop();// s2 vaut "Cinq"
		String s3 = s.peek();// s3 vaut "Quatre"

		int y = s.search("Deux"); // retourne 2
		

		boolean isEmpty = s.empty(); // retourne false
	
		// R�instanciation de l'it�rateur
		// pour le repositionner en d�but de liste
		it = s.iterator();
		System.out.println("Valeurs de la pile : ");
		while(it.hasNext())
		{
			System.out.println("occurence : "+it.next());
		}
		
	}
	
	
}
