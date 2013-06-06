class Eleve
{ 
		private String nom ;
		private Mention resul ;
		
		public Eleve (String n)
		{ 
			this.nom = n;
			this.resul = Mention.NC ; // valeur par défaut
		}

		public String getNom(){return this.nom ;}
		public Mention getResul() {return this.resul ;}

		public void setNom(String nom) { this.nom = nom;}
		public void setResul(Mention r) { this.resul = r ;}
		
}