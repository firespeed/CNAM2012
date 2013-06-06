
class Eleve 
{ 
		private String nom ;
		private String prenom ;
		private int age ;
		private int id;
		
		public Eleve ()
		{ 
		}

		public Eleve (String nom, String prenom, int age, int id)
		{ 
			this.nom = nom;
			this.prenom = prenom;
			this.age = age;
			this.id = id;
		}
		
		public String getNom(){return this.nom ;}
		public String getPrenom(){return this.prenom ;}
		public int getAge(){return this.age;}
		public int getId(){return this.id;}

		public void setNom(String nom) { this.nom = nom;}
		public void setPrenom(String prenom) { this.prenom = prenom;}
		public void setAge(int age) { this.age = age;}
		public void setId(int id) { this.id = id;}
		

		public boolean equals(Eleve eleve)
		{
			if(this.getId() == eleve.getId()) return true;
			else return false;
		}
		
		public int hashCode ()
		{ 
			return this.getId(); 
		}

}