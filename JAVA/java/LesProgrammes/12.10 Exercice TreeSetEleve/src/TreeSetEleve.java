import java.util.TreeSet;
import java.util.Iterator;

public class TreeSetEleve  {
	
	public static void afficheCours(TreeSet<Eleve> cours, String lib){
		
		System.out.println("Liste des élèves du cours : "+lib);
		Iterator<Eleve> iter = cours.iterator();		
		while(iter.hasNext())
		{
			Eleve eleve = new Eleve();
			eleve = iter.next();
			System.out.print("|"+eleve.getNom()+" " +eleve.getPrenom()+"|");
		}
		System.out.println();
		System.out.println("----------------------------------");
		
	}
	
	public static void main (String args[])
	{
		Eleve e1 = new Eleve("Durand","Tony",20, 1);
		Eleve e2 = new Eleve("Dupont","Anne",20, 2);
		Eleve e3 = new Eleve("Martin","Morgane",20, 3);
		Eleve e4 = new Eleve("Martin","Alex",20, 4);
		Eleve e5 = new Eleve("Dubois","Axel",20, 5);
		
 		TreeSet<Eleve> cours1 = new TreeSet<Eleve>();
 		TreeSet<Eleve> cours2 = new TreeSet<Eleve>();
 		
 		cours1.add(e1);
 		cours1.add(e2);
 		cours1.add(e3);
 		cours1.add(e4);

 		cours2.add(e1);
 		cours2.add(e3);
 		cours2.add(e5);
 			 		
		afficheCours(cours1, "Cours N° 1");
		afficheCours(cours2, "Cours N° 2");

		
		// Union des 2 cours
		TreeSet<Eleve> coursAll = new TreeSet<Eleve>();
		coursAll.addAll(cours1);
		coursAll.addAll(cours2);
		afficheCours(coursAll, "Tous les élèves");
		
		TreeSet<Eleve> coursInter = new TreeSet<Eleve>();
		coursInter.addAll(cours1);
		coursInter.retainAll(cours2);
		afficheCours(coursInter, "les élèves participants à tous les cours");

		TreeSet<Eleve> coursDiff = new TreeSet<Eleve>();
		coursDiff.addAll(cours1);
		coursDiff.removeAll(cours2);
		afficheCours(coursDiff, "les élèves ne participants qu'au cours N°1");

		
	}
}
