enum Mention
	{ 
		NA ("Non admis"), P ("Passable"), AB ("Assez bien"),
		B ("Bien"), TB ("Tres bien"), NC ("Non connu");
		
		private Mention (String d) {mention = d ;}
		
		public String details() { return mention;}
	
		private String mention; 
	}


public class Examen {
	
		// m�thode qui demande au clavier trois notes pour un nom donne
		// et qui fournit en retour la moyenne correspondante
		static public double moyenne (String n)
		{ 
			System.out.println ("donnez les trois notes de l'eleve " + n) ;
			double som = 0. ;
			for (int i=0 ; i<3 ; i++)
			{ 
				double note = Clavier.lireDouble() ;
				som += note ;
			}
			double moyenne = som / 3. ;
			return moyenne ;
		}
		// m�thode qui d�finit la mention en fonction de la moyenne
		static public Mention resul (double m)
		{ 
			if ( m<10. ) return Mention.NA ;
			if ( m<12.0) return Mention.P ;
			if ( m<14.0) return Mention.AB ;
			if ( m<16.0) return Mention.B ;
			return Mention.TB ;
		}	

	public static void main (String args[])
	{ 
		String noms[] = { "Dutronc", "Dunoyer", "Lechene", "Dubois", "Frenet" } ;
		// creation du tableau d'eleves
		int nel = noms.length ;
	
		Eleve eleves [] = new Eleve [nel] ;
		for (int i=0 ; i<nel ; i++)
			eleves [i] = new Eleve (noms[i]) ;
	
		// lecture des notes et d�termination du r�sultat de chaque �l�ve
		for (Eleve el : eleves)
		{ 
			double moy = moyenne (el.getNom()) ;
			el.setResul ((resul(moy))) ;
		}
	
		// affichage r�sultats
		System.out.println ("Resultats : ") ;
		for (Eleve el : eleves)
			System.out.println (el.getNom() + " - " + el.getResul().details()) ;
		}
	
		
	}