enum Mois
{ 
	janvier (31, "jan", "january"), 
	fevrier (28, "fev", "february"),
	mars (31, "mar", "march"), 
	avril (30, "avr", "april"),
	mai (31, "mai", "may"), 
	juin (30, "jun", "june"),
	juillet (31, "jul", "july"), 
	aout (31, "aou", "august"),
	septembre (30, "sep", "september"), 
	octobre (31, "oct", "october"),
	novembre (30, "nov", "november"), 
	decembre (31, "dec", "december");

		private Mois(int n, String abrev, String na)
		{ 
			nj = n ;
			abrege = abrev ;
			anglais = na ;
		}
	
		public int nbJours () { return nj;}
	
		public String abreviation (){ return abrege ;}
	
		public String nomAnglais (){ return anglais ;}
	
		private int nj ;
	
		private String abrege ;
	
		private String anglais ;
	}

	public class EnumMethode{ 
		
		public static void main (String args[])
		{ 
			for (Mois m : Mois.values() )
				System.out.println ( m.abreviation() + " = " + m + " = "
						+m.nomAnglais() + " - " + m.nbJours() + " jours") ;
		}
	}
