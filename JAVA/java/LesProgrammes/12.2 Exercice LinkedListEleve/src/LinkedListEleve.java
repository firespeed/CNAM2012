import java.util.LinkedList;
import java.util.ListIterator;


public class LinkedListEleve {

	
	public static void main (String[] args)
	{ 
		String reponse;
		
		LinkedList<Eleve> liste = new LinkedList<Eleve>();
		System.out.print("Voulez-vous saisir un eleve ? (O/N)");
		reponse = Clavier.lireString();
		System.out.println();

		while(reponse.equals("O"))
		{
			// Création d'un élève
			Eleve eleve = new Eleve();
			
			System.out.print("Nom : ");			
			eleve.setNom(Clavier.lireString());
			System.out.println();
			
			System.out.print("Prenom : ");
			eleve.setPrenom(Clavier.lireString());
			System.out.println();
			
			System.out.print("Age : ");
			eleve.setAge(Clavier.lireInt());
			System.out.println();
			
			liste.add(eleve);			
			
			System.out.print("Voulez-vous saisir un autre eleve ? (O/N)");
			reponse = Clavier.lireString();
			System.out.println();
		}
	
		System.out.println("Liste des élèves :");
		ListIterator<Eleve> iter = liste.listIterator();
	
		while(iter.hasNext())
		{
			Eleve eleve = new Eleve();
			eleve = iter.next();
			System.out.println("----------------------------------");
			System.out.println("Nom : "+eleve.getNom());
			System.out.println("Prénom : "+eleve.getPrenom());
			System.out.println("Age : "+eleve.getAge());
			System.out.println("----------------------------------");
		}
	}
		
}

