import java.io.*;
import java.util.*;


class SaisieVecteur
{

	public static void main (String args[]) throws IOException
	{
		Vector<String> v = new Vector<String>();
		int reponse;
		String tampon;	
		
		//preparation pour la saisie
		InputStreamReader flotClavier=new InputStreamReader(System.in);
		BufferedReader lc = new BufferedReader (flotClavier);

		System.out.print("Combien de valeurs voulez-vous saisir ? :");
		reponse=Integer.valueOf(lc.readLine()).intValue();

		System.out.println();
		for (int i=0;i<reponse;i++)
		{
			System.out.print("Chaine a saisir ==> :");
			tampon = lc.readLine();
			v.add(tampon);
			System.out.println();
		}
		
		System.out.println("Contenu du Vecteur :");
			for(int i=0;i<v.size();i++)
			{
				System.out.println(i+" ==> "+v.get(i));
			}	
		
	}

}