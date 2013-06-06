package com.membre;

public class LesMembresFamilles {

	
	
	public static void main (String[] args)
	{
		Pere lePere = new Pere();
		Fils leFils = new Fils();
		
		System.out.println("Le père : nom : "+lePere.nom+" - prenom : "+lePere.prenom+" - age : "+lePere.age);			
		System.out.println("Le fils : nom : "+leFils.nom+" - prenom : "+leFils.prenom+" - age : "+leFils.age);			

		
	}
	
}
