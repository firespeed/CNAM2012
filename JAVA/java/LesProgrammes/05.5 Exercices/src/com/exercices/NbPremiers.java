package com.exercices;

public class NbPremiers {
	public static void main(String[] args) {
		// Calcul des nb premiers => 200
		int jusqua = 200;
		
		// Premiere boucle pour tous les nombres jusqu a 200
		for(int i=0; i<jusqua ; i++){
			// On part du principe au départ que c'est un nombre premier
			boolean premier = true;
			// 2° boucle repartant de 2 jusqu'au nombre actuel de la 1° boucle 
			for(int j=2 ; j<i; j++){
				// Si la division entiere donne 0
				// c'est qu'il est divisible par un nombre inferieur
				// donc ce n'est pas un nombre premier
				if(i%j == 0)
				{
					premier = false;
				}
			}
			// si premier et toujours à vrai
			// on a pas rencontré de diviseur entier
			// donc c'est un nombre premier
			if(premier) System.out.println(" ==> "+i);
		}
	}
}
