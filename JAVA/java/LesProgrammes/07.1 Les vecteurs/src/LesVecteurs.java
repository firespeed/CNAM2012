import java.io.IOException;
import java.util.*;

public class LesVecteurs {

	
	public static void main (String args[]) throws IOException
	{
		Vector<String> v = new Vector<String>();
		
		
		// ajout d'occurences au vecteur
		for(int i=0; i<100000; i++)
		{
			v.add("Enreg N�"+i);
		}

		
		// Parcours du vecteur avec un iterateur
		System.out.println("Parcours avec iterateur : ");		
		Iterator<String> it = v.iterator();

		long startTime = System.currentTimeMillis();
		while(it.hasNext())
		{
//			System.out.println("occurence : "+it.next());			
			it.next();
		}
		long endTime = System.currentTimeMillis();
		long temps = endTime - startTime;
		System.out.println("Temps d' ex�cution : "+temps+" ms");			

		
		
		// Parcours traditionnel du vecteur
		System.out.println("Parcours traditionnel : ");			
		startTime = System.currentTimeMillis();
		for(int i=0;i<v.size();i++)
		{
//			System.out.println("occurence : "+v.get(i));			
			v.get(i);
		}
		endTime = System.currentTimeMillis();
		temps = endTime - startTime;
		System.out.println("Temps d' ex�cution : "+temps+" ms");		
	}
	
}
