
class Couple<T, U> {
	
	private T x; // le premier element du couple
	private U y; // le second element du couple

	public Couple(T premier, U second) {
		x = premier;
		y = second;
	}

	public T getPremier() {
		return x;
	}

	public void affiche() {
		System.out.println("premiere valeur : " + x + " - deuxieme valeur : "+ y);
	}
}