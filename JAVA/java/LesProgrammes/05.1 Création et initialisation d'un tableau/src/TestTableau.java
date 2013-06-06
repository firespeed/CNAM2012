class TestTableau
{
	String[] prenom = { "Dennis","Grace","Bjarne","James" };
	String[] nom = new String[prenom.length];

	void ImprimeNom() {
		int i=0;
		System.out.println(prenom[i]
		+ " " + nom[i]);
		i++;
		System.out.println(prenom[i]
		+ " " + nom[i]);
		i++;
		System.out.println(prenom[i]
		+ " " + nom[i]);
		i++;
		System.out.println(prenom[i]
		 + " " + nom[i]);
	}

	public static void main (String args[]) {
		TestTableau a = new TestTableau();
		a.ImprimeNom();
		System.out.println("---------");
		a.nom[0] = "Ritchie";
		a.nom[1] = "Hopper";
		a.nom[2] = "Stroustrup";
		a.nom[3] = "Gosling";
		a.ImprimeNom();
	}
}
