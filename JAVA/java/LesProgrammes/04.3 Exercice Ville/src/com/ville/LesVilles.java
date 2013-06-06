package com.ville;

public class LesVilles {

	
	public static void main (String[] args)
	{
		Paris villeParis = new Paris();
		NewYork villeNewYork = new NewYork();
		Berlin villeBerlin = new Berlin();
		Lyon villeLyon = new Lyon();
		
		System.out.println("Ville : "+
		" - Nom : "+
		villeParis.nom+
		" - Pays : "+
		villeParis.pays+
		" - monnaie : "+
		villeParis.monnaie+
		" - nb Habitants pays : "+
		villeParis.nbHabitants+
		" - Nb habitants : "+
		villeParis.nbHabitantsVille
		);			

		System.out.println("Ville : "+
		" - Nom : "+
		villeNewYork.nom+
		" - Pays : "+
		villeNewYork.pays+
		" - monnaie : "+
		villeNewYork.monnaie+
		" - nb Habitants pays : "+
		villeNewYork.nbHabitants+
		" - Nb habitants : "+
		villeNewYork.nbHabitantsVille
		);			
		
		System.out.println("Ville : "+
		" - Nom : "+
		villeBerlin.nom+
		" - Pays : "+
		villeBerlin.pays+
		" - monnaie : "+
		villeBerlin.monnaie+
		" - nb Habitants pays : "+
		villeBerlin.nbHabitants+
		" - Nb habitants : "+
		villeBerlin.nbHabitantsVille
		);			

		System.out.println("Ville : "+
		" - Nom : "+
		villeLyon.nom+
		" - Pays : "+
		villeLyon.pays+
		" - monnaie : "+
		villeLyon.monnaie+
		" - nb Habitants pays : "+
		villeLyon.nbHabitants+
		" - Nb habitants : "+
		villeBerlin.nbHabitantsVille
		);			
		
		
	}
}
