package com.exercices;

public class MultipleDeTrois {

	public static void main(String[] args) {
		
		// le chiffre pour lequel on veut calculer tous les multiple de 3
		// situés avant
		int chiffre = 300;
		
		// Une boucle for, pour parcourir tous les nombres
		// Jusqu'à cet entier
		for(int i = 0;i<=chiffre; i++)
		{
			// Si la division entière par 3 donne 0
			// c'est un multiple
			if(i%3 == 0)
			{
				// Affichage des résultats dans la console
				System.out.println("Multiple de 3 : "+i);
			}
		}
	}
}

