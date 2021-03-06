class Point {
	private int x, y;
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int hashCode() {
	// Ici la table de hachage determine 
	// que le code de hachage de l'�l�ment est la somme
	// de ses coordonn�es
		return x + y;
	}

	public boolean equals(Object pp) {
	// M�thode d�terminant l'�galit� de 2 �l�ments
	// ils sont �gaux si leurs coordonn�es sont �gales
		Point p = (Point) pp;
		return ((this.x == p.x) & (this.y == p.y));
	}

	public void affiche() {
		System.out.print("[" + x + " " + y + "] ");
	}
}