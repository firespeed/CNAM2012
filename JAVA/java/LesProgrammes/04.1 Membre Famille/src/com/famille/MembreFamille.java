package com.famille;

public abstract class MembreFamille {

	// Le nom est défini en variable de classe
	// avec le mot-clef static
	// Il est donc le même pour tous les objets
	public static String nom = "Johnson";
	
	// Le prénom et l'age sont des variables
	// D'instance propre à chaque objet
	public String prenom;
	public int age;

}
