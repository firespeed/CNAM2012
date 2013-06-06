class Point implements Comparable // ne pas oublier implements ....
{
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int compareTo(Object pp) {
		Point p = (Point) pp;
		
		// D�finition des r�gles d'�galit�
		// et de l'ordre des �l�ments -1 0 1
		if (this.x < p.x)
			return -1;
		else if (this.x > p.x)
			return 1;
		else if (this.y < p.y)
			return -1;
		else if (this.y > p.y)
			return 1;
		else
			return 0;
	}

	public void affiche() {
		System.out.print("[" + x + " " + y + "] ");
	}

	private int x, y;
}